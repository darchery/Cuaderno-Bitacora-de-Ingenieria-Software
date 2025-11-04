import libreria_local.*
import scala.annotation.tailrec
import scala.util.Random

object ejercicio_5 {
  // Apartado A
  def mezclar(l1: List[Int], l2: List[Int]): List[Int] = {
    @tailrec
    def bucle(l1_res: List[Int], l2_res: List[Int], acc: List[Int]): List[Int] =
      (l1_res, l2_res) match
        case (Nil, Nil) => acc.distinct
        case (Nil, h2 :: t2) =>
          bucle(Nil, t2, acc :+ h2)
        case (h1 :: t1, Nil) =>
          bucle(t1, Nil, acc :+ h1)
        case (h1 :: t1, h2 :: t2) =>
          if (h1 <= h2) bucle(t1, l2_res, acc :+ h1)
          else bucle(l1_res, t2, acc :+ h2)
    bucle(l1, l2, Nil)
  }

  // Apartado B
  def ordenar(l: List[Int]): List[Int] = {
    var lista_res = List.empty[Int]

    // Si está vacía o su tamaño es 1 está vacía
    if (!(l.length == 1) && !l.isEmpty) {
      var (primeraMitad, segundaMitad) = l.splitAt((l.length/2)-1)

      val h1 = thread {
        primeraMitad = primeraMitad.sortWith(_<=_)
      }
      val h2 = thread {
        segundaMitad = segundaMitad.sortWith(_<=_)
      }
      h1.join(); h2.join()

      lista_res = mezclar(primeraMitad, segundaMitad)
    }
    lista_res
  }

  def ordenarParallel(l: List[Int]): List[Int] = {
    var lista_res = List.empty[Int]

    // Si está vacía o su tamaño es 1 está vacía
    if (!(l.length == 1) && !l.isEmpty) {
      var (primeraMitad, segundaMitad) = l.splitAt((l.length / 2) - 1)

      val t = thread {
        parallel(primeraMitad.sortWith(_ <= _), segundaMitad.sortWith(_ <= _))
      }
      t.join()

      lista_res = mezclar(primeraMitad, segundaMitad)
    }
    lista_res
  }

  def main(args: Array[String]): Unit = {
    val l1 = List(1, 2, 3, 5, 10)
    val l2 = List(2, 4, 7, 9)
    println(mezclar(l1, l2))

    val l3 = List.fill(Random.nextInt(50))(Random.nextInt(100))
    println(l3)
    println(ordenar(l3))

    println()
    val l4 = List.fill(Random.nextInt(50))(Random.nextInt(100))
    println(l4)
    println(ordenar(l4))
  }
}


