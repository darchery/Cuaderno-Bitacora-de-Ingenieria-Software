import scala.annotation.tailrec

/**
 * 4. Define la función
 * def f(l:List[Int]):List[Int]
 * que dada la lista l construye una lista con los valores absolutos de los elementos negativos de l. Por
 * ejemplo,
 * f(List(1,-2,3,-4,-5,6)) == List(2,4,5)
 * Implementa la función de dos formas
 * a) Mediante una función recursiva de cola, haciendo uso del pattern matching
 * b) Usando únicamente funciones de orden superior (map, filter, etc.)*/

/*
* acc -> resultado
* rest -> restante por analizar*/
def f_recusivaCola_versionA(l:List[Int]):List[Int] =
  @tailrec
  def aux(acc: List[Int], rest: List[Int]): List[Int] =
    rest match
      case Nil => acc.reverse
      case head :: tail =>
        if (head >= 0) aux(acc, tail)
        else aux(math.abs(head) :: acc, tail)
  aux(Nil, l)

/*
* Primero aplicaré filter para eliminar los elementos positivos
* Por último aplicaré una función map para hacer el absoluto de cada número*/
def f_ordenSuperior_versionB(l:List[Int]):List[Int] =
  l.filter(_<0)
    .map(x => math.abs(x))

object ejercicio_4 extends App {
  println(f_recusivaCola_versionA(List(1,-2,3,-4,-5,6)) == List(2,4,5))
  println(f_recusivaCola_versionA(List(1,-2,3,-4,-5,6)))
  println("\n")
  println(f_ordenSuperior_versionB(List(1,-2,3,-4,-5,6)) == List(2,4,5))
  println(f_ordenSuperior_versionB(List(1,-2,3,-4,-5,6)))
}
