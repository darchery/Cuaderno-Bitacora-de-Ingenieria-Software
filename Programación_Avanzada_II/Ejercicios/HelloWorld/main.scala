object main {
  def main(args: Array[String]): Unit=
    val array = new Array[String](3)
    array(0) = "Hola"
    array(1) = ","
    array(2) = "Mundo"
    println(array(0))
    array(0) = "Adios"
    println(array(0))

    array.update(0, "Hola")
    println(array.apply(0))

    val vector = Array(1,2,3,4)

    var i = 0
    while (i < vector.length) {
      println(vector(i))
      i += 1 // i.+=(1)
    }

    for (i <- 0 until vector.length) {
      println(i + " ")
    }

    for (i <- 0 to vector.length - 1) {
      println(i + " ")
    }

    for (i <- 0 until vector.length) {
      print(s"$i ")
    }

    for (v<-vector) print(s"$v ")

    vector.foreach((n: Int) => print(s"$n "))
    vector.foreach(println)

    println("Hello World!\n")


  def max(x: Int, y: Int) =
    if (x > y) x else y

  def variables(args: Array[String]): Unit={
    val c = 0;
    val d : Int = 4;
    var x = 1;
    var y : Float = 3.1F;
    var z : Double = 3.14159;
    /*c = 2;  Error */
  }
}

// TODO ES UN OBJETO EN SCALA
