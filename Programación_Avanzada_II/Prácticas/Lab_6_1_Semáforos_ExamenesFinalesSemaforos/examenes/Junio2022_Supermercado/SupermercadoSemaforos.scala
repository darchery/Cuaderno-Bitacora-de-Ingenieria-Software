package examenes.Junio2022_Supermercado

import java.util.concurrent.Semaphore

/**
 * FUCNCIONA AL => 80 - 90%
 * PROBLEMA: a veces cuando el cajero permanente debería actuar no actua y llama a otro nuevo y no sale más
 * esto ocurre a veces, cuando ocurre el cajero se bloquea*/

class SupermercadoSemaforos extends Supermercado {

  private val permanente = new Cajero(this, true) // Crea el primer cajero, el permanente
  permanente.start()

  private var numClientesCola = 0
  private var superCerrado = false

  private val mutex = new Semaphore(1)
  private val puertaAbiertaSuper = new Semaphore(1) // Al principio entramos
  private val esperoCliente = new Semaphore(0) // Función: bloquear al cajero permanente

  @throws[InterruptedException]
  override def fin(): Unit = {
    mutex.acquire()
    superCerrado = true // Cerramos el super
    println("********************")
    println("SUPERMERCADO CERRADO")
    println("********************")
    mutex.release()
  }

  @throws[InterruptedException]
  override def nuevoCliente(id: Int): Unit = {

    if (!superCerrado) { // Si el super no está cerrado
      puertaAbiertaSuper.acquire() // Cogemos el turno

      mutex.acquire()
      numClientesCola += 1
      println(s"Llega cliente ${id}. Hay ${numClientesCola}")

      if (numClientesCola > 0) esperoCliente.release() // Chapuza para intentar evitar el bloqueo

      if (numClientesCola > 3 * Cajero.numCajerosActivos()) { // Si con los cajeros actuales no damos a vasto => Abrimos uno ocasional
        val cajeroOcasional = new Cajero(this, false)
        println(s"Se crea un cajero nuevo ${Cajero.numCajerosActivos()}")
        cajeroOcasional.start()
      }

      esperoCliente.release() // Avisamos al cajero permanente que tiene trabajo => Lo desbloquea
      puertaAbiertaSuper.release() // Dejamos el turno para otro cliente
      mutex.release()
    } else { // Si está cerrado noo hace nada
      println(s"Llega el cliente ${id} y ve el Supermercado cerrado. ME VOY")
    }

  }

  @throws[InterruptedException]
  override def permanenteAtiendeCliente(id: Int): Boolean = {

    // Si está cerrado y no hay clientes => cerramos
    if (numClientesCola == 0 && superCerrado) return false

    if (numClientesCola > 0) { // Si hay clientes y está abierto(por la condición anterior)
      mutex.acquire()
      numClientesCola -= 1
      println(s"Cajero permanente atiende al cliente ${id}. Quedan ${numClientesCola}")
      mutex.release()
      return true

    } else { // No hay clientes pero está abierto
      println("Cajero permanente espera")
      esperoCliente.acquire() // Bloqueamos al cajero permanente

      if (numClientesCola > 0) { // Al desbloquearse atiende al cliente
        mutex.acquire()
        numClientesCola -= 1
        println(s"Cajero permanente atiende al cliente ${id}. Quedan ${numClientesCola}")
        mutex.release()
        return true
      }
    }
    false
  }

  @throws[InterruptedException]
  override def ocasionalAtiendeCliente(id: Int): Boolean = {
    mutex.acquire()

    if (numClientesCola == 0) { // Si no hay clientes => se cierra el cajero
      println(s"No hay clientes. Cajero ${id} termina: ${numClientesCola}")
      mutex.release()
      false

    } else { // Si hay clientes =>  se atiende
      numClientesCola -= 1
      println(s"Cajero ${id} atiende a un cliente: Quedan ${numClientesCola} clientes")
      mutex.release()
      true
    }
  }
}
