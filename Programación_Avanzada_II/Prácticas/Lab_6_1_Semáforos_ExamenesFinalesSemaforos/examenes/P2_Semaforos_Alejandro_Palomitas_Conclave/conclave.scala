package examenes.P2_Semaforos_Alejandro_Palomitas_Conclave

/*
En un cónclave de cardenales, se debe realizar una votación para elegir a un nuevo Papa.
Hay N cardenales (en este caso, 9), que votan por cualquier candidato. En cada ronda:
(i) Los cardenales votan de manera concurrente.
(ii) Si ningún candidato obtiene más de la mitad de los votos (N/2), se realiza una nueva votación.
(iii) Si un candidato obtiene más de la mitad de los votos, se declara ganador y se enciende la
"fumata blanca" (fumata_blanca = true), indicando que el cónclave ha finalizado.
El programa debe garantizar la sincronización entre los cardenales para evitar condiciones de
carrera y asegurar que los votos se procesen correctamente. Los cardenales deben esperar a que
todos terminen de votar antes de iniciar una nueva ronda.
*/
/** // VOTAN VARIAS VECES LOS CARDENALES
import concurrencia.{log, thread}
import scala.util.Random
import java.util.concurrent.Semaphore

object conclave {
  // CS-1: Todos los cardenales votan en cada votación
  // CS-2: Un cardenal no debe votar más de una vez en la misma votación
  // CS-3: Se garantizará la exclusión mutua para evitar condiciones de carrera
  val numCardenales = 9
  var fumata_blanca = false
  var ganador: Option[Int] = None
  private val votos = scala.collection.mutable.Map[Int,Int]()
  private var votacion = 0

  private val mutex = new Semaphore(1)
  private val puedeVotar = new Semaphore(1)
  private var numVotos = 0

  def vota(i: Int) = {

    puedeVotar.acquire()

    mutex.acquire()
    numVotos += 1
    votos.update(i ,votos.getOrElse(i, 0) + 1)
    // ó votos(i) = votos.getOrElse(i, 0) + 1

    if (numVotos >= numCardenales) { // Se hicieron todos los votos
      ganador = Some(votos.maxBy(_._2)._1)

      log(s"Votación ${votacion}, gana el candidato ${ganador.get} con ${votos(ganador.get)} votos")

      if (votos(ganador.get) > numCardenales/2) { // Nuevo Papa!
        fumata_blanca = true
      } else { // No se declaró un nuevo papa
        numVotos = 0
        votacion += 1
        votos.clear()
        puedeVotar.release()
      }

    } else { // Aún no
      puedeVotar.release()
    }
    mutex.release()
  }

  def mainConclave(): Unit = {
    val N = conclave.numCardenales
    val cardenal = new Array[Thread](N)

    for (i <- 0 until N)
      cardenal(i) = thread {
        while (!conclave.fumata_blanca) {
          conclave.vota(Random.nextInt(N))
          Thread.sleep(Random.nextInt(200))
        }
      }
    for (i <- 0 until N)
      cardenal(i).join()
    log(s"El nuevo papa es el cardenal ${conclave.ganador.get}")

  }

}

object main extends App {
  import conclave._
  mainConclave()
}*/

// VERSIÓN PROFE
import concurrencia.{log, thread}
import scala.util.Random
import java.util.concurrent.Semaphore

object conclave {
  // CS-1: Todos los cardenales votan en cada votación
  // CS-2: Un cardenal no debe votar más de una vez en la misma votación
  // CS-3: Se garantizará la exclusión mutua para evitar condiciones de carrera
  val numCardenales = 9
  var fumata_blanca = false
  var ganador: Option[Int] = None
  private val votos = scala.collection.mutable.Map[Int,Int]()
  private var votacion = 0

  private val puedoVotar = new Semaphore(1) // Es como el mutex, bloque el acceso de más cardenales
  private val esperaFinVotacion = new Semaphore(0) // Semáforo crucial para frenar al votante
  private var numVotos = 0

  def vota(i: Int) = {
    // no es necesario un mutex, puedoVotar garantiza la exclusión entre los cardenales
    puedoVotar.acquire() // Similar a mutex

    numVotos += 1
    votos(i) = votos.getOrElse(i, 0) + 1 // Actualizamos los votos de ese cardenal

    if (numVotos < numCardenales) { // Si suma de los botos es menor que 9, aún no han votado todos
      puedoVotar.release() // Se avisa a los votantes/ mutex.release
      esperaFinVotacion.acquire() // Se bloquea este votante hasta que se reinicie la ronda
      // Todos los cardenales que no son el último en votar, se quedan bloqueados aquí
    }
    else { // Votaron todos los cardenales
      ganador = Some(votos.maxBy(_._2)._1) // Tomamos la clave del candidato(._1) con más votos (_._2)

      log(s"Votación ${votacion}, gana el candidato ${ganador.get} con ${votos(ganador.get)} votos")

      if (votos(ganador.get) > numCardenales / 2) { // Si alcanzó el nº de votos necesarios
        fumata_blanca = true // Acabamos
      } else {
        votacion += 1
        numVotos = 0
        votos.clear() // Si no limpiamos y asignamos a esta una nueva votación
      }
      esperaFinVotacion.release(numCardenales - 1) // Avisamos a los 8 cardenales que bloqueamos anteriormente, el último en votar avisa
      puedoVotar.release() // Se indica que ya se puede votar
    }
  }
  def mainConclave(): Unit = {
    val N = conclave.numCardenales
    val cardenal = new Array[Thread](N)

    for (i <- 0 until N)
      cardenal(i) = thread {
        while (!conclave.fumata_blanca) {
          conclave.vota(Random.nextInt(N))
          Thread.sleep(Random.nextInt(200))
        }
      }
    for (i <- 0 until N)
      cardenal(i).join()
    log(s"El nuevo papa es el cardenal ${conclave.ganador.get}")

  }

}

object main extends App {
  import conclave._
  mainConclave()
}


/** // INTENTO FALLIDO
package examenes.P2_Semaforos_Alejandro

/*
En un cónclave de cardenales, se debe realizar una votación para elegir a un nuevo Papa.
Hay N cardenales (en este caso, 9), que votan por cualquier candidato. En cada ronda:
(i) Los cardenales votan de manera concurrente.
(ii) Si ningún candidato obtiene más de la mitad de los votos (N/2), se realiza una nueva votación.
(iii) Si un candidato obtiene más de la mitad de los votos, se declara ganador y se enciende la
"fumata blanca" (fumata_blanca = true), indicando que el cónclave ha finalizado.
El programa debe garantizar la sincronización entre los cardenales para evitar condiciones de
carrera y asegurar que los votos se procesen correctamente. Los cardenales deben esperar a que
todos terminen de votar antes de iniciar una nueva ronda.
*/

import concurrencia.{log, thread}
import scala.util.Random
import java.util.concurrent.Semaphore

object conclave {
  // CS-1: Todos los cardenales votan en cada votación
  // CS-2: Un cardenal no debe votar más de una vez en la misma votación
  // CS-3: Se garantizará la exclusión mutua para evitar condiciones de carrera
  val numCardenales = 9
  var fumata_blanca = false
  var ganador: Option[Int] = None
  private val votos = scala.collection.mutable.Map[Int,Int]()

  private var votacion = 0

  private var numVotos = 0
  private val mutex = new Semaphore(1)
  private val puedenVotar = new Array[Semaphore](9) // CS-1
  for (i<-puedenVotar.indices) {
    puedenVotar(i) = new Semaphore(1)
  }

  def vota(i: Int) = {

    puedenVotar(i).acquire()

    mutex.acquire()

    numVotos += 1
    votos(i) = votos.getOrElse(i, 0) + 1

    if (numVotos >= numCardenales) { // Votaron todos los cardenales
      ganador = Some(votos.maxBy(_._2)._1)

      log(s"Votación ${votacion}, gana el candidato ${ganador.get} con ${votos(ganador.get)} votos")

      if (votos(ganador.get) > numCardenales/2) {
        fumata_blanca = true
      } else {
        numVotos = 0
        votacion += 1
        votos.clear()

        for (i<- puedenVotar.indices) {
          puedenVotar(i).release()
        }
      }
    } else { // Aún no se terminó de votar
      puedenVotar(i).release()
      /** PROBLEMA: UN CARDENAL PUEDE VOTAR VARIAS VECES?*/
    }

    mutex.release()

  }

   def mainConclave(): Unit = {
    val N = conclave.numCardenales
    val cardenal = new Array[Thread](N)

    for (i <- 0 until N)
      cardenal(i) = thread {
        while (!conclave.fumata_blanca) {
          conclave.vota(Random.nextInt(N))
          Thread.sleep(Random.nextInt(200))
        }
      }
    for (i <- 0 until N) {
      cardenal(i).join()
    }
     log(s"El nuevo papa es el cardenal ${conclave.ganador.get}")

  }

}

object main extends App {
  import conclave._
  mainConclave()
}*/

