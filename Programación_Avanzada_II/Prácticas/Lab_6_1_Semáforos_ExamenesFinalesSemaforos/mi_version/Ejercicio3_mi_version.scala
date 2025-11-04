/**
 * ERRORES:
 * Todo bien , bien identificado las condiciones de sincronización
 * Pero error en poner 2 semáforos en vez de 1, e invertir acquire y release en
 * entraCliente y saleCliente*/

package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object Ejercicio3_mi_version {
  def main(args: Array[String]) = {
    val cliente = new Array[Thread](10)

    for (i <- 0 until cliente.length)
      cliente(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(500))
          aseo_mi_version.entraCliente(i)
          Thread.sleep(Random.nextInt(50))
          aseo_mi_version.saleCliente(i)
        }
      }
    val equipoLimpieza = thread {
      while (true) {
        Thread.sleep(Random.nextInt(500))
        aseo_mi_version.entraEquipoLimpieza
        Thread.sleep(Random.nextInt(100))
        aseo_mi_version.saleEquipoLimpieza
      }
    }
  }
}

object aseo_mi_version{
  // CS-Cliente: Esperan si está el Equipo de Limpieza en el aseo
  // CS-EquipoLimpieza: Espera si hay clientes en el aseo

  private var numClientes = 0
  private val mutex = new Semaphore(1)
  private val ocupado = new Semaphore(1) // CS-Cliente/Equipo
  // Comparten semáforo, así que cada uno lo bloque y libera

  def entraCliente(id:Int)={
    mutex.acquire()
    numClientes += 1 // SC
    // Soy el primer cliente => Bloqueo equipo de limpieza
    if (numClientes == 1) ocupado.acquire()
    log(s"Entra cliente $id. Hay $numClientes clientes.")
    mutex.release()
  }

  def saleCliente(id:Int)={
    mutex.acquire()
    numClientes -= 1
    log(s"Sale cliente $id. Hay $numClientes clientes.")
    // Soy el último cliente => Libero al equipo de limpieza
    if (numClientes == 0) ocupado.release()
    mutex.release()
  }
  def entraEquipoLimpieza = {
    ocupado.acquire() // Bloqueo a los clientes
    log(s"        Entra el equipo de limpieza.")
  }
  def saleEquipoLimpieza = {
    log(s"        Sale el equipo de limpieza.")
    ocupado.release() // Libero a los clientes
  }
}

object aseo_mi_version_REPASO {
  // CS-Cliente: Esperan si está el Equipo de Limpieza en el aseo
  // CS-EquipoLimpieza: Espera si hay clientes en el aseo

  private var numClientes = 0
  private val mutex = new Semaphore(1) // EXM
  private val ocupado = new Semaphore(1)

  def entraCliente(id:Int)={
    mutex.acquire()
    numClientes += 1
    if (numClientes == 1) ocupado.acquire( )// Primer cliente => Sale equipo
    log(s"Entra cliente $id. Hay $numClientes clientes.")
    mutex.release()

  }
  def saleCliente(id:Int)={
    mutex.acquire()
    numClientes -= 1
    if (numClientes == 0) ocupado.release()// Último cliente => Entra equipo
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

