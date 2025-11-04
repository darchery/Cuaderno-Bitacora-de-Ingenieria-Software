import scala.annotation.tailrec

/**
 * RESUMEN DE LA EVALUACIÓN:
 *
 * 1. Todo bien menos el método +, error al no convertir v a lista y no devolver un MyVector
 *
 * 2. Bien
 *
 * 3a. Bien
 * 3b. Posiblemente mal
 *
 * 4a. Bien
 *
 * 4b. Error al no cumplir la recursión de cola con el for, tenía que haber usado .find*/

trait ImmmutableVector {
  def toList: List[Double]
  def dim: Int
  def +(v: MiVector): MiVector
  def *(v: MiVector): Double
}

// Ejercicio 1 (3 puntos)
class MiVector private (private val elems: List[Double]) extends ImmmutableVector {
  def this(elems: Double*) =
    this(elems.toList)

  def toList: List[Double] =
    elems.toList

  def dim: Int =
    elems.size

  def +(v: MiVector): MiVector = 
    if (v.dim == this.dim) {
      // No consigo comprimir this con v
      val tupla_vec  = this.toList.zip(v.toList)

      MiVector(
        tupla_vec.foldLeft(MiVector().toList) { (acc, elem_tuple) =>
          acc ++ List(elem_tuple._1 + elem_tuple._2)
        }
      )
    } else {
      throw new RuntimeException(s"Diferente tamaño: ${v.dim} != ${this.dim}")
    }

  // Versión ERRÓNEA + del exámen original
  /*def +(v: MiVector): MiVector =
    if (v.dim == this.dim) {
      // No consigo comprimir this con v
      val tupla_vec = this.toList.zip(v)

      tupla_vec.foldLeft(MiVector().toList) { (acc, elem_tuple) =>
        acc ++ List(elem_tuple._1 + elem_tuple._2)
      }
    } else {
      throw new RuntimeException(s"Diferente tamaño: ${v.dim} != ${this.dim}")
    }*/
    
  def *(v: MiVector): Double =
    if (v.dim == this.dim) {
      val tupla_vec = this.toList.zip(v.toList)

      tupla_vec.foldLeft(0.0) { (acc, elem_tuple) =>
        acc + elem_tuple._1 * elem_tuple._2 
      }
    } else {
      throw new RuntimeException(s"Diferente tamaño: ${v.dim} != ${this.dim}")
    }
    
  override def toString: String =
          elems.mkString("(", ", ", ")")

  override def equals(obj: Any): Boolean =
     obj match
       case that: MiVector =>
         this.elems.sortWith((x, y) => x < y) == that.elems.sortWith((x, y) => x < y)
       case _ => false

  override def hashCode(): Int =
          elems.hashCode()

}

// Ejercicio 2 (2 puntos)
def propercuts[A](list: List[A]): List[(List[A], List[A])] =
  @tailrec
  def bucle(acc: List[(List[A], List[A])], list_rest: List[A], accTuple_2: List[A]): List[(List[A], List[A])] =
    list_rest match
      case head :: Nil => acc
      case _ =>
        val init = list_rest.init
        val last = list_rest.last

        bucle(acc :+ (init ,  (accTuple_2 ++ List(last)).reverse  ), init, accTuple_2 ++ List(last))
  bucle(List[(List[A], List[A])](), list, Nil)

// Ejercicio 3a
def merge[A](lq: (A, A) => Boolean)(l1: List[A], l2: List[A]): List[A] =
  l1.foldLeft(l2) { (acc, elem) =>
   elem :: acc
  }.sortWith( (x: A, y: A) => lq(x, y))

// Ejercicio 3b
def mergeSort[A](lq: (A, A) => Boolean)(list: List[A]): List[A] =
  list.sortWith( (x: A, y: A) => lq(x, y))

// Ejercicio 4a
def powerset[A](list: List[A]): List[List[A]] =
  list.foldLeft[List[List[A]]](List(List())) { (acc, elem) =>
    Nil ++ acc ++ acc.map(_++List(elem))
  }

// Ejercicio 4b
def knapsack(n: Int, list: List[Int]): Option[List[Int]] =
  @tailrec
  def bucle(list_rest: List[Int], acc: Option[List[Int]]): Option[List[Int]] =
    list_rest match
      case Nil => acc
      case head :: tail =>
        tail.find(elem => head + elem == n) match
          case Some(elem) => Some(List(head, elem))  // Se encontró la combinación
          case None => bucle(tail, acc)             // Seguir buscando en el resto de la lista
  bucle(list, None)

// Versión ERRÓNEA knapsack del exámen original
/*def knapsack(n: Int, list: List[Int]): Option[List[Int]] =
  @tailrec
  def bucle(list_rest: List[Int], res: Option[List[Int]]): Option[List[Int]] =
    list_rest match
      case Nil => None
      case head :: tail =>

        for(elem <- tail) {
          if (head + elem == n) bucle( tail, Some(List(head, elem)) )
        }
        bucle(tail, None)
  bucle(list, Option.empty)*/


object control1 {
  def main(args: Array[String]) = {}
  // 1
  println("CORRECTO: Eje 1")
  val v = new MiVector(1, 2, 3)
  val w = new MiVector(2, 3, 4)
  println(s"suma de $v y $w: ${v + w}")
  println(s"producto escalar de $v y $w: ${v * w}")
  println(s"Son iguales $v y $w?: ${w == v}")
  println(s"Son iguales $v y ${new MiVector(1, 2, 3)}?: ${v == new MiVector(1, 2, 3)}")
  try {
    val x = v + new MiVector(1, 2)
  } catch {
    case _ => println("no son de la misma dimensión")
  }

  // 2
  println("CORRECTO: Eje 2")
  println(propercuts(List(1, 2, 3, 4)) ==
      List( ( List(1, 2, 3), List(4) ), ( List(1, 2), List(3, 4) ), ( List(1), List(2, 3, 4) ) ) )
  println(propercuts(List(1, 2, 3, 4)))

  println("\n")
  // 3a
  println("CORRECTO: Eje 3a")
  println(merge[Int](_<=_)(List(1,2,3),List(1,3,4)) == List(1,1,2,3,3,4))
  println(merge[Int](_<=_)(List(1,2,3),List(1,3,4)))

  println("\n")
  // 3b
  println("POSIBLEMENTE INCORRECTO: Eje 3b")
  println(merge[Int](_<=_)(List(1,2,3),List(1,3,4)) == List(1,1,2,3,3,4))


  println("\n")
  // 4a
  println("CORRECTO: Eje 4a")
  println(powerset(List(1,2,3)) ==
    List(List(1, 2, 3), List(1, 2), List(1, 3), List(1), List(2, 3), List(2), List(3), List()))
  println(println(powerset(List(1,2,3))))
  // Está ordenado en órden inverso

  println("\n")
  // 4b
  println("CORRECTO: Eje 4a")
  println(knapsack(5, List(1, 2, 3, 4, 5)) == Some(List(1, 4)))
  println(knapsack(18, List(1, 2, 3, 4, 5)) == None)
}

