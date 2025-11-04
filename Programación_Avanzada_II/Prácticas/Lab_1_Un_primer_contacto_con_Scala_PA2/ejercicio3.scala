import scala.annotation.tailrec

object ejercicio3 {
  /*3. Define una función recursiva genérica unzip que tome una lista de tuplas con dos componentes y
  que devuelva una tupla con dos listas: una con las primeras componentes y otra con las segundas.
  Por ejemplo,
  unzip(List((10, 'a'), (20, 'b'), (10, 'c'))
  == (List(10, 20, 30), List('a', 'b', 'c'))*/
  def main(args: Array[String]): Unit = {
    def unzip[A, B](list: List[(A, B)]): (List[A], List[B]) = {
      @tailrec
      def unzipAux[A, B](listAux: List[(A, B)], acc1: List[A], acc2: List[B]): (List[A], List[B]) = {
        listAux match
          // Caso base: devuelve la lista al revés, para ponerlos en orden
          case Nil => (acc1.reverse, acc2.reverse)
          // Descompongo la tupla en a y b, le pasamos la cola como siguiente lista a analizar,
          // anidamos el primer elemento a la primera lista
          // y anidamos el segundo elemento a la segunda lista
          case (a, b) :: tail => unzipAux(tail, a :: acc1, b :: acc2)
      }
      unzipAux(list, List.empty[A], List.empty[B])
    }
    println(unzip(List((10, 'a'), (20, 'b'), (30, 'c'))))
  }
}
/*
* Solución 1 (Pattern matching)
def unzip[A,B](l:List[(A,B)]): (List[A], List[B]) =
l match
case Nil => (Nil, Nil)
case (a, b) :: t =>
val (as, bs) = unzip(t)
(a :: as, b :: bs)

Solución 2 (Iterativa)
def unzip[A,B](l: List[(A,B)]): (List[A], List[B]) =
var l0 = List[A]()
var l1 = List[B]()
for (e <- l)
l0 = l0 :+ e(0)
l1 = l1 :+e(1)
(l0, l1)

Solución 3 (Recursiva de cola)
def unzip[A,B](l: List[(A,B)]) : (List[A],List[B]) =
@annotation.tailrec
def go(l: List[(A,B)], la: List[A], lb: List[B]) : (List[A], List[B]) =
if l.isEmpty then (la,lb)
else go(l.tail, la :+ l.head(0), lb :+ l.head(1))
go(l, Nil, Nil)*/