package tema7

import java.util.concurrent.locks._


class Buffer_EjmploLock(N: Int) {
  private val l = new ReentrantLock(true)
  private val b = new Array[Int](N)
  private var i = 0 // index productor
  private var j = 0 // index consumidor
  private var numElem = 0
  private val noVacio = l.newCondition() // CS-consumidor
  private val noLleno = l.newCondition() // CS-productor
  // CS-Prod
  // CS-Cons

  def almacenar(dato: Int) = {
    l.lock() 
    try {
      // CS-Prod    
      // Si está lleno => ESPERA para almacenar
      while (numElem == N) noLleno.wait() // CS-productor
      b(i) = dato
      i = (i + 1) % N
      numElem += 1
      noVacio.signal() // Despertamos al consumidor que no está vacío => para que pueda EXTRAER 
    } finally {
      l.unlock()
    }
  }

  def extraer(): Int = {
    l.lock()
    try {
      // CS-Cons
      // Si está vacío => Dejo de extraer => DORMIMOS al consumidor
      while (numElem == 0) noVacio.wait()
      val dato = b(j)
      j = (j + 1) % N
      numElem -= 1
      // Si ponemos un elemento => DESPERTAMOS al consumidor
      if (numElem == 1) noVacio.signal()
      dato  
    } finally {
      l.unlock()
    }
  }
}


object EjemploLock_ProdCons {
  
}
