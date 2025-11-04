package tema2

def isSorted[A](as: Array[A], comp: (A, A) => Boolean): Boolean =
  def bucle(i: Int): Boolean =
    if (i>=as.length-1) true
    else
      if (!comp(as(i), as(i+1))) false
      else bucle(i+1)
  if (as.length==0 || as.length==1) true
  else bucle(0)

def partial[A, B, C](a: A, f: (A, B) => C): B => C =
  (y: B) => f(a, y) 

def curry[A, B, C](f: (A, B) => C): A => (B => C) =
  (x: A) => ((y: B) => f(x, y))

object Ejercicios extends App{
  println(isSorted(Array(3,2,1,0),_>=_))
}
