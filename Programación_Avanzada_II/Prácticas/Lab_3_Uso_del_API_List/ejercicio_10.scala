import scala.annotation.tailrec

/**
 * 10. Escribe una función
 * def halfEven(l1:List[Int],l2:List[Int]):List[Int]
 * que toma dos listas de enteros como entrada y suma sus elementos l1(i) y l2(i). Si la suma l1(i) + l2(i) es
 * par se divide por dos. En otro caso, se elimina de la lista resultante. Por ejemplo,
 * halfEven(List(1,2,3,4),List(3,2,4)) == List(2,2)
 * Implementa la función de dos formas
 * c) Mediante una función recursiva de cola, haciendo uso del pattern matching
 * d) Usando únicamente funciones de orden superior (map, filter, etc.)*/

def halfEven_recursiva_cola(l1:List[Int],l2:List[Int]): List[Int] =
  @tailrec
  def aux(acc: List[Int], l1_rest: List[Int], l2_rest: List[Int]): List[Int] =
    (l1_rest, l2_rest) match
      case (Nil, _) | (_, Nil) | (Nil, Nil) => acc
      case (head1 :: tail1, head2 :: tail2) =>
        if ((head1 + head2) % 2 == 0) aux((head1 + head2)/2 :: acc, tail1, tail2)
        else aux(acc, tail1, tail2)
  aux(Nil, l1, l2)

/*
* Con l1.zip(l2) hacemos que se forme una lista de tuplas forma con cada elemento
* en la misma posición con el de la otra lista, hasta que una de las 2 se quede
* sin elementos
* Luego con map sumamos cada par de elementos, formando una lista con cada par de
* elementos sumados
* Luego con filter eliminamos los números impares
* Posteriormente con map dividimos entre 2 los elementos restantes*/
def halfEven_f_orden_superior(l1:List[Int],l2:List[Int]): List[Int] =
  l1.zip(l2).map{
    case (elem1, elem2) => elem1 + elem2
  }.filter(_%2 == 0).map(_/2)

object ejercicio_10 extends App {
  println(halfEven_recursiva_cola(List(1,2,3,4),List(3,2,4)) == List(2,2))
  println(halfEven_recursiva_cola(List(1,2,3,4),List(3,2,4)))

  println(halfEven_f_orden_superior(List(1, 2, 3, 4), List(3, 2, 4)) == List(2, 2))
  println(halfEven_f_orden_superior(List(1, 2, 3, 4), List(3, 2, 4)))
}
