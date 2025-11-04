import scala.annotation.tailrec

object ejercicio1 {
  /*1. Escribe una función recursiva de cola primeFactors (n: Int): List[Int] que devuelva una
    lista con los factores primos de un entero positivo dado n.Ejemplos: */
  def main(args: Array[String]): Unit = {
    def primeFactors(n: Int): List[Int] = {
      def bucle(dividend: Int, divisor: Int): List[Int] = {
        // Caso base: para evitar que aparezca 1 como divisor(1 es divisor de todos los números)
        if (divisor * divisor > dividend) List(dividend)
        // Si es divisible: devolvemos una lista con el divisor al principio anidada a
        // la lista que será producida por la recursividad
        else if (dividend % divisor == 0) divisor :: bucle(dividend/divisor, divisor)
        // Si no es divisible, se llama otra vez al bucle con otro divisor  
        else bucle(dividend, divisor + 1)
      }
      bucle(n, 2)
    }
    println(primeFactors(97)) // Output: List(97)
    println(primeFactors(84)) // Output: List(2, 2, 3, 7)
    println(primeFactors(60)) // Output: List(2, 2, 3, 5)
  }
}