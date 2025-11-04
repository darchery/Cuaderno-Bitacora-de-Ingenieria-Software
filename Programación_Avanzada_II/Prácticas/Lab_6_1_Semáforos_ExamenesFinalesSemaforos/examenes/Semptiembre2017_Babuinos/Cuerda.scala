package examenes.Semptiembre2017_Babuinos

import java.util.concurrent.Semaphore
import Lab61.soluciones._

/**Versión definitiva*/
class Cuerda {

  private val N = 3

  private var numBabuinosSurNorte = 0
  private var numBabuinosNorteSur = 0

  private val mutexNS = new Semaphore(1)
  private val mutexSN = new Semaphore(1)
  private val cuerdaLibre = new Semaphore(1)

  private val viajeNS = new Semaphore(1)
  private val viajeSN = new Semaphore(1)

  private val salirNS = new Semaphore(0)
  private val salirSN = new Semaphore(0)

  @throws[InterruptedException]
  def entraDireccionNS(id: Int): Unit = {
    cuerdaLibre.acquire()
    viajeNS.acquire()
    mutexNS.acquire()

    numBabuinosNorteSur += 1
    log(s"Babuino $id se sube en la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")
    if (numBabuinosNorteSur == 1) viajeSN.acquire()

    if (numBabuinosNorteSur < N) {
      cuerdaLibre.release()
      viajeNS.release()
    } else {
      log("     Se ha llenado la cuerda de babuinos Norte-Sur")
    }
    salirNS.release()
    mutexNS.release()
  }

  @throws[InterruptedException]
  def entraDireccionSN(id: Int): Unit = {
    cuerdaLibre.acquire()
    viajeSN.acquire()
    mutexSN.acquire()

    numBabuinosSurNorte += 1
    log(s"Babuino $id se sube en la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")
    if (numBabuinosSurNorte == 1) viajeNS.acquire()

    if (numBabuinosSurNorte < N) {
      cuerdaLibre.release()
      viajeSN.release()
    } else {
      log("     Se ha llenado la cuerda de babuinos Sur-Norte")
    }
    salirSN.release()
    mutexSN.release()
  }

  @throws[InterruptedException]
  def saleDireccionNS(id: Int): Unit = {
    salirNS.acquire()
    mutexNS.acquire()

    numBabuinosNorteSur -= 1
    log(s"Babuino $id sale de la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")

    if (numBabuinosNorteSur == 0) {
      log("****************************************************************")
      log("CUERDA VACÍA - por NS")
      log("****************************************************************")
      cuerdaLibre.release()
      viajeNS.release()
      viajeSN.release()
    } else {
      salirNS.release()
    }
    mutexNS.release()
  }

  @throws[InterruptedException]
  def saleDireccionSN(id: Int): Unit = {
    salirSN.acquire()
    mutexSN.acquire()

    numBabuinosSurNorte -= 1
    log(s"Babuino $id sale de la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")

    if (numBabuinosSurNorte == 0) {
      log("****************************************************************")
      log("CUERDA VACÍA - por NS")
      log("****************************************************************")
      cuerdaLibre.release()
      viajeSN.release()
      viajeNS.release()
    } else {
      salirSN.release()
    }
    mutexSN.release()
  }
}


/** Versión cercana mía + Deepseek*/
/*class Cuerda {

  private val N = 3

  private var numBabuinosSurNorte = 0
  private var numBabuinosNorteSur = 0

  private val mutex = new Semaphore(1)           // Controla acceso a variables compartidas
  private val cuerdaLibre = new Semaphore(1)     // Controla acceso inicial a la cuerda
  private val bloqueoNS = new Semaphore(1)       // Bloquea dirección Norte-Sur
  private val bloqueoSN = new Semaphore(1)       // Bloquea dirección Sur-Norte

  // Versión más cercana => Pero incorrecta por "poco"
  @throws[InterruptedException]
  def entraDireccionNS(id: Int): Unit = {
    // Paso 1: Esperar si la cuerda está ocupada por dirección opuesta
    bloqueoNS.acquire()
    bloqueoNS.release()

    // Paso 2: Adquirir acceso a la cuerda
    cuerdaLibre.acquire()

    mutex.acquire()
    // Primer babuino NS bloquea dirección opuesta
    if (numBabuinosNorteSur == 0 && numBabuinosSurNorte == 0) {
      bloqueoSN.acquire()
    }

    numBabuinosNorteSur += 1
    log(s"Babuino $id se sube en la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")

    // Liberar cuerda si no está llena
    if (numBabuinosNorteSur < N) {
      cuerdaLibre.release()
    } else {
      log("     Se ha llenado la cuerda de babuinos Norte-Sur")
    }
    mutex.release()
  }

  @throws[InterruptedException]
  def entraDireccionSN(id: Int): Unit = {
    // Paso 1: Esperar si la cuerda está ocupada por dirección opuesta
    bloqueoSN.acquire()
    bloqueoSN.release()

    // Paso 2: Adquirir acceso a la cuerda
    cuerdaLibre.acquire()

    mutex.acquire()
    // Primer babuino SN bloquea dirección opuesta
    if (numBabuinosSurNorte == 0 && numBabuinosNorteSur == 0) {
      bloqueoNS.acquire()
    }

    numBabuinosSurNorte += 1
    log(s"Babuino $id se sube en la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")

    // Liberar cuerda si no está llena
    if (numBabuinosSurNorte < N) {
      cuerdaLibre.release()
    } else {
      log("     Se ha llenado la cuerda de babuinos Sur-Norte")
    }
    mutex.release()
  }

  @throws[InterruptedException]
  def saleDireccionNS(id: Int): Unit = {
    mutex.acquire()
    numBabuinosNorteSur -= 1
    log(s"Babuino $id sale de la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")

    // Último babuino NS libera dirección opuesta
    if (numBabuinosNorteSur == 0) {
      bloqueoSN.release()
      cuerdaLibre.release()
      log("****************************************************************")
      log("CUERDA VACÍA - por NS")
      log("****************************************************************")
    }
    mutex.release()
  }

  @throws[InterruptedException]
  def saleDireccionSN(id: Int): Unit = {
    mutex.acquire()
    numBabuinosSurNorte -= 1
    log(s"Babuino $id sale de la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")

    // Último babuino SN libera dirección opuesta
    if (numBabuinosSurNorte == 0) {
      bloqueoNS.release()
      cuerdaLibre.release()
      log("****************************************************************")
      log("CUERDA VACÍA - por SN ")
      log("****************************************************************")
    }
    mutex.release()
  }
}*/

/** Versión wuolah candela*/
/*class Cuerda {
  //VARIABLES
  private var nMonos = 0 //Número de monos en la cuerda
  //SEMÁFOROS
  private val acceso_cuerda = new Semaphore(1) //para ver si se puede pasar o no a la cuerda
  private val mutex = new Semaphore(1) // mutex para la variable Monos
  private val monosN = new Semaphore(1) // entrada por el norte
  private val monosS = new Semaphore(1) //entrada por el sur
  private val salidaN = new Semaphore(0) //salida por el norte
  private val salidaS = new Semaphore(0) //salida por el sur

  /**
   * Utilizado por un babuino cuando quiere cruzar el cañón colgándose de la
   * cuerda en dirección Norte-Sur
   * Cuando el método termina, el babuino está en la cuerda y deben satisfacerse
   * las dos condiciones de sincronización
   *
   * @param id del babuino que entra en la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def entraDireccionNS(id: Int): Unit = {
    acceso_cuerda.acquire()
    monosN.acquire()

    mutex.acquire()
    nMonos += 1
    println(s"El mono $id entra en dirección NS. Hay ${nMonos} en la cuerda.")

    if (nMonos == 3) { //si llena la cuerda tiene que cerrar el paso a la cuerda
      println(s"Se ha llenado la cuerda(NS)")
    } else {
      if (nMonos == 1) { //si es el primero en entrar abre la puerta de salida y bloquea la entrada a los del otro sentido
        monosS.acquire()
        salidaS.release()
      }
      acceso_cuerda.release()
      monosN.release()
    }
    mutex.release()
  }

  /**
   * Utilizado por un babuino cuando quiere cruzar el cañón  colgándose de la
   * cuerda en dirección Sur-Norte
   * Cuando el método termina, el babuino está en la cuerda y deben satisfacerse
   * las dos condiciones de sincronización
   *
   * @param id del babuino que entra en la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def entraDireccionSN(id: Int): Unit = {
    acceso_cuerda.acquire()
    monosS.acquire()

    mutex.acquire()
    nMonos += 1
    println(s"El mono $id entra en dirección SN. Hay ${nMonos} en la cuerda.")

    if (nMonos == 3) { //si llena la cuerda tiene que cerrar el paso a la cuerda
      println(s"Se ha llenado la cuerda(SN)")
    } else {
      if (nMonos == 1) { //si es el primero en entrar abre la puerta de salida y bloquea la entrada a los del otro sentido
        monosN.acquire()
        salidaN.release()
      }
      acceso_cuerda.release()
      monosN.release()
    }
    mutex.release()
  }


  /**
   * Utilizado por un babuino que termina de cruzar por la cuerda en dirección Norte-Sur
   *
   * @param id del babuino que sale de la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def saleDireccionNS(id: Int): Unit = {
    salidaS.acquire()

    mutex.acquire()
    nMonos -= 1
    println(s"El mono $id sale en la  dirección NS. Hay ${nMonos} en la cuerda.")

    if (nMonos == 2) { // Si ha sido el primer mono en salir de la cuerda => libera la puerta de entrada
      monosN.release() // Monos norte pueden volver a entrar
      acceso_cuerda.release()
      salidaS.release()

    } else if (nMonos == 0) { // Si es el último mono entonces de la puerta de salida cerrada y abre la de los monos del otro lado
        log("****************************************************************")
        log("CUERDA VACÍA - por NS")
        log("****************************************************************")
        monosS.release()
    } else {
      salidaS.release() // Sigan saliendo
    }
    mutex.release()
  }



/**
 * Utilizado por un babuino que termina de cruzar por la cuerda en dirección Sur-Norte
 *
 * @param id del babuino que sale de la cuerda
 * @throws InterruptedException
 */
  @throws[InterruptedException]
  def saleDireccionSN(id: Int): Unit = {
    salidaN.acquire()

    mutex.acquire()
    nMonos -= 1
    println(s"El mono $id sale en la  dirección SN. Hay ${nMonos} en la cuerda.")

    if (nMonos == 2) { // Si ha sido el primer mono en salir de la cuerda => libera la puerta de entrada
      monosS.release() // Monos sur pueden volver a entrar
      acceso_cuerda.release()
      salidaN.release()

    } else if (nMonos == 0) { // Si es el último mono entonces de la puerta de salida cerrada y abre la de los monos del otro lado
      log("****************************************************************")
      log("CUERDA VACÍA - por SN")
      log("****************************************************************")
      monosN.release()
    } else {
      salidaN.release() // Sigan saliendo
    }
    mutex.release()
  }
}*/



/** Versión cercana mía*/
/*package examenes.Semptiembre2017_Babuinos

import java.util.concurrent.Semaphore
import Lab61.soluciones._

class Cuerda {

  private val N = 3

  private var numBabuinosSurNorte = 0
  private var numBabuinosNorteSur = 0

  private val mutex = new Semaphore(1)
  private val cuerdaLibre = new Semaphore(1)
  private val entradaSurNorte = new Semaphore(1)
  private val entradaNorteSur = new Semaphore(1)

  /**
   * Utilizado por un babuino cuando quiere cruzar el cañón colgándose de la
   * cuerda en dirección Norte-Sur
   * Cuando el método termina, el babuino está en la cuerda y deben satisfacerse
   * las dos condiciones de sincronización
   *
   * @param id del babuino que entra en la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def entraDireccionNS(id: Int): Unit = {

    cuerdaLibre.acquire()

    entradaNorteSur.acquire()

    mutex.acquire()
    numBabuinosNorteSur += 1
    log(s"Babuino $id se sube en la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")

    if (numBabuinosNorteSur == 1) { // Es el primer babuino NS => Bloqueamos a los SN
      entradaSurNorte.acquire()
    }

    if (numBabuinosNorteSur < N) { // Aún hay hueco
      cuerdaLibre.release() // Abrimos de nuevo la cuerda para el siguiente
      entradaNorteSur.release() // Siempre liberamos la entrada para el siguiente
    } else {
      log("     Se ha llenado la cuerda de babuinos Norte-Sur")
      // No liberamos cuerdaLibre hasta que todos salgan
    }

    mutex.release()
  }

  /**
   * Utilizado por un babuino cuando quiere cruzar el cañón  colgándose de la
   * cuerda en dirección Sur-Norte
   * Cuando el método termina, el babuino está en la cuerda y deben satisfacerse
   * las dos condiciones de sincronización
   *
   * @param id del babuino que entra en la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def entraDireccionSN(id: Int): Unit = {
    cuerdaLibre.acquire()
    entradaSurNorte.acquire()

    mutex.acquire()
    numBabuinosSurNorte += 1
    log(s"Babuino $id se sube en la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")

    if (numBabuinosSurNorte == 1) { // Es el primer babuino SN => Bloqueamos a los NS
      entradaNorteSur.acquire()
    }

    if (numBabuinosSurNorte < N) { // Aún hay hueco
      cuerdaLibre.release() // Abrimos de nuevo la cuerda para el siguiente
      entradaSurNorte.release() // Siempre liberamos la entrada para el siguiente

    } else {
      log("     Se ha llenado la cuerda de babuinos Sur-Norte")
      // No liberamos cuerdaLibre hasta que todos salgan
    }

    mutex.release()
  }

  /**
   * Utilizado por un babuino que termina de cruzar por la cuerda en dirección Norte-Sur
   *
   * @param id del babuino que sale de la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def saleDireccionNS(id: Int): Unit = {

    mutex.acquire()
    numBabuinosNorteSur -= 1
    log(s"Babuino $id se baja de la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")

    if (numBabuinosNorteSur == 0) {
      log("****************************************************************")
      log("CUERDA VACÍA")
      log("****************************************************************")
      cuerdaLibre.release() // Liberamos la cuerda
      entradaSurNorte.release() // Permitimos que entren los babuinos SN
    }
    mutex.release()
  }

  /**
   * Utilizado por un babuino que termina de cruzar por la cuerda en dirección Sur-Norte
   *
   * @param id del babuino que sale de la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def saleDireccionSN(id: Int): Unit = {
    mutex.acquire()
    numBabuinosSurNorte -= 1
    log(s"Babuino $id se baja de la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")

    if (numBabuinosSurNorte == 0) {
      log("****************************************************************")
      log("CUERDA VACÍA")
      log("****************************************************************")
      cuerdaLibre.release() // Liberamos la cuerda
      entradaNorteSur.release() // Permitimos que entren los babuinos NS
    }
    mutex.release()
  }
}*/

/** Versión cercana mía + wuolah*/
/*class Cuerda {

  private val N = 3

  private var numBabuinosSurNorte = 0
  private var numBabuinosNorteSur = 0

  private val mutex = new Semaphore(1)
  private val cuerdaLibre = new Semaphore(1)
  private val entradaSurNorte = new Semaphore(1)
  private val entradaNorteSur = new Semaphore(1)
  private val salidaNorteSur = new Semaphore(0)
  private val salidaSurNorte = new Semaphore(0)

  /**
   * Utilizado por un babuino cuando quiere cruzar el cañón colgándose de la
   * cuerda en dirección Norte-Sur
   * Cuando el método termina, el babuino está en la cuerda y deben satisfacerse
   * las dos condiciones de sincronización
   *
   * @param id del babuino que entra en la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def entraDireccionNS(id: Int): Unit = {
    cuerdaLibre.acquire()
    entradaNorteSur.acquire()

    mutex.acquire()
    numBabuinosNorteSur += 1
    log(s"Babuino $id se sube en la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")

    if (numBabuinosNorteSur < N) { // Aún hay hueco
      if (numBabuinosNorteSur == 1) { // Es el primer babuinoNS => Bloqueamos a los SN
        entradaSurNorte.acquire()
      }
      cuerdaLibre.release() // Abrimos de nuevo la cuerda
      entradaNorteSur.release()
    } else {
      log("     Se ha llenado la cuerda de babuinos Norte-Sur")
      cuerdaLibre.release()
      // Liberamos N permits para que todos los babuinos puedan salir
      salidaNorteSur.release(N)
    }
    mutex.release()
  }

  /**
   * Utilizado por un babuino cuando quiere cruzar el cañón  colgándose de la
   * cuerda en dirección Sur-Norte
   * Cuando el método termina, el babuino está en la cuerda y deben satisfacerse
   * las dos condiciones de sincronización
   *
   * @param id del babuino que entra en la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def entraDireccionSN(id: Int): Unit = {
    cuerdaLibre.acquire()
    entradaSurNorte.acquire()

    mutex.acquire()
    numBabuinosSurNorte += 1
    log(s"Babuino $id se sube en la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")

    if (numBabuinosSurNorte < N) {
      if (numBabuinosSurNorte == 1) {
        entradaNorteSur.acquire()
      }
      cuerdaLibre.release()
      entradaSurNorte.release()
    } else {
      log("     Se ha llenado la cuerda de babuinos Sur-Norte")
      cuerdaLibre.release()
      // Liberamos N permits para que todos los babuinos puedan salir
      salidaSurNorte.release(N)
    }
    mutex.release()
  }

  /**
   * Utilizado por un babuino que termina de cruzar por la cuerda en dirección Norte-Sur
   *
   * @param id del babuino que sale de la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def saleDireccionNS(id: Int): Unit = {
    salidaNorteSur.acquire()

    mutex.acquire()
    numBabuinosNorteSur -= 1
    log(s"Babuino $id se baja de la cuerda dirección Norte-Sur. Hay $numBabuinosNorteSur")

    if (numBabuinosNorteSur == 0) {
      log("****************************************************************")
      log("CUERDA VACÍA")
      log("****************************************************************")
      cuerdaLibre.release()
      entradaSurNorte.release() // Permitimos que entren los babuinos SN
    }
    mutex.release()
  }

  /**
   * Utilizado por un babuino que termina de cruzar por la cuerda en dirección Sur-Norte
   *
   * @param id del babuino que sale de la cuerda
   * @throws InterruptedException
   */
  @throws[InterruptedException]
  def saleDireccionSN(id: Int): Unit = {
    salidaSurNorte.acquire()

    mutex.acquire()
    numBabuinosSurNorte -= 1
    log(s"Babuino $id se baja de la cuerda dirección Sur-Norte. Hay $numBabuinosSurNorte")

    if (numBabuinosSurNorte == 0) {
      log("****************************************************************")
      log("CUERDA VACÍA")
      log("****************************************************************")
      cuerdaLibre.release()
      entradaNorteSur.release() // Permitimos que entren los babuinos NS
    }
    mutex.release()
  }
}*/