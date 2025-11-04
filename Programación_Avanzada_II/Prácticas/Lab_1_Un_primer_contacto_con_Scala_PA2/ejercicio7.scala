import scala.annotation.tailrec

object ejercicio7 {
  /*7. Implementa una operación groupBy(l, f) que tome como argumentos una lista l de elementos de
  tipo A y una función f: A => B y que devuelva un objeto de tipo Map[B, List[A]] que asocie una lista
  con los elementos e de l con el mismo f(e).
  println(groupBy(List(1,2,3,4,5), _ % 2 == 0))
  // Output: Map(false -> List(5, 3, 1), true -> List(4, 2))*/
  def main(args: Array[String]): Unit = {
    def groupBy[A, B](list: List[A], f: A => B): Map[B, List[A]] = {
      @tailrec
      def bucle(auxList: List[A], map: Map[B, List[A]]): Map[B, List[A]] = {
        auxList match
          // Si no hay más elementos en la lista
          case Nil => map
          // Dividimos el primer elemento de la lista y el resto
          case head :: tail =>
            // Obtenemos las claves B
            val clave = f(head)
            // Añadimos al mapa con esa clave su respectivo valor A anidado a su anterior lista
            val mapaActualizado =  map.updated(clave, head :: map.getOrElse(clave, Nil))
            // recursión
            bucle(tail, mapaActualizado)
      }
      // Inicialización del bucle
      bucle(list, Map.empty[B, List[A]])
    }
    println(groupBy(List(1,2,3,4,5), _ % 2 == 0))
  }
}

/*
Solución 1 (Iterativa – Map mutable)
def groupBy[A,B](l:List[A], f: A => B): Map[B, List[A]] =
val map = collection.mutable.Map[B, List[A]]()
for e <- l do
val key = f(e)
if map.contains(key) then
map(key) = e :: map(key)
else
map(key) = List(e)
map.toMap

Solución 2 (Recursiva de cola – Map inmutable)
def groupBy[A,B](l: List[A], f: A => B): Map[B, List[A]] =
@annotation.tailrec
def loop(l: List[A], f: A => B, m: Map[B, List[A]]): Map[B, List[A]] =
if l.isEmpty then m
else loop(l.tail, f, m.updated(f(l.head), m.getOrElse(f(l.head), Nil)
:+ l.head))
loop(l, f, Map.empty)*/