package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

class Nido(B: Int) {
  // B => Número máximo de bichitos
  // CS-bebé i: no puede coger un bichito del plato si está vacío
  // CS-papá/mamá: no puede dejar un bichito en el plato si está lleno

  private var plato = 0
  private val mutex = new Semaphore(1) // Simper que usemos exclusión mutua => mutex a 1
  private val hayEspacioPlato = new Semaphore(1) // CS-papá
  private val hayBichitos = new Semaphore(0) // CS - bebé

  def cojoBichito(i: Int) = {
    // el bebé i coge un bichito del plato
    hayBichitos.acquire()
    mutex.acquire()
    plato -= 1
    log(s"Bebé $i coge un bichito. Quedan $plato bichitos")
    // Si hay 1 o más bichitos en el plato => llama a los pajaros para que cojan bichitos
    if (plato > 0) hayBichitos.release()
    // Si uno de los bebes come un bichito => hay espacio para que el padre ponga 1
    if (plato == B-1) hayEspacioPlato.release()
    mutex.release()
  }

  def pongoBichito(i: Int) = {
    // el papá/la mamá pone un bichito en el plato (0=papá, 1=mamá)
    hayEspacioPlato.acquire()
    mutex.acquire()
    plato += 1
    log(s"Papá $i pone un bichito. Quedan $plato bichitos")
    // Si caben bichitos en el plato => se llama al padre para que ponga bichitos
    if (plato < B) hayEspacioPlato.release()
    // Si hay un bichito => se llama a los bichos
    if (plato == 1) hayBichitos.release()
    mutex.release()
  }
}

object Ejercicio7 {
  def main(args: Array[String]): Unit = {
    val N = 10
    val nido = new Nido(5)
    val bebe = new Array[Thread](N)
    for (i <- bebe.indices)
      bebe(i) = thread {
        while (true)
          nido.cojoBichito(i)
        Thread.sleep(Random.nextInt(600))
      }
    val papa = new Array[Thread](2)
    for (i <- papa.indices)
      papa(i) = thread {
        while (true)
          Thread.sleep(Random.nextInt(100))
        nido.pongoBichito(i)
      }
  }
}
