package esqueletosLaboratorio7
package Locks

import java.util.concurrent.locks.ReentrantLock
import scala.util.Random

class Coche(C:Int) extends Thread{
  //CS-pasajero1: si el coche está lleno, un pasajero no puede subir al coche hasta que haya terminado
  //el viaje y se hayan bajado los pasajeros de la vuelta actual
  //CS-pasajero2: un pasajero que está en el coche no se puede bajarse hasta que haya terminado el viaje
  //CS-coche: el coche espera a que se hayan subido C pasajeros para dar una vuelta
  private var numPas = 0

  private val l = new ReentrantLock(true)

  private var lleno = false
  private val clleno = l.newCondition()

  private var pEntradaAbierta = true
  private val cpEntradaAbierta = l.newCondition()

  private var finalViaje = false
  private val cfinalViaje = l.newCondition()


  def nuevoPaseo(id:Int)= {
    //el pasajero id  quiere dar un paseo en la montaña rusa
    l.lock()
    try {
      // Mientras la puerta esté cerrada
      while (!pEntradaAbierta) cpEntradaAbierta.await()
      numPas += 1 // Añadimos al pasajero
      log(s"El pasajero $id se sube al coche. Hay $numPas pasajeros.")
      if (numPas == C) { // Si se ha llenado
        pEntradaAbierta = false // Cerramos puerta
        lleno = true // Lenamos el coche
        clleno.signal() // Le avsisamos al coche
      }
      while(!finalViaje) cfinalViaje.await()
      numPas -= 1
      log(s"El pasajero $id se baja del coche. Hay $numPas pasajeros.")
      if (numPas == 0) { // Si se ha vaciado
        finalViaje = false // Se acabo el viaje
        pEntradaAbierta = true // Abrimos la puerta de entrada
        cpEntradaAbierta.signalAll() // Avisamos a todos de que se puede iniciar un nuevo viaje
      }
    } finally {
      l.unlock()
    }
  }

  def esperaLleno =  {
    //el coche espera a que se llene para dar un paseo
    l.lock
    try {
      while (!lleno) clleno.await()
      lleno = false
      log(s"        Coche lleno!!! empieza el viaje....")
    } finally {
      l.unlock()
    }
  }

  def finViaje =  {
    //el coche indica que se ha terminado el viaje
    l.lock()
    try {
      finalViaje = true
      cfinalViaje.signalAll()
      log(s"        Fin del viaje... :-(")
    } finally {
      l.unlock()
    }

    
  }

  override def run = {
    while (true){
      esperaLleno
      Thread.sleep(Random.nextInt(Random.nextInt(500))) //el coche da una vuelta
      finViaje
    }
  }
}
object Ejercicio4 {
  def main(args:Array[String])=
    val coche = new Coche(5)
    val pasajero = new Array[Thread](20)
    coche.start()
    for (i<-0 until pasajero.length)
      pasajero(i) = thread{
   //     while (true)
          Thread.sleep(Random.nextInt(500))
          coche.nuevoPaseo(i)
      }
      
}
