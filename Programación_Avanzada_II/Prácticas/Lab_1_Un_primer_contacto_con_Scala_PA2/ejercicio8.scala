object ejercicio8 {
  /*8. Implementa una operación reduce(l, f) que toma como argumentos una lista l de elementos de tipo
  A y una función f de tipo (A, A) => A y que devuelva el resultado de combinar todos los elementos
  de l utilizando la función f. Por ejemplo:
  println(reduce(List(1,2,3,4,5), _ + _)) // Output: 15*/
  def main(args: Array[String]): Unit = {
    def reduce[A](list: List[A], f: (A, A) => A): A = {
      list match
        // Si solo queda un elemento => devolvemos ese elemento
        case head :: Nil => head
        // Si no, partimos la lista y aplicamos al primer elemento la función con su
        // respectiva llamada recursiva con el resto de la lista
        case head :: tail => f(head, reduce(tail, f))
    }
    println(reduce(List(1,2,3,4,5), _ + _)) // Output: 15
  }
}
/*
Solución 1 (Iterativa)
def reduce[A](l:List[A], f: (A, A) => A): A =
require(l.nonEmpty)
var acc = l.head
for e <- l.tail do
acc = f(acc, e)
acc

Solución 2 (Recursiva de cola)
def reduce[A](l: List[A], f : (A,A) => A) : A =
@annotation.tailrec
def loop(l : List[A], f: (A,A) => A, res: A) : A =
if l.isEmpty then res
else loop(l.tail, f, f(res,l.head))
loop(l.tail, f, l.head)*/