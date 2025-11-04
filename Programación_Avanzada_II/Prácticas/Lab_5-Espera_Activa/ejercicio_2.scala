import libreria_local.*

object ejercicio_2 {
  private val limiteRio = 1000
  private val limitePresa = 1000
  private val incrementoRio = 1
  private val decrementoPresa = -1

  class Lago extends Thread {
    @volatile private var nivelAguaLago = 0 // Imposible menos que cero

    def desembocarRio(): Unit = {
      // Supuestamente no debe tener condición de sincronización?
      // while(nivelAguaLago == limitePresa) Thread.sleep(0) // SC - Presa
      nivelAguaLago += incrementoRio
    }
    def abrePresa(): Unit = {
      while (nivelAguaLago == 0) Thread.sleep(0) // SC - Rio
       nivelAguaLago += decrementoPresa
    }

    def getAguaLago: Int = nivelAguaLago
  }

  def main(args: Array[String]): Unit = {
    val lago = new Lago

    val rio1 = thread {
      for (i<-0 until limiteRio)
        lago.desembocarRio()
      log(s"Nivel después del Río 1: ${lago.getAguaLago}")
    }
    val rio2 = thread {
      for (i<-0 until limiteRio)
        lago.desembocarRio()
      log(s"Nivel después del Río 2: ${lago.getAguaLago}")
    }
    val presa1 = thread {
      for (i<-0 until limitePresa)
        lago.abrePresa()
      log(s"Nivel después del Presa 1: ${lago.getAguaLago}")
    }
    val presa2 = thread {
      for (i<-0 until limitePresa)
        lago.abrePresa()
      log(s"Nivel después del Presa 2: ${lago.getAguaLago}")
    }

    rio1.join(); rio2.join()
    presa1.join(); presa2.join()

    log(s"Nivel del agua: ${lago.getAguaLago}")
  }
}
