import scala.annotation.tailrec

object ejercicio2 {
  /*2. Escribe una función recursiva de cola binarySearch(arr: Array[Int], elt: Int):
    Option[Int] que devuelva el índice de elt (Some(i)) en un array ordenado utilizando el
  algoritmo de búsqueda binaria, o None en caso de que el elemento no se esté. Ejemplos:*/
  def main(args: Array[String]): Unit = {
    def binarySearch(arr: Array[Int], elt: Int): Option[Int] = {
      @tailrec
      def bucle(array: Array[Int],elt: Int,low: Int, high: Int): Option[Int] = {
        if (low > high) None
        else 
          val mid = low + (high - low)/2
          // ó val mid = (low + high) / 2

          // Elegimos el medio del array y usamos match
          arr(mid) match {
            // Si es igual devolvemos Some(índice)
            case x if x == elt => Some(mid)
            // Si es menor, actualizamos low -> mid + 1
            case x if x < elt => bucle(array, elt, mid + 1, high)
            // Si no es mayor, actualizamos high -> mid - 1
            case _ => bucle(array, elt, low, mid - 1)
        }
      }
      // Iniciamos con el array ordenado(muy importante), el elemento a buscar
      // el 0(low -> primer índice array) y el último índice del array
      bucle(arr, elt, 0, arr.length - 1)
    }
    
    // NO DA EL RESULTADO ESPERADO PARA EL PRIMER TEST
    
    val arr = Array(1, 3, 5, 7, 9, 11)
    println(binarySearch(arr, 5)) // Output: Some(2)
    println(binarySearch(arr, 10)) // Output: None
  }
} 