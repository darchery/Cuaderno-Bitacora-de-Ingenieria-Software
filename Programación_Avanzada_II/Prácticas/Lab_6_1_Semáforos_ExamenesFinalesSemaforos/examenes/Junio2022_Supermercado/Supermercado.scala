package examenes.Junio2022_Supermercado

trait Supermercado {
  @throws(classOf[InterruptedException])
  def fin(): Unit

  @throws(classOf[InterruptedException])
  def nuevoCliente(id: Int): Unit

  @throws(classOf[InterruptedException])
  def permanenteAtiendeCliente(id: Int): Boolean

  @throws(classOf[InterruptedException])
  def ocasionalAtiendeCliente(id: Int): Boolean
}
