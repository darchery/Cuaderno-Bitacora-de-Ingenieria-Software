/**2. Utilizando foldLeft o foldRight define las funciones
 def reverse[A](l:List[A]):List[A]
 def append[A](l1:List[A],l2:List[A]):List[A]
 que calculan la longitud de la lista l y la invierten. Ejemplos:
 reverse(List(1,2,3)) == List(3,2,1)
 append(List(1,2,3),List(1,2)) == List(1,2,3,1,2)*/


/*
* Supongamos que los ejemplos se realizan con una List(1, 2, 3)
*
* Como empieza por la izquierda(izq-der) hace lo siguiente:
* 3 :: (2 :: (1 :: Nil)), lo que da como resultado una lista inversa
*
* Si usase foldRight empezaría por la derecha(der-izq):
* 1 :: (2 :: (3 ::Nil)), por lo tanto, quedaría una copia de la lista*/

def reverse[A](l:List[A]):List[A] =
  l.foldLeft[List[A]](Nil) { (acc, elem) =>
    elem :: acc
  }

def append[A](l1:List[A],l2:List[A]):List[A] =
  l2.foldLeft(l1) { (acc, elem) =>
    /*println(s"añadido: ${elem}")
    println(s"listaActual: ${elem :: acc}")*/
    acc ++ List(elem)
  }

object ejercicio_2 extends App {
  println(reverse(List(1,2,3)) == List(3,2,1))
  println(append(List(1,2,3),List(1,2)) == List(1,2,3,1,2))
  println(append(List(1,2,3),List(1,2)))
}
