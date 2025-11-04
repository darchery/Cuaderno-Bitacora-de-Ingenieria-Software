package pa1_ejercicios_basicos

import scala.annotation.tailrec

/**
 * 10. Escribe una función recursiva de cola generateParentheses(n: Int): List[String] que
 * genere todas las combinaciones válidas de n pares de paréntesis. Ejemplos:
 * println(generateParentheses(3))
 * // Output: Lista("((()))", "((())", "(())", "((())", "()()()")
 * Consejos:
 * • Utiliza un acumulador para almacenar secuencias válidas.
 * • Haz un seguimiento del número de paréntesis de apertura (open) y cierre (closed) utilizados.
 * • Caso base: Cuando open == closed == n, agrega la secuencia al resultado.*/

def generateParentheses(n: Int): List[String] = {
  @tailrec
  def generate(open: Int, close: Int, acc: List[String], stack: List[(String, Int, Int)]): List[String] = {
    stack match {
      case Nil => acc // Base case: no more states to process
      case (current, openLeft, closeLeft) :: rest =>
        if (openLeft == 0 && closeLeft == 0)
          generate(open, close, current :: acc, rest) // Valid sequence found, add to accumulator
        else {
          val newStack =
          (if (openLeft > 0)
            (current + "(", openLeft - 1, closeLeft) :: rest else rest) :::
          (if (closeLeft > openLeft)
            (current + ")", openLeft, closeLeft - 1) :: rest else rest)
          generate (open, close, acc, newStack)
        }
    }
  }
  generate(n, n, List(), List(("", n, n)))
}

object ejercicio_10 extends App {
  println(generateParentheses(3))
  // Output: Lista("((()))", "((())", "(())", "((())", "()()()")
}
