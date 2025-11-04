package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object Ejercicio7_mi_version {
  def main(args: Array[String]): Unit = {
    val N = 10
    val nido = new Nido_mi_version(5)
    val bebe = new Array[Thread](N)

    for (i <- bebe.indices)
      bebe(i) = thread {
        while (true) {
          nido.cojoBichito(i)
          Thread.sleep(Random.nextInt(600))
        }
      }

    val papa = new Array[Thread](2)

    for (i <- papa.indices)
      papa(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(100))
          nido.pongoBichito(i)
        }
      }
  }
}

class Nido_mi_version(B: Int) {
  // CS-bebé i: no puede coger un bichito del plato si está vacío
  // CS-papá/mamá: no puede dejar un bichito en el plato si está lleno
  // Máximo de bichitos B => plato ha de ser <= B

  private var plato = 0
  private val mutex = new Semaphore(1)
  private val hayEspacioPlato = new Semaphore(1) // CS - papá // plato = 0 => Abierto
  private val hayBichito = new Semaphore(0) // CS-bebe // plato = 0 => Cerrado

  def cojoBichito(i: Int) = {
    // el bebé i coge un bichito del plato
    hayBichito.acquire() // Detengo a los demás pollitos
    mutex.acquire()
    plato -= 1
    log(s"Bebé $i coge un bichito. Quedan $plato bichitos")
    if (plato > 0) hayBichito.release() // Aún hay bichitos => Pollito comen
    if (plato == B - 1) hayEspacioPlato.release() // Cogen un bichito del nido lleno => Papá pone bichito
    mutex.release()
  }

  def pongoBichito(i: Int) = {
    // el papá/la mamá pone un bichito en el plato (0=papá, 1=mamá)
    hayEspacioPlato.acquire() // Detengo al otro papá
    mutex.acquire()
    plato += 1
    log(s"Papá $i pone un bichito. Quedan $plato bichitos")
    if (plato == 1) hayBichito.release() // Hay un bichito => Pollito comen
    if (plato < B) hayEspacioPlato.release() // Aún hay espacio => Papás cazan
    mutex.release()
  }
}

class Nido_mi_version_REPASO(B: Int) {
  // CS-bebé i: no puede coger un bichito del plato si está vacío
  // CS-papá/mamá: no puede dejar un bichito en el plato si está lleno

  private var plato = 0
  private val mutex = new Semaphore(1)
  private val hayEspacioPlato = new Semaphore(1)
  private val hayBichito = new Semaphore(0)

  def cojoBichito(i: Int) = {
    // el bebé i coge un bichito del plato
    hayBichito.acquire()
    mutex.acquire()
    plato -= 1
    if (plato > 0) hayBichito.release()
    if (plato == B-1) hayEspacioPlato.release()
    log(s"Bebé $i coge un bichito. Quedan $plato bichitos")
    mutex.release()
  }

  def pongoBichito(i: Int) = {
    // el papá/la mamá pone un bichito en el plato (0=papá, 1=mamá)
    hayEspacioPlato.acquire()
    mutex.acquire()
    plato += 1
    if (plato == 1) hayBichito.release()
    if (plato < B) hayEspacioPlato.release()
    log(s"Papá $i pone un bichito. Quedan $plato bichitos")
    mutex.release()
  }
}