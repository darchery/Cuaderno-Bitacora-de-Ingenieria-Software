import libreria_local.log

import scala.annotation.tailrec
import scala.util.Random

object ejercicio_3 {
  def thread(body: => Unit): Thread = {
    val t = new Thread {
      override def run(): Unit =
        body
    }
    t.start()
    t
  }

  // Apartado a
  def parallel[A, B](a: => A, b: => B): (A, B) = {
    var vA = null.asInstanceOf[A]
    var vB = null.asInstanceOf[B]

    val hA =  thread {
      vA = a
    }
    val hB = thread {
      vB = b
    }
    hA.join(); hB.join()
    (vA, vB)
  }

  // B.a.1
  def todosTrueIter(list: List[Boolean], inic: Int, fin: Int): Boolean = {
    for (i<-inic until fin)
      if(!list(i)) false
    true
  }
  //B.a.2
  def todosTrueRecCola(list: List[Boolean]): Boolean = {
    @tailrec
    def bucle(list_res: List[Boolean]): Boolean = {
      list_res match
        case Nil => true
        case (head :: tail) =>
          if (head) bucle(tail)
          else false
    }
    bucle(list)
  }
  // Apartado B.a.2 - Implementación recursiva
  def todosTrueRecursivo(lista: List[Boolean], inic: Int, fin: Int): Boolean = {
    if (inic >= fin) true
    else if (!lista(inic)) false
    else todosTrueRecursivo(lista, inic + 1, fin)
  }
  //B.b
  def comprobarLista(list: List[Boolean]): Boolean = {
    if (list.isEmpty) true

    val mitad = list.length/2

    val (primeraMitad, segundaMitad) = parallel(
      todosTrueIter(list, 0, mitad-1),
      todosTrueIter(list, mitad, list.length-1)
    )

    primeraMitad & segundaMitad
  }

  def main(args: Array[String]): Unit = {
    val lista = List.fill(Random.nextInt(10))(Random.nextBoolean())

    println(comprobarLista(lista))
  }
}

