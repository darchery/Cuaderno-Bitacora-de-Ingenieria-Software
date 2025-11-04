package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 6. Implementa una operación map(l, f) que tome como argumentos una lista l de elementos de tipo
 * A y una función f: A => B y que devuelva una lista de elementos de tipo B con los elementos
 * resultantes de aplicar f a cada uno de los elementos de l.
 * println(map(List(1,2,3,4,5), _ * 2)) // Output: List(2,4,6,8,10)*/

def map[A, B](l: List[A], f: A => B): List[B] =
  @tailrec
  def bucle(acc: List[B], l_resto: List[A]): List[B] =
    l_resto match
      case Nil => acc.reverse
      case head :: tail => bucle(f(head) :: acc, tail)
  bucle(Nil, l)    

object ejercicio_6 extends App {
  println(map(List(1,2,3,4,5), _ * 2)) // Output: List(2,4,6,8,10)
}
