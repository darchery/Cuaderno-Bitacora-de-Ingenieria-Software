package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 8. Implementa una operación reduce(l, f) que toma como argumentos una lista l de elementos de tipo
 * A y una función f de tipo (A, A) => A y que devuelva el resultado de combinar todos los elementos
 * de l utilizando la función f. Por ejemplo:
 * println(reduce(List(1,2,3,4,5), _ + _)) // Output: 15*/

def reduce[A](l: List[A], f: (A, A) => A): A =
  @tailrec
  def bucle(acc: A, l_res: List[A]): A =
    l_res match
      case Nil => acc
      case head :: tail => bucle(f(acc, head), tail)
  bucle(l.head, l.tail)   

object ejercicio_8 extends App {
  println(reduce(List(1, 2, 3, 4, 5), _ + _)) // Output: 15
}
