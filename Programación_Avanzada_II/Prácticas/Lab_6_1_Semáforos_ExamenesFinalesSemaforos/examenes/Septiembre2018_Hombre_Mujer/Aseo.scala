package examenes.Septiembre2018_Hombre_Mujer

import java.util.concurrent.Semaphore

class Aseo {

  private var numHombres = 0
  private var numMujeres = 0

  private val mutexHombre = new Semaphore(1) // Controla la EXC de numHombres
  private val mutexMujer = new Semaphore(1) // Controla la EXC de numMujeres

  private val puertaEntrada = new Semaphore(1) // Control de la entrada de clientes

  private val entradaHombre = new Semaphore(1) // Controla la entrada de hombres
  private val entradaMujer = new Semaphore(1) // Controla la entrada de mujeres

  private val salidaHombre = new Semaphore(0) // Controla la salida de hombres
  private val salidaMujer = new Semaphore(0) // Controla la salida de mujeres

  /**
   * El hombre id quiere entrar en el aseo.
   * Espera si no es posible, es decir, si hay alguna mujer en ese
   * momento en el aseo
   */
  @throws[InterruptedException]
  def llegaHombre(id: Int): Unit = {

    puertaEntrada.acquire()
    entradaHombre.acquire()
    mutexHombre.acquire()

    numHombres += 1
    println(s"Hombre ${id} entra en el baño. Hay ${numHombres} hombres")
    if (numHombres == 1) { // Entra primero un hombre
      entradaMujer.acquire() // Bloq mujeres
      salidaHombre.release() // Pueden salir hombres
    }
    puertaEntrada.release() // Reincio
    entradaHombre.release()
    mutexHombre.release()
  }

  /**
   * La mujer id quiere entrar en el aseo.
   * Espera si no es posible, es decir, si hay algun hombre en ese
   * momento en el aseo
   */
  @throws[InterruptedException]
  def llegaMujer(id: Int): Unit = {
    puertaEntrada.acquire()
    entradaMujer.acquire()
    mutexMujer.acquire()

    numMujeres += 1
    println(s"Mujer ${id} entra en el baño. Hay ${numMujeres} mujeres")
    if (numMujeres == 1) { // Primera mujer
      entradaHombre.acquire() //  Bloq hombres
      salidaMujer.release() // Pueden salir mujeres
    }

    puertaEntrada.release()
    entradaMujer.release()
    mutexMujer.release()

  }

  /**
   * El hombre id, que estaba en el aseo, sale
   */
  @throws[InterruptedException]
  def saleHombre(id: Int): Unit = {
    salidaHombre.acquire()
    mutexHombre.acquire()

    numHombres -= 1
    println(s"Hombre ${id} sale del baño. Hay ${numHombres} hombres")
    if (numHombres == 0) {
      println("************************")
      println("BAÑO VACÍO")
      println("************************")
      entradaMujer.release()
    } else {
      salidaHombre.release()
    }
    mutexHombre.release()
  }

  /**
   * La mujer id, que estaba en el aseo, sale
   */
  @throws[InterruptedException]
  def saleMujer(id: Int): Unit = {
    salidaMujer.acquire()
    mutexMujer.acquire()

    numMujeres -= 1
    println(s"Mujer ${id} sale del baño. Hay ${numMujeres} mujeres")

    if (numMujeres == 0) {
      println("************************")
      println("BAÑO VACÍO")
      println("************************")
      entradaHombre.release()
    } else {
      salidaMujer.release()
    }
    mutexMujer.release()
  }
}

/*
private var numHombres = 0
  private var numMujeres = 0

  private val mutex = new Semaphore(1)
  private val puertaAbiertaHombre = new Semaphore(1)
  private val puertaAbiertaMujer = new Semaphore(0)

  /**
   * El hombre id quiere entrar en el aseo.
   * Espera si no es posible, es decir, si hay alguna mujer en ese
   * momento en el aseo
   */
  @throws[InterruptedException]
  def llegaHombre(id: Int): Unit = {
    puertaAbiertaHombre.acquire()

    mutex.acquire()
    numHombres += 1
    println(s"Hombre ${id} entra en el baño. Hay ${numHombres} hombres")
    mutex.release()

    puertaAbiertaHombre.release()

  }

  /**
   * La mujer id quiere entrar en el aseo.
   * Espera si no es posible, es decir, si hay algun hombre en ese
   * momento en el aseo
   */
  @throws[InterruptedException]
  def llegaMujer(id: Int): Unit = {
    puertaAbiertaMujer.acquire()

    mutex.acquire()
    numMujeres += 1
    println(s"Mujer ${id} entra en el baño. Hay ${numMujeres} mujeres")
    mutex.release()

    puertaAbiertaMujer.release()
  }

  /**
   * El hombre id, que estaba en el aseo, sale
   */
  @throws[InterruptedException]
  def saleHombre(id: Int): Unit = {
    mutex.acquire()

    numHombres -= 1
    println(s"Hombre ${id} sale del baño. Hay ${numHombres} hombres")
    if (numHombres == 0) {
      println("************************")
      println("BAÑO VACÍO")
      println("************************")
      puertaAbiertaHombre.acquire()
      puertaAbiertaMujer.release()
    }


    mutex.release()
  }

  /**
   * La mujer id, que estaba en el aseo, sale
   */
  @throws[InterruptedException]
  def saleMujer(id: Int): Unit = {
    mutex.acquire()

    numMujeres -= 1
    println(s"Mujer ${id} sale del baño. Hay ${numMujeres} mujeres")
    if (numMujeres == 0) {
      println("************************")
      println("BAÑO VACÍO")
      println("************************")
      puertaAbiertaMujer.acquire()
      puertaAbiertaHombre.release()
    }

    mutex.release()
  }
*/