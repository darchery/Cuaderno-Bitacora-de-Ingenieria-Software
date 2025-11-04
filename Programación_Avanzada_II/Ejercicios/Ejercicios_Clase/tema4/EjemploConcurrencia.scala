package tema4

import java.util.random.*

object EjemploConcurrencia

class Escribe(c: Char) extends Thread {
  override def run =
    for(i<-0 until 10)
      println(c)
}

/*
* Solo tiene el método run, que hace lo mismo que el anterior*/
class EscribeR(c: Char) extends Runnable {
  override def run =
    for (i <- 0 until 10)
      //println(c)
      // Para saber que hebra es la que se está ejecutando
      println(s"${Thread.currentThread().getName}: $c")
      Thread.sleep(1000)
      //Thread.sleep(Random.nextInt(1000))
}

object Principal {
  def main(args: Array[String]): Unit = {
    /*
    * Ambos son exactamente iguales, solo que Escribe R crea hebras de igual manera que Thread, por lo tanto
    * le pasamos al constructor de Thread una hebra con la interfaz Runnable*/

    //val h1 = new Escribe('a')
    //val h2 = new Escribe('b')
    //val h3 = new Escribe('c')
    val h1 = new Thread(new EscribeR('a'))
    val h2 = new Thread(new EscribeR('b'))
    val h3 = new Thread(new EscribeR('c'))
    // Si NO hay joins, la hebra main será lo primero que se ejecuta
    h1.start()
    h2.start()
    h3.start()
    // Si hay joins, la hebra main será lo último que se ejecute
    h1.join()
    h2.join()
    h3.join()
    // Suelta la hebra del main
    println(s"${Thread.currentThread().getName}: Principal")
    // println(s"${Thread.currentThread().getName}: Fin del programa")
  }
}
/*
* Si llamo a run es el main el que lo ejecuta y no crea la hebra, pero con start se crean las hebras
* si hago
* h1.run()
* h2.run()
* h3.run()
* la salida será: aaaaaaaaaaaaabbbbbbbbbbbbcccccccccccccc
* Ya que se ejecuta desde el main y por lo tanto su ejecución es SECUENCIAL y no CONCURRENTE como hacemos con
* starr de thread*/


/*
* Cada una de la ejecuciones son diferentes, ya que por la concurrencia escoge los procesos por tramas, y hay muchas
* tramas diferentes -> SENCILLO EJEMPLO PARA EXPLICAR LOS THREADS(HEBRAS o HILOS) Y CONCURRENCIA*/
