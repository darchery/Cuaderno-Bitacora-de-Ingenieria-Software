package examenes.Septiembre2020_Curso_Online

import java.util.concurrent.Semaphore

class Curso {

  // Número máximo de alumnos cursando simultáneamente la parte de iniciación
  private val MAX_ALUMNOS_INI = 10

  // Número de alumnos por grupo en la parte avanzada
  private val ALUMNOS_AV = 3

  private var alumIni = 0
  private var esperandoGrupo = 0
  private var terminadoProyecto = 0

  private val mutex = new Semaphore(1) // Exclusión mutua para las variables
  private val inicioIni = new Semaphore(1) // Control de inicio curso
  private val esperaGrupo = new Semaphore(1) // Se puede bloquear para esperar a que alumnos acaben la parte avanzada
  private val esperaFinProyecto = new Semaphore(0) // Se puede bloquear para esperar a que alumnos acaben la parte avanzada del proyecto

  // El alumno tendrá que esperar si ya hay 10 alumnos cursando la parte de iniciación
  @throws[InterruptedException]
  def esperaPlazaIniciacion(id: Int): Unit = {
    // Espera si ya hay 10 alumnos cursando esta parte
    inicioIni.acquire()

    mutex.acquire()

    alumIni += 1
    // Mensaje a mostrar cuando el alumno pueda conectarse y cursar la parte de iniciación
    println(s"PARTE INICIACION: Alumno $id cursa parte iniciacion")

    if (alumIni < MAX_ALUMNOS_INI) inicioIni.release() // Si aún hay hueco

    mutex.release()
  }

  // El alumno informa que ya ha terminado de cursar la parte de iniciación
  @throws[InterruptedException]
  def finIniciacion(id: Int): Unit = {

    mutex.acquire()

    alumIni -= 1
    // Mensaje a mostrar para indicar que el alumno ha terminado la parte de principiantes
    println(s"PARTE INICIACION: Alumno $id termina parte iniciacion")

    // Libera la conexión para que otro alumno pueda usarla
    if (alumIni == MAX_ALUMNOS_INI - 1) inicioIni.release() // Avisa a otro de que hay un hueco

    mutex.release()
  }

  /* El alumno tendrá que esperar:
   *   - si ya hay un grupo realizando la parte avanzada
   *   - si todavía no están los tres miembros del grupo conectados
   */
  @throws[InterruptedException]
  def esperaPlazaAvanzado(id: Int): Unit = {
    // Espera a que no haya otro grupo realizando esta parte
    esperaGrupo.acquire()

    // Espera a que haya tres alumnos conectados
    mutex.acquire()

    esperandoGrupo += 1
    // Mensaje a mostrar si el alumno tiene que esperar al resto de miembros en el grupo
    println(s"PARTE AVANZADA: Alumno $id espera a que haya $ALUMNOS_AV alumnos")

    if (esperandoGrupo < ALUMNOS_AV) {
      // Dejamos al siguiente alummo entrar
      esperaGrupo.release()

      // Bloqueamos para esperar a los otros 2 compañeros
      mutex.release()
      esperaFinProyecto.acquire() // Bloqueamos a la hebra para que espere
      mutex.acquire() // Cogemos el mutex cuando me desbloquean

    } else {
      // Mensaje a mostrar cuando el alumno pueda empezar a cursar la parte avanzada
      println(s"PARTE AVANZADA: Hay $ALUMNOS_AV alumnos. Alumno $id empieza el proyecto")
    }
    esperandoGrupo -= 1 // Acabó

    // Si aún quedan alumnos esperando a sus compañeros => los liberamos (en cascada)
    if (esperandoGrupo != 0) esperaFinProyecto.release() // Desbloqueamos a los 3 alumnos

    mutex.release()

  }

  /* El alumno:
   *   - informa que ya ha terminado de cursar la parte avanzada
   *   - espera hasta que los tres miembros del grupo hayan terminado su parte
   */
  @throws[InterruptedException]
  def finAvanzado(id: Int): Unit = {
    // Espera a que los 3 alumnos terminen su parte avanzada

    mutex.acquire()

    terminadoProyecto += 1 // termina su parte del proyecto
    // Mensaje a mostrar si el alumno tiene que esperar a que los otros miembros del grupo terminen
    println(s"PARTE AVANZADA: Alumno $id termina su parte del proyecto. Espera al resto")


    if (terminadoProyecto < ALUMNOS_AV) {

      // Bloqueamos la hebra para que espere a sus compañeros
      mutex.release()
      esperaFinProyecto.acquire()
    } else { // Si ya han terminado todos
      // Mensaje a mostrar cuando los tres alumnos del grupo han terminado su parte
      println(s"PARTE AVANZADA: LOS $ALUMNOS_AV ALUMNOS HAN TERMINADO EL CURSO")
    }

    terminadoProyecto -= 1 // Alumno termina

    if (terminadoProyecto != 0) { // Si aún hay alumnos esperando => liberamos a otro
      esperaFinProyecto.release()
    } else { // Si no => indicamos a otro grupo que puede entrar
      esperaGrupo.release()
    }
    mutex.release()

  }
}
