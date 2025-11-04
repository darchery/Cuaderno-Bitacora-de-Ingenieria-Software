package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * Define una función recursiva genérica unzip que tome una lista de tuplas con dos componentes y
 * que devuelva una tupla con dos listas: una con las primeras componentes y otra con las segundas.
 * Por ejemplo,
 * unzip(List((10, 'a'), (20, 'b'), (10, 'c')) == (List(10, 20, 30), List('a', 'b', 'c'))*/

def unzip[A, B](list: List[(A, B)]): (List[A], List[B]) =
  @tailrec
  def unzipAux[A, B](listAux: List[(A, B)], acc1: List[A], acc2: List[B]): (List[A], List[B]) =
    listAux match
      case Nil => (acc1.reverse, acc2.reverse)
      case (h1, h2) :: tail => unzipAux(tail, h1 :: acc1, h2 :: acc2)
  unzipAux(list, Nil, Nil)


object ejercicio_3 extends App {
  println(unzip(List((10, 'a'), (20, 'b'), (10, 'c'))))
}
