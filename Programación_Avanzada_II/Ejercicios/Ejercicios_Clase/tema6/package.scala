package object concurrencia_semaforos {
  def log(msg: String): Unit =
    println(s"${Thread.currentThread().getName}: $msg")
  def thread(body: =>Unit): Thread = {
    val t = new Thread {
      override def run() = body
    }
    t.start()
    t
  }
}
