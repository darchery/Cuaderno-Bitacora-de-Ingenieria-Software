object libreria_local {
  def log(str: String) =
    println(s"${Thread.currentThread().getName}: $str")

  def periodico(t: Long)(b: => Unit): Thread = {
    val hebra = new Thread {
      override def run(): Unit = {
        while (true) {
          Thread.sleep(t)
          b
        }
      }
    }
    hebra
  }
  
  def thread(body: => Unit): Thread = {
    val t = new Thread {
      override def run(): Unit =
        body
    }
    t.start()
    t
  }

  def parallel[A, B](a: => A, b: => B): (A, B) = {
    var vA = null.asInstanceOf[A]
    var vB = null.asInstanceOf[B]

    val hA = thread {
      vA = a
    }
    val hB = thread {
      vB = b
    }
    hA.join();
    hB.join()
    (vA, vB)
  }
}
