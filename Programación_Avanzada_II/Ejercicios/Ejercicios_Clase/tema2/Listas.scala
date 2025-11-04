package tema2


enum Lista[+A]:
  case Nula
  case Cons(a: A, r: Lista[A])

object Lista:
  def apply[A](args: A*): Lista[A] =
    if (args.isEmpty) Nula
    else Cons(args(0), apply(args.tail*))
  
  def longitud[A](l: Lista[A]): Int =
    l match
      case Nula => 0
      case Cons(a, r) => 1 + longitud(r)

  def sumaR(l: Lista[Int]) : Int =
    l match
      case Nula => 0
      case Cons(a, r) => a + sumaR(r)

  def sumaL(l: Lista[Int]): Int =
    def bucle(l: Lista[Int], acc: Int): Int =
      l match
        case Nula => acc
        case Cons(a, r) => bucle(r, a + acc)
    bucle(l, 0)

  def productoL(l: Lista[Int]): Int =
    def bucle(l: Lista[Int], acc: Int): Int =
      l match
        case Nula => acc
        case Cons(a, r) => bucle(r, a * acc)
    bucle(l, 1)


  /**
   * LEFT -> Recursividad de cola
   * RIGHT -> Recursividad con l match solo
   */



  // Operar LEFT
  def operarL[A](l: Lista[A], inic: A, f: (A, A) => A) =
    def bucle(l: Lista[A], acc: A): A =
      l match
        case Nula => acc
        case Cons(a, r) => bucle(r, f(a, acc))
    bucle(l, inic)

    // Ejemplo uso: operar(Lista(1,2,3), 1, _*_)
    // val res4: Int = 6, mutiplica todos los elementos de la lista

    // operarL(Lista(1,2,3), 0, _+_)
    // val res3: Int = 6, suma desde 0, todos los elementos de la lista

    // operarL(Lista("Hola", "Mundo", ", ", "Adiós"), "", _+_)
    //val res5: String = Adiós, MundoHola

  // Operar RIGHT
  def operarR[A](l: Lista[A], inic: A, f: (A, A) => A): A =
    l match
      case Nula => inic
      case Cons(a, r) => f(a, operarR(r, inic, f))
   // val res6: String = HolaMundo, Adiósº

  def foldRight[A, B](l: Lista[A], inic: B, f: (A, B) => B): B =
    l match
      case Nula => inic
      case Cons(a, r) => f(a, foldRight(r, inic, f))
  // foldRight(Lista(1, 2, 3), 1, _*_)
  // val res2: Int = 6, multiplica todos los elementos

  // foldRight(Lista('1', '2'. '3'), 0, (x, y) => y+1)
  // val res1: Int = 3, cuenta los elementos de la lista

  def foldLeft[A, B](l: Lista[A], inic: B, f: (A, B) => B): B =
    def bucle(l: Lista[A], acc: B): B =
      l match
        case Nula => acc
        case Cons(a, r) => bucle(r, f(a, acc))
    bucle(l, inic)

  // Invertir el orden de una lista una lista:
  /* foldLeft[Int, Lista[Int]](Lista(1, 2, 3), Nula, (x, y) => Cons(x, y))
     val res0: tema2.Lista[Int] = Cons(3,Cons(2,Cons(1,Nula))*/
object Listas extends App{

}
