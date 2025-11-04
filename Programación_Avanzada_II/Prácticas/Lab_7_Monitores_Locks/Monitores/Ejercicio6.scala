package esqueletosLaboratorio7

import scala.util.Random


class Bandeja(R:Int){

  private var raciones = 0

  // Primera versión -> MEJOR CON BOOLEANOS
  def quieroRacion(id:Int)= synchronized {
    while (raciones == 0) wait()

    raciones -= 1
    log(s"Niño $id ha cogido una ración. Quedan $raciones")

    if (raciones == 0) notifyAll()
  }
  def tarta()= synchronized {
    while (raciones != 0) wait()

    raciones = R
    log("El pastelero pone una nueva tarta.")
    notifyAll()
  }

  // Segunda versión
  private var hayRacion = false
  private var pasteleroDespierto = true

  def quieroRacion_v2(id: Int) = synchronized {
    while (!hayRacion) wait()

    raciones -= 1
    log(s"Niño $id ha cogido una ración. Quedan $raciones")

    if (raciones  == 0) {
      hayRacion = false
      pasteleroDespierto = true
      notifyAll()
    } 
  }

  def tarta_v2() = synchronized {
    while (!pasteleroDespierto) wait()

    raciones = R
    log("El pastelero pone una nueva tarta.")
    pasteleroDespierto = false
    hayRacion = true
    notifyAll()
  }

  // Segunda versión
}
object Ejercicio6 {

  def main(args:Array[String]):Unit = {
    val R = 5
    val N = 10
    val bandeja = new Bandeja(R)
    var niño = new Array[Thread](N)
    for (i<-niño.indices)
      niño(i) = thread{
        while (true){
          Thread.sleep(Random.nextInt(500))
          bandeja.quieroRacion(i)
        }
      }
    val pastelero = thread{
      while (true){
        Thread.sleep(Random.nextInt(100))
        bandeja.tarta()
      }
    }
  }


}
