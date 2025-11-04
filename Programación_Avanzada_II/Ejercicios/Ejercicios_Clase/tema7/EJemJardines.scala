package tema7
import concurrencia.*

object Jardin {
  private var n = 0
  def inc = synchronized {
    log("Ejemplo")
    n += 1
  }
  def valor = n
}

object EJemJardines {
  def main(args: Array[String]): Unit = {
    val p0 = thread {
      for (i<-0 until 1000)
        Jardin.inc
    }
    val p1 = thread {
      for (i <- 0 until 1000)
        Jardin.inc
    }
  }
}
