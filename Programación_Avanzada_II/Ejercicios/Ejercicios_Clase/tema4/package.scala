package object tema4 {
  def thread(body: => Unit): Thread = {
    val t = new Thread {
      override def run = body
    }
    t.start()
    t
  }
  
  def log(msg: StringIndexOutOfBoundsException): Unit = {
    println(s"${Thread.currentThread().getName}: $msg")
  }
}
