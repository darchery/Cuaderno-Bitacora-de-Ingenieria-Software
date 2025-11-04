/**
 * 12. Dada una lista de transacciones de ventas representadas como (productName, quantitySold, pricePerUnit),
 * queremos (1) calcular los ingresos totales y (2) obtener la lista de las transacciones de cuantías
 * (quantitySold) superiores (o iguales) a 100 ordenadas por su cuantía.
 * Dados los siguientes datos:
 * val sales = List(
 * ("Laptop", 2, 1000.0),
 * ("Mouse", 10, 15.0),
 * ("Keyboard", 5, 50.0),
 * ("Monitor", 3, 200.0),
 * ("USB Drive", 20, 5.0)
 * )
 * la salida esperada para (1) es
 * 3100.0
 * y para (2):
 * List((Laptop,2000.0), (Monitor,600.0), (Keyboard,250.0), (Mouse,150.0),
 * (USB Drive,100.0))*/

object ejercicio_12 extends App {
  val sales = List(
    ("Laptop", 2, 1000.0),
    ("Mouse", 10, 15.0),
    ("Keyboard", 5, 50.0),
    ("Monitor", 3, 200.0),
    ("USB Drive", 20, 5.0)
  )

  val sumatorioSales = sales
    .foldLeft(0.0) { case (result, (product , quantity, price)) =>
      result + (quantity * price)
    }

  /* Transformamos una lista de tuplas de 3 en una lista de Doubles con la suma
  * del precio*/
  val sumatorioSalesMap = sales
    .map{ case (_, quantity, price) =>
      quantity * price
    }.sum


  val listaTransacciones = sales
    .foldRight[List[(String, Double)]](Nil) { case ((product, quantity, price), transactions) =>
      (product, quantity * price) :: transactions
    }
    .filter { case (product, price) => price >= 100}
    .sortWith{ case ((_, value1), (_, value2)) => value1 > value2 }

  /* Conseguimos transformar una lista de tuplas de 3 a otra de listas de 2*/
  val listaTransaccionesMap = sales
    .map{ case (product, quantity, price) =>
      (product, quantity * price)
    }
    .filter { case (product, price) => price >= 100}
    .sortWith{ case ((_, value1),(_, value2)) => value1 > value2}

  println(sumatorioSales == 3100.0)
  println(sumatorioSales)
  println(sumatorioSalesMap)

  println(listaTransacciones)
  println(listaTransaccionesMap)

}
