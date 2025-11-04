package esqueletosLaboratorio7
package Locks

import scala.util.Random

object Barca{
  private var nIPhone = 0
  private var nAndroid = 0
  

  def paseoIphone(id:Int) =  {
   
    log(s"Estudiante IPhone $id se sube a la barca. Hay: iphone=$nIPhone,android=$nAndroid ")
    
    
      //log(s"Empieza el viaje....")
      //Thread.sleep(Random.nextInt(200))
      //log(s"fin del viaje....")
      
    
    log(s"Estudiante IPhone $id se baja de la barca. Hay: iphone=$nIPhone,android=$nAndroid ")
   
  }

  def paseoAndroid(id:Int) =  {
    
    log(s"Estudiante Android $id se sube a la barca. Hay: iphone=$nIPhone,android=$nAndroid ")
    
      //log(s"Empieza el viaje....")
      //Thread.sleep(Random.nextInt(200))
      //log(s"fin del viaje....")
      
    log(s"Estudiante Android $id se baja de la barca. Hay: iphone=$nIPhone,android=$nAndroid ")
    
  }
}
object Ejercicio5 {

  def main(args:Array[String]) = {
    val NPhones = 10
    val NAndroid = 10
    val iphone = new Array[Thread](NPhones)
    val android = new Array[Thread](NAndroid)
    for (i<-iphone.indices)
      iphone(i) = thread{
     //   while (true){
          Thread.sleep(Random.nextInt(400))
          Barca.paseoIphone(i)
        //    }
      }
    for (i <- android.indices)
      android(i) = thread {
     //   while (true) {
          Thread.sleep(Random.nextInt(400))
          Barca.paseoAndroid(i)
     //   }
      }
  }
}
