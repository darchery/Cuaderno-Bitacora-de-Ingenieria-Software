/**
 * Usando foldRight implementa la función
 * def compose[A](lf:List[A=>A],v:A):Boolean
 * que dada una lista de funciones List(f1,f2,..,fn) y un valor v calcula f1(f2(…fn(v))…). Por
 * ejemplo,
 * compose(List[Int => Int](Math.pow(_,2).toInt, _+2), 5) == (5+2)^2 == 49*/

/*
* Empezamos por el elemento v, calculando el resultado de cada función de 
* la lista de funciones, empezando por la derecha*/
def compose[A](lf: List[A=>A],v: A): A =
  lf.foldRight(v) { (elem_f, acc) => elem_f(acc)}

object ejercicio_6 extends App {
  // Lista de funciones con 2 funciones:
  // Elevar al cuadrado
  // Sumar 2
  println(compose(List[Int => Int](Math.pow(_,2).toInt, _+2), 5) == 49)
}
