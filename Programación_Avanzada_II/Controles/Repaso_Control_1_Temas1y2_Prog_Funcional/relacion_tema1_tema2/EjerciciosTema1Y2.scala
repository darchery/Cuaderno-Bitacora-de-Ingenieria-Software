package pa1_ejercicios_basicos

import java.lang.Math.*
import scala.annotation.tailrec

/* 10. Crea una clase Complejo que admita:
 sumas, restas, multiplicaciones y módulo */
class Complejo(real: Int, imaginary: Int) {
  val r = real
  val i = imaginary

  override def toString: String = s"z = ${r} + ${i}i"

  def suma(complejo: Complejo): Complejo =
    new Complejo(r + complejo.r, i + complejo.i)

  def resta(complejo: Complejo): Complejo =
    new Complejo(r - complejo.r, i - complejo.i)

  def producto(complejo: Complejo): Complejo =
    new Complejo((r * complejo.r) - (i * complejo.i), (r * complejo.i) + (i * complejo.r))

  def modulo(): Double =
    sqrt(r * r + i * i)
}

object Funciones {
  /* 1. Implementa una función que compruebe si una cadena es un palíndromo(ignorando
     mayúsculas y minúsculas y espacios). Nota: utilizar las funciones de la librería
     para la clase String.*/
  def palindromos(palabra: String): Boolean =
    /*if (palabra.compareToIgnoreCase(palabra.reverse) == 0) true
    else false*/
    // ó
    (palabra.reverse.toLowerCase == palabra.toLowerCase)

  /* 2. Crea un programa que imprima los primeors n números primos */
  def isPrime(n: Int): Boolean =
    var prime = true

    for (i<-2 to sqrt(n).toInt if prime )
      if (n%i == 0) prime = false
    prime

  def primerosPrimos(n: Int): Unit =
    for (i<-2 to n)
      if (isPrime(i)) print(i + " ")

  /* 3. Implementa un programa que calcule el máximo común divisor(MCD) y el mínimo
     común múltiplo(MCM) de 2 números. Nota: el tipo devuelto por la función es una
     tupla de 2 componentes*/
  def maximoMinimo(n1: Int, n2: Int): (Int, Int) =
    var mcd = 0
    var mcm = 0
    var found = false

    // Máximo común divisor de 2 números: el primer divisor de ambos
    // Elegime el mínimo posible como primer posible divisor
    var i = math.min(n1, n2)
    while (i >= 1 && !found)
      if (n1%i == 0 && n2%i == 0)
        found = true
        mcd = i
      i -= 1

    // Mínimo común multiplo de 2 números: el mínimo primer multiplo de ambos
    // Fórmula -> MCM = (n1 * n2) / MCD
    // mcm = (n1 * n2) / mcd , diseño alternativo
    // Necesitamos localizar el número más grande
    mcm = math.max(n1, n2)
    while (mcm%n1 != 0 || mcm%n2 != 0)
      mcm += 1


    // Creación de la tupla
    val mcdMcm = (mcd, mcm)
    mcdMcm

  /* 4. Implementa una función que encuentre el segundo elemento más grande de una
  * lista. Nota: Utilizar las funciones de la clase List */
  def segundoElemento(l: List[Int]): Int =
    val newList = l.filter(_!=l.max)
    newList.max

  /* 5. Escribe un programa que elimine todos los duplicados de una lista(sin usar
  *  funciones predifinidas como distinct) */


  def eliminarDuplicados(l: List[Int]): List[Int] =
    // Recursiva de cola
    @tailrec
    def bucle(acc: List[Int], rest: List[Int]): List[Int] =
      rest match
        case Nil => acc
        case head :: tail =>
          if (!acc.contains(head)) bucle(acc ++ List(head), tail)
          else bucle(acc, tail)
    bucle(Nil, l)

  // Versión iterativa
   /*var newL = List[Int]()

    for (elem <- l)
      if (!newL.contains(elem))
        newL = newL :+ elem
    newL*/

  /* 6. Implementa una función que gire una lista k posiciones a la derecha(por ejemplo,
  *  [1, 2, 3, 4, 5] rotado en 2 se convierte en [4, 5, 1, 2, 3])*/
  def gira(l: List[Int], k: Int): List[Int] =
    if (l.isEmpty || k == 0) l
    else
      // Normalizamos con el módulo de la longitud de la lista para no salirnos
      // de los bordes
      val desplazamiento = k % l.length
      // Dividimos en 2 la lista para reposicionar, divide desde los n primeros elementos
      // en este caso los primeros l.length - desplazamiento elementos
      val (parteFinal, parteInicial) = l.splitAt(l.length - desplazamiento)
      parteInicial ++ parteFinal

  /* 7. Implementa un programa que compruebe si 2 listas son permutaciones entre sí,
  *  sin ordenar las listas */
  def esPermutación(l1: List[Int], l2: List[Int]): Boolean =
    /*var found = true

    for (i<-0 until l1.length if found)
      // Repeticiones de un elemento de l1
      val countL1 = l1.count((x: Int) => x == l1(i))
      // Repeticiones de l1(1) en l2
      val countL2 = l2.count((x: Int) => x == l1(i))

      // Si tienen la misma cantidad, para todos los elementos son permutacion
      // si no, cambiamos elm boolean a false
      if (countL1 != countL2) found = false
    found*/

    // ó ordenamos las listas y vemos si son iguales
    l1.sortWith((x: Int, y: Int) => x < y) ==  l2.sortWith((x: Int, y: Int) => x < y)


  /* 8. Implementa una función que comprima una cadena mediante la codificación de
  *  de longitud de ejecución(por ejemplo, aaabbc -> a3b2c1) */
  def comprime(str: String): String =
    val compress = new StringBuilder()

    for (i<-0 until str.length)
      if (!compress.contains(str.charAt(i)))
        compress.append(s"${str.charAt(i)}${str.count((x: Char) => x == str.charAt(i))}")
    compress.toString()

  /* 9. Implementa un programa que encuentre el caracter que aparece con más frecuencia
  *  en una cadena(si hay más de un carácter, devolver cualquiera)*/
  def masFrecuente(str: String): Char =
    var frecuencia = Integer.MIN_VALUE
    var c = ' '

    for (i <- 0 until str.length)
      if(frecuencia < str.count((x: Char) => x == str.charAt(i)))
        c = str.charAt(i)
        frecuencia = str.count((x: Char) => x == str.charAt(i))
    c

  /* 10. Crea una clase Complejo que admita sumas, restas, multiplicaciones y módulo */
  // Arriba está la solución

  /* 11. Implementa una función recursiva que devuelve la suma de dígitos de un entero
  *  dado. Conviertela en recursiva de cola.*/

  // Versión recursiva de cola
  def sumaDigitos(n: Int): Int =
    @tailrec
    def bucle(acc: Int, n_rest: Int): Int =
      if (n_rest == 0) acc
      else bucle(acc + n_rest%10, n_rest/10)
    require(n >= 0, "Número negativo")
    bucle(0, n)

  // NO COLA
  def sumaDigitosNoCola(n: Int): Int =
    if(n == 0) 0
    else n%10 + sumaDigitosNoCola(n/10)

  /* 12. Define una función recursiva de cola def sumaCuadrados(List[Int]): Int que
  *  calcule la suma de los elementos de la lista de enteros que recibe como argumentos*/
  def sumaCuadrados_v2(l: List[Int]): Int =
    @tailrec
    def bucle(acc: Int, l_resto: List[Int]): Int =
      l_resto match
        case Nil => acc
        case head :: tail => bucle(acc + head*head, tail)
    bucle(0, l)

  def sumaCuadrados(l: List[Int]): Int =
    @tailrec
    def bucle(res: Int, n: Int): Int =
      // Caso base
      if (n == 0) res + l(0)*l(0)
      else bucle(res + pow(l(n), 2).toInt, n - 1)
    require(!l.isEmpty, "Lista vacía")
    bucle(0, l.length - 1)

/* 13. Define una función recursiva de cola que tome un entero n mayor o igual que 0
*  y devuelva una lista con los números naturales desde 0 a n*/
// Versión cola
  def crearLista(n: Int): List[Int] =
    @tailrec
    def bucle(acc: List[Int], n_resto: Int): List[Int] =
      if (n_resto == 0) List(0) ++ acc
      else bucle(List(n_resto) ++ acc, n_resto - 1)
    require(n > 0, "Número menor o igual a cero")
    bucle(Nil, n)

  // NO COLA
  def crearListaNoCola(n: Int): List[Int] =
    if (n == 0) List[Int](0)
    else crearListaNoCola(n-1) ++ List[Int](n)
}

object EjerciciosTema1Y2 extends App{
import Funciones.*

// 1.
println(palindromos("Ana"))
// 2.
println(primerosPrimos(20))
// 3.
println(s"El mcd de 2 y 3 es: ${maximoMinimo(2, 3)._1}")
println(s"El mcm de 2 y 3 es: ${maximoMinimo(2, 3)._2}")
println(s"El mcd de 8 y 56 es: ${maximoMinimo(8, 56)._1}")
println(s"El mcm de 8 y 56 es: ${maximoMinimo(8, 56)._2}")
// 4.
println(s"El segundo elemento más grande de la lista (1,2,3) es: ${segundoElemento(List(1,2,3))}")
// 5.
println(s"Lista ${List(2, 4, 1, 2, 3 ,1 , 5)} sin duplicados: ${eliminarDuplicados(List(2, 4, 1, 2, 3 ,1 , 5))}")
// 6.
println(s"La lista del 1 al 5 girada a la derecha 2 veces es: ${gira(List(1,2,3,4,5),2)}")
// 7.
println(s"La lista (1,2,3,4,5) y (5,1,3,4,2) son permutaciones entre sí: ${esPermutación(List(1,2,3,4,5),List(5,1,3,4,2))}")
// 8.
println(s"aaabbc comprimido es: ${comprime("aaabbc")} ")
// 9.
println(s"Char mas frecuente en bbccaaab es: ${masFrecuente("bbccaaab")}")
// 10.
val complejo1 = Complejo(2, 3)
val complejo2 = Complejo(1, 2)
println(s"toString: ${complejo1}")
println(s"Suma: ${complejo1} + ${complejo2} es: ${complejo1.suma(complejo2)}")
println(s"Resta: ${complejo1} - ${complejo2} es: ${complejo1.resta(complejo2)}")
println(s"Producto: ${complejo1} * ${complejo2} es: ${complejo1.resta(complejo2)}")
println(s"Modulo: ${complejo1}: ${complejo1.modulo()}")

// 11.
println(s"COLA: Suma de los digitos de 568 es: ${sumaDigitos(568)}")
// Versión NO COLA
println(s"NO COLA: Suma de los digitos de 568 es: ${sumaDigitosNoCola(568)}")

// 12.
println(s"COLA: Suma de cuadrados de la lista: 1,2,3,4: ${sumaCuadrados(List(1,2,3,4))}")
println(s"COLA: Suma de cuadrados de la lista: 1,2,3,4: ${sumaCuadrados_v2(List(1,2,3,4))}")


// 13.
println(s"COLA: Lista creada a partir de n: ${crearLista(13)}")
// Versión NO COLA
println(s"NO COLA: Lista creada a partir de n: ${crearListaNoCola(13)}")
}

