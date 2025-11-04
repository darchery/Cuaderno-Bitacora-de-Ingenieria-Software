package examenes.P2_Semaforos_2025_FiestaDecano

import java.util.concurrent.Semaphore
import scala.util.Random
class Salon(cap:Int){

  /*
   * Condiciones sincronización del ejercicio 1
   * CS-Dec1: El decano no entra en la salon hasta que lo avisan de que se ha excedido el aforo
   * CS-Dec2: El decano espera a que se vacíe el salón para volver a dormir
   * CS-Est1: Un estudiante no puede entrar si el decano está en ella
   */

  /*
  * Condiciones sincronización del ejercicio 2
  * CS-Est2: Un estudiante que está en la fiesta no puede salir si el decano ha sido avisado
  */

  private var numEstudiantes = 0
  private var avisadoDecano = false // Variable para avisar al decano Y solo mandar el mensaje una sóla vez
  private var enSalaDecano = false // Indica si el decano está despierto/en la sala o no

  // Ejercicio 1
  private val mutex = new Semaphore(1)
  private val hayHuecoFiesta = new Semaphore(1) // CS-Est
  private val despertarDecano = new Semaphore(0) // CS-Dec1
  private val esperoVaciado = new Semaphore(0) // CS-Dec2

  // Ejercicio 2
  private val puedoSalirFiesta = new Semaphore(1) // CS-Est2

  def llegoAFiesta(id:Int)={
    //El estudiante llama a este método cuando quiere entrar en la fiesta

    hayHuecoFiesta.acquire() // Puede entrar si no => Se bloque la hebra si el decano ha entrado
    mutex.acquire()

    numEstudiantes += 1
    log(s"Estudiante $id llega a la fiesta. Hay ${numEstudiantes}")


    if (!avisadoDecano && numEstudiantes == cap) { // Si aún no se ha avisado y se llegó al límite => avisamos
      //el estudiante que detecta que se ha superado el aforo avisa al decano
      log(s"        Estudiante ${id} avisó al decano. Hay ${numEstudiantes}")
      avisadoDecano = true
      puedoSalirFiesta.acquire() // No pueden salir los estudiantes que han sobrepasado el cap tras un bloqueo
      despertarDecano.release() // Despertamos al decano

    }

    mutex.release()
    hayHuecoFiesta.release() // Dejamos que entre(ya que no hay límite hasta que entre el decano)
  }

  def salgoFiesta(id:Int)={
    //estudiante id llama a este método cuando quiere abandonar la fiesta

    puedoSalirFiesta.acquire()
    mutex.acquire()

    numEstudiantes -= 1
    log(s"Estudiante $id sale de la fiesta. Hay ${numEstudiantes}")

    if (enSalaDecano && numEstudiantes == 0) { // Si ya está el decano y no hay estudiantes avisamos al decano
      esperoVaciado.release()
      enSalaDecano = false
      avisadoDecano = false
    }

    mutex.release()
    puedoSalirFiesta.release()
  }

  def meDuermo()= {
    //El decano llama a este método cuando quiere dormir
    //se despierta cuando le avisan de que se ha superado el aforo

    despertarDecano.acquire() // Confirmamos el aviso
    log(s"Decano: me despierto")

    mutex.acquire()
    enSalaDecano = true
    mutex.release()

    hayHuecoFiesta.acquire() // Como el decano está dentro => Nadie puede entrar
    log(s"Decano: entro en la sala: ya sé quienes son. Los estudiantes pueden salir")
  }
  def esperoTodosFuera()={
    //El decano llama a este método para esperar a que salgan del solón todos los estudiantes

    log(s"Decano: espero que salgan todos")
    puedoSalirFiesta.release() // Liberamos el bloque que le asignó el estudiante que dió la voz al Decano
    esperoVaciado.acquire() // Bloqueamos al decano para dar paso a la salida de alumnos

    log(s"Decano: me voy otra vez a dormir")
    hayHuecoFiesta.release() // Indicamos que la fiesta se abre otra vez
  }
}
object ejemResidencia {

  def main(args:Array[String]):Unit={
    val R = 20
    val Cap = 5
    val F = 1
    val salon = new Salon(Cap)
    val estudiante = new Array[Thread](R)
    for (i<-estudiante.indices)
      estudiante(i) = thread{
        for (j<-0 until F)
          Thread.sleep(Random.nextInt(700))
          salon.llegoAFiesta(i)
          Thread.sleep(100)
          salon.salgoFiesta(i)
          Thread.sleep(700)
      }
    val decano = thread{
      var fin =false
      while (!fin && !Thread.interrupted()){
        try{
          Thread.sleep(Random.nextInt(200))
          salon.meDuermo()
          salon.esperoTodosFuera()
        } catch {
          case e:InterruptedException => fin = true
        }
      }
    }
    estudiante.foreach(_.join())
    decano.interrupt()
    decano.join()
    log(s"Todos los estudiantes y el decano se han ido a dormir")
  }

}
