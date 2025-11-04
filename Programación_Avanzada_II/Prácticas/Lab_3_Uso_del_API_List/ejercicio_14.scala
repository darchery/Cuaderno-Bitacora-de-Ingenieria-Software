/**
 * 14. Dada una lista de palabras, queremos contar la frecuencia de cada palabra.
 * Dados los siguientes datos
 * val words = List("scala", "is", "awesome", "scala", "functional", "scala",
 * "is", "great")
 * la salida esperada es
 * HashMap(is -> 2, awesome -> 1, scala -> 3, functional -> 1, great -> 1)*/

object ejercicio_14 extends  App {
  val words = List("scala", "is", "awesome", "scala", "functional", "scala",
    "is", "great")

  val frencuenciaWords = words
    .groupBy((x => x))
    .map{ case (word, list_word) => (word, list_word.size)}

  // otra implementación
  val frec = words
    .groupBy(identity).mapValues(_.size).toMap

  println(frencuenciaWords)
  println(frec)
}
