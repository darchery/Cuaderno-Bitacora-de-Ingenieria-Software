import libreria_local.log

object ejercicio_2 {

  def periodico(t: Long) (b: => Unit): Thread = {
    val hebra = new Thread {
      override def run(): Unit = {
        while (true) {
          Thread.sleep(t)
          b
        }
      }
    }
    hebra
  }

  def main(args: Array[String]): Unit = {
    val h1 = periodico(1000)(println("Hola soy h1"))
    val h2 = periodico(3000)(println("Adios soy h2"))

    h1.start(); h2.start()
    h1.join(); h2.join()
  }
}
