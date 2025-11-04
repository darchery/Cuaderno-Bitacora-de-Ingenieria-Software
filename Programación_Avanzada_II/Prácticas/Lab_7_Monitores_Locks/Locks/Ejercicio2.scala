package esqueletosLaboratorio7

package Locks

import java.util.concurrent.locks.ReentrantLock
import scala.collection.mutable.ListBuffer
import scala.util.Random

class Recursos(rec:Int) {

  private val enEspera = new ListBuffer[Int]() // Es una lista que nos guarda el orden de los procesos que piden recursos
  private var numRec = rec // Recursos restantes
  private var procesosEsperando = 0
  private var siguienteProceso = -1
  
  private val l = new ReentrantLock(true)
  private val primero = l.newCondition()
  private val cEnEspera = l.newCondition()
  
  def pidoRecursos(id:Int,num:Int) =  {
      l.lock()
      try {
        procesosEsperando += 1
        log(s"Proceso $id pide $num recursos.")
        if(procesosEsperando > 1) {
          enEspera += id
          
          while (siguienteProceso != id) cEnEspera.await() // SI no lo toca => espera
          // siguienteProceso = -1 // Esto es para que el while no vuelva => reinicio
        }
        
        while(num > numRec) primero.await()
        numRec -= num
        procesosEsperando -= 1

        log(s"Proceso $id coge $num recursos. Quedan $numRec")

        if (procesosEsperando != 0) { // Si hay gente procesosEsperando
          siguienteProceso = enEspera.remove(0) // Cogemos el primero de la lista
          cEnEspera.signal() // Avisamos a la primera hebra
        } else {
          siguienteProceso = -1 // Reseteamos el siguiente proceso
        }
      } finally {
        l.unlock()
      }
  }

  def libRecursos(id:Int,num:Int) =  {
    //proceso id devuelve num recursos
    l.lock()
    try {
      numRec += num
      log(s"Proceso $id devuelve $num recursos. Quedan $numRec")  
      primero.signal() // Liberamos al primero 
    } finally {
      l.unlock()
    }
    
  }
}
object Ejercicio2 {

  def main(args:Array[String]):Unit = {
    val rec = 5
    val numProc = 10
    val recursos = new Recursos(rec)
    val proceso = new Array[Thread](numProc)
    for (i<-proceso.indices)
      proceso(i) = thread{
      //  while (true){
          val r = Random.nextInt(rec)+1
          recursos.pidoRecursos(i,r)
          Thread.sleep(Random.nextInt(300))
          recursos.libRecursos(i,r)
     //   }
      }
  }
}
