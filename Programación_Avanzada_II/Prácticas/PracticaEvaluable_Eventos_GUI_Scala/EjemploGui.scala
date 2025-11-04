import java.awt.event.{ActionEvent, ActionListener}
import java.awt.{BorderLayout, FlowLayout, GridLayout}
import java.beans.{PropertyChangeEvent, PropertyChangeListener}
import java.util
import javax.swing.{JButton, JFrame, JLabel, JPanel, JProgressBar, JScrollPane, JTextArea, JTextField, SwingUtilities, SwingWorker, WindowConstants}
import scala.collection.mutable.ListBuffer
import scala.concurrent.CancellationException

class WorkerEjemplo(n:Int, panel:PanelEjemplo) extends SwingWorker[Unit,Int]{

  def esPrimo(n: Int): Boolean = {
    def loop(div: Int): Boolean = {
      if (div * div > n) true
      else if (n % div == 0) false
      else loop(div + 1)
    }

    if (n == 1 || n == 2) true
    else loop(2)
  }

  def listaPrimos(n: Int): Unit=
    def loop(i: Int, pprimo: Int): Unit = {
      if (i < n && !this.isCancelled)
        if (esPrimo(pprimo))
          publish(pprimo)
          this.setProgress((i+1)*100/n)
          loop(i + 1, pprimo + 1)
        else
          loop(i, pprimo + 1)
      }
    loop(0, 1)

  override def doInBackground():Unit = {
    this.setProgress(0)
    listaPrimos(n)
  }

  override def done(): Unit = {
    try{
      panel.nuevoMensaje("Tarea finalizada")
    } catch{
      case e:CancellationException => panel.nuevoMensaje("Tarea cancelada")
    }
  }

  override def process(chunks: util.List[Int]): Unit =
    panel.listaPrimos(chunks)

}
class ControladorEjemplo(panel:PanelEjemplo) extends ActionListener,PropertyChangeListener {

  private var worker: WorkerEjemplo = null

  override def actionPerformed(e: ActionEvent): Unit = {
    if (e.getActionCommand.equals("SI")) {
      panel.nuevoMensaje("Sí pulsado")
    } else if (e.getActionCommand.equals("NO")) {
      panel.nuevoMensaje("No pulsado")
    } else if (e.getActionCommand.equals("CANCELAR")) {
      if (worker!=null) worker.cancel(true)
    } else
    //e.getActionCommand.equals("PRIMOS")
      try {
        val n = panel.numero()
        panel.limpiarArea()
        panel.nuevoProgreso(0)
        // panel.nuevoMensaje("Canculando primos....")
        //   val lista = listaPrimos(n)
        //  panel.listaPrimos(lista)
        // panel.nuevoMensaje("Tarea finalizada")
        worker = new WorkerEjemplo(n, panel)
        worker.addPropertyChangeListener(this)
        worker.execute()
      } catch {
        case e: NumberFormatException => panel.nuevoMensaje("Número incorrecto")
      }
  }

  override def propertyChange(evt: PropertyChangeEvent): Unit = {
    if (evt.getPropertyName.equals("progress")){
      panel.nuevoProgreso(evt.getNewValue.toString.toInt)
    }
  }
}

class PanelEjemplo extends JPanel{
  private val panelNorte = new JPanel()
  private val etiq = new JLabel("es verdad?")
  private val bsi = new JButton("Sí")
  private val bno = new JButton("No")
  
  private val etiqPrimos = new JLabel("Primos?:")
  private val nprimos = new JTextField(5)
  
  private val mensaje = new JLabel("GUI creada")
  private val area = new JTextArea(30,30)
  private val cancelar = new JButton("Cancelar")
  private val progreso = new JProgressBar(0,100)
  
  
  progreso.setStringPainted(true)
  progreso.setVisible(true)

  panelNorte.add(etiq)
  panelNorte.add(bsi)
  panelNorte.add(bno)
  panelNorte.add(etiqPrimos)
  panelNorte.add(nprimos)
  panelNorte.add(cancelar)

  private val scrol = new JScrollPane(area)
  this.setLayout(new BorderLayout())
  this.add(panelNorte,BorderLayout.NORTH)
  val panelSur = new JPanel()
  panelSur.add(mensaje)
  panelSur.add(progreso)
  this.add(panelSur,BorderLayout.SOUTH)
  this.add(scrol,BorderLayout.CENTER)

  def controlador(ctr:ActionListener)={
    bsi.setActionCommand("SI")
    bno.setActionCommand("NO")
    bsi.addActionListener(ctr)
    bno.addActionListener(ctr)
    nprimos.setActionCommand("PRIMOS")
    nprimos.addActionListener(ctr)
    cancelar.setActionCommand("CANCELAR")
    cancelar.addActionListener(ctr)
  }

  def nuevoMensaje(str:String) = {
    mensaje.setText(str)
  }

  def numero():Int = {
    Integer.parseInt(nprimos.getText)
  }

  def listaPrimos(lista:java.util.List[Int]) ={
    for (i<-0 until lista.size())
      area.append(s"${lista.get(i)} ")
      if ((i+1)%10 == 0) area.append("\n")
  }
  def limpiarArea()=
    area.setText("")

  def nuevoProgreso(n:Int) =
    progreso.setValue(n)
}


object EjemploGui {

  def crearGUI(ventana:JFrame)={
    val panel = new PanelEjemplo
    val ctr = new ControladorEjemplo(panel)
    panel.controlador(ctr)
    ventana.setContentPane(panel)
    ventana.pack()
    ventana.setVisible(true)
    // Controla que cuando se clicke en el botón de cerrar este se cierre con éxito
    ventana.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE)
  }

  def main(args:Array[String]): Unit = {
    SwingUtilities.invokeLater(
      new Runnable:
        override def run(): Unit =
          val ventana = new JFrame("Ejemplo primos")
          crearGUI(ventana)
    )


  }

}
