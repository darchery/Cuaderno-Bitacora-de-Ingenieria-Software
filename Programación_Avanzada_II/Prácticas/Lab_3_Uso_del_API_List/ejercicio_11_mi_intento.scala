object ejercicio_11_mi_intento extends App {
  val logs = List(
    "ERROR: Null pointer exception",
    "INFO: User logged in",
    "ERROR: Out of memory",
    "WARNING: Disk space low",
    "INFO: File uploaded",
    "ERROR: Database connection failed"
  )

  /*
  * Con map(_.split(":")(0)), hacemos un map a cada elemento al cual le aplicamos
  * split hasta : a cada lista de caracteres y nos quedamos con el primer elemento
  *
  * Luego hacemos un mapa con groupBy, agrupando a cada elemento como clave y
  * asociándole como valor una lista cuyo contenido son los elementos que coinciden
  * con la clave
  *
  * Con ese map lo que hacemos es separar cada clave-valor para cambiar el tipo
  * de los datos del mapa, de cadena a lista a cadena y tamaño de la lista*/
  val logMessagesTypeCounter = logs
    .map(_.split(":")(0))
    .groupBy((x => x))
    .map{case (k -> list) => (k -> list.size )}

  val logErrorList = logs
    .filter(_.startsWith("ERROR:"))

  println(logMessagesTypeCounter)
  println(logErrorList)
}
