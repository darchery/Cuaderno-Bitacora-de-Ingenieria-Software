package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 7. Implementa una operación groupBy(l, f) que tome como argumentos una lista l de elementos de
 * tipo A y una función f: A => B y que devuelva un objeto de tipo Map[B, List[A]] que asocie una lista
 * con los elementos e de l con el mismo f(e).
 * println(groupBy(List(1,2,3,4,5), _ % 2 == 0))
 * // Output: Map(false -> List(5, 3, 1), true -> List(4, 2))*/

def groupBy[A, B](l: List[A], f: A => B): Map[B, List[A]] =
  @tailrec
  def bucle(acc: Map[B, List[A]], l_resto: List[A]): Map[B, List[A]] =
    l_resto match
      case Nil => acc
      case head:: tail => 
        val key = f(head)
        bucle(acc.updated(f(head), head :: acc.getOrElse(key, Nil)), tail)
  bucle(Map.empty, l)    

object ejercicio_7 extends App {
  println(groupBy(List(1, 2, 3, 4, 5), _ % 2 == 0))
  // Output: Map(false -> List(5, 3, 1), true -> List(4, 2))
}
