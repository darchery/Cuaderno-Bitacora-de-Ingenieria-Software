object ejercicio6 {
  /*6. Implementa una operación map(l, f) que tome como argumentos una lista l de elementos de tipo
  A y una función f: A => B y que devuelva una lista de elementos de tipo B con los elementos
  resultantes de aplicar f a cada uno de los elementos de l.
  println(map(List(1,2,3,4,5), _ * 2)) // Output: List(2,4,6,8,10)*/
  def main(args: Array[String]): Unit = {
    def map[A, B](list: List[A], f: A => B): List[B] = {
      list match
        // Caso base: lista vacía
        case Nil => Nil
        // Partimos la lista, en el primer elemento y el resto
        // aplicamos f al primer elemento y anidamos a la lista con la siguiente llamada recursiva
        case head :: tail => f(head) :: map(tail, f)
    }
    println(map(List(1,2,3,4,5), _ * 2)) // Output: List(2,4,6,8,10)  
  }
}
/*
Solución 1 (Pattern Matching)
def map[A,B](l:List[A], f: A => B): List[B] =
l match
case Nil => Nil
case h :: t => f(h) :: map(t, f)

Solución 2 (Recursiva de cola)
def map[A,B](l: List[A], f : A => B) : List[B] =
@annotation.tailrec
def loop(l: List[A], f: A => B, lb: List[B]): List[B] =
if l.isEmpty then lb
else loop(l.tail, f, lb :+ f(l.head))
loop(l, f, Nil)*/