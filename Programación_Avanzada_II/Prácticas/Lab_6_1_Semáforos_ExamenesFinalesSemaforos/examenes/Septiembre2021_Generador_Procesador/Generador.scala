package examenes.Septiembre2021_Generador_Procesador

import scala.util.Random

class Generador(nDatos: Int, dato: DatoCompartido) extends Thread {
  private val MAX_VALOR = 100
  private val rnd = new Random()

  override def run(): Unit = {
    try {
      for (_ <- 0 until nDatos) {
        val d = dato.generaDato(rnd.nextInt(MAX_VALOR))
        println(s"Resultado procesamiento = $d")
        println("-------------------------------")
      }
    } catch {
      case e: Exception => e.printStackTrace()
    }
  }
}
