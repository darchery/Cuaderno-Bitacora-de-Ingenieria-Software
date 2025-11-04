package examenes.Septiembre2021_Generador_Procesador

class Procesador(val id: Int, val nDatos: Int, val dato: DatoCompartido) extends Thread {

  override def run(): Unit = {
    try {
      for (_ <- 0 until nDatos) {
        // Protocolo de entrada: lee el dato del recurso compartido
        var d = dato.leeDato(id)
        // Procesa el dato incrementándolo en 1
        d = d + 1
        // Protocolo de salida: actualiza el dato en el recurso compartido
        dato.actualizaDato(id, d)
      }
    } catch {
      case e: Exception => e.printStackTrace()
    }
  }
}
