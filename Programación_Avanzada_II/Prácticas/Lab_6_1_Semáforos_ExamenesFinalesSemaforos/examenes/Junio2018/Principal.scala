package examenes.Junio2018

object Principal extends App {

  val gestor = new GestorAgua
  val h = new Array[Hidrogeno](10) // 10 elementos para Hidrógeno
  val o = new Array[Oxigeno](5)     // 5 elementos para Oxígeno

  // Inicializando los objetos de Hidrógeno
  for (i <- h.indices) {
    h(i) = new Hidrogeno(i, gestor)
  }

  // Inicializando los objetos de Oxígeno
  for (i <- o.indices) {
    o(i) = new Oxigeno(i, gestor)
  }

  // Iniciando los hilos de Hidrógeno
  for (i <- h.indices) {
    h(i).start()
  }

  // Iniciando los hilos de Oxígeno
  for (i <- o.indices) {
    o(i).start()
  }
}
