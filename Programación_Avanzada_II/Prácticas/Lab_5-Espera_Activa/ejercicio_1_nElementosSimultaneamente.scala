import libreria_local.*

object ejercicio_1_nElementosSimultaneamente {
  val N = 20
  val numEnteros = 200

  class Buffer(maxElems: Int) extends Thread {
    var c = 0
    var p = 0
    var numElem = 0
    var elem = new Array[Int](maxElems)

    def nuevoDato(dato: Int) = {
      while (numElem == maxElems) Thread.sleep(0) // CS - Consumidor
      numElem += 1 // SC
      elem(p) = dato // SC
      p = (p + 1) % N
    }

    def leeDato(): Int = {
      while (numElem == 0) Thread.sleep(0) // CS - Productor
      val dato = elem(c)
      numElem -= 1 // SC
      elem(c) = 0 // SC
      c = (c + 1) % N
      dato
    }
  }

  def main(args: Array[String]): Unit = {
    val buffer = new Buffer(N)

    val productor = thread {
      for (i <- 0 to numEnteros)
        log(s"Productor: dato -> $i")
        buffer.nuevoDato(i)
    }
    val consumidor = thread {
      for (i <- 0 to numEnteros)
        log(s"Consumidor lee dato: ${buffer.leeDato()}")
    }
    productor.join();
    consumidor.join()
  }
}
