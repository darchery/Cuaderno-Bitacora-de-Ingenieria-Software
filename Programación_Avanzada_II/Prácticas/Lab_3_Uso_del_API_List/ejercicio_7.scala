object ejercicio_7 {
  /**
   * 7. Usando foldRight implementa la función
   * def remdups[A](lista:List[A]):List[A]
   * que elimina los duplicados adyacentes de la lista. Por ejemplo,
   * remdups(List(1,1,3,3,3,2,1,2,2,1,2)) == List(1, 3, 2, 1, 2, 1, 2)*/
  
  def main(args: Array[String]): Unit = {

    // NO USADOS, solo para mejor entendimiento
    def copia[A](l: List[A]): List[A] =
      l.foldRight[List[A]](List()) {(elem, acc) =>
        elem :: acc
      }

    def copiaPares(l: List[Int]): List[Int] =
      /*l.foldRight[List[Int]](List()) { (acc, elem) =>
        (acc :: elem).filter((x: Int) => x % 2 == 0)
      }*/
      // otra implementación
      l.foldRight[List[Int]](List()) { (elem, acc) =>
        if (elem % 2 == 0) elem :: acc
        else acc
      }

    // Comprobamos que el elemento elem no coincide con la cabeza de la lista
    // que estamos creando de derecha a izquierda
    def remdups[A](l: List[A]): List[A] =
      l.foldRight[List[A]](Nil) { (elem, acc) =>
        if (acc.isEmpty || acc.head != elem) elem :: acc
        else acc
      }

    var listaCopia = List(1, 2, 3, 4)

    println(copia(listaCopia))
    println(copiaPares(listaCopia))

    println(remdups(List(1,1,3,3,3,2,1,2,2,1,2)))
    println(remdups(List(1,1,3,3,3,2,1,2,2,1,2)) == List(1, 3, 2, 1, 2, 1, 2))
  }
}