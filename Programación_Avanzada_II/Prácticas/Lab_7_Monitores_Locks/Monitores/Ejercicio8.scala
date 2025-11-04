package esqueletosLaboratorio7

import scala.util.Random

object gestorAgua {
  //CS-Hid1: El hidrógeno que quiere formar una molécula espera si ya hay dos hidrógenos
  //CS-Hid2: Un hidrógeno debe esperar a los otros dos átomos para formar la molécula
  //CS-Ox1: El oxígeno que quiere formar una molécula espera si ya hay un oxígeno
  //CS-Ox2: El oxígeno debe esperar a los otros dos átomos para formar la molécula


  def hidrogeno(id: Int) =  {
    //el oxigeno id quiere formar una molécula

    log(s"Hidrógeno $id quiere formar una molécula")

      //log(s"      Molécula formada!!!")

  }



  def oxigeno(id: Int) =  {
    //el oxigeno id quiere formar una molécula

    log(s"Oxígeno $id quiere formar una molécula")

      //log(s"      Molécula formada!!!")

  }

}
object Ejercicio8 {

  def main(args:Array[String]) =
    val N = 1
    val hidrogeno = new Array[Thread](2*N)
    for (i<-0 until hidrogeno.length)
      hidrogeno(i) = thread{
        Thread.sleep(Random.nextInt(500))
        gestorAgua.hidrogeno(i)
      }
    val oxigeno = new Array[Thread](N)
    for(i <- 0 until oxigeno.length)
      oxigeno(i) = thread {
        Thread.sleep(Random.nextInt(500))
        gestorAgua.oxigeno(i)
      }
    hidrogeno.foreach(_.join())
    oxigeno.foreach(_.join())
    log("Fin del programa")
}
