object ejercicio_13 extends App {
  val sentences = Set(
    "Scala is a functional language", " ",
    "The power of functional programming is great",
    "Functional programming is elegant"
  )
  val stopWords = Set("a", "the", "is", "of")

  /*
  * Aplanamos el mapa  en vez de dejar el mapa solo, porque?
  * Map: creará una cojunto de array de strings(con cada frase)-> no queremos eso
  * flatMap: creara un conjunto de strings, que es mucho más manejable
  * Básicamente flatMap elimina un nivel de anidación
  *
  * Hacemos el flatmap, aplicando toLowerCase y dividiendo con split cada
  * elemento que encuentre separado de \\s(cualquier espacio en blanco)+(una o más
  * veces)
  *
  * Luego hacemos la diferencia del conjunto para eliminar las stopWords del
  * conjunto(podemos también hacer un filter)
  *
  * Y por último eliminamos las caracteres vacíos(AUNQUE esto no necesario ya
  * que usamos \\s+)*/
  val palabrasUnicas = sentences
    .flatMap(_.toLowerCase.split("\\s+"))
    .diff(stopWords).filter(_.nonEmpty)

  println(palabrasUnicas)
}

/**
 * map Vs flatMap
 * 🔹 map
 *
 * Aplica una función a cada elemento de la colección y devuelve una nueva colección con los resultados.
 *
 * Si la función devuelve una estructura anidada (List, Option, etc.), la estructura original permanecerá anidada.
 *
 * val lista = List(1, 2, 3)
 * val resultado = lista.map(x => List(x, x * 2))
 * println(resultado) // List(List(1, 2), List(2, 4), List(3, 6))
 *
 * Aquí, map mantiene la estructura de listas anidadas.
 *
 *
 * 🔹 flatMap
 *
 * Aplica una función que devuelve una estructura anidada, pero luego aplana el resultado (elimina un nivel de anidación).
 *
 * Es útil cuando la función devuelve colecciones, Option, Future, etc.
 *
 * val lista = List(1, 2, 3)
 * val resultado = lista.flatMap(x => List(x, x * 2))
 * println(resultado) // List(1, 2, 2, 4, 3, 6)
 *
 * Aquí, flatMap ha eliminado la estructura anidada y ha devuelto una lista plana.*/