package examenes.Septiembre2020_Curso_Online

object Principal {
  def main(args: Array[String]): Unit = {
    // Número total de alumnos que realizarán el curso
    val NUMALUMNOS = 15

    val curso = new Curso()

    // Crea NUMALUMNOS alumnos
    val alumnos = Array.tabulate(NUMALUMNOS)(i => new Alumno(i, curso))

    // Inicia la ejecución de los alumnos (hilos)
    alumnos.foreach(_.start())

    // Espera a que todos los alumnos finalicen el curso y termina
    try {
      alumnos.foreach(_.join())
    } catch {
      case e: InterruptedException => e.printStackTrace()
    }
  }
}
