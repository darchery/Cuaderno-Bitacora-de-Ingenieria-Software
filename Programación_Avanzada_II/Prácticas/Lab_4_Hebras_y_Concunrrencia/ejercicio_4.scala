import libreria_local.*

object ejercicio_4 {
  def fibonacci(n: Int): (Int, Int) = {
    if (n == 1)
      // Log del resultado
      log(s"${Thread.currentThread().getName}: fib(1) = 1")
      (1, 0)
    else
      // Creamos la hebra
      val t = thread {
        // Este será su body(que por ahora NO se ejecuta)
        fibonacci(n-1)
      }
      // Se una la hebra
      t.join()

      // Calculamos  su resultado en este paso
      val (fibN1, fibN2) = fibonacci(n-1)
      val fibN = fibN1 + fibN2
      // Imprimos por pantalla
      log(s"${Thread.currentThread().getName}: fib($n) = $fibN")
      (fibN, fibN1)
  }

  def main(args: Array[String]): Unit = {
    val n = 7
    val (fibN, _) = fibonacci(n)
    log(s"main: fib($n) = $fibN")
    log("Fin")
  }
}
