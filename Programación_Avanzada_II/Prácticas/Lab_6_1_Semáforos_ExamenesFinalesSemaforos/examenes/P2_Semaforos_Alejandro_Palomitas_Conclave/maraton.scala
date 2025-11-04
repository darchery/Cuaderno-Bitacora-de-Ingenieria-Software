package examenes.P2_Semaforos_Alejandro_Palomitas_Conclave

// MISMO EJERCICIO QUE EL DE LOS CANÍBALES
//package control_2

/*
En nuestro grupo (nos llamaremos jóvenes) hemos preparado un maratón para ver todas las series
de nuestra plataforma de televisión favorita, que presume de tener un número ilimitado de horas
disponibles. Obviamente, no podemos ver nada en televisión sin comer palomitas sin parar, así que
hemos preparado un sistema en el que dispondremos de un bowl para las palomitas del que comeremos
todos. Cuando un joven quiere una palomita y el bowl no está vacío coge una palomita, pero si se
encuentra el bowl vacío llamará al encargado de preparar las palomitas (el palomitero), y esperará
a que rellene el bowl. Cuando el palomitero rellena el bowl, el joven que le había avisado coge
su palomita. Al palomitero le encanta hacer palomitas, y siempre está esperando un nuevo pedido,
cuando lo llaman prepara las palomitas, rellena el bowl y se queda a la espera de que le vuelvan
a llamar.
*/

import concurrencia.{log, thread}
import java.util.concurrent.Semaphore
import scala.util.Random

class Bowl(R: Int) {
  // CS-joven i: no coge una palomita del bowl si este está vacía
  // CS-palomitero: no llena el bowl hasta que está vacío

  private var bowl = R // inicialmente lleno
  private val mutex = new Semaphore(1)
  private val comerPalomitas = new Semaphore(1) // CS-joven -> Hay palomitas al inicio
  private val reponerPalomitas = new Semaphore(0) // CS-palomitero -> No tiene que reponer al principio

  def coge(i: Int) = {
    comerPalomitas.acquire()

    mutex.acquire()

    bowl -= 1
    log(s"Joven $i coge una palomita del bowl. Quedan $bowl palomitas.")
    if (bowl > 0) comerPalomitas.release()
    else reponerPalomitas.release()

    mutex.release()
  }

  def dormir = {
    reponerPalomitas.acquire()

  }

  def llenarBowl = {
    /** COMENTARIO ANTIGUA VERSIÓN SIN MUTEX*/
    // Aquí no hace falta hacer un mutex porque sólo tenemos un palomitero, y los jóvenes están dormidos
    // Si hacemos un mutex tendríamos a los jovenes bloqueados esperando el relleno y al palomitero también bloqueado
    // por lo tanto si llega aquí no tiene que usar exclsuión mutua porque ya no hay jóvenes despiertos

    mutex.acquire()
    bowl = R
    log(s"El palomitero llena el bowl. Quedan $bowl palomitas.")
    mutex.release()
    comerPalomitas.release()
  }
}

object marathon {
  def main(args: Array[String]): Unit = {
    val NJovenes = 20 // número de jóvenes en la maratón
    val bowl = new Bowl(100) // el bowl se inicializa lleno, indicando en el constructor su capacidad
    val joven = new Array[Thread](NJovenes)

    for (i <- joven.indices)
      joven(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(100)) // espera entre palomita y palomita, no se vaya a atragantar
          bowl.coge(i)
        }
      }

    val palomitero = thread {
      while (true) {
        bowl.dormir
        Thread.sleep(500) // preparando las palomitas
        bowl.llenarBowl
      }
    }
  }
}
