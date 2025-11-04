/**
 * 8. Usando foldRight implementa la función
 * def fibonnaci(n:Int):Int
 * que dado un número n calcula el n-ésimo número de Fibonacci. Por ejemplo,
 * fibonacci(5) == 5
 * fibonacci(10) == 55*/

/*
* 1º Caso: si es 0 o menor que 0 => 0
* 2º Caso: si es 1 => prev + curr = 0 + 1 = 1
* 3º Caso: creamos una lista de elementos desde 2 hasta n
* como punto de incio estableceremos una tupla (prev, curr) a (0, 1)
* posteriormente estableceremo solo un solo caso, en el cual
* tendremos una tupla cuyo primer elemento es cualquiera y el segundo
* será otra tupla con (prev, curr). Posteriormente asignamos ese primer
* valor de la tupla a curr y el segundo la suma de prev + curr
* (fibRes = fibAnterior + fibActual)*/

def fibonacci(n: Int): Int =
  if (n <= 0) 0
  else if( n == 1) 1
  else
    (2 to n).foldRight(0, 1) {
      case (_, (prev, curr)) => (curr, prev + curr)
    }._2

object ejercicio_8 extends App {
  println(fibonacci(5) == 5)
  println(fibonacci(10) == 55)
}
