package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * . Implementa una operación filter(l, f) que tome una lista l de elementos de tipo A y una función f: A
 * => Boolean y que devuelva una lista con los elementos e de l que satisfacen f(e). Por ejemplo:
 * println(filter(List(1,2,3,4,5), _ % 2 == 0)) // Output: List(2,4)*/

def filter[A](l: List[A], f: A => Boolean): List[A] =
  @tailrec
  def bucle(acc: List[A], l_resto: List[A]): List[A] =
    l_resto match
      case Nil => acc.reverse
      case head :: tail =>
        if (f(head)) bucle(head :: acc, tail)
        else bucle(acc, tail)
  bucle(Nil, l)

object ejercicio_5 extends App {
  println(filter(List(1,2,3,4,5), _ % 2 == 0)) // Output: List(2,4)
}
