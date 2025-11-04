val logs = List(
  "ERROR: Null pointer exception",
  "INFO: User logged in",
  "ERROR: Out of memory",
  "WARNING: Disk space low",
  "INFO: File uploaded",
  "ERROR: Database connection failed"
)

/**
 * .groupBy[K](f: A => K): Map[K, C]
 * Devuelve un mapa tal que por el resultado de la función como clave
 * asociando en listas la frecuencia de cada clave*/

val logCounts = logs
  // Nos quedamos con la primera palabra => ERROR, INFO, etc
  .map(_.split(":")(0))
  .groupBy(x => x) // ó .groupBy(identity)
  .map{case(k -> v) => (k -> v.size)} // Cambia la forma del mapa de una clave k a una lista
                                      // a esa clave k con el tamaño de la lista como valor
val errorMessages = logs.filter(_.startsWith("ERROR:"))

object ejercicio_11 extends App{
 println(logCounts)
 println(errorMessages)
 
}
