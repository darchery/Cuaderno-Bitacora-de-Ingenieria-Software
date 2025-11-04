// Lucas Díaz Ruiz
// 2ºA, Ingeniería del Software
// PAII

import java.awt.{BorderLayout, GridLayout}
import java.beans.{PropertyChangeEvent, PropertyChangeListener}
import java.awt.event.{ActionEvent, ActionListener}
import java.util
import javax.swing.*
import scala.annotation.tailrec
import scala.concurrent.CancellationException // Importamos toda la librería swing(Usaremos JPanel, JLabel, JTextField, JTextArea, JProgressBar, ...)

class Primos(posicion: Int, primo1: Int, primo2: Int) {
  override def toString: String = s"$posicion:($primo1, $primo2) "
}

class Panel extends JPanel { // Panel hereda de JPanel => esta clase será una ventana/panel personalizado para la GUI
  /**
   * // Patrón seguido
   * +---------------------------+   <- NORTH: typeLabel + typeField
   * | ¿cuántos primos...?       |
   * +---------------------------+
   * |                           |   <- CENTER: JTextArea con scroll
   * |  [área de resultados]     |
   * |                           |
   * +---------------------------+
   * | Área type creada          |   <- SOUTH: typeMsg
   * +---------------------------+
   */

  // Constantes para expresar los campos de entrada de cada asociación de pares primos y el botón de cancelar
  val TWIN_FIELD = "NUMBER1"
  val COUSIN_FIELD = "NUMBER2"
  val SEXY_FIELD = "NUMBER3"
  val CANCEL_BUTTON = "CANCEL"

  // Etiquetas(Labels) y Campos(fields)
  // Etiqueta y campo de texto para los primos twin
  private val twinLabel = JLabel("cuántos primos twin quieres?")
  private val twinField = JTextField(3) // Campo de tamaño 3

  // Etiqueta y campo de texto para los primos cousin
  private val cousinLabel = JLabel("cuántos primos cousin quieres?")
  private val cousinField = JTextField(3) // Campo de tamaño 3

  // Etiqueta y campo de texto para los primos sexy
  private val sexyLabel = JLabel("cuantos primos sexy quires?")
  private val sexyField = JTextField(3) // Campo de tamaño 3

  // Mensaje de estado(será puesto en la parte inferior)
  private val statusMessage = JLabel("GUI Creada")

  // Áreas de texto para mostrar los resultados de cada tipo
  private val twinArea = JTextArea(10, 40) // Número de filas(10) y columnas(40) visibles
  private val cousinArea = JTextArea(10, 40)
  private val sexyArea = JTextArea(10, 40)

  // Colocamos esta área creada en los scrolls(para poder observar todos los valores por si el tamaño de JTextArea no es suficiente)
  private val twinScroll = JScrollPane(twinArea)
  private val cousinScroll = JScrollPane(cousinArea)
  private val sexyScroll = JScrollPane(sexyArea)

  // Etiquetas informativas para cada área(creación de cada una)
  private val twinMsg = JLabel("Área Twin creada")
  private val cousinMsg = JLabel("Área Cousin creada")
  private val sexyMsg = JLabel("Área Sexy creada")

  // Botón para cancelar las operaciones en cálculo o calculadas
  private val cancelButton = JButton("Cancelar")


  // Getters de Twin
  def getTwinField: JTextField = twinField
  def getTwinArea: JTextArea = twinArea

  // Getters de Cousin
  def getCousinField: JTextField = cousinField
  def getCousinArea: JTextArea = cousinArea

  // Getters de Sexy
  def getSexyField: JTextField = sexyField
  def getSexyArea: JTextArea = sexyArea

  init() // Métodoo para inicializar y ensamblar toda la interfaz

  private def init(): Unit = {
    this.setLayout(BorderLayout()) // Setea el diseño principal del panel a BorderLayout(NORTH, SOUTH, CENTER, EAST, WEST)

    // Panel norte => solo con el botón cancelar
    val northPanel = JPanel()
    northPanel.add(cancelButton)

    // Panel central con 1 fila y 3 columnas(twin, cousin y sexy)
    val centerPanel = JPanel(GridLayout(1, 3))

    // Construcción de cada columna(twin, cousin, sexy)
    // Se crea un panel superior añadiendo la etiqueta y el campo asociado
    val twinTop = JPanel()
    twinTop.add(twinLabel) // Añade etiqueta(texto pregunta)
    twinTop.add(twinField) // Añade el campo de texto

    val cousinTop = JPanel()
    cousinTop.add(cousinLabel)
    cousinTop.add(cousinField)

    val sexyTop = JPanel()
    sexyTop.add(sexyLabel)
    sexyTop.add(sexyField)

    // Creamos el panel twin
    val twinPanel = JPanel(BorderLayout()) /* Nuevo panel que usa BorderLayout => gestor de diseño que divide el espacio en 5 partes => NORTH, SOUTH, CENTER, EAST y WEST*/
    // Parte norte
    twinPanel.add(BorderLayout.NORTH, twinTop) // Añade al panel twin, en la parte norte el panel twinTop(con su label y su campo de texto)
    // Parte central
    twinPanel.add(BorderLayout.CENTER, twinScroll) // Añade en el centro el scroll bar de twin(contiene un JTextArea)
    // Panel twin inferior
    val twinBottom = JPanel() // Sin BorderLayout
    twinBottom.add(twinMsg) // Añadimos abajo el mensaje de estado twin
    // Parte sur
    twinPanel.add(BorderLayout.SOUTH, twinBottom) // Añadimos al sur el boton twin

    // Panel cousin
    val cousinPanel = JPanel(BorderLayout()) // Uso de BorderLayout
    // Parte norte
    cousinPanel.add(BorderLayout.NORTH, cousinTop) // Añadimos al sur el panel superior de cousin
    // Parte central
    cousinPanel.add(BorderLayout.CENTER, cousinScroll) // Añadimos en el centro el scroll de cousin
    // Panel cousin inferior
    val cousinBottom = JPanel() // No usa BorderLayout
    cousinBottom.add(cousinMsg) // Añade el mensaje de estado
    // Parte sur
    cousinPanel.add(BorderLayout.SOUTH, cousinBottom) // Añadimos al panel en el sur este panel inferior

    // Panel sexy
    val sexyPanel = JPanel(BorderLayout()) // Uso de BorderLayout
    // Parte norte
    sexyPanel.add(BorderLayout.NORTH, sexyTop) // Añadimos el panel top al norte
    sexyPanel.add(BorderLayout.CENTER, sexyScroll) // Añadimos el scroll al centro
    val sexyBottom = JPanel()
    sexyBottom.add(sexyMsg)
    // Parte sur
    sexyPanel.add(BorderLayout.SOUTH, sexyBottom)

    // Añadimos al panel central los paneles twin, cousin y sexy
    centerPanel.add(twinPanel)
    centerPanel.add(cousinPanel)
    centerPanel.add(sexyPanel)

    // Añadimos al panel principal el panel norte, central y el mensaje de status del panel
    this.add(BorderLayout.NORTH, northPanel)
    this.add(BorderLayout.CENTER, centerPanel)
    this.add(BorderLayout.SOUTH, statusMessage)
  }

  def controlador(ctr: ActionListener, tipo :String): Unit = {

    if (tipo == "twin") {
      twinField.setActionCommand("TWIN")
      twinField.addActionListener(ctr)
    } else if (tipo == "cousin") {
      cousinField.setActionCommand("COUSIN")
      cousinField.addActionListener(ctr)
    } else {
      sexyField.setActionCommand("SEXY")
      sexyField.addActionListener(ctr)
    }
    cancelButton.setActionCommand("CANCELAR")
    cancelButton.addActionListener(ctr)
  }

  def nuevoMensaje(str: String, tipo: String): Unit = {
    if (tipo == "twin") {
      twinMsg.setText(str)
    } else if (tipo == "cousin") {
      cousinMsg.setText(str)
    } else if (tipo == "sexy") {
      sexyMsg.setText(str)
    } else {
      statusMessage.setText(str)
    }
  }

  def numero(tipo: String): Int = {
    if (tipo == "twin") {
      Integer.parseInt(twinField.getText)
    } else if (tipo == "cousin") {
      Integer.parseInt(cousinField.getText)
    } else {
      Integer.parseInt(sexyField.getText)
    }
  }


  def listaPrimos(lista: java.util.List[String], tipo: String): Unit = {

    if (tipo == "twin") {
      for (i <- 0 until lista.size())
        twinArea.append(s"${lista.get(i)} ")
        if ((i + 1) % 10 == 0) twinArea.append("\n")
    } else if (tipo == "cousin") {
      for (i <- 0 until lista.size())
        cousinArea.append(s"${lista.get(i)} ")
        if ((i + 1) % 10 == 0) cousinArea.append("\n")
    } else {
      for (i <- 0 until lista.size())
        sexyArea.append(s"${lista.get(i)} ")
        if ((i + 1) % 10 == 0) sexyArea.append("\n")
    }
  }

  def limpiarArea(tipo: String): Unit = {
    if (tipo == "twin") {
      twinArea.setText("")
    } else if (tipo == "cousin") {
      cousinArea.setText("")
    } else {
      sexyArea.setText("")
    }
  }
}

class Controlador(panel: Panel) extends ActionListener, PropertyChangeListener {
  private var workerTwin: WorkerTwin = _
  private var workerCousin: WorkerCousin = _
  private var workerSexy: WorkerSexy = _


  override def actionPerformed(e: ActionEvent): Unit = {
    val comando = e.getActionCommand

    if (comando.equals("CANCELAR")) {
      Seq(workerTwin, workerCousin, workerSexy).filter(_ != null).foreach(_.cancel(true))

    } else {
      var tipo = ""

      if (comando.equals("TWIN")) {
        tipo = "twin"
      } else if (comando.equals("COUSIN")) {
        tipo = "cousin"
      } else {
        tipo = "sexy"
      }

      try {
        val n = panel.numero(tipo)
        panel.limpiarArea(tipo)
        panel.nuevoMensaje("Calculando primos...", "")

        val workerGeneral = tipo match {
          case "twin" => workerTwin = new WorkerTwin(n, panel); workerTwin // Return  de los workers
          case "cousin" => workerCousin = new WorkerCousin(n, panel); workerCousin
          case _ => workerSexy = new WorkerSexy(n, panel); workerSexy
        }
        workerGeneral.addPropertyChangeListener(this)
        workerGeneral.execute()

      } catch {
        case e: NumberFormatException => panel.nuevoMensaje("Número incorrecto", "")
      }
    }
  }


  override def propertyChange(evt: PropertyChangeEvent): Unit = {
    // No uso barra de progreso
  }
}

class WorkerTwin(n: Int, panel: Panel) extends SwingWorker[Unit, String] {
  private val resultados = new util.ArrayList[String]()


  def esPrimo(n: Int): Boolean = {
    @tailrec
    def loop(div: Int): Boolean = {
      if (div * div > n) true
      else if (n % div == 0) false
      else loop(div +1)
    }

    if (n == 2) true
    else loop(2)
  }

  // listaTwinParesPrimos
  def listaPrimos(n: Int): Unit = {
    @tailrec
    def loop(i: Int, pprimo: Int): Unit = {
      if (i < n && !this.isCancelled) // Comprueba que no se haya cancelado la tarea
        if (esPrimo(pprimo) && esPrimo(pprimo + 2))
          val parejaTwin = new Primos(i, pprimo, pprimo + 2)
          resultados.add(parejaTwin.toString)
          this.setProgress((i + 1) * 100 / n)
          loop(i + 1, pprimo + 1)
        else
          loop(i, pprimo + 1)
    }
    loop(0, 2)
  }

  override def doInBackground(): Unit = {
    this.setProgress(0)
    listaPrimos(n)
  }

  override def done(): Unit = {
    try {
      get() // Permite que se reciban excepciones mientras se ejecuta doInBackground
      val sb = new StringBuilder()
      for (i<-0 until resultados.size()) {
        sb.append(resultados.get(i))
        if ((i+1) % 10 == 0) sb.append("\n")
      }
      publish(sb.toString())
      panel.nuevoMensaje("Pares primos twin calculados", "twin")
      panel.nuevoMensaje("Tarea twin finalizada", "")
    } catch {
      case e: CancellationException => panel.nuevoMensaje("Tarea cancelada", "")
    }
  }

  override def process(chunks: util.List[String]): Unit = {
    panel.nuevoMensaje("calculando primos twin...", "twin")
    panel.listaPrimos(chunks, "twin")
  }

}

class WorkerCousin(n: Int, panel: Panel) extends SwingWorker[Unit, String] {
  private val resultados = new util.ArrayList[String]()

  def esPrimo(n: Int): Boolean = {
    @tailrec
    def loop(div: Int): Boolean = {
      if (div * div > n) true
      else if (n % div == 0) false
      else loop(div + 1)
    }

    if (n == 2) true
    else loop(2)
  }

  // listaCousinParesPrimos
  def listaPrimos(n: Int): Unit = {
    @tailrec
    def loop(i: Int, pprimo: Int): Unit = {
      if (i < n && !this.isCancelled) // Comprueba que no se haya cancelado la tarea
        if (esPrimo(pprimo) && esPrimo(pprimo + 4))
          val parejaTwin = new Primos(i, pprimo, pprimo + 4)
          resultados.add(parejaTwin.toString)
          this.setProgress((i + 1) * 100 / n)
          loop(i + 1, pprimo + 1)
        else
          loop(i, pprimo + 1)
    }

    loop(0, 2)
  }

  override def doInBackground(): Unit = {
    this.setProgress(0)
    listaPrimos(n)
  }

  override def done(): Unit = {
    try {
      get() // Permite que se reciban excepciones mientras se ejecuta doInBackground
      val sb = new StringBuilder()
      for (i <- 0 until resultados.size()) {
        sb.append(resultados.get(i))
        if ((i + 1) % 10 == 0) sb.append("\n")
      }
      publish(sb.toString())
      panel.nuevoMensaje("Pares primos cousin calculados", "cousin")
      panel.nuevoMensaje("Tarea cousin finalizada", "")
    } catch {
      case e: CancellationException => panel.nuevoMensaje("Tarea cancelada", "")
    }
  }

  override def process(chunks: util.List[String]): Unit = {
    panel.nuevoMensaje("calculando primos cousin...", "cousin")
    panel.listaPrimos(chunks, "cousin")

  }
}

class WorkerSexy(n: Int, panel: Panel) extends SwingWorker[Unit, String] {
  private val resultados = new util.ArrayList[String]()

  def esPrimo(n: Int): Boolean = {
    @tailrec
    def loop(div: Int): Boolean = {
      if (div * div > n) true
      else if (n % div == 0) false
      else loop(div + 1)
    }

    if (n == 2) true
    else loop(2)
  }

  // listaSexyParesPrimos
  def listaPrimos(n: Int): Unit = {
    @tailrec
    def loop(i: Int, pprimo: Int): Unit = {
      if (i < n && !this.isCancelled) // Comprueba que no se haya cancelado la tarea
        if (esPrimo(pprimo) && esPrimo(pprimo + 6))
          val parejaTwin = new Primos(i, pprimo, pprimo + 6)
          resultados.add(parejaTwin.toString)
          this.setProgress((i + 1) * 100 / n)
          loop(i + 1, pprimo + 1)
        else
          loop(i, pprimo + 1)
    }

    loop(0, 2)
  }

  override def doInBackground(): Unit = {
    this.setProgress(0)
    listaPrimos(n)
  }

  override def done(): Unit = {
    try {
      get() // Permite que se reciban excepciones mientras se ejecuta doInBackground
      val sb = new StringBuilder()
      for (i <- 0 until resultados.size()) {
        sb.append(resultados.get(i))
        if ((i + 1) % 10 == 0) sb.append("\n")
      }
      publish(sb.toString())
      panel.nuevoMensaje("Pares primos sexy calculados", "sexy")
      panel.nuevoMensaje("Tareas sexy finalizada", "")
    } catch {
      case e: CancellationException => panel.nuevoMensaje("Tarea cancelada", "")
    }
  }

  override def process(chunks: util.List[String]): Unit = {
    panel.nuevoMensaje("calculando primos sexy...", "sexy")
    panel.listaPrimos(chunks, "sexy")
  }
}

object A_GUI_con_SwingWorker {

  // Función para crear la GUI
  def crearGUI(ventana:JFrame):Unit = {
    val panel = new Panel// Creamos el panel
    val controlador = new Controlador(panel)
    panel.controlador(controlador, "twin")
    panel.controlador(controlador, "cousin")
    panel.controlador(controlador, "sexy")

    ventana.setContentPane(panel) // Al JFrame le asignamos como contenido el panel que hemos creado
    ventana.pack() // Empaquetamos
    ventana.setVisible(true) // Mostramos la ventana
    ventana.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE) // Controla que cuando se haga click en el botón de cerrar este se cierre con éxito

  }
  def main(args:Array[String]):Unit = {

    //completar
    // Asegura que la GUI se construya en el hilo de eventos de Swing
    SwingUtilities.invokeLater(
      new Runnable:
        override def run(): Unit =
          val ventana = new JFrame("Números primos") // Creamos la ventana(sólo el nombre de la ventana)
          crearGUI(ventana) // Crear GUI la ejecuta
    )
  }

}
