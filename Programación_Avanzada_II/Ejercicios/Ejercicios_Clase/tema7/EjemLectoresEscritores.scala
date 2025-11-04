package tema7
import concurrencia.*

object EjemLectoresEscritores {
  private var nLectores = 0
  private var nEscritores = 0
  private var hayEscritor = false

  def entraLector() = synchronized {
    while (hayEscritor || nEscritores > 0) wait()
    nLectores += 1
  }

  def saleLector() = synchronized {
    nLectores -= 1
    if (nLectores == 0) notifyAll() // Avisamos a todos los escritores
  }

  def entraEscritor() = synchronized {
    nEscritores += 1
    while (nLectores > 0 || hayEscritor) wait()
    hayEscritor = true
  }

  def saleEscritor() = synchronized {
    hayEscritor = false
    nEscritores -= 1
    notifyAll()
  }
 }
