package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 2. Escribe una función recursiva de cola binarySearch(arr: Array[Int], elt: Int):
 * Option[Int] que devuelva el índice de elt (Some(i)) en un array ordenado utilizando el
 * algoritmo de búsqueda binaria, o None en caso de que el elemento no se esté. Ejemplos:
 * val arr = Array(1, 3, 5, 7, 9, 11)
 * println(binarySearch(arr, 5)) // Output: Some(2)
 * println(binarySearch(arr, 10)) // Output: None*/

def binarySearch(arr: Array[Int], elt: Int): Option[Int] =
   @tailrec
   def bucle(array: Array[Int], elem_obj: Int, high: Int, low: Int): Option[Int] =
     if (low > high) None
     else
       val mid = (high + low) / 2
       if (array(mid) == elem_obj ) Some(elem_obj)
       else if (array(mid) < elem_obj) bucle(array, elem_obj, high, mid + 1)
       else bucle(array, elem_obj, mid - 1, low)
   bucle(arr, elt, arr.length - 1, 0)

object ejercicio_2 extends App {
  val arr = Array(1, 3, 5, 7, 9, 11)
  println(binarySearch(arr, 5)) // Output: Some(2)
  println(binarySearch(arr, 10)) // Output: None
}
