package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 1. Escribe una función recursiva de cola primeFactors(n: Int): List[Int] que devuelva una
 * lista con los factores primos de un entero positivo dado n. Ejemplos:
 * println(primeFactors(60)) // Output: List(2, 2, 3, 5)
 * println(primeFactors(97)) // Output: List(97)
 * println(primeFactors(84)) // Output: List(2, 2, 3, 7)*/

def primeFactors(n: Int): List[Int] =
  @tailrec
  def bucle(acc: List[Int], dividendo: Int, divisor: Int): List[Int] =
    if (divisor > dividendo) acc.reverse
    else if(dividendo % divisor == 0) bucle(divisor :: acc, dividendo/divisor, divisor)
    else bucle(acc, dividendo, divisor + 1)
  bucle(Nil, n, 2)

object ejercicio_1 extends App {
  println(primeFactors(60))
  println(primeFactors(97))
  println(primeFactors(84))
}
