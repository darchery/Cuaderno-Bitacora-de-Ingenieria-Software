package esqueletosLaboratorio7

package Locks

import java.util.concurrent.locks.ReentrantLock
import scala.util.Random

class Bandeja(R:Int){

  private var raciones = 0

  private val l = new ReentrantLock(true)

  private val cHayRacion = l.newCondition()
  private var hayRacion = false

  private val cPasteleroDespierto = l.newCondition()
  private var pasteleroDespierto = true


  def quieroRacion(id:Int)= {
    l.lock()
    try {
      while (!hayRacion) cHayRacion.await()

      raciones -= 1
      log(s"Niño $id ha cogido una ración. Quedan $raciones")

      if (raciones == 0) {
        hayRacion = false
        pasteleroDespierto = true
        cPasteleroDespierto.signal()
      }
    } finally {
      l.unlock()
    }
  }
  def tarta()= {
    l.lock()
    try {
      while (!pasteleroDespierto) cPasteleroDespierto.await()

      raciones = R
      hayRacion = true
      pasteleroDespierto = false
      log("El pastelero pone una nueva tarta.")

      cHayRacion.signalAll()
    } finally {
      l.unlock()
    }
  }
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

/*


import scala.util.Random
import java.util.concurrent.locks.*
def thread(body: => Unit): Thread = {
  val t = new Thread {
    override def run = body
  }
  t.start()
  t
}

def log(msg: String) =
  println(s"${Thread.currentThread().getName}: $msg")


class Bandeja(R:Int){

  private val l = new ReentrantLock(true)
  private var raciones = 0
  private var bandejaVacia = true
  private val cBandejaVacia = l.newCondition() //pastelero

  private var esperoPastelero = true
  private val cEsperoPastelero =l.newCondition() //para el primer niño

  private var pAbierta = true
  private val cPuertaAbierta = l.newCondition() //resto de niños


  def quieroRacion(id:Int)= {
    l.lock()
    try {
      while (!pAbierta) cPuertaAbierta.await()

      if (raciones==0){
        log(s"Bandeja vacía, aviso al pastelero")
        pAbierta = false
        bandejaVacia = true
        cBandejaVacia.signal()
        while (esperoPastelero) cEsperoPastelero.await()
        esperoPastelero = true

      }
      raciones -= 1
      log(s"Niño $id ha cogido una ración. Quedan $raciones")
      if (raciones==R-1) {
        pAbierta = true
        cPuertaAbierta.signalAll()
      }

    }finally {
      l.unlock()
    }
  }
  def tarta()= {
    l.lock()
    try {
      while (!bandejaVacia) cBandejaVacia.await()
      raciones = R
      bandejaVacia = false
      log(s"El pastelero pone una nueva tarta. $raciones")
      esperoPastelero = false
      cEsperoPastelero.signal()

    } finally {
      l.unlock()
    }


  }
}
object Ejercicio6 {

  def main(args:Array[String]):Unit = {
    val R = 5
    val N = 10
    val bandeja = new Bandeja(R)
    val niño = new Array[Thread](N)
    for (i<-niño.indices)
      niño(i) = thread{
        for (j<-0 until 5){
          Thread.sleep(Random.nextInt(500))
          bandeja.quieroRacion(i)
        }
      }
    val pastelero = thread{
      var fin = false
      while (!Thread.interrupted() && !fin){
        try{
          Thread.sleep(Random.nextInt(100))
          bandeja.tarta()
        }catch
          case e:InterruptedException => fin = true
      }
    }
    niño.foreach(_.join())
    log(s"Los niños se han ido a casa")
    pastelero.interrupt()
    pastelero.join()
    log("fin del programa")
  }


}


*/