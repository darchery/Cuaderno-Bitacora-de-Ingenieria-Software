package examenes.Junio2022_Supermercado

import scala.util.Random

object Driver {
  def main(args: Array[String]): Unit = {
    val NC = 15
    val r = new Random()
    val mkt: Supermercado = new SupermercadoSemaforos() // Comenta esta línea para probar la versión con monitores
    // val mkt: Supermercado = new SupermercadoMonitores() // Descomenta esta línea para probar la versión con monitores

    val c1 = Array.tabulate(NC)(i => new Cliente(mkt, i))
    c1.foreach { cliente =>
      Thread.sleep(r.nextInt(1500))
      cliente.start()
    }

    Thread.sleep(r.nextInt(1500))

    val c2 = Array.tabulate(NC)(i => new Cliente(mkt, i + 15))
    c2.foreach { cliente =>
      Thread.sleep(r.nextInt(1500))
      cliente.start()
    }

    // c.foreach(_.join()) // Si se desea esperar a que terminen

    Thread.sleep(2000)
    mkt.fin()
  }
}
