package practica_22

trait ImmutableQueue[T] {
  def enqueue(elem: T): ImmutableQueue[T]
  def dequeue(): (T, ImmutableQueue[T])
  def isEmpty: Boolean
}

class SimpleQueue[T] private (private val elems: List[T]) extends ImmutableQueue[T] {
  // Constructor con argumentos T*
  /**
   * LLamamos a toList para crear una Lista con los números pasados como argumento */
  def this(elems: T*) =
    this(elems.toList)
  // Constructor sin argumentos(Nil -> Lista vacía)
  def this() =
    this(Nil)

  /**
   * Con el constructor de SimpleQueue creamos una cola concatenando la lista anterior
   * con una lista con el elemento a encolar al al final de la cola*/
  // ENQUEUE: SimpleQueue(elem ++ List(elems))
  def enqueue(elem: T): ImmutableQueue[T] =
    SimpleQueue(elems ++ List(elem))
  /**
   * Devolvemos una tupla con el elemento eliminado(la cabeza al ser una cola) y
   * una SimpleQueue con el resto de lista sin esa cabeza*/
  // DEQUEUE: (elems.head, SimpleQueue(elems.tail)
  def dequeue(): (T, ImmutableQueue[T]) =
  if (isEmpty)
    throw new NoSuchElementException("La cola está vacía")
  else
    (elems.head, SimpleQueue(elems.tail))

  // Verifica si la lista está vacía
  def isEmpty: Boolean =
    elems.isEmpty

  override def toString: String =
    elems.mkString("SimpleQueue(", ", ", ")")

  override def equals(obj: Any): Boolean =
    obj match
      case that: SimpleQueue[_] => this.elems == that.elems
      case _=> false

  override def hashCode(): Int =
    elems.hashCode()
}

@main def testSimpleQueue(): Unit = {
  val squeue = new SimpleQueue[Int]()
  val q = squeue.enqueue(1).enqueue(2).enqueue(3).enqueue(4)
  assert(q.dequeue() == (1, SimpleQueue(2, 3, 4)), s"${q.dequeue()} should be equal to (1, SimpleQueue(List(2, 3, 4)))")
  assert(squeue.isEmpty, s"{q} should be empty")
  assert(!q.isEmpty, s"{q should not be empty")
  val q2 = SimpleQueue(1, 2, 3, 4)
  assert(q == q2, s"${q} and ${q2} should be equal")
  assert(q.hashCode() == q2.hashCode(), s"The hash codes of ${q} and ${q2} should be equal")
}

