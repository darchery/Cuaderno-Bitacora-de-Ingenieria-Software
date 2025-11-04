package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object mediciones_mi_version {
  // CS-Sensor-i: sensor i no puede volver a medir hasta que el trabajador no ha
  // terminado de procesar las medidas anteriores
  // CS-Trabajador: no puede realizar su tarea hasta que no están las
  // tres mediciones
  private var numMediciones = 0
  private val mutex = new Semaphore(1)
  private val esperoMediciones = new Semaphore(0) // CS-Trabajador => Empieza parado, esperando 3 mediciones
  private val esperoSensor = new Array[Semaphore](3) // CS-Sensor i => Empieza activo, midiendo
  for (i<-0 until esperoSensor.length)
    esperoSensor(i) = new Semaphore(1)

  def nuevaMedicion(id: Int) = {
    esperoSensor(id).acquire() // CS - Sensor id // VA FUERA DE MUTEX PORQUE PRIMERO EL SENSOR TOMA LA MEDICIÓN
    mutex.acquire()
    numMediciones += 1 // SC
    log(s"Sensor $id almacena su medición")
    if (numMediciones ==  3) esperoMediciones.release() // CS - Trabajador
    mutex.release()
  }

  def leerMediciones() = {
    esperoMediciones.acquire() // Paramos la espera del trabajador
    mutex.acquire()
    numMediciones = 0 // SC // Reiniciamos el contador
    log(s"El trabajador recoge las mediciones")
    mutex.release()
  }

  def finTarea() = {
    for (i<-0 until esperoSensor.length) // Activamos los 3 sensores otra vez
      esperoSensor(i).release()
    log(s"El trabajador ha terminado sus tareas")
  }
}



object Ejercicio1_mi_version {
  def main(args: Array[String]) = {
    val sensor = new Array[Thread](3)

    for (i <- 0 until sensor.length) {
      sensor(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(100)) // midiendo
          mediciones_mi_version.nuevaMedicion(i)
        }
      }
    }

    val trabajador = thread {
      while (true) {
        mediciones_mi_version.leerMediciones()
        Thread.sleep(Random.nextInt(100)) // realizando la tarea
        mediciones_mi_version.finTarea()
      }
    }
  }
}

// REPASO
object mediciones_mi_version_REPASO {
  // CS-Sensor-i: sensor i no puede volver a medir hasta que el trabajador no ha
  // terminado de procesar las medidas anteriores
  // CS-Trabajador: no puede realizar su tarea hasta que no están las
  // tres mediciones
  private var numeroMediciones = 0
  private val mutex = new Semaphore(1) // EXM
  private val esperoSensores = new Semaphore(0) // CS-Trab
  private val sensorActivado = new Array[Semaphore](3) // CS-Sensor i
  for (i<-sensorActivado.indices)
    sensorActivado(i) = new Semaphore(1)

  def nuevaMedicion(id: Int) = {
    sensorActivado(id).acquire()
    mutex.acquire()
    numeroMediciones += 1
    log(s"Sensor $id almacena su medición" )
    if (numeroMediciones == 3) esperoSensores.release()
    mutex.release()
  }

  def leerMediciones() = {
    esperoSensores.acquire()
    mutex.acquire()
    numeroMediciones = 0
    log(s"El trabajador recoge las mediciones")
    mutex.release()
  }

  def finTarea() = {
    for (i<-sensorActivado.indices)
      sensorActivado(i).release()
    log(s"El trabajador ha terminado sus tareas")
  }
}
