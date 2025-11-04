package esqueletosLaboratorio7

import scala.collection.mutable.ListBuffer
import scala.util.Random

/**
 * Este tipo de estructura es útil si el order importa, variable ESPERANDO */

class Recursos(rec:Int) {
  private var numRec = rec // Recursos restantes
  private val enEspera = new ListBuffer[Int]() // Lista para que almacene los procesos en espera
  private var procEsperando = 0 // Nº de procesos esperando
  private var siguienteProceso = -1 // Variable que tiene el id del proceso al que le toca

  def pidoRecursos(id:Int,num:Int) = synchronized {
    //proceso id solicita num recursos
    procEsperando += 1
    log(s"Proceso $id pide $num recursos.")
    if (procEsperando > 1) {
      enEspera.append(id)

      while (siguienteProceso != id) wait()
    }

    while (num > numRec) wait()

    numRec -= num
    procEsperando -= 1
    log(s"Proceso $id coge $num recursos. Quedan $numRec")


    if (procEsperando != 0) {
      if (procEsperando != 0) {
        siguienteProceso = enEspera.remove(0)
        notifyAll()
      } else {
        siguienteProceso = -1
      }
    }
  }

  def libRecursos(id:Int,num:Int) = synchronized {
    //proceso id devuelve num recursos
    numRec += num
    log(s"Proceso $id devuelve $num recursos. Quedan $numRec")
    notifyAll()
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
        while (true){
          val r = Random.nextInt(rec)+1
          recursos.pidoRecursos(i,r)
          Thread.sleep(Random.nextInt(300))
          recursos.libRecursos(i,r)
        }
      }
  }
}
/*
def pidoRecursos(id:Int,num:Int) = synchronized {
    //proceso id solicita num recursos
      esperando += 1
      log(s"Proceso $id pide $num recursos.")
      if (esperando > 1) { // Si no soy el primero, El primer empresario se lo salta
        resto += id
        while (siguiente != id)
          wait() // aquí esperan todos los demás
        siguiente -= 1
      }
      while (num > numRec) wait() // No hay recursos para ti todavía
      numRec -= num
      esperando -= 1
      log(s"Proceso $id coge $num recursos. Quedan $numRec")
      if (esperando > 0) // Si aún hay hilos esperando
        siguiente = resto.remove(0) // Se establece como siguiente el primer valor del buffer(más antiguo)
        notifyAll()
  }

  def libRecursos(id:Int,num:Int) = synchronized {
    //proceso id devuelve num recursos
    numRec += num
    log(s"Proceso $id devuelve $num recursos. Quedan $numRec")
    notifyAll()
  }
}
* */