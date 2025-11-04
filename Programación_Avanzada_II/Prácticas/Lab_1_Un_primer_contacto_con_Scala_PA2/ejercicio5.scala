object ejercicio5 {
  /*5. Implementa una operación filter(l, f) que tome una lista l de elementos de tipo A
  y una función f: A => Boolean y que devuelva una lista con los elementos e de l que satisfacen f(e). Por ejemplo:
  println(filter(List(1,2,3,4,5), _ % 2 == 0)) // Output: List(2,4)*/
  def main(args: Array[String]): Unit = {
    def filter[A](list: List[A], f: A => Boolean): List[A] = {
      list match {
        // Casos null
        case Nil => Nil
        // Separamos la cabeza(primer elemento de la lista) y la cola(resto)
        // si al aplicar f sobre head, esta devuelve head(elemento que cumple la f) anidada con la
        // llamada recursiva del resto de la lista y la función. Si no la cumple desechamos la cabeza
        // y devolvemos solo la llamada recursiva
        case head :: tail => if (f(head)) head :: filter(tail, f) else filter(tail, f)
      }
    }
    println(filter(List(1,2,3,4,5), _ % 2 == 0)) // Output: List(2,4)
  }
}
/*
Solución 1 (Pattern Matching)
def filter[A](l:List[A], f: A => Boolean): List[A] =
l match
case Nil => Nil
case h :: t =>
if f(h) then h :: filter(t, f)
else filter(t, f)

Solución 2 (Recursiva de cola)
def filter[A](l: List[A], f: A => Boolean) : List[A] =
@annotation.tailrec
def loop(l: List[A], f: A => Boolean, lres : List[A]) : List[A] =
if l.isEmpty then lres
else if f(l.head) then loop(l.tail,f,lres :+ l.head)
else loop(l.tail,f,lres)
loop(l,f,Nil)*/