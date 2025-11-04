package examenes.Junio2016_Aseo

object Principal {
  def main(args: Array[String]): Unit = {
    // TODO Auto-generated method stub
    val NUM_CLIENTES = 20
    val aseo = new Aseos
    val cliente = new Array[Cliente](NUM_CLIENTES)
    for (i <- 0 until cliente.length) {
      cliente(i) = new Cliente(i, aseo)
    }
    val equipo = new EquipoLimpieza(aseo)
    equipo.start
    for (i <- 0 until cliente.length) {
      cliente(i).start
    }
  }
}
