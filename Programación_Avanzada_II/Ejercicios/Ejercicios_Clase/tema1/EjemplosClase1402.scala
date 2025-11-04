package tema1

object EjemplosClase1402 {
  // Hello world main
  def main(args: Array[String]): Unit = {
    println("Hola Mundo!")
  }
  // Imprime el argumento
  def main2(args: Array[String]): Unit = {
    for (i <- 0 until args.length)
      println(args(i))
  }
  // Máximo entre 2 números
  def max(x: Int, y: Int) =
    if (x > y) x
    else y
  // Mínimo entre 3 números
  def min(x: Int, y: Int) =
    if(x < y) x
    else y
  // Función que imprime un saludo
  def saludos(): Unit =
    println("Hola!")
  // Bucles
  /*var i = 0
  while (i < args.lenght) {
    println(args(i))
    i +=1
  }
  
  var i = 0
  while (i < args.length) {
    if (i != 0) print(" ")
    print(args(i))
    i = i + 1
  }
  
  for (i <- 0 until args.length)
    println(args(i))
    
  for (arg <- args)
    println(arg)

  args.foreach((arg : String) =>println(arg))

  args.foreach(println)*/

  // scala > for (i <- 0 until 10 if i % 2 == 0) print(s"$i ")
  // 0 2 4 6 8

  // scala > for (i <- 0 until 10 if i % 2 == 0 if (i > 2)) print(s"$i ")
  // 4 6 8
}
