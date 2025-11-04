import libreria_local.*

object ejercicio_1_trataElementosDeUnoEnUno {
  val N = 20
  val numEnteros = 200

  class Buffer(maxElems: Int) extends Thread {
    var c = 0
    var p = 0
    var numElem = 0
    var elem = new Array[Int](maxElems)
    var hayDato = false

    def nuevoDato(dato: Int) = {
      while (hayDato) Thread.sleep(0) // CS - Consumidor
      elem(p) = dato
      p = (p + 1) % N
      hayDato = true
    }

    def leeDato(): Int = {
      while (!hayDato) Thread.sleep(0) // CS - Productor
      val dato = elem(c)
      elem(c) = 0
      c = (c + 1) % N
      hayDato = false
      dato
    }
  }

  def main(args: Array[String]): Unit = {
    val buffer = new Buffer(N)

    val productor = thread {
      for(i<-0 to numEnteros)
        log(s"Productor: dato -> $i")
        buffer.nuevoDato(i)
    }
    val consumidor = thread {
      for(i<-0 to numEnteros)
        log(s"Consumidor lee dato: ${buffer.leeDato()}")
    }
    productor.join(); consumidor.join()
  }
}
