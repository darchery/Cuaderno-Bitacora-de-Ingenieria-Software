import scala.annotation.tailrec

// DISCLAIMER: NO ES RECURSIVA DE COLA
object ejercicio10 {
  /*10. Escribe una función recursiva de cola generateParentheses(n: Int): List[String] que
  genere todas las combinaciones válidas de n pares de paréntesis. Ejemplos:
  println(generateParentheses(3))
  // Output: Lista("((()))", "((())", "(())", "((())", "()()()")
  Consejos:
  • Utiliza un acumulador para almacenar secuencias válidas.
  • Haz un seguimiento del número de paréntesis de apertura (open) y cierre (closed) utilizados.
  • Caso base: Cuando open == closed == n, agrega la secuencia al resultado.*/
  def main(args: Array[String]): Unit = {
    def generateParentheses(n: Int): List[String] = {
      def bucle(actual: String, open: Int, closed: Int, res: List[String]): List[String] = {
        // Caso base: agregamos la secuencia al resultado
        if (open == n && closed == n ) res :+ actual
        // Ahora debemos añadir más secuencias
        else {
          // Podemos añadir paréntesis de apertura?
          val apertura =
            if (open < n) bucle(actual + "(", open + 1, closed, res)
            // Si no, devolvemos lo anterior
            else res
          // Podemos añadir paréntesis de cierre?(aquí el nuevo res es apertura)
          val cierre =
            if (closed < open) bucle(actual + ")", open, closed + 1, apertura)
            // Si no, devolvemos el anterior cambio: la apertura
            else apertura
          // Devolvemos el resultado acumulado(aquí el nuevo res es cierre)
          cierre
        }
      }
      // Empezamos con la cadena a crear vacía, con contadores de paréntesis
      // en cero y una lista vacía
      bucle("",0, 0, List())
    }
    println(generateParentheses(3))
    // Output: Lista("((()))", "((())", "(())", "((())", "()()()")
  }
}
/*Solución (Recursiva de cola)
def generateParentheses(n: Int): List[String] = {
@scala.annotation.tailrec
def generate(open: Int, close: Int, acc: List[String], stack:
List[(String, Int, Int)]): List[String] = {
stack match {
case Nil => acc // Base case: no more states to process
case (current, openLeft, closeLeft) :: rest =>
if (openLeft == 0 && closeLeft == 0)
generate(open, close, current :: acc, rest) // Valid sequence
found, add to accumulator
else {
val newStack =
(if (openLeft > 0) (current + "(", openLeft - 1, closeLeft)
:: rest else rest) :::
(if (closeLeft > openLeft) (current + ")", openLeft,
closeLeft - 1) :: rest else rest)
generate(open, close, acc, newStack)
}
}
}
generate(n, n, List(), List(("", n, n)))
}*/