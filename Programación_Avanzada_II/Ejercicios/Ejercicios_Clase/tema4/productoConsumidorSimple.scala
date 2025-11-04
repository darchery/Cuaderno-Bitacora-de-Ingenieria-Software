package tema4

class BufferSimple {
  private var c = 0
  private var hayDato = false
  
  def nuevoDato(dato: Int) =
    while (hayDato)// Condición de sincronización del productor
      c = dato
      hayDato = true // CS-Cons
 
  def leerDato() =
    while (!hayDato) {}  // Condición de sincronización del consumidor
    val aux = c
    hayDato = false // CS-Prod
    aux
}

object productoConsumidorSimple {
  def main(args: Array[String]): Unit = {
    val buffer = new BufferSimple
    
    val productor = thread
    for (i<-0 until 50)
      println(s"Porductor: $i")
      buffer.nuevoDato(i)

    val consumidor = thread
    for (i <- 0 until 50)
      println(s"                      Consumidor: ${buffer.leerDato()}")
  }
}
