package tema7

import java.util.concurrent.locks._

object EjemploLock_LectoresEscritores {
  private val l = new ReentrantLock(true)
  private var nLectores = 0
  private var nEscritores = 0
  private var escribiendo = false
  private val ok_lector  = l.newCondition()
  private val ok_escritor = l.newCondition()

  def entraLector() = {
    l.lock()
    try {
      // Si hay un escritor escribiendo o haya escritores => Lector ESPERA
      while (escribiendo || nEscritores > 0) ok_lector.wait()
      nLectores += 1
    } finally {
      l.unlock()
    }
  }

  def saleLector() = {
    l.lock()
    try {
      nLectores -= 1
      // Si era el último lector => DESPERTAMOS a todos los escritores
      if (nLectores == 0) ok_escritor.notifyAll() // Avisamos a todos los escritores
    } finally {
      l.unlock()
    }
  }

  def entraEscritor() = {
    l.lock()
    try {
      nEscritores += 1
      // Mientras haya lectores o haya un escritor escribiendo => Escritor ESPERA
      while (nLectores > 0 || escribiendo) ok_escritor.wait()
      escribiendo = true
    } finally {
      l.unlock()
    }
  }

  def saleEscritor() = {
    l.lock()
    try {
      nEscritores -= 1
      escribiendo = false
      ok_lector.signalAll()
    } finally {
      l.unlock()
    }
  }
}
