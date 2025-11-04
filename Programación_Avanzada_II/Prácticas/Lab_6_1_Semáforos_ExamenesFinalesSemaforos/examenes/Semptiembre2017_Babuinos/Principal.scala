package examenes.Semptiembre2017_Babuinos

object Principal {
  def main(args: Array[String]): Unit = {
    // TODO Auto-generated method stub
    val id = new Array[BabuinoSN](25)
    val di = new Array[BabuinoNS](25)
    val p = new Cuerda
    for (i <- 0 until id.length) {
      id(i) = new BabuinoSN(i, p)
    }
    for (i <- 0 until di.length) {
      di(i) = new BabuinoNS(i, p)
    }
    for (i <- 0 until id.length) {
      id(i).start

    }
    for (i <- 0 until di.length) {
      di(i).start
    }


  }
}
