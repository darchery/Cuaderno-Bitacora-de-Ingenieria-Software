package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 4. Define una función recursiva genérica zip que tome dos listas y devuelva una lista de tuplas, donde
 * las primeras componentes se tomen de la primera lista y las segundas componentes de la segunda
 * lista. Por ejemplo:
 * zip(List(10, 20, 30), List('a', 'b', 'c'))
 * == List((10, 'a'), (20, 'b'), (10, 'c'))
 * zip(List(10, 20, 30), List('a', 'b'))
 * == List((10,'a'), (20,'b'))*/

def zip[A, B](lA: List[A], lB: List[B]): List[(A, B)] =
  @tailrec
  def bucle(acc: List[(A, B)], lA_res: List[A], lB_res: List[B]): List[(A, B)] =
    (lA_res, lB_res) match
      case (Nil, _) => acc.reverse
      case (_, Nil) => acc.reverse
      case (Nil, Nil) => acc.reverse
      case (hA :: tA, hB :: tB) => bucle((hA, hB) :: acc, tA, tB)
  bucle(List[(A, B)](), lA, lB)

object ejercicio_4 extends App {
  println(zip(List(10, 20, 30), List('a', 'b', 'c')) == List((10, 'a'), (20, 'b'), (30, 'c')))
  println(zip(List(10, 20, 30), List('a', 'b', 'c')))

  println(zip(List(10, 20, 30), List('a', 'b')) == List((10,'a'), (20,'b')))
  println(zip(List(10, 20, 30), List('a', 'b')))
}
