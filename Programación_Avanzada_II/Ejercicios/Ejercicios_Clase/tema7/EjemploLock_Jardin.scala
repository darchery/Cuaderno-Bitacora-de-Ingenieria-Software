package tema7
import concurrencia.*

import java.util.concurrent.locks._

object Jardin_EjemploLock {
  private var n = 0
  private val l = new ReentrantLock(true)

  def inc =  {
    l.lock()
    try {
      n += 1
    } finally {
      l.unlock()
    }

  }
  def valor = n
}

object EjemploLock_Jardin {
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
