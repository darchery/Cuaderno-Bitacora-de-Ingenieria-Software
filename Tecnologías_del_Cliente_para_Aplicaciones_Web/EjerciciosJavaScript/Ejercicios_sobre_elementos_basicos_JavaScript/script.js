function titulo(texto) {
    console.log("\n" + "=".repeat(80) + "\n" + texto + "\n" + "=".repeat(80));
}
function separador() {
    console.log("-".repeat(80));
}

// ============================================================================
// TIPOS, VARIABLES Y CONSTANTES
// ============================================================================

/*
 * 1. Tipado dinámico y typeof:
 * Declara una variable con let y asígnale sucesivamente un número, una cadena, 
 * un booleano y null. Tras cada asignación, muestra por consola el valor y el 
 * resultado de aplicarle typeof. Observa y comenta en el código por qué 
 * typeof null devuelve "object" en lugar de "null".
 * 
 * Los objetos tiene la etiqueta 0, null se representa con un puntero NULL(0x00)
 * Cuando typeof verificaba la etiqueta de tipo null, no lo distinguía de un objeto,
 * porque compartían la misma representación interna => por eso devuelve object
 */
titulo("Ejercicio 1: Tipado dinámico y typeof")
let x = 3;
console.log(x, ":", typeof(x))

x = "hola";
console.log(x, ":", typeof(x))

x =  true;
console.log(x, ":", typeof(x))

x = null;
console.log(x, ":", typeof(x))
separador()

/*
 * 2. Tipos envoltura (wrapper types):
 * Declara el número 3.14159 en una variable y aplícale los métodos toString(), 
 * toFixed(2) y toExponential(). Muestra los tres resultados por consola.
 * Explica en un comentario por qué es posible llamar a métodos sobre un
 * valor primitivo de tipo number.
 * 
 * Porque JS, convierte automáticamente el primitivo en un Wrapper asociado al primitivo
 * Ej: int => new Number()
 */
titulo("Ejercicio 2: Tipos envoltura (wrapper types)")
let pi = 3.14159;
console.log("Pi: " + pi + ": " + typeof(pi))
piS = pi.toString()
console.log("String: " + piS + ": " + typeof(piS))
piF = pi.toFixed(2)
console.log("Fixed: " + piF + ": " + typeof(piF))
piE = pi.toExponential()
console.log("Exponential: " + piE + ": " + typeof(piE))
separador()

/*
 * 3. Constantes y objetos mutables:
 * Declara con const un objeto que represente un libro con las propiedades titulo, 
 * autor y paginas. A continuación modifica el número de páginas y añade una 
 * nueva propiedad editorial. Muestra el objeto por consola antes y después de 
 * las modificaciones. Intenta reasignar la constante a otro objeto y
 * observa el error que se produce.
 * 
 * const NO permite reasignar la variable a otro valor, pero si modificar las propiedades
 */
titulo("Ejercicio 3: Constantes y objetos mutables")
const libro = {
    titulo: "Vagabond #1", autor: "Takehiko Inoue", paginas: "192"
}
console.log("Libro original:", libro)

libro.paginas = "220"
libro.editorial = "Ivrea"
console.log("Libro modificado:", libro)
 
// libro = {otroLibro: "Prueba"} //TypeError: Assignment to constant variable.
separador()
/*
 * 4. Coalescencia nula (??):
 * Declara cuatro variables: una con valor null, una con undefined, una con 0 y 
 * una con la cadena vacía "". Para cada una, usa el operador ?? para
 * asignarle un valor por defecto de "valor por defecto" si la variable es null 
 * o undefined. Muestra los resultados por consola y explica en qué se 
 * diferencia ?? del operador ||.
 * 
 * Uno elige un valor en caso de que sea null o undefined, y el otro es un operador lógico
 * 
 */
titulo("Ejercicio 4: Coalescencia nula (??)")
const a = null ?? "valor por defecto"
const b = undefined ?? "valor por defecto"
const c = 0
const d = ""

console.log("Null: " + a)
console.log("Undefined: " + b)
console.log("Zero: " + c)
console.log("'': " + d)

separador()
// ============================================================================
// NÚMEROS Y OPERADORES
// ============================================================================

/*
 * 5. Operaciones aritméticas y de comparación:
 * Declara dos variables numéricas y calcula con ellas: suma, resta, producto,
 * división, resto (%) y exponenciación (**). Luego compara los dos números 
 * con ==, ===, != y !== usando una de las variables con su valor numérico y 
 * una cadena con el mismo dígito (por ejemplo, 5 y "5"). Muestra todos los 
 * resultados por consola y comenta las diferencias entre == y ===.
 */

titulo("Ejercicio 5: Operaciones aritméticas y de comparación")
let ej5_x = 2
let ej5_y = 3

console.log("Suma: " + (ej5_x + ej5_y), "==:" + (ej5_x + ej5_y == "5"), "===:" + (ej5_x + ej5_y === "5"), 
    "!=:" + (ej5_x + ej5_y != "5"), "!==:" + (ej5_x + ej5_y !== "5"))
console.log("Resta: " + (ej5_x - ej5_y), "==:" + ((ej5_x - ej5_y) == "-1"), "===:" + ((ej5_x - ej5_y) === "-1"),
    "!=:" + ((ej5_x - ej5_y) != "-1"), "!==:" + ((ej5_x - ej5_y) !== "-1"))
console.log("Producto: " + (ej5_x * ej5_y), "==:" + ((ej5_x * ej5_y) == "6"), "===:" + ((ej5_x * ej5_y) === "6"),
    "!=:" + ((ej5_x * ej5_y) != "6"), "!==:" + ((ej5_x * ej5_y) !== "6"))
console.log("División: " + (ej5_x / ej5_y), "==:" + ((ej5_x / ej5_y) == (2/3)), "===:" + ((ej5_x / ej5_y) === (2/3)),
    "!=:" + ((ej5_x / ej5_y) != (2/3)), "!==:" + ((ej5_x / ej5_y) !== (2/3)))
console.log("Resto: " + (ej5_x % ej5_y), "==:" + ((ej5_x % ej5_y) == "2"), "===:" + ((ej5_x % ej5_y) === "2"),
    "!=:" + ((ej5_x % ej5_y) != "2"), "!==:" + ((ej5_x % ej5_y) !== "2"))
console.log("Exponenciación: " + (ej5_x ** ej5_y), "==:" + ((ej5_x ** ej5_y) == "8"), "===:" + ((ej5_x ** ej5_y) === "8"),
    "!=:" + ((ej5_x ** ej5_y) != "8"), "!==:" + ((ej5_x ** ej5_y) !== "8"))
console.log("\nDiferencía == vs ===: == convierte tipos (5 == '5' es true), === no (5 === '5' es false)")
separador()

/*
 * 6. Operador condicional ternario:
 * Escribe una función clasificarNota(nota) que reciba un número entre 0 y
 * 10 y devuelva la calificación usando exclusivamente operadores ternarios
 * anidados: "Suspenso" si es menor que 5, "Aprobado" si está entre 5 y 6.9, 
 * "Notable" si está entre 7 y 8.9 y "Sobresaliente" si es 9 o más. Prueba
 * la función con al menos cinco valores distintos y muestra los resultados
 * con console.log.
 */
titulo("Ejercicio 6: Operador condicional ternario")
function clasificarNota(nota) {
    return nota < 5 ? "Suspenso" : 
        ((nota >= 5 && nota < 7) ? "Aprobado" : 
        ((nota >= 7 && nota < 9) ? "Notable" : "Sobresaliente"))
}
console.log(clasificarNota(4))
console.log(clasificarNota(5))
console.log(clasificarNota(7))
console.log(clasificarNota(9))

separador()
/*
 * 7. Operador in y propiedades de objetos:
 * Crea un objeto vehiculo con las propiedades marca, modelo y año.
 * Usa el operador in para comprobar si las propiedades marca, color y length 
 * pertenecen al objeto. Luego crea un array de cinco elementos y comprueba 
 * con in si los índices 0, 4 y 7 existen, y si la propiedad "length" pertenece 
 * al array. Muestra todos los resultados por consola.
 */
titulo("7. Operador in y propiedades de objetos")
const vehiculo = {
    marca: "Dacia", modelo: "Duster", anyo: "2016"
}
console.log("Marca: ", vehiculo.marca)
console.log("Color: ", vehiculo.color)
console.log("Length: ", vehiculo.length)

let ej7_array = [1, 2, 3, 4, 5]
console.log("Existe índice 0: ", 0 in ej7_array) 
console.log("Existe índice 4: ", 4 in ej7_array)
console.log("Existe índice 7: ", 7 in ej7_array)
console.log("Length: ", ej7_array.length)

separador()
// ============================================================================
// CADENAS
// ============================================================================

/*
 * 8. Operaciones básicas sobre cadenas:
 * Declara la cadena "Desarrollo de Aplicaciones Web". Usando sus
 * métodos, muestra por consola: su longitud, el carácter en la posición
 * 11, si contiene la subcadena "Web", si empieza por "Desa", si termina 
 * en "web" (en minúsculas), la posición de la primera "a" y la subcadena 
 * desde la posición 12 hasta el final.
 */

titulo("8. Operaciones básicas sobre cadenas")
let ej8_cadena = "Desarrollo de Aplicaciones Web"
console.log("Length: ", ej8_cadena.length)
console.log("Caracter pos 11: ", ej8_cadena.at(11))
console.log("Contiene Web: ", ej8_cadena.includes("Web"))
console.log("Empieza por Desa: ", ej8_cadena.startsWith("Desa"))
console.log("Termian en web: ", ej8_cadena.endsWith("web"))
console.log("Posición primera: ", ej8_cadena.indexOf("a"))
console.log("Subcadena desde la posición 12: ", ej8_cadena.substring(12))
separador()
/*
 * 9. Transformación y sustitución de cadenas:
 * Declara la cadena "la programación en javascript es divertida". A
 * partir de ella, muestra por consola: la cadena en mayúsculas, la cadena
 * con la primera letra de cada palabra en mayúscula (resuélvelo combinando 
 * split, map y join), la cadena con todas las apariciones de "a" sustituidas 
 * por "@" usando replaceAll, y la longitud de la cadena resultante.
 */
titulo("9. Transformación y sustitución de cadenas")
let ej9_cadena = "la programación en javascript es divertida"
console.log("Mayus: ", ej9_cadena.toUpperCase())
console.log("Primera letra mayus: ", ej9_cadena.split(" ").map(palabra => palabra.charAt(0).toUpperCase() + palabra.slice(1)).join(" "))
// Dividimos la cadena entre espacios, cambios el primer caracter de cada palabra a mayus, y unimos ese caractar a la palabra partida desde
// la posición 1, luego hacemos un join entre espacios para dejarlo como antes
console.log("Replace: ", ej9_cadena.replaceAll("a", "@"))
console.log("Length: ", ej9_cadena.length)

separador()
/*
 * 10. Cadenas de plantilla (template literals):
 * Crea un objeto producto con las propiedades nombre, precio y cantidad. 
 * Usando exclusivamente cadenas de plantilla (sin concatenación con +), genera 
 * y muestra por consola: una línea de descripción del producto, el precio 
 * total (precio × cantidad) formateado con dos decimales usando toFixed, y 
 * un mensaje que indique si el stock es bajo (menos de 5 unidades) usando el 
 * operador ternario dentro de la plantilla.
 */

titulo("10. Cadenas de plantilla(template literals)")
const producto = {
    nombre: "Poke", precio: "5.5", cantidad: "2"
}
console.log("Descripación: ", `El ${producto.nombre} cuesta ${producto.precio} €, unidades: ${producto.cantidad}`)
console.log("Precio total: ", `${(new Number(producto.cantidad) * new Number(producto.precio)).toFixed(2)}`)
console.log("Stock: ", producto.cantidad < 5 ? "Stock bajo" : "Stock suficiente")

separador()
/*
 * 11. Cadenas multilínea y split/join:
 * Declara una cadena multilínea con comillas invertidas que contenga tres 
 * versos de un poema (inventados). Muestra la cadena completa por consola. 
 * Luego usa split("\n") para obtener un array con los versos, muestra
 * cuántos versos hay y reconstrúyela usando join(" / ") para
 * mostrarla en una sola línea.
 */

titulo("11. Cadenas multilínea y split/join")
let ej11_multi = `Hola, soy un ejercicio muy complicado y esto, es un poema inventado,
mirame, me estoy acabando porque ya estoy cansado`
console.log("Texto normal: ", ej11_multi)
console.log("Texto separado: ", ej11_multi.split("\n"))
console.log("Número versos: ", ej11_multi.split("\n").length)
console.log("Unido: ", ej11_multi.split("\n").join("\n"))
separador()

// ============================================================================
// ARRAYS
// ============================================================================

/*
 * 12. Operaciones básicas: push, pop, shift, unshift y splice:
 * Crea un array con los nombres de cinco frutas. Aplica en orden las
 * siguientes operaciones mostrando el estado del array tras cada una:
 * añade una fruta al final, elimina la primera fruta, añade dos frutas al
 * principio, elimina la fruta de la posición 3 con splice.
 * Muestra también el valor devuelto por cada operación.
 */

titulo("12. Operaciones básicas: push, pop")
let ej12_arr = ["Tomate", "Aguacate", "Aceituna", "Piña", "Albaricoque"]
console.log("Inicio:", ej12_arr)

ej12_arr.push("Pitaya")
console.log("Fruta al final:", ej12_arr)

ej12_arr.shift()
console.log("Elimana primera fruta: ", ej12_arr)

ej12_arr.unshift("Pera", "Melocotón")
console.log("Añade 2 frutas: ", ej12_arr)

ej12_arr.splice(3, 1) // Desde el index 3, borra 1 elemento
console.log("Elimina la fruta, index 3: ", ej12_arr)

separador()
/*
 * 13. Búsqueda en arrays: includes, indexOf y lastIndexOf:
 * Crea el array [10, 20, 30, 20, 40, 20, 50]. Para el valor 20, muestra por 
 * consola: si está incluido en el array, la posición de su primera aparición, 
 * la posición de su última aparición y cuántas veces aparece (resuélvelo con 
 * un bucle o con filter). Haz lo mismo para el valor 99.
 */

titulo("13. Búsqueda en arrays: includes, indexOf y lastIndexOf")

let ej13_arr = [10, 20, 30, 20, 40, 20, 50]

console.log(ej13_arr.includes(20))
console.log(ej13_arr.indexOf(20))
console.log(ej13_arr.lastIndexOf(20))


separador()
/*
 * 14. concat, toString y join:
 * Crea dos arrays de números: los cinco primeros pares positivos y los cinco 
 * primeros impares positivos. Concaténalos con concat y muestra el resultado. 
 * Luego muestra el array resultante como cadena usando toString y usando 
 * join(" - "). Finalmente muestra la longitud del array concatenado.
 */
titulo("14. concat, toString y join")


let ej14_arr1 = [2, 4, 6, 8, 10]
let ej14_arr2 = [1, 3, 5, 7, 9]
let ej14_res = ej14_arr1.concat(ej14_arr2)
console.log(ej14_res)
console.log(ej14_res.toString())
console.log(ej14_res.join("-"))
console.log(ej14_res.length)

separador()

/*
 * 15. Iteración con for, for..of y forEach:
 * Dado el array ["lunes", "martes", "miércoles", "jueves", "viernes"],
 * recórrelo de tres formas distintas: con un bucle for clásico mostrando el 
 * índice y el valor, con for..of mostrando solo el valor en mayúsculas, y con 
 * el método forEach mostrando el valor seguido de su longitud. Usa console.log 
 * en los tres casos.
 */
titulo("15. Iteración con for, for..of y forEach")

let ej15_arr = ["lunes", "martes", "miércoles", "jueves", "viernes"]

for (let i = 0; i < ej15_arr.length; i++) {
    console.log("Índice: ", i, ", Valor: ", ej15_arr[i])
} 

for (const dia of ej15_arr) {
    console.log("Valor: " + dia.toUpperCase())

}

ej15_arr.forEach( dia =>
    console.log("Valor: ", dia , ", Longitud: ", dia.length)
)


separador()
/*
 * 16. map y filter:
 * Dado el array de números [3, 7, 2, 9, 4, 11, 6, 8, 1, 5], usa map para 
 * obtener un nuevo array con el cuadrado de cada elemento y filter para 
 * obtener un array solo con los números mayores que 5. Luego encadena filter 
 * y map en una sola expresión para obtener los cuadrados de los números mayores 
 * que 5. Muestra los tres resultados por consola.
 */
titulo("16. map y filter")

let ej16_arr = [3, 7, 2, 9, 4, 11, 6, 8, 1, 5]
console.log(ej16_arr.map(num => num*num))
console.log(ej16_arr.filter(num => num > 5))
console.log(ej16_arr.filter(num => num > 5).map(num => num*num))

separador()
// ============================================================================
// FUNCIONES
// ============================================================================

/*
 * 17. Definición, parámetros por defecto y valor de retorno:
 * Define una función imc(peso, altura, unidad = "métrico") que calcule el 
 * Índice de Masa Corporal (peso en kg dividido por la altura en metros al
 * cuadrado). Si unidad es "imperial", convierta primero libras a kg 
 * (1 lb = 0,453592 kg) y pulgadas a metros (1 in = 0,0254 m). Prueba la función 
 * con y sin el tercer parámetro y muestra los resultados con console.log.
 */
titulo("17. Función IMC")
function imc(peso, altura, unidad="métrico") {
    if (unidad == "imperial") {
        peso = peso * 0.453592
        altura = altura * 0.0254
    }
    return peso/(altura**2)
}

console.log(imc(95, 1.88))                  // métrico por defecto
console.log(imc(209.44, 74, "imperial"))    // aprox equivalente a 95kg y 1.88m
separador()
/*
 * 18. Funciones anónimas y expresiones de función:
 * Escribe la misma función de tres formas distintas: como función declarada con 
 * function, como expresión de función asignada a una constante y como función 
 * flecha asignada a una constante. La función debe recibir un array de números 
 * y devolver su media aritmética. Verifica que las tres versiones producen el 
 * mismo resultado con el array [4, 8, 15, 16, 23, 42].
 */
titulo("18. Funciones anónimas y expresiones de función")

function ej18_function(arr) {
    return arr.reduce((total, num) => total += num, 0)/arr.length
}
console.log(ej18_function([4, 8, 15, 16, 23, 42]))

const ej18_const = function (arr) {
    return arr.reduce((total, num) => total += num, 0)/arr.length
}
console.log(ej18_const([4, 8, 15, 16, 23, 42]))

const ej18_arrow = (arr) => {
    return arr.reduce((total, num) => total += num, 0)/arr.length
}
console.log(ej18_arrow([4, 8, 15, 16, 23, 42]))

separador()
/*
 * 19. Funciones flecha y sintaxis abreviada:
 * Dado el array ["Ana", "Carlos", "Beatriz", "David", "Elena"], usa
 * funciones flecha en su forma más abreviada (sin llaves ni return) para: 
 * obtener un array con las longitudes de cada nombre, filtrar los nombres que 
 * tengan más de 5 letras y obtener un array con todos los nombres en formato 
 * "Hola, [nombre]!". Muestra los tres resultados por consola.
 */
let ej19_arr = ["Ana", "Carlos", "Beatriz", "David", "Elena"]

const ej19_a = (arr) =>
    arr.map(elem => elem.length)
console.log(ej19_a(ej19_arr))

const ej19_b = (arr) =>
    arr.filter(elem => elem.length > 5)
console.log(ej19_b(ej19_arr))

const ej19_c = (arr) => 
    arr.map(elem => "Hola, " + elem + "!")
console.log(ej19_c(ej19_arr))

// Todo combinado
const ej19_arrow = (arr) => 
    arr.filter(elem => elem.length > 5).map(elem => "Hola, " + elem + "!")

console.log(ej19_arrow(ej19_arr))


/*
 * 20. Ámbito de variables: let vs. variables globales:
 * Escribe un bloque de código que demuestre la diferencia de ámbito entre una 
 * variable declarada con let dentro de un bloque {} y una variable declarada sin 
 * let (global implícita). Declara también una variable con let dentro de una 
 * función e intenta acceder a ella desde fuera. Documenta con comentarios qué 
 * ocurre en cada caso y por qué se recomienda siempre declarar las variables 
 * con let o const.
 */
titulo("20. Ámbito de variables: let vs. variables globales")

// 1. Variable con let dentro de un bloque {}
{
    let dentroBloque = "solo dentro del bloque";
    console.log("Dentro del bloque:", dentroBloque); // ✓ Funciona
}
// console.log(dentroBloque); // ✗ ReferenceError: dentroBloque is not defined
// let tiene ámbito de bloque: solo existe dentro de las llaves {}

// 2. Variable sin let (global implícita) - NO RECOMENDADO
{
    sinLet = "global implícita";
    console.log("Dentro del bloque:", sinLet); // ✓ Funciona
}
console.log("Fuera del bloque:", sinLet); // ✓ También funciona (es global)
// Sin let/const, la variable se convierte en global automáticamente (peligroso)
// Puede ser modificada desde otro fichero HTML si se llaman de la misma forma

// 3. Variable con let dentro de una función
function ej20_prueba() {
    let dentroFuncion = "solo en la función";
    console.log("Dentro de función:", dentroFuncion); // ✓ Funciona
}
ej20_prueba();
// console.log(dentroFuncion); // ✗ ReferenceError: dentroFuncion is not defined
// let tiene ámbito de función: no es accesible fuera de ella

// Conclusión: Siempre usar let o const evita crear variables globales accidentalmente
// y hace el código más predecible y fácil de mantener

separador()

// ============================================================================
// OBJETOS
// ============================================================================

/*
 * 21. Creación y acceso a propiedades:
 * Crea un objeto biblioteca con al menos tres propiedades que sean a su vez
 * objetos, cada uno representando un libro con titulo, autor, año y disponible
 * (booleano). Accede a las propiedades usando tanto el operador punto como
 * la notación con corchetes y una variable que contenga el nombre de la
 * propiedad. Muestra por consola el título del segundo libro y el autor
 * del tercero.
 */
titulo("21. Creación y acceso a propiedades")

const biblioteca = {
    libro1: {
        titulo: "Absolute Batman #12", autor: "Scott Snyder y Nick Dragotta", anyo: "2025", disponible: true
    },
    libro2: {
        titulo: "Ataque a los titanes #1", autor: "Hajime Iyasama", anyo: "2010", disponible: true
    },
    libro3: {
        titulo: "Superman: Las 4 estaciones", autor: "Jeph Loeb y Tim Sale", anyo: "1998", disponible: true
    }
}
console.log(biblioteca.libro2.titulo)
console.log(biblioteca.libro3["autor"])
const ej21_propiedad = "titulo"
console.log(biblioteca.libro1[ej21_propiedad])

separador()

/*
 * 22. Añadir propiedades y métodos a un objeto:
 * Crea un objeto calculadora vacío {}. Añádele dinámicamente (tras su creación) 
 * las propiedades marca y modelo, y los métodos sumar(a, b), restar(a, b), 
 * multiplicar(a, b) y dividir(a, b), donde dividir debe devolver un mensaje de 
 * error si el divisor es cero. Prueba todos los métodos con console.log.
 */
titulo("22. Añadir propiedades y métodos a un objeto")

const calculadora = {}
calculadora.marca = "Casio"
calculadora.modelo = "Vn-570MS"
calculadora.sumar = function(a, b) {
    return a + b
}
calculadora.restar = function(a, b) {
    return a - b
}
calculadora.multiplicar = function(a, b) {
    return a * b
}
calculadora.dividir = function(a, b) {
    if (b == 0) {
        return "ERROR: No se puede dividir por cero"
    } else {
        return a / b
    }
}

console.log(calculadora.sumar(2, 3))
console.log(calculadora.restar(2, 3))
console.log(calculadora.multiplicar(2, 3))
console.log(calculadora.dividir(2, 3))
console.log(calculadora.dividir(2, 0))

separador()
/*
 * 23. Constructores y this:
 * Define una función constructora Estudiante(nombre, apellido, curso)
 * que cree objetos con esas tres propiedades y los métodos nombreCompleto() 
 * (que devuelve nombre y apellido concatenados) y presentacion() (que muestra 
 * por consola una frase de presentación usando this). Crea tres instancias
 * con new y llama a sus métodos. Comprueba con typeof e instanceof el tipo 
 * de los objetos creados.
 */
titulo("23. Constructores y this")

function Estudiante(nombre, apellido, curso) {
    this.nombre = nombre
    this.apellido = apellido
    this.curso = curso

    this.nombreCompleto = function() {
        return nombre + " " + apellido
    }
    this.presentacion = function() {
        console.log("¡Hola, me llamo ", nombre, "!")
    }
}

const lucasEstudiante = new Estudiante("Lucas", "Díaz", "3ºA")
console.log(typeof(lucasEstudiante))
console.log(lucasEstudiante instanceof Estudiante)
console.log(lucasEstudiante.nombreCompleto())
lucasEstudiante.presentacion()

const daniEstudiante = new Estudiante("Danis", "Alcaide", "4ºA")
console.log(typeof(daniEstudiante))
console.log(daniEstudiante instanceof Estudiante)
console.log(daniEstudiante.nombreCompleto())
daniEstudiante.presentacion()


const martaEstudiante = new Estudiante("Marta", "Díaz", "4ºESO")
console.log(typeof(martaEstudiante))
console.log(martaEstudiante instanceof Estudiante)
console.log(martaEstudiante.nombreCompleto())
martaEstudiante.presentacion()


separador()
// ============================================================================
// EVENTOS (Mínimo uso del DOM)
// ============================================================================

/*
 * 24. Manejadores de eventos con addEventListener:
 * Crea una página HTML mínima con un único botón. Asocia al evento click del 
 * botón tres manejadores distintos usando addEventListener: el primero
 * muestra un alert con la hora actual, el segundo muestra por consola las 
 * coordenadas del ratón (clientX, clientY) en el momento del clic usando el 
 * objeto evento, y el tercero incrementa un contador interno y lo muestra en 
 * un alert. Verifica que los tres manejadores se ejecutan al mismo tiempo al 
 * pulsar el botón.
 */
titulo("24. Manejadores de eventos con addEventListener")

// Verificamos si estamos en un navegador (document existe)
if (typeof document !== 'undefined') {
    const ej24_button = document.querySelector("#ej24")
    
    // Primer manejador: muestra la hora actual
    ej24_button.addEventListener("click", () => {
        alert(new Date())
    })
    
    // Segundo manejador: muestra coordenadas del ratón
    ej24_button.addEventListener("click", (event) => {
        console.log("Coordenadas: X-", event.clientX, " Y-", event.clientY)
    })

    let cnt = 0
    ej24_button.addEventListener("click", () => {
        cnt++
        alert(cnt)
    })
} else {
    console.log("⚠️ Ejercicio 24: Abre index.html en el navegador para probar los eventos")
}

separador()
/*
 * 25. preventDefault y objeto evento:
 * Crea una página HTML con un formulario que tenga dos campos de texto (nombre
 * y correo electrónico) y un botón de envío. Usa addEventListener sobre el evento 
 * submit del formulario para interceptarlo y validar que ningún campo está vacío 
 * y que el correo contiene el carácter @. Si la validación falla, llama a 
 * preventDefault() para evitar el envío y muestra un alert con el error concreto. 
 * Si la validación es correcta, muestra un alert de confirmación con los datos
 * introducidos usando una cadena de plantilla.
 */
titulo("25. preventDefault y objeto evento")

if (typeof document !== 'undefined') {
    const ej26_form = document.querySelector("#ej26_form")
    const ej26_name = document.getElementById("ej26_name")
    const ej26_email = document.getElementById("ej26_email")

    ej26_form.addEventListener("submit", (e) => {
        if (ej26_name.value === "" || ej26_email.value === "" || !(ej26_email.value).contains("@")) {
            e.preventDefault()

            if(ej26_name.value === "") {
                alert("ERROR: El nombre está vacío")
            }
            if(ej26_email.value === "") {
                alert("ERROR: El email está vacío")
            }
            if(!(ej26_email.value).contains("@")) {
                alert("ERROR: El email no contiene '@'")
            }
        } else {
            alert("CONFIRM: Todos los parámetros tienen el formato correcto")
        }
    })
} else {
    console.log("⚠️ Ejercicio 25: Abre index.html en el navegador para probar los eventos")
}
separador()

