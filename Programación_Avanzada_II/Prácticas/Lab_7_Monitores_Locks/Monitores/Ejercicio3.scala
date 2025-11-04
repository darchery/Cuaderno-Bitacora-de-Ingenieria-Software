package esqueletosLaboratorio7

object Parejas{
  var hayHombre = false
  var hayMujer = false
  var nPersonas = 0

  def llegaHombre(id:Int) = synchronized {
    while (hayHombre) wait() // Si hay otro hombre -> Espera

    hayHombre = true
    nPersonas += 1
    log(s"Hombre $id quiere formar pareja")
    notifyAll() // Avisamos a las mujeres(y a todos)

    if (nPersonas < 2) { // Si aún no se ha presentado la pareja
      while (!hayMujer) wait()
    } else {
      log("Se ha formado una pareja!!!")
      hayHombre = false
      hayMujer = false
      nPersonas = 0
    }
  }

  def llegaMujer(id: Int) =  synchronized {
    while(hayMujer) wait()

    hayMujer = true
    nPersonas += 1
    log(s"Mujer $id quiere formar pareja")
    notifyAll()

    if (nPersonas < 2) {
      while (!hayHombre) wait()
    } else {
      log("Se ha formado una pareja!!!")
      hayHombre = false
      hayMujer = false
      nPersonas = 0
    }
  }
}
object Ejercicio3 {

  def main(args:Array[String]):Unit = {
    val NP = 10
    val mujer = new Array[Thread](NP)
    val hombre = new Array[Thread](NP)
    for (i<-mujer.indices)
      mujer(i) = thread{
        Parejas.llegaMujer(i)
      }
    for (i <- hombre.indices)
      hombre(i) = thread {
        Parejas.llegaHombre(i)
      }
  }

}
