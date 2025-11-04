package tema7

/*package esqueletosLaboratorio7

import scala.util.Random

class Coche_v2(C:Int) extends Thread{
  //CS-pasajero1: si el coche está lleno, un pasajero no puede subir al coche hasta que haya terminado
  //el viaje y se hayan bajado los pasajeros de la vuelta actual
  //CS-pasajero2: un pasajero que está en el coche no se puede bajarse hasta que haya terminado el viaje
  //CS-coche: el coche espera a que se hayan subido C pasajeros para dar una vuelta
  private var numPas = 0
  private var puertaEntrada = true
  private var puertaSalida = false
  private var llenoCoche = false

  def nuevoPaseo(id:Int)= synchronized {
    //el pasajero id  quiere dar un paseo en la montaña rusa
    while (!puertaEntrada) wait()
    numPas += 1
    log(s"El pasajero $id se sube al coche. Hay $numPas pasajeros.")
    if (numPas == C) { // Ultimo pasajero => Coche lleno
      puertaEntrada = false
      llenoCoche = true
      notifyAll()
    }

    // Bajar del coche
    while (!puertaSalida) wait()
    numPas -= 1
    log(s"El pasajero $id se baja del coche. Hay $numPas pasajeros.")
    if (numPas == 0) { // Último pasajero => Coche vacío
      puertaSalida = false
      puertaEntrada = true
      llenoCoche = false
      notifyAll()
    }
  }

  def esperaLleno = synchronized {
    //el coche espera a que se llene para dar un paseo
    while (!llenoCoche) wait()
    llenoCoche = false
    log(s"        Coche lleno!!! empieza el viaje....")
  }

  def finViaje = synchronized {
    //el coche indica que se ha terminado el viaje
    log(s"        Fin del viaje... :-(")
    puertaSalida = true
    notifyAll()
  }

  override def run = {
    var fin = false
    while (!Thread.interrupted() && !fin){
      try {
        esperaLleno
        Thread.sleep(Random.nextInt(Random.nextInt(500))) //el coche da una vuelta
        finViaje 
      } catch {
        case e:InterruptedException => fin = true
      }
    }
  }
}
object Ejercicio4_Interruptions {
  def main(args:Array[String])=
    val coche = new Coche_v2(5)
    val pasajero = new Array[Thread](20)
    coche.start()
    for (i<-0 until pasajero.length)
      pasajero(i) = thread{
        //while (true)
        Thread.sleep(Random.nextInt(500))
        coche.nuevoPaseo(i)
      }
    pasajero.foreach(._join())
    coche.interrupt()
    coche.join
    log("Fin del programa")
}
*/