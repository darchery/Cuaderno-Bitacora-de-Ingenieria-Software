object ejercicio4 {
  /*4. Define una función recursiva genérica zip que tome dos listas y devuelva una lista de tuplas, donde
  las primeras componentes se tomen de la primera lista y las segundas componentes de la segunda
  lista. Por ejemplo:
  zip(List(10, 20, 30), List('a', 'b', 'c'))
  == List((10, 'a'), (20, 'b'), (10, 'c'))
  zip(List(10, 20, 30), List('a', 'b'))
  == List((10,'a'), (20,'b'))
  */
  def main(args: Array[String]): Unit = {
    def zip[A, B](lA: List[A], lB: List[B]): List[(A, B)] = {
      // Hacemos match de las 2 listas
      (lA, lB) match
        // Casos lista vacía
        case (Nil, _) => Nil
        case (_, Nil) => Nil
        // Separamos la cabeza de la lista del rest(en ambas)
        // luego anidamos los 2 primeros como tupla a la llamada recursiva con el resto
        // de las listas
        case (head1 :: tail1, head2 :: tail2) => (head1, head2) :: zip(tail1, tail2)
    }
    println(zip(List(10, 20, 30), List('a', 'b', 'c')))
    println(zip(List(10, 20, 30), List('a', 'b')))
  }
}
/*
Solución 1 (Pattern Matching)
def zip[A,B](l1:List[A], l2:List[B]): List[(A,B)] =
(l1, l2) match
case (Nil, _) => Nil
case (_, Nil) => Nil
case (h1 :: t1, h2 :: t2) => (h1, h2) :: zip(t1, t2)

Solución 2 (Recursiva de cola)
def zip[A,B](la: List[A], lb: List[B] ) : List[(A,B)] =
@annotation.tailrec
def go(la: List[A], lb: List[B], lc: List[(A,B)]) : List[(A,B)] =
if la.isEmpty || lb.isEmpty then lc
else go(la.tail, lb.tail, lc :+ (la.head,lb.head))
go(la, lb, Nil)
* */