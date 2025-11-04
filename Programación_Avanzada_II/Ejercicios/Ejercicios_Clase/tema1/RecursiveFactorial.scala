package tema1

object RecursiveFactorial {
  def factorial(x: BigInt): BigInt =
    if (x == 0)
      1
    else
      x * factorial(x - 1)

  def main(args: Array[String]): Unit =
    println(factorial(7))
}


