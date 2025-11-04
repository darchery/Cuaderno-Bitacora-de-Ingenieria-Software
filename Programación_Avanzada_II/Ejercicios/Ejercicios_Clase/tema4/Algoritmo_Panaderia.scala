package tema4

object Algoritmo_Panaderia {
  val N = 10
  val i  = 0

  var turno = new Array[Int](N)

  turno(i) = turno.max + 1

  for (j<-0 until N)
    while (leToca(i, j)) {}
    // SCI
    turno(i) = 0
  

  def leToca(i: Int, j: Int): Boolean =
    // = true si le toca a j antes que a i
    if (turno(j) != 0 && turno(j) < turno(i)) true
    else if (turno(i) == turno(j) && j < i) true
    else false
}
