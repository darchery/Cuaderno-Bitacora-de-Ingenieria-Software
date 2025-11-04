package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 9. Implementa una función recursiva para generar todos los subconjuntos de un conjunto
 * determinado. Conviértela en recursiva de cola.
 * println(subsets(Set())) // Output: Set(Set())
 * println(subsets(Set(1))) // Output: Set(Set(), Set(1))
 * println(subsets(Set(1,2))) // Output: Set(Set(),Set(1),Set(2),Set(1,2))
 * println(subsets(Set(1, 2, 3)))
 * // Output: Set(Set(),Set(1),Set(2),Set(1,2),Set(3),Set(1,3),Set(2,3),Set(1,2,3))*/

def subsets[A](cnjt: Set[A]): Set[Set[A]] =
  @tailrec
  def bucle(acc: Set[Set[A]], cnjt_res: Set[A]): Set[Set[A]] =
    if (cnjt_res.isEmpty) acc
    else
      bucle(acc ++ acc.map(_ + cnjt_res.head), cnjt_res.tail)
      // Inicializamos con un conjunto con un conjunto vacío
  bucle(Set(Set()), cnjt)

object ejercicio_9 extends App {
  println(subsets(Set())) // Output: Set(Set())
  println(subsets(Set(1))) // Output: Set(Set(), Set(1))
  println(subsets(Set(1, 2))) // Output: Set(Set(),Set(1),Set(2),Set(1,2))
  println(subsets(Set(1, 2, 3)))
  // Output: Set(Set(),Set(1),Set(2),Set(1,2),Set(3),Set(1,3),Set(2,3),Set(1,2,3))
}
