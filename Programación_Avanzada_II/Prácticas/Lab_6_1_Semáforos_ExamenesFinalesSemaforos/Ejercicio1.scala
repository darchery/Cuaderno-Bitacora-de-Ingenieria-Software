package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

/**
 * VALORES SEMÁFORO:
 *  0 - En pausa
 *  1 - Activado
 *
 *           |---> 3 sensores miden y almacenan -> trabajador lee y comienza tarea -|
 *           |                                                                      |
 * CS-sensor |                                                                      |
 *           |-- termina la tarea <-------------------------------------------------| */

object mediciones {
  // CS-Sensor-i: sensor i no puede volver a medir hasta que el trabajador no ha
  // terminado de procesar las medidas anteriores
  // CS-Trabajador: no puede realizar su tarea hasta que no están las
  // tres mediciones

  // Para que el semáforo sepa cuando tiene que dejar al trabajor/sensor actuar y para
  private var numeroMediciones = 0
  private val mutex = new Semaphore(1) // para numeroMediciones
  private val esperoMediciones = new Semaphore(0) // CS - Trabajador
  private val esperoSensor = new Array[Semaphore](3) // CS - Sensor i
  // Ponemos en cada espacio del array un semáforo con valor 1
  for (i<- esperoSensor.indices)
    esperoSensor(i) = new Semaphore(1)

  // SENSOR
  def nuevaMedicion(id: Int) = {
    // El sensor "id" deja su medición
    mutex.acquire()             // Resta 1 al valor del semáforo(1 - 1 = 0 => nuevo estado)
    numeroMediciones += 1       // Aumentamos la medición
    log(s"Sensor $id almacena su medición" )
    // TRABAJADOR TIENE QUE ACTUAR(MAX_MEDICIONES = 3), FRENAMOS AL SEMÁFORO DE LOS SENSORES
    if (numeroMediciones == 3) esperoMediciones.release() // CS - Trabajador
    mutex.release()            // Incrementamos el valor del semáforo
    esperoSensor(id).acquire() // CS - Sensor id // VA FUERA DE MUTEX PORQUE PRIMERO DEL SENSOR TOMA LA MEDICION
  }

  // TAREA DEL TRABAJADOR POR LAS MEDICIONES DE LOS SENSORES
  def leerMediciones() = {
    esperoMediciones.acquire()
    log(s"El trabajador recoge las mediciones")
    numeroMediciones = 0
  }

  // FIN DE TAREA
  def finTarea() = {
    log(s"El trabajador ha terminado sus tareas")
    // ACTIVAMOS TODOS LOS SENSORES
    for(i<- esperoSensor.indices)
      esperoSensor(i).release() // Avisamos a los sensores que están 0(parados) que pasen a 1 para actuar y
                                // toma las mediciones pertinentes
  }
}

object Ejercicio1 {
  def main(args: Array[String]) = {
    val sensor = new Array[Thread](3)

    for (i <- 0 until sensor.length)
      sensor(i) = thread {
        while (true)
          Thread.sleep(Random.nextInt(100)) // midiendo
        mediciones.nuevaMedicion(i)
      }

    val trabajador = thread {
      while (true)
        mediciones.leerMediciones()
      Thread.sleep(Random.nextInt(100)) // realizando la tarea
      mediciones.finTarea()
    }
  }
}
