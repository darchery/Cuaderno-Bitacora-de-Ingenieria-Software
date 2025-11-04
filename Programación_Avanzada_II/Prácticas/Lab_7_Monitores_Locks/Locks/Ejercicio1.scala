package esqueletosLaboratorio7
package Locks

import java.util.concurrent.locks.{Condition, ReentrantLock}
import scala.util.Random

class Buffer(ncons:Int,tam:Int){
  //ncons-número de consumidores
  //tam-tamaño del buffer

  private val l = new ReentrantLock(true)
  private val espacio = l.newCondition()

  private var indexCons = 0
  private var indexProd = 0
  private var numElem = 0
    
  private val buffer = new Array[Int](tam)
  for (i<-buffer.indices)
    buffer(i) = 0 // Para la salida por pantalla
    
  def nuevoDato(dato:Int) = {
    //el productor pone un nuevo dato
    l.lock()
    try {

      log(s"Productor almacena $dato: buffer=${buffer.mkString("[", ",", "]")}}")

    } finally {
      l.unlock()
    }
  }

  def extraerDato(id:Int):Int =  {

    l.lock()
    try {
      val dato = buffer(indexCons)
      log(s"Consumidor $id lee $dato: buffer=${buffer.mkString("[", ",", "]")}")
      dato
    } finally {
      l.unlock()
    }
  }
}
object Ejercicio1 {

  def main(args:Array[String]):Unit = {
    val ncons = 4
    val tam = 3
    val nIter = 10
    val buffer  = new Buffer(ncons,tam)
    val consumidor = new Array[Thread](ncons)
    for (i<-consumidor.indices)
      consumidor(i) = thread{
        for (j<-0 until nIter)
          val dato = buffer.extraerDato(i)
          Thread.sleep(Random.nextInt(200))
      }
    val productor = thread{
      for (i<-0 until nIter)
        Thread.sleep(Random.nextInt(50))
        buffer.nuevoDato(i+1)
    }
  }

}

// Variables antiguas
/*
private val hayDato = new Array[Int](ncons)
  for(i<-hayDato.indices) hayDato(i) = 0

  private val indCons = new Array[Int](tam)
  for(i<-indCons) indCons(i) = 0

  private var huecos = tam
  private var indProd = 0
  private val bufferAux = new Array[Int](tam)


  private val l = new ReentrantLock(true)
  private val espacio = l.newCondition()

  private val dato = new Array[Condition](ncons)
  for (i<-dato.indices)
    dato(i) = l.newCondition()

  private val buffer = new Array[Int](tam)
  for (i<-buffer.indices)
    buffer(i) = 0 // Para la salida por pantalla

  def nuevoDato(dato:Int) = {
    //el productor pone un nuevo dato
    l.lock()
    try {
      while (huecos == 0) espacio.await()
      buffer(indexProd) = ncons
      log(s"Productor almacena $dato: buffer=${buffer.mkString("[", ",", "]")}}")
      indexProd = (indexProd + 1) % tam
      for (i<-hayDato.indices)
        hayDato(i) += 1
        //if(hayDato(i) == 1) dato(i).signal // ????
      huecos -= 1
    } finally {
      l.unlock()
    }
  }

  def extraerDato(id:Int):Int =  {
    l.lock()
    try {
      while (hayDato(id) == 0) dato(id).await()
      val d = buffer(indCons(id))
      bufferAux(indCons(id)) -= 1
      if (bufferAux(indCons(id)) == 0) {
        buffer(indCons(id)) = 0 // Para la salida por pantalla
        huecos += 1

        if (huecos == 1) espacio.signal()
      }
      indCons(id) = (indCons(id) + 1) % tam
      d
    } finally {
      l.unlock()
    }
    log(s"Consumidor $id lee : buffer=${buffer.mkString("[",",","]")}")
    0
  }
}
*/