package examenes.Junio2022_Supermercado

class SupermercadoMonitores extends Supermercado {

  private val permanente = new Cajero(this, true) // Crea el primer cajero, el permanente
  permanente.start()

  // TODO: lógica adicional necesaria para el monitor

  @throws(classOf[InterruptedException])
  override def fin(): Unit = {
    // TODO: implementación pendiente
  }

  @throws(classOf[InterruptedException])
  override def nuevoCliente(id: Int): Unit = {
    // TODO: implementación pendiente
  }

  @throws(classOf[InterruptedException])
  override def permanenteAtiendeCliente(id: Int): Boolean = {
    // TODO: implementación pendiente
    false // borrar cuando esté implementado
  }

  @throws(classOf[InterruptedException])
  override def ocasionalAtiendeCliente(id: Int): Boolean = {
    // TODO: implementación pendiente
    false // borrar cuando esté implementado
  }
}
