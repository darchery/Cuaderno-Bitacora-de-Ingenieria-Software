/**1. Utilizando foldRight, define las funciones
 def sum(l:List[Int]):Int
 def product(l:List[Int]):Int
 def length[A](l:List[A]):Int
 que, respectivamente, suman/multiplican los elementos de la lista l, y calculan su longitud, respectivamente.
 Ejemplos:
 sum(List(1,2,3)) == 6
 product(List(1,3,5)) == 15
 length(List(“Hola”, “ ”, “Mundo”)) == 3*/

def sum(l: List[Int]): Int =
  l.foldRight(0) { (elem, acc) => elem + acc }

def product(l: List[Int]): Int =
  l.foldRight(1) { (elem, acc) => elem + acc }

def length[A](l:List[A]): Int =
  l.foldRight(0) { (_, acc) => 1 + acc }

object ejercicio_1 extends App{
  println(sum(List(1, 2, 3)) == 6)
  println(product(List(1, 3, 5)) == 15)
  println(length(List("Hola", "", "Mundo") ) == 3)
}
