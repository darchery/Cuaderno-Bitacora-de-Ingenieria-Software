package practica_22

/*
* Front: inicio de la lista(donde se eliminan los elementos), front tendrá los elementos
* al frente de la cola
* Rear: final de la lista(donde se añaden los elementos), rear tendrá los elementos
* en la cola. Para hacerlo más eficiente mantendremos los elementos en rear invertidos
*
* De forma que:
* 1. Para EXTRAER un elemento lo EXTRAEMOS de la CABEZA(head) de FRONT. Cuando FRONT
* esté VACÍO, antes de sacarlo, invertimos el REAR y lo transferimos a REAR
* 2. Para INSERTAR un elemento lo insertamos en la CABEZA(HEAD) de REAR*/


class EfficientQueue[T] private (private val front: List[T], private val rear: List[T]) extends ImmutableQueue[T] {
  // Constructor con argumentos
  def this(p: T*) =
    this(p.toList, Nil)
  // Constructor sin argumentos
  def this() =
    this(Nil, Nil)

  def enqueue(elem: T): EfficientQueue[T] =
    // Para INSERTAR un elemento lo insertamos en la CABEZA(HEAD) de REAR
    EfficientQueue(front, elem :: rear)

  def dequeue(): (T, EfficientQueue[T]) =
    if (front.isEmpty)
      if (rear.isEmpty)
        throw new NoSuchElementException("La cola está vacía")
      else
        //Cuando FRONT esté VACÍO, antes de sacarlo, invertimos el REAR y lo transferimos a REAR
        EfficientQueue(rear.reverse,Nil).dequeue()
    else
      // Para EXTRAER un elemento lo EXTRAEMOS de la CABEZA(head) de FRONT.
      (front.head, EfficientQueue(front.tail, rear))

  def isEmpty: Boolean =
    front.isEmpty && rear.isEmpty

  override def toString: String =
  (front ++ rear.reverse).mkString("EfficientQueue(", ", ", ")")

  override def equals(obj: Any): Boolean =
    obj match
      case that: EfficientQueue[_] => (this.front ++ this.rear.reverse) == (that.front ++ that.rear.reverse)
      case _=> false

  override def hashCode(): Int =
    (front ++ rear.reverse).hashCode()
}

@main def testImmutableQueue(): Unit = {
  val squeue = new EfficientQueue[Int]()
  val q = squeue.enqueue(1).enqueue(2).enqueue(3).enqueue(4)
  assert(q.dequeue() == (1, EfficientQueue(2, 3, 4)), s"${q.dequeue()} should be equal to (1, SimpleQueue(List(2, 3, 4)))")
  assert(squeue.isEmpty, s"{q} should be empty")
  assert(!q.isEmpty, s"{q should not be empty")
  val q2 = EfficientQueue(1, 2, 3, 4)
  assert(q == q2, s"${q} and ${q2} should be equal")
  assert(q.hashCode() == q2.hashCode(), s"The hash codes of ${q} and ${q2} should be equal")
}
