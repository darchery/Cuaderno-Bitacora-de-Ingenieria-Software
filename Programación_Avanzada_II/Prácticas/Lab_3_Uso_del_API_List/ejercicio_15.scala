/**
 * 15. Dados dos maps que representan el stock de productos en dos almacenes diferentes, queremos combinarlos
 * sumando las cantidades de los productos que aparecen en ambos.
 * Dados los siguientes datos
 * val warehouse1 = Map("laptop" -> 5, "mouse" -> 20, "keyboard" -> 10)
 * val warehouse2 = Map("laptop" -> 3, "mouse" -> 15, "monitor" -> 8)
 * la salida esperada es
 * Map(laptop -> 8, mouse -> 35, keyboard -> 10, monitor -> 8)*/

object ejercicio_15 extends App {
  val warehouse1 = Map("laptop" -> 5, "mouse" -> 20, "keyboard" -> 10)
  val warehouse2 = Map("laptop" -> 3, "mouse" -> 15, "monitor" -> 8)

  /*
  * Hacemos un foldLeft de wh1 con wh2 como acumulador incial
  *
  * Dividiremos en un caso => el acc(mapa wh2) y una tupla con el (clave, valor) de wh1
  *
  * Aquí haremos un update del mapa:
  * el clave -> product actualizamos el
  * valor con quantity + el value que tenía acc esa calve con acc.getOrEsle(product, 0)
  * ese 0 es por si no hay valor asociada en algún caso devuelva 0*/
  val totalWarehouse = warehouse1.foldLeft(warehouse2) { case (acc, (product, quantity)) =>
    acc.updated(product, acc.getOrElse(product, 0)+ quantity)
  }

  println(totalWarehouse)
}
