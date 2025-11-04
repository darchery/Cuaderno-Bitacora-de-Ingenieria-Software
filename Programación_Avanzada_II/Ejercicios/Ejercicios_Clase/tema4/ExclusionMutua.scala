package tema4

object ExclusionMutua {
  def main(args: Array[String]): Unit = {
    var c = 0
    @volatile var f0 = false
    @volatile var f1 = false
    @volatile var turno = 0

    val h0 = thread {
      for (i <- 0 until 1000)
        f0 = true
        turno = 1

        while (f1 && turno == 1){println("en el bucle")}

        c += 1 // SC0 // turno = 0
        turno = 1
        f0 =false
      // SNC0
    }

    val h1 = thread {
      for (i <- 0 until 1000)
        f1 = true
        turno = 0

        while (f0 && turno == 0){println("en el bucle")}

        c += 1 // SC1 // turno = 1
        turno = 0
        f1 = false
        // SNC1
    }

    h0.join()
    h1.join()
    println(s"c = $c")
  }
}
