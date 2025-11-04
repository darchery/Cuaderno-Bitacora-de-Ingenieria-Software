package examenes.Septiembre2021_Generador_Procesador

object Driver {
  def main(args: Array[String]): Unit = {
    val NPROCESADORES = 10
    val NDATOS = 3

    val dato = new DatoCompartido(NPROCESADORES)
    val generador = new Generador(NDATOS, dato)
    generador.start()

    val procesadores = Array.tabulate(NPROCESADORES)(i => new Procesador(i, NDATOS, dato))
    procesadores.foreach(_.start())
  }
}
