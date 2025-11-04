package tema8

import java.awt.event.{ActionEvent, ActionListener}
import java.awt.{BorderLayout, FlowLayout, GridLayout}
import javax.swing.{JButton, JFrame, JLabel, JPanel, JScrollBar, JScrollPane, JTextArea, JTextField, WindowConstants}

class Controlador extends ActionListener {
  override def actionPerformed(e: ActionEvent): Unit = {
    if (e.getActionCommand == "SI") {
      // Código SI
      panel.nuevoMensaje("Si pulsada")
    } else {
      // Código NO
      panel.nuevoMensaje("No pulsado")
    }
  }
}

class Panel1 extends JPanel {
  private val label = new JLabel("¿Es verdad?")
  private val buttonYes = new JButton("Si")
  private val buttonNo = new JButton("No")
  //this.setLayout(new FlowLayout())
  this.setLayout(new GridLayout(3, 1))
  this.add(label)
  this.add(buttonYes)
  this.add(buttonNo)
  
  def controlador(ctr: ActionListener) = {
    buttonYes.addActionListener(ctr)
    buttonYes.setActionCommand("SI")
    
    buttonNo.addActionListener(ctr)
    buttonNo.setActionCommand("NO")
  }
}

class Panel2 extends JPanel {
  this.setLayout(new BorderLayout())
  private val buttonNorth = new JButton("Norte")
  private val buttonSouth = new JButton("Sur")
  private val buttonCenter = new JButton("Centro")
  private val buttonEast = new JButton("Este")
  private val buttonWest1 = new JButton("Oeste 1")
  private val buttonWest2 = new JButton("Oeste 2")
  this.add(buttonNorth, BorderLayout.NORTH)
  this.add(buttonSouth, BorderLayout.SOUTH)
  this.add(buttonEast, BorderLayout.EAST)
  this.add(buttonCenter, BorderLayout.CENTER)
  private val westPanel = new JPanel()
  westPanel.setLayout(new GridLayout(2, 1))
  westPanel.add(buttonWest1)
  westPanel.add(buttonWest2)
  this.add(westPanel, BorderLayout.WEST)
}

// Sin acabar: no me dio tiempo a copiar
class Panel3 extends JPanel {
    this.setLayout(new BorderLayout())
    private val etiquetaTam = new JLabel("¿Tamaño?")
    private val tam = new JTextField(4)
    private val buttonNorth = new JButton("Norte")
    private val northPane = new JPanel()
    northPane.add(buttonNorth); northPane.add(etiquetaTam); northPane.add(tam)

    private val buttonSouth = new JButton("Sur")

    private val centerArea = new JTextArea(30, 20)
    private val scrollArea = new JScrollPane(centerArea)

    private val buttonEast = new JButton("Este")
    private val buttonWest1 = new JButton("Oeste 1")
    private val buttonWest2 = new JButton("Oeste 2")
    this.add(buttonNorth, BorderLayout.NORTH)
    this.add(buttonSouth, BorderLayout.SOUTH)
    this.add(buttonEast, BorderLayout.EAST)
    this.add(scrollArea, BorderLayout.CENTER)
    private val westPanel = new JPanel()
    westPanel.setLayout(new GridLayout(2, 1))
    westPanel.add(buttonWest1)
    westPanel.add(buttonWest2)
    this.add(westPanel, BorderLayout.WEST)
}


object EjemploGUI {
  def main(args: Array[String]): Unit = {
    val ventana = new JFrame("Un ejemplo")
    val panel = new Panel1() //los elementos visuales
    val ctr = new Controlador
    panel.controlador(ctr)
    ventana.setContentPane(panel)
    ventana.pack()
    ventana.setVisible(true)
    ventana.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE)
  }
}
