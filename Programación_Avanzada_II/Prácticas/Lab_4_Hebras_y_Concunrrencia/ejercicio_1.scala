import libreria_local.log
object ejercicio_1 {

// Apartado A
class HebraA(t: Int, c: Char) extends Thread {
  override def run() = {
    for (i <- 0 until t)
      print(c)
  }
}

// Apartado B
@volatile var turno = 1 // A => 1, B => 2, C => 3
@volatile var iter = 0

class HebraB(t: Int, c: Char, miId: Int) extends Thread {
  override def run() = {
    val maxIter = miId
    for(i<-0 until t) {
      while (turno != miId) Thread.sleep(0) // CS-HB

      print(c)

      iter += 1 // SC

      if(iter == maxIter) {
        iter = 0
        turno = (turno % 3) + 1 // Siguiente hebra // SC
      }
    }
  }
}


  def main(args: Array[String]): Unit = {
    /*val hebraA1 = new HebraA(10, 'A')
    val hebraA2 = new HebraA(10, 'B')
    val hebraA3 = new HebraA(10, 'C')

    hebraA1.start()
    hebraA2.start()
    hebraA3.start()*/

    val t = 10
    val hebraB0 = new HebraB(t, 'A', 1)
    val hebraB1 = new HebraB(2*t, 'B', 2)
    val hebraB2 = new HebraB(3*t, 'C', 3)

    hebraB0.start()
    hebraB1.start()
    hebraB2.start()

    hebraB0.join()
    hebraB1.join()
    hebraB2.join()
  }
}
