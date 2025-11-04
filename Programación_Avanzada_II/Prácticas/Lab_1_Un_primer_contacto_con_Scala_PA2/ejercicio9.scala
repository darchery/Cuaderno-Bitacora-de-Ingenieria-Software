import scala.annotation.tailrec

object ejercicio9 {
  /*9. Implementa una función recursiva para generar todos los subconjuntos de un conjunto
  determinado. Conviértela en recursiva de cola.
  println(subsets(Set())) // Output: Set(Set())
  println(subsets(Set(1))) // Output: Set(Set(), Set(1))
  println(subsets(Set(1,2))) // Output: Set(Set(),Set(1),Set(2),Set(1,2))
  println(subsets(Set(1, 2, 3)))
  // Output: Set(Set(),Set(1),Set(2),Set(1,2),Set(3),Set(1,3),Set(2,3),Set(1,2,3))*/
  def main(args: Array[String]): Unit = {
    def subsets[A](set: Set[A]): Set[Set[A]] = {
      @tailrec
      def bucle(setRestante: Set[A], accSet: Set[Set[A]]): Set[Set[A]] = {
        // Si está vacío devolvemos el set acumulado
        if (setRestante.isEmpty)
          accSet
        // Si no, continuamos creando el conjunto acumulado
        else
          // Escogemos la cabeza del conjunto restante
          val cabeza = setRestante.head
          // Y dejamos el resto
          val resto = setRestante.tail
          // Llamamos de nuevo a la recursión, con el resto como conjunto restante
          // y anidamos nuestro conjunto acumulado actual más el resultado de la función
          // map sobre ese conjunto, que básicamente devuelve otro conjunto con el
          // conjunto acumulado anidado al elemento que hemos guardado en cabeza, y así
          // con todos los elementos del conjunto
          bucle(resto, accSet ++ accSet.map(_+cabeza))

      }
      bucle(set, Set(Set()))
    }
    println(subsets(Set())) // Output: Set(Set())
    println(subsets(Set(1))) // Output: Set(Set(), Set(1))
    println(subsets(Set(1, 2))) // Output: Set(Set(),Set(1),Set(2),Set(1,2))
    println(subsets(Set(1, 2, 3))) // Output: Set(Set(),Set(1),Set(2),Set(1,2),Set(3),Set(1,3),Set(2,3),Set(1,2,3))
  }
}
/*
Solución 1 (Iterativa)
def subsets[A](set: Set[A]): Set[Set[A]] = {
if (set.isEmpty) Set(Set())
else {
val rest = subsets(set.tail)
rest ++ rest.map(_ + set.head)
}
}

Solución 2 (Recursiva de cola)
def subsets[A](set: Set[A]): Set[Set[A]] = {
@scala.annotation.tailrec
def subsetsAux(set: Set[A], acc: Set[Set[A]]): Set[Set[A]] = {
if (set.isEmpty) acc
else {
val rest = acc.map(_ + set.head)
subsetsAux(set.tail, acc ++ rest)
}
}
subsetsAux(set, Set(Set()))
}*/