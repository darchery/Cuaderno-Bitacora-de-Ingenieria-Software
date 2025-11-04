package tema1

// Aquí definimos funciones ESTÁTICAS
object Racional {
  // Cuando en un array ejecutamos
  // a(0) = "algo"
  // por debajo se ejecuta a.apply(0)
  def apply(num: Int, den: Int) =
    new Racional(num, den)

  def apply(num: Int) =
    new Racional(num)
    
  // Versión estática de +, NO implementada
  def +(r1: Racional, r2: Racional) = {

  }  
}

class Racional(num: Int, den: Int) {
  // Por defecto las variables se crean privadas
  // Poniendo val las hacemos públicas

  // Con require verificamos que den sea diferente de 0
  require(den!=0)
  def this(num: Int) =
    this(num, 1)
  // println(s"$num/dem")
  val n = num/mcd(num, den)
  val d = den/mcd(num, den)
  override def toString: String = s"$num/$den"

  def +(otro: Racional): Racional = {
    new Racional(n * otro.d + d * otro.n, d * otro.d)
  }

  def *(otro: Racional) = {
    new Racional(n * otro.n, d * otro.d)
  }

  def *(ent: Int) =
    new Racional(n * ent, d)

  private def mcd(x: Int, y: Int): Int =
    if (y == 0) x
    else mcd(y, x % y)
}

object main extends App {
  val r = new Racional(1, 2)
  println(s"${r+r}")
}