package examenes.Junio2017_Bebes

object Principal {
  def main(args: Array[String]): Unit = {
    // TODO Auto-generated method stub
    val NUM_ADULTOS = 5
    val NUM_BEBES = 15
    val g = new Guarderia
    val b = new Array[Bebe](NUM_BEBES)
    for (i <- 0 until b.length) {
      b(i) = new Bebe(g, i)
    }
    val a = new Array[Adulto](NUM_ADULTOS)
    for (i <- 0 until a.length) {
      a(i) = new Adulto(g, i)
    }
    for (i <- 0 until b.length) {
      3(i).start
    }
    for (i <- 0 until a.length) {
      a(i).start
    }
  }
}