package tema7

class Buffer(N: Int) {
  private val b = new Array[Int](N)
  private var i = 0
  private var j = 0
  private var numElem = 0
  // CS-Prod
  // CS-Cons
  
  def almacenar(dato: Int) = synchronized {
    // CS-Prod    
    while (numElem == N) wait()
    b(i) = dato
    i = (i + 1) % N
    numElem += 1
    notify()
  }

  def extraer():Int = synchronized {
    // CS-Cons
    while (numElem == 0) wait()
    val dato = b(j)
    j = (j + 1) % N
    numElem -= 1
    notify()
    dato
  }
}

object EjemProdCons {
  
}