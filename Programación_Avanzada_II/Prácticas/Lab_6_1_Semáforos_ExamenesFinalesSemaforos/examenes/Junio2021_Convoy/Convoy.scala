package examenes.Junio2021_Convoy

import java.util.concurrent.Semaphore

class Convoy(tam: Int) {

  private var numFurgonetas = 0
  private var lider = -1

  private val mutex = new Semaphore(1)
  private val saleConvoy = new Semaphore(0) // CS-FLider 1 y FLider2
  private val llegamosDestino = new Semaphore(0) // CS-Seguidora


  def unir(id: Int): Int = {
    // TODO: Poner los mensajes donde corresponda

    mutex.acquire()

    numFurgonetas += 1

    if (numFurgonetas == 1) {
      lider = id
      println(s"** Furgoneta $id lidera del convoy **")
    } else {
      println(s"Furgoneta $id seguidora")
      if (numFurgonetas == tam) saleConvoy.release() // Si han llegado todas => salimos

    }
    mutex.release()

    lider
  }

  def calcularRuta(id: Int): Unit = {
    // TODO
    saleConvoy.acquire()
    println(s"** Furgoneta $id lider:  ruta calculada, nos ponemos en marcha **")
    println(s"** Furgoneta $id lider:  hemos llegado a casa")
    llegamosDestino.release() // Llegamos al destino =>  avisamos a las furgonetas
  }

  def destino(id: Int): Unit = {
    // TODO
    saleConvoy.acquire()
    println(s"** Furgoneta $id lider abandona el convoy **")
  }

  def seguirLider(id: Int): Unit = {
    // TODO
    llegamosDestino.acquire()
    mutex.acquire()

    numFurgonetas -= 1
    println(s"Furgoneta $id abandona el convoy")

    if (numFurgonetas == 1) saleConvoy.release()
    else llegamosDestino.release()
    mutex.release()

  }
}
