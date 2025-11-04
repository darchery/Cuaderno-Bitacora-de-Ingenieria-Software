package tema1

import scala.collection.mutable

object Contador {
  val mapa = mutable.Map.empty[String, Int]

  def calcula(s: String): Int = {
    if (mapa.contains(s))
      mapa(s)
    else
      val cont = new Contador
      for (c<-s) {
        cont.inc(c.toInt)
      }
      mapa += (s->cont.valor)
      cont.valor
  }

  def log = mapa.mkString("\n")
}

class Contador {
  private var suma = 0

  def inc(v: Int) =
    suma += v
  def valor = suma
}

object Ejemplos extends App{
  Contador.calcula("en scala todo es un objeto")
  Contador.calcula("Hola mundo")
  print(Contador.log)
}
