package esqueletosLaboratorio7
import scala.util.Random

// Monitores
class Buffer(ncons:Int,tam:Int){

  //ncons-número de consumidores
  //tam-tamaño del buffer
  private val buffer = new Array[Int](tam)
  private var indexCons = 0
  private var indexProd = 0
  private var numElem = 0  // Si hay hueco en el buffer -> 0
  private val contador = new Array[Int](tam)

  def nuevoDato(dato:Int) = synchronized {
    //el productor pone un nuevo dato
    while (numElem == tam) wait() // Si no hay espacio => Prod espera

    buffer(indexProd) = dato // Cuando haya ponemos el dato
    contador(indexProd) = ncons // Le indicamos a los consumidores que deben consumir el dato
    numElem += 1
    log(s"Productor almacena $dato: buffer=${buffer.mkString("[",",","]")}}")

    indexProd = (indexProd + 1) % tam // Actualizamso posición para guardar el próximo dato

    if (numElem == 1) notifyAll() // Despertamos a to-do el mundo (consumidores que esperan un dato)
  }

  def extraerDato(id:Int):Int = synchronized {
    while (numElem == 0) wait() // Mientras no haya elementos => Consumidor espera

    contador(indexCons) = contador(indexCons) - 1 // Lo ha leido un consumidor
    val dato = buffer(indexCons) // Guardamos dato
    if (contador(indexCons) == 0) { // Si se leyeron todos -> Se elimina del buffer
      buffer(indexCons) = 0
      numElem -= 1
      indexCons = (indexCons + 1) % tam
    }
    log(s"Consumidor $id lee $dato: buffer=${buffer.mkString("[", ",", "]")}")

    if (numElem == tam - 1) notifyAll() // Si hay un hueco -> despertamos a todos (también los productores)
    dato
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
// Antigua cabecera
/*
  private val buffer = new Array[Int](tam)
  private var huecos = tam

  private val indexCons = new Array[Int](tam)
  private val porConsumir = new Array[Int](tam)
  private var indexProd = 0
*/