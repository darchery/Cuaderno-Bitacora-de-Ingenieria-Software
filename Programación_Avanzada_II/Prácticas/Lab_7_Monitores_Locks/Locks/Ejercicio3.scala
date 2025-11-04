package esqueletosLaboratorio7
package Locks

import java.util.concurrent.locks.ReentrantLock
import scala.util.Random

object Parejas{

  private val l = new ReentrantLock(true)
  private var nPersonas = 0

  private var hayHombre = false
  private val cHayHombre = l.newCondition()

  private var hayMujer = false
  private val cHayMujer = l.newCondition()

  private var hayPareja = false
  private val cHayPareja = l.newCondition()


  def llegaHombre(id:Int) = {
    l.lock()
    try{
      while (hayHombre) cHayHombre.await()

      hayHombre = true
      nPersonas += 1
      log(s"Hombre $id quiere formar pareja")

      if (nPersonas<2){
        while (!hayPareja) cHayPareja.await()
      } else {
        log("Se ha formado la pareja!!!!")
        hayPareja = true
        cHayPareja.signal()
      }

      nPersonas -= 1

      if (nPersonas==0){
        hayPareja = false
        hayMujer = false
        cHayMujer.signal()
        hayHombre = false
        cHayHombre.signal()
      }
    }finally {
      l.unlock()
    }
  }

  def llegaMujer(id: Int) =  {
    l.lock()
    try {
      while (hayMujer) cHayMujer.await()

      hayMujer = true
      nPersonas += 1
      log(s"Mujer $id quiere formar pareja")

      if (nPersonas < 2) {
        while (!hayPareja) cHayPareja.await()
      } else {
        log("Se ha formado la pareja!!!!")
        hayPareja = true
        cHayPareja.signal()
      }

      nPersonas -= 1

      if (nPersonas == 0) {
        hayPareja = false
        hayMujer = false
        cHayMujer.signal()
        hayHombre = false
        cHayHombre.signal()
      }
    } finally {
      l.unlock()
    }

  }
}
object Ejercicio3 {

  def main(args:Array[String]):Unit = {
    val NP = 10
    val mujer = new Array[Thread](NP)
    val hombre = new Array[Thread](NP)
    for (i<-mujer.indices)
      mujer(i) = thread{
        Parejas.llegaMujer(i)
      }
    for (i <- hombre.indices)
      hombre(i) = thread {
        Parejas.llegaHombre(i)
      }
  }

}