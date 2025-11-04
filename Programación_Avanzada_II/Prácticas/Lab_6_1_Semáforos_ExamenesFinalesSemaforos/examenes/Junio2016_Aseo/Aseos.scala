package examenes.Junio2016_Aseo

import java.util.concurrent.Semaphore
import Lab61.soluciones._

class Aseos {
  /**
   * Utilizado por el cliente id cuando quiere entrar en los aseos
   * CS Version injusta: El cliente espera si el equipo de limpieza est� trabajando
   * CS Version justa: El cliente espera si el equipo de limpieza est� trabajando o
   * est� esperando para poder limpiar los aseos
   *
   */


  private var numClientes = 0

  private val mutex = new Semaphore(1)
  private val ocupado = new Semaphore(1) // Controlamos la entrada de los clientes y el bloqueo del servicio de la limpieza

  def entroAseo(id: Int): Unit = {
    // Versión injusta

    // Versión justa
    mutex.acquire()
    numClientes += 1
    log(s"Entra cliente $id. Hay $numClientes clientes")
    if (numClientes == 1) ocupado.acquire() // Bloqueamos al equipo de limpieza(bloq)
    mutex.release()
  }

  /**
   * Utilizado por el cliente id cuando sale de los aseos
   *
   */
  def salgoAseo(id: Int): Unit = {
    // Versión injusta

    // Versión justa
    mutex.acquire()
    numClientes -= 1
    log(s"Sale cliente $id. Hay $numClientes clientes")
    if (numClientes == 0) ocupado.release() // Desbloqueamos al equipo de limpieza(0)
    mutex.release()
  }

  /**
   * Utilizado por el Equipo de Limpieza cuando quiere entrar en los aseos
   * CS: El equipo de trabajo est� solo en los aseos, es decir, espera hasta que no
   * haya ning�n cliente.
   *
   */
  def entraEquipoLimpieza(): Unit = {
    // Versión injusta

    // Versión justa
    ocupado.acquire() // Al ejecutarse primero consume el valor de 1 y se pone a 0
    log("     Entra el equipo de limpieza")

  }

  /**
   * Utilizado por el Equipo de Limpieza cuando  sale de los aseos
   *
   *
   */
  def saleEquipoLimpieza(): Unit = {
    // Versión injusta

    // Versión justa
    log("     Sale el equipo de limpieza")
    ocupado.release() // Semáforo a 1
  }
}

/** Versión wuolah */
/*
    // Versión injusta => igual sólo que sólo se le avisa cuando se queda vacío el sitio, no se le bloquearía en entro aseo?
  private var numClientes = 0

  private val mutex = new Semaphore(1)

  private val limpieza = new Semaphore(1) // Controla al equipo de limpieza
  private val entrar = new Semaphore(1) // Controla la entrada de clientes y limpieza
  private val salir = new Semaphore(0) // Salidas de clientes
  private val salirLimpieza = new Semaphore(0) // Salidas de limpieza

def entroAseo(id: Int): Unit = {

    // Versión injusta

    // Versión justa
    entrar.acquire()
    mutex.acquire()

    numClientes += 1
    log(s"Entra cliente $id. Hay $numClientes clientes")
    if (numClientes == 1) { // Si es el primero => Bloqueamos limpieza e indicamos que los clientes pueden salir
      limpieza.acquire()
      salir.release()
    }
    entrar.release() // Reiniciamos
    mutex.release()
  }

  /**
   * Utilizado por el cliente id cuando sale de los aseos
   *
   */
  def salgoAseo(id: Int): Unit = {
    // Versión injusta

    // Versión justa
    salir.acquire()
    mutex.acquire()

    numClientes -= 1
    log(s"Sale cliente $id. Hay $numClientes clientes")
    if (numClientes == 0) { // Si no hay cliente => desbloqueamos a la limpieza
      limpieza.release()
    } else { // Si no => clientes siguen saliendo
        salir.release()
    }
    mutex.release()
  }

  /**
   * Utilizado por el Equipo de Limpieza cuando quiere entrar en los aseos
   * CS: El equipo de trabajo est� solo en los aseos, es decir, espera hasta que no
   * haya ning�n cliente.
   *
   */
  def entraEquipoLimpieza(): Unit = {
    // Versión injusta

    // Versión justa
    entrar.acquire() // Indicamos la entrada
    limpieza.acquire()
    log("     Entra el equipo de limpieza")
    salirLimpieza.release() // Puede salir el equipo de lipieza
  }

  /**
   * Utilizado por el Equipo de Limpieza cuando  sale de los aseos
   *
   *
   */
  def saleEquipoLimpieza(): Unit = {
    // Versión injusta

    // Versión justa
    salirLimpieza.acquire()
    log("     Sale el equipo de limpieza")
    entrar.release() // Reiniciamos
    limpieza.release()
  }

 */
