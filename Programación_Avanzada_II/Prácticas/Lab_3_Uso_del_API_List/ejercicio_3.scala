/**
 * 3. Utilizando foldLeft o foldRight define la función
 * def existe[A](l:List[A],f:A=>Boolean):Boolean
 * que comprueba si l tiene un elemento que satisface f. Ejemplos:
 * existe(List(1,2,3),_>2) == true
 * existe(List(“Hola”,”Mundo”),_.length>=5) == true
 * existe(List(“Hola”,”Mundo”),_.length<3) == false*/

/*
* Empezamos con false como resultado, ya que si está vacía necesitamos el false.
* Luego operamos con or siempre ya que nos vale con que alguna de las operaciones sea
* true, ya sea el valor anterior o el actual producto de f(elem), por lo tanto la unica
* manera de que sea falso el resultado es que ambas lo sean*/
def existe[A](l: List[A], f: A => Boolean): Boolean =
  l.foldRight(false) { (elem, found) =>
    f(elem) || found
  }

object ejercicio_3 extends App {
  println(existe(List(1,2,3),_>2) == true)
  println(existe(List("Hola","Mundo"),_.length>=5) == true)
  println(existe(List("Hola","Mundo"),_.length<3) == false)
}
