package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random
object aseo{
  // CS-Cliente: Esperan si está el Equipo de Limpieza en el aseo
  // CS-EquipoLimpieza: Espera si hay clientes en el aseo

  var numClientes = 0
  val mutex = new Semaphore(1)
  val ocupado = new Semaphore(1) // CS - Cliente // CS - Equipo de Limpieza
  // Ese ocupado quiere decir que hay un cliente(por lo tanto está ocupado)

  def entraCliente(id:Int)={
    mutex.acquire()
    numClientes += 1 // SC
    if (numClientes == 1) ocupado.acquire() // Soy el primer cliente => bloqueo al equipo de limpieza
    log(s"Entra cliente $id. Hay $numClientes clientes.")
    mutex.release()
  }
  def saleCliente(id:Int)={
    mutex.acquire()
    numClientes -= 1 // SC
    if (numClientes == 0) ocupado.release() // Soy el último cliente => libero al equipo de limpieza
    log(s"Sale cliente $id. Hay $numClientes clientes.")
    mutex.release()
  }
  def entraEquipoLimpieza ={
    ocupado.acquire()
    log(s"        Entra el equipo de limpieza.")
  }
  def saleEquipoLimpieza = {
    log(s"        Sale el equipo de limpieza.")
    ocupado.release()
  }
}

object Ejercicio3 {
  def main(args: Array[String]) = {
    val cliente = new Array[Thread](10)
    for (i <- 0 until cliente.length) {
      cliente(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(500))
          aseo.entraCliente(i)
          Thread.sleep(Random.nextInt(50))
          aseo.saleCliente(i)
        }
      }
    }
    val equipoLimpieza = thread {
      while (true) {
        Thread.sleep(Random.nextInt(500))
        aseo.entraEquipoLimpieza
        Thread.sleep(Random.nextInt(100))
        aseo.saleEquipoLimpieza
      }
    }

  }
}
