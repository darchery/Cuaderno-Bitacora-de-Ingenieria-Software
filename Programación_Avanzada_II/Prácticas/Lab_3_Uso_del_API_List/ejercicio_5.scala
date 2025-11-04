
/**
 * 5. Usando foldRight implementa la función
 * def unzip[A](l:List[(A,B)]):(List[A],List[B])
 * que dada una lista de tuplas List((a1, b1), …, (an, bn)) devuelve dos listas de la forma List(a1,
 * …, an) y List(b1, …, bn). Ejemplo:
 * * unzip(List((1,’a’),(2,’b’),(3,’c’))) == (List(1,2,3), List(‘a’,‘b’,‘c’))*/

// Función para el entendimiento => NO USADA
def unzipAux[A, B](a: (A, B), b: (A, B)): (List[A], List[B]) =
  (List(a._1, b._1), List(a._2, b._2))

def unzip[A, B](l: List[(A, B)]): (List[A], List[B]) =
  l.foldRight( (List[A](), List[B]()) ) { (elem , acc) =>
    (elem._1 :: acc._1 , elem._2 :: acc._2)
  }

/*def unzip[A, B](l: List[(A, B)]): (List[A], List[B]) =
  l.foldRight[(List[A], List[B])](Nil, Nil) { (elem, acc) =>
    (elem._1 :: acc._1, elem._2 :: acc._2)
  }*/


object main extends App {
  println(unzip(List((1,'a'),(2,'b'),(3,'c'))) == (List(1,2,3), List('a','b','c')))
}
