package Lab61.soluciones
import java.util.concurrent.Semaphore
import scala.util.Random

object Ejer_Barberia_Cliente {
  class Barberia {
    private var n = 0
    private val mutex = new Semaphore(1) // EXM
    private val espera = new Semaphore(0) // CS - barbero/cliente
    // espera a 0 => Dormido , espera a 1 => Despertar

    def nuevoCliente(): Unit = {
      //llega un nuevo cliente a la sala de espera
      mutex.acquire()
      n += 1
      log(s"Ha llegado un cliente $n")
      if (n == 0 ) espera.release(); log("Despierta barbero!")
      mutex.release()
    }

    def pelar() = {
      //el barbero pela a un cliente, si hay alguien esperando
      //en otro caso sigue durmiendo
      mutex.acquire()
      n -= 1
      if (n == -1) { // Barbero dormido
        mutex.release() // EXM - Ini
        log("A dormir! :)")
        espera.acquire() // Se duerme
        mutex.acquire() // EXM - Fin
      }
      Thread.sleep(Random.nextInt(500)) // Tiempo en el que pela
      log(s"He pelado un cliente $n")
      mutex.release()
    }
  }

  def main(args: Array[String]): Unit = {
    val barberia = new Barberia

    val barbero = thread {
      while (true) {
        barberia.pelar()
      }
    }
    val entorno = thread {
      while (true) {
        barberia.nuevoCliente()
      }
    }
  }
}
