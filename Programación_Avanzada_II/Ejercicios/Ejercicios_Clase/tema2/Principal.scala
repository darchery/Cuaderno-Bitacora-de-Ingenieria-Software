package tema2

import scala.annotation.tailrec

def factIter(n: Int): BigInt =
  require(n >= 0)
  var fact: BigInt = 1
  for (i <- 1 to n) fact = fact * i
  fact

// Versión recursiva normal
def factRec(n: Int): BigInt =
  require(n >= 0)
  if (n == 0 ) 1
  else n * factRec(n - 1)

def fact(n: Int): BigInt =
  def bucle(i: Int, f: BigInt): BigInt =
    // fact = i!
    if (i == n) f
    else bucle(i+1, f*(i + 1))
  bucle(0,1)

// Recursividad de cola
def factorial(x: Int): Int =
  @tailrec
  def aux(acc: Int, i: Int): Int =
    // Caso base
    if i == 0 then acc
    // multiplicamos el acc por el factorial de ese ciclo y restamos uno al factorial i
    else aux(acc*i, i-1)
  require(x>=0, "Número negativo")
  aux(1, x)

def fibRec(n: Int): Int =
  if (n == 0 || n == 1) n
  else fibRec(n - 1) + fibRec(n - 2)

def fib(n: Int): Int =
  def bucle(i: Int, fibi: Int, fib1: Int): Int =
    // fibi = fib(i), fib1 = fib(i - 1)
    if (i == n) fibi
    else bucle(i + 1, fibi + fib1, fibi)
  if (n == 0) 0
  else bucle(1, 1, 0)  

def formatoFact(n: Int): String =
  s"El factorial de $n es ${fact(n)}"

def formatoFib(n: Int): String =
    s"El fibonacci de $n es ${fib(n)}"

def formato(n: Int, nombre: String, f: Int => Int) =
  s"El $nombre de $n es ${f(n)}"

def buscarPos(v: Array[Int], elem: Int): Int =
  def bucle(i: Int): Int =
    // No está(si se sale)
    if(i >= v.length) -1
    // Case base: caso encontrado  
    else if (v(i) == elem) i
    // Si no, avanzamos en el bucle
    else bucle(i+1)
  bucle(0)

def buscar[A](v: Array[A], cond: A => Boolean )=
  def bucle(i: Int): Int =
    if (i >= v.length) -1
    else if (cond(v(i))) i
    else bucle(i + 1)
  bucle(0)

object Principal extends App  {

}
