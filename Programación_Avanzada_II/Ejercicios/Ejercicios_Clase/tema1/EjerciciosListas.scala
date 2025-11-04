package tema1

object EjerciciosListas extends App{
  // Creación de la lista
  var lista = List(1, 2, 3, 4, 5, 6, 7, 8)

  // 1. La cabeza de la lista
  println("1. La cabeza de la lista")
  println(lista.head)

  // 2. El resto de la lista
  println("2. El resto de la lista")
  println(lista)

  // 3. Una lista con todos los elementos salvo el 5
  println("3. Una lista con todos los elementos salvo el 5")
  println(lista.filter((n: Int) => n != 5))

  // 4. La longitud de la lista
  println("4. La longitud de la lista")
  println(lista.length)

  // 5. La lista invertida
  println("5. La lista invertida")
  println(lista.reverse)

  // 6. Una lista con el doble de todos los elementos
  println("6. Una lista con el doble de todos los elementos")
  println( lista.map(_*2))

  // 7. Una lista con todos los elementos que son
  // múltiplos de 3
  println("7. Una lista con todos los elementos que son múltiplos de 3")
  println(lista.filter((n: Int) => n%3 == 0))

  // 8. Una lista con todos los múltiplos de 3 invertida
  println("8. Una lista con todos los múltiplos de 3 invertida")
  println(lista.filter((n: Int) => n%3 == 0).reverse)

  // 9. Si todos los elementos son pares
  println("9. Si todos los elementos son pares")
  println(lista.filter((n: Int) => n%2 == 0).length.equals(lista.length))

  // 10. Si exite algún elemento mayor que 5
  println("10. Si exite algún elemento mayor que 5")
  println(lista.exists(_>5))

  // 11. El mayor elemento par de la lista
  println("11. El mayor elemento par de la lista")
  println(lista.filter((n: Int) => n%2 == 0).max)

  // 12. La lista sin el mayor elemento par
  println("12. La lista sin el mayor elemento par")
  println(lista.filter((n: Int) => n != lista.filter((n: Int) => n%2 == 0).max))

  // 13. Si existe un elemento par que sea mayor que 10
  println("13. Si existe un elemento par que sea mayor que 10")
  println(lista.exists((n: Int) => n%2 == 0 && n > 10))
}
