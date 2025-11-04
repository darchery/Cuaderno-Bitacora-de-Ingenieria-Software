/**
 * 9. Usando foldRight implementa la función
 * def inits[A](l:List[A):List[List[A]]
 * que construye una lista con todas las listas prefijos de l. Por ejemplo,
 * inits(List(1,2,3)) == List(List(),List(1),List(1,2),List(1,2,3))
 * inits(List(3)) == List(List(),List(3))
 * inits(List()) == List(List())*/

// Versión sin foldRight
/*def inits[A](l: List[A]): List[List[A]] =
  def aux(acc: List[List[A]], rest: List[A]): List[List[A]] =
    rest match
      case Nil => acc
      case _ => aux(rest :: acc, rest.init)
      /*
      * Va uniendo la lista completa con acc, y como resto coges
      * la lista entera SIN el último elemento*/
  aux(List(Nil), l) // Se inicia con la lista completa y se va reduciendo*/

def inits[A](l:List[A]): List[List[A]] =
  l.foldRight(List(List[A]())) { (elem, acc) =>
    Nil :: acc.map(elem :: _)
  }
  /*
  * A cada iteración le concatenas la lista vacía(para incluirla en la lista) concatenado con
  * la función map de concatenar a todas las listas de la lista el elem*/

object ejercicio_9 extends App {
  println(inits(List(1,2,3)) == List(List(),List(1),List(1,2),List(1,2,3)))
  println(inits(List(1,2,3)))
  println(inits(List(3)) == List(List(),List(3)))
  println(inits(List()) == List(List()))
}
