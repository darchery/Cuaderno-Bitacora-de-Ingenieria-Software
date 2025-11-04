/**
 * Ejercicio 2
 * Dada una lista de frases, queremos contar la frecuencia de las palabras significativas de las cadenas que
 * empiecen por "FINAL" (sin distinguir mayúsculas y minúsculas). Por ejemplo, dada la lista
 * val sentences = List(
 * "FINAL: Scala is a functional language",
 * "DRAFT: The power of functional programming is great",
 * "DRAFT: Programming is elegant",
 * "FINAL: Functional programming is elegant",
 * "FINAL: Object-oriented programming is great")
 * y el conjunto de palabras no significativas
 * val stopWords = Set("a", "the", "is", "of")
 * queremos como salida un map
 * HashMap(programming -> 2, language -> 1, object-oriented -> 1, scala -> 1, elegant -> 1,
 * functional -> 2, great -> 1)*/

object ejercicio_2 extends App{
  val sentences = List(
    "FINAL: Scala is a functional language",
    "DRAFT: The power of functional programming is great",
    "DRAFT: Programming is elegant",
    "FINAL: Functional programming is elegant",
    "FINAL: Object-oriented programming is great")

  val stopWords = Set("a", "the", "is", "of")

  /*val frecEachWordSentences = sentences
    .flatMap(_.toLowerCase.split("FINAL: ")(1).split("\\s+"))
    .filter((elem: String) => !stopWords.contains(elem))
    .groupBy(identity)
    .map{ case (word, lista_words) => (word, lista_words.size)}*/


  /*
  * 1º: .filter(_.startsWith("FINAL: ")): conseguimos filtrar del conjunto y formas una lista con
  * los elementos que empezaran por "FINAL: "
  *
  * 2º: .flatMap(_.split("FINAL: ")(1).toLowerCase.split("\\s+")):  conseguimos reducir el nivel de anidación,
  * dividimos en 2 el String, desde "FINAL: " y el resto de la oración(lo que nos interesa), posteriormente la elegimos
  * con el índice 1(0 -> "FINAl: ", 1 -> Resto), luego ponemos en minúscula todas la oraciones y por último dividmos
  * cada palabra quitando los espacios simples, dobles y tabulaciones. Y como resultado obtenemos una lista de Strings
  * cuyos elementos son palabras
  *
  * 3º: .filter((word: String) => !stopWords.contains(word)): filtramos las palabras que estén NO contenidas en el
  * cojuntso stopWords
  *
  * 4º: .groupBy((x => x)) : obtenemos un mapa con cada palabra como clave y como valor con una lista con la clave
  * por cada aparición de la clave
  *
  * 5º: .map { case (key, value_list) => (key, value_list.size)}: por último transformamos el mapa de una clave y una lista
  * a esa misma clave pero en vez la lista, obtenemos su size  */
  val frecEachWordSentences = sentences
    .filter(_.startsWith("FINAL: "))
    .map(_.split("FINAL: ")(1).toLowerCase) // Lista de frases(strins)
    .flatMap(_.split("\\s+")) // Lista de palabras (strings)
    .filter((word: String) => !stopWords.contains(word))
    .groupBy((x => x))
    .map { case (key, value_list) => (key, value_list.size)}

  println(frecEachWordSentences)
}
// FALTA SOLO ANALIZAR LAS FINAL SENTENCES

/**
 * SALIDA:
 * HashMap(programming -> 2, language -> 1, object-oriented -> 1, scala -> 1, elegant -> 1,
 * functional -> 2, great -> 1) */