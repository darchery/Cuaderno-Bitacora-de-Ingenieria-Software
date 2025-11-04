package examenes.Septiembre2018_Hombre_Mujer

object Principal extends App {

  val aseo = new Aseo
  val hombres = Array.tabulate(10)(i => new Hombre(aseo, i))
  val mujeres = Array.tabulate(10)(i => new Mujer(aseo, i))

  hombres.foreach(_.start())
  mujeres.foreach(_.start())
}
