import scala.annotation.tailrec

trait ImmutableSet[T] {
  def add(elem: T): ImmutableSet[T] // añade el elemento elem al conjunto si no está presente
  def remove(elem: T): ImmutableSet[T] // elimina elem del conjunto; no modifica el conjunto si no está
  def contains(elem: T): Boolean // comprueba si un elemento está en el conjunto
  def size: Int // devuelve el número de elementos en el conjunto
  def isEmpty: Boolean // comprueba si el conjunto está vacío
}

                    // Constructor privado
class SimpleSet[T] private (private val elems: List[T]) extends ImmutableSet[T] {
  // Constructor secuencia de valores
  def this(elems: T*) =
    this(elems.toList.distinct)
              // Usamos distinct ya que ha de ser un conjunto

  def toList: List[T] =
    elems

  def union(other: SimpleSet[T]): SimpleSet[T] =
    @tailrec
    def bucle(acc: SimpleSet[T], resto: List[T]): SimpleSet[T] =
      resto match
        case Nil => acc
        case head :: tail => bucle(acc.add(head), tail)
        // Ya tenemos resuelto los casos al añadir en la función def
    bucle(SimpleSet(elems), other.toList.distinct)

  def intersection(other: SimpleSet[T]): SimpleSet[T] =
    SimpleSet(elems.filter((x: T) => other.contains(x)))

  def difference(other: SimpleSet[T]): SimpleSet[T] =
    elems.foldLeft(SimpleSet[T]()) { (acc , elem) =>
      if (other.contains(elem)) acc
      else acc.add(elem)
    }
    
  def add(elem: T): SimpleSet[T] =
    if (!contains(elem)) 
      SimpleSet(elems ++ List(elem))
      // ó
      //  SimpleSet(elem :: elems)
      // ò
      // SimpleSet(elems :+ elem)
    else
      this

  def remove(elem: T): SimpleSet[T] =
    if (contains(elem))
      SimpleSet(elems.filter(_!= elem))
    else
      this

  def contains(elem: T): Boolean =
    elems.contains(elem)

  def size: Int =
    elems.size
    //??
    // elems.length

  def isEmpty: Boolean =
    elems.isEmpty

  override def toString: String =
    elems.mkString("Set(", ", ", ")")

  override def hashCode(): Int =
    elems.foldRight(0) { (elem, acc) =>
      elem.hashCode() + acc
    }
    // ó
    //elems.foldRight(0)(_.hashCode() + _)

  override def equals(obj: Any): Boolean =
    obj match
      case that: SimpleSet[_] => this.elems == that.elems
      case _=> false
}

object Main extends App {
  // Creación conjunto
  var simpleSet = new SimpleSet(1, 2, 3, 4, 5, 4, 5)
  var simpleSet2 = new SimpleSet(1, 2, 3)
  var simpleSet3 = new SimpleSet(1, 2, 3)
  println(simpleSet)
  val set = new SimpleSet(List(1,2,3))
  println(set)

  // Elimina el 4
  println(simpleSet.remove(4))
  println(simpleSet.remove(7))

  // Añade el 6
  println(simpleSet.add(6))
  println(simpleSet.add(1))

  // equals
  println(simpleSet.equals(simpleSet2))
  println(simpleSet2.equals(simpleSet3))

  // hashcode
  println(simpleSet2.hashCode())

  // Union
  var setUnion = new SimpleSet(4,5,6,7)
  println(simpleSet.union(setUnion))
  println(simpleSet2.union(simpleSet3))

  // Inteseccion
  var setInter1 = new SimpleSet(1, 2, 3, 4)
  var setInter2 = new SimpleSet(7, 8, 4)
  println(setInter1.intersection(setInter2))
  print(setInter2.intersection(simpleSet2))

  // Difference
  println(setInter1.difference(setInter2))
  println(setInter2.difference(setInter1))
  println(setInter1.difference(setInter1))
}