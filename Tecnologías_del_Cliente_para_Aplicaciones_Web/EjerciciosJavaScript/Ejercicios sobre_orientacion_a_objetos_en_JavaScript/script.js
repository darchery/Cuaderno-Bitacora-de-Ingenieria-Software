// ============================================================================
// 12 Ejercicios de Orientación a Objetos en JavaScript
// ============================================================================

/**
 * Imprime un título centrado y formateado en la consola a modo de separador.
 * @param {string} texto - El texto del título.
 */
function titulo(texto) {
  const anchoLinea = 60;
  console.log("\n" + "=".repeat(anchoLinea));
  const espacios = Math.max(0, Math.floor((anchoLinea - texto.length) / 2));
  console.log(" ".repeat(espacios) + texto);
  console.log("=".repeat(anchoLinea));
}

/**
 * Imprime un salto de línea en la consola para separar resultados.
 */
function espacio() {
  console.log("\n");
}


// ============================================================================
// PROTOTIPOS Y CADENA DE PROTOTIPOS
// ============================================================================

// ----------------------------------------------------------------------------
// EJERCICIO 1: Exploración de la cadena de prototipos
// Crea tres objetos usando tres mecanismos distintos: un literal de objeto ({}), 
// una instancia de Date con new Date() y un objeto creado con Object.create() 
// a partir de un objeto base propio. Para cada uno, recorre su cadena de prototipos 
// completa usando un bucle do...while con Object.getPrototypeOf() e imprime 
// cada eslabón por consola hasta llegar a null.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 1: Cadena de Prototipos");

const baseProto = { descripcion: "protótipo base" };

let objeto1 = {};
let objeto2 = new Date();
let objeto3 = Object.create(baseProto);
do {
    objeto1 = Object.getPrototypeOf(objeto1)
    console.log("Objeto 1: ", objeto1) 
} while (objeto1);


do {
    objeto2 = Object.getPrototypeOf(objeto2)
    console.log("Objeto 2: ", objeto2) 
} while (objeto2);

do {
    objeto3 = Object.getPrototypeOf(objeto3)
    console.log("Objeto 3: ", objeto3) 
} while (objeto3);

espacio();


// ----------------------------------------------------------------------------
// EJERCICIO 2: Propiedades propias vs. heredadas
// Define un objeto prototipo 'vehiculo' con las propiedades tipo: "vehículo" y 
// un método describir() que imprima tipo y marca. Crea tres objetos con 
// Object.create(vehiculo) asignándoles distintas marcas. Para cada objeto, usa 
// Object.hasOwn() para determinar qué propiedades son propias y cuáles vienen 
// del prototipo. Después, itera las propiedades de uno de los objetos con for...in 
// y con Object.keys() y observa la diferencia.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 2: Propiedades propias vs. heredadas");

const prototipoVehiculo = {
    describir() {
        console.log("Tipo: ", this.tipo, " , Marca: ", this.marca)
    }
};

function Vehiculo(tipo, marca) {
  this.tipo = tipo;
  this.marca = marca;
}

Object.assign(Vehiculo.prototype, prototipoVehiculo)


const vehiculo1 = Object.create(prototipoVehiculo);
vehiculo1.marca = "Renault";
vehiculo1.tipo = "407"

const vehiculo2 = Object.create(prototipoVehiculo);
vehiculo2.marca = "Dacia";
vehiculo1.tipo = "Duster"

const vehiculo3 = Object.create(prototipoVehiculo);
vehiculo3.marca = "Seat";
vehiculo1.tipo = "Ibiza"

espacio()

const propiedades_vehiculos = ["tipo", "marca", "describir"]

for (prop of propiedades_vehiculos) {
    console.log(`Pertenece ${prop} al ${vehiculo1.marca}  ${vehiculo1.tipo}: ${Object.hasOwn(vehiculo1, prop)}`)
    console.log(`Pertenece ${prop} al ${vehiculo2.marca}  ${vehiculo2.tipo}: ${Object.hasOwn(vehiculo2, prop)}`)
    console.log(`Pertenece ${prop} al ${vehiculo3.marca}  ${vehiculo3.tipo}: ${Object.hasOwn(vehiculo3, prop)}`)
}

espacio()

console.log("Iteración con for...in (incluye heredadas):");
for (const prop in vehiculo1) {
    console.log("-", prop, "(propia:", Object.hasOwn(vehiculo1, prop), ")");
}

console.log("Object.keys (solo propias):", Object.keys(vehiculo1));

espacio();


// ----------------------------------------------------------------------------
// EJERCICIO 3: Ocultación de propiedades en el prototipo
// Crea un objeto base con los métodos saludar() y despedirse(). Crea tres objetos 
// con Object.create(base): el primero sin modificar, el segundo sobreescribiendo 
// solo saludar(), y el tercero sobreescribiendo ambos. Llama a los dos métodos 
// sobre los tres objetos y observa cuál versión se ejecuta en cada caso. 
// Para el tercer objeto, muestra cómo acceder a la versión original.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 3: Ocultación en el prototipo");

const ej3_objeto_base = {
    saludar() {
        console.log("No hago saludo")
    },
    despedirse() {
        console.log("No hago despedida")
    }
}

let ej3_objeto1 = Object.create(ej3_objeto_base) 

let ej3_objeto2 = Object.create(ej3_objeto_base) 
ej3_objeto2.saludar = function () {
    console.log("Saludos")
}

let ej3_objeto3 = Object.create(ej3_objeto_base) 
ej3_objeto3.saludar = function () {
    console.log("Saludos")
} 
ej3_objeto3.despedirse = function () {
    console.log("Hasta luego")
} 

console.log("Objeto 1: ")
ej3_objeto1.saludar()
ej3_objeto1.despedirse()

espacio();

console.log("Objeto 2: ")
ej3_objeto2.saludar()
ej3_objeto2.despedirse()

espacio();

console.log("Objeto 3: ")
ej3_objeto3.saludar()
ej3_objeto3.despedirse()

espacio();

console.log('--- Accediendo a la versión original desde objeto3 ---');
Object.getPrototypeOf(ej3_objeto3).saludar.call(ej3_objeto3);

// ----------------------------------------------------------------------------
// EJERCICIO 4: Prototipo con Object.create() vs. constructor
// Implementa una figura geométrica de dos formas: una con Object.create() 
// y un prototipo explícito, y otra con una función constructora asignando 
// métodos a Figura.prototype. Crea dos instancias con cada versión y verifica 
// con Object.hasOwn() las propiedades propias y heredadas.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 4: Object.create() vs Constructor");

const prototipoFigura = {
    describir() {
        console.log(`Prototipo - Soy la figura ${this.nombre} y tengo ${this.numLados} lados`)
    }
}

function FiguraF_ej4(nombre, numLados) {
    this.nombre = nombre
    this.numLados = numLados
}

Object.assign(FiguraF_ej4.prototype, prototipoFigura)

const figuraF = Object.create(prototipoFigura)
figuraF.nombre = "Cuadrado"
figuraF.numLados = 4

figuraF.describir()

class Figura_ej4 {
    nombre;
    numLados;

    constructor(nombre, numLados) {
        this.nombre = nombre
        this.numLados = numLados
    }
}

Figura_ej4.prototype.describir = function(nombre, numLados){
    console.log(`Constructor -  Soy la figura ${this.nombre} y tengo ${this.numLados} lados`)
}


const figura = new Figura_ej4("Cuadrado", 4)
figura.describir()


espacio()


console.log("Figura con prototype")
console.log("Iteración con for...in (incluye heredadas):");
for (const prop in figuraF) {
    console.log("-", prop, "(propia:", Object.hasOwn(figuraF, prop), ")");
}

console.log("Object.keys (solo propias):", Object.keys(figuraF));

espacio()

console.log("Figura con constructor")
console.log("Iteración con for...in (incluye heredadas):");
for (const prop in figura) {
    console.log("-", prop, "(propia:", Object.hasOwn(figura, prop), ")");
}

console.log("Object.keys (solo propias):", Object.keys(figura));

espacio();



// ============================================================================
// CLASES: DEFINICIÓN Y USO BÁSICO
// ============================================================================

// ----------------------------------------------------------------------------
// EJERCICIO 5: Clase CuentaBancaria
// Define una clase CuentaBancaria con titular, saldo y movimientos.
// Implementa ingresar(cantidad), retirar(cantidad) (que lance Error si 
// no hay saldo) y extracto(). Crea tres instancias, realiza operaciones 
// y verifica que el saldo de una no afecta a las demás.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 5: Clase CuentaBancaria");

class CuentaBancaria {
    titular
    saldo
    movimientos

    constructor(titular, saldo) {
        this.titular = titular
        this.saldo = saldo
        this.movimientos = []
    }

    ingresar(cantidad) {
        this.saldo += cantidad
        console.log("Ingreso realizado con éxito - nuevo saldo: ", this.saldo)
        this.movimientos.push(`Ingreso de: ${cantidad},  nuevo saldo: ${this.saldo}`)
    }

    retirar(cantidad) {
        if (this.saldo - cantidad >= 0) {
            this.saldo -= cantidad 
            console.log("Retirada realizado con éxito - nuevo saldo: ", this.saldo)
            this.movimientos.push(`Retirada de: ${cantidad},  nuevo saldo: ${this.saldo}`)
        } else {
            throw new Error("No hay saldo suficiente para realizar la operación")
        }
    }

    extracto() {
        console.log(`Cliente: ${this.titular}, tiene saldo: ${this.saldo}`)
        let cnt = 1
        for(const movimiento of this.movimientos) {
            console.log(cnt, ": ", movimiento)
            cnt++
        }
    }
}

const cuenta1 = new CuentaBancaria("Lucas", 0)
const cuenta2 = new CuentaBancaria("Marta", 50)
const cuenta3 = new CuentaBancaria("Dani", 100)

const lista_cuentas = [cuenta1, cuenta2, cuenta3]

for (const cuenta of lista_cuentas) {
    cuenta.ingresar(100)
    cuenta.retirar(100)
    cuenta.extracto()
}


espacio();


// ----------------------------------------------------------------------------
// EJERCICIO 6: Constructor opcional y método toString
// Define una clase Fraccion. El constructor lanza Error si el denominador es 0.
// Implementa sumar(), multiplicar() y simplificar(). Sobreescribe toString() 
// para que devuelva "3/4". Prueba todas las operaciones y el console.log.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 6: Clase Fraccion y toString()");

class Fraccion {
    numerador 
    denominador

    constructor(numerador, denominador) {
        if(denominador == 0) {
            throw new Error("El denominador no puede ser igual a 0")
        }
        this.numerador = numerador
        this.denominador = denominador
    }

    sumar(numerador2, denominador2) {
        this.numerador = this.numerador * denominador2 + numerador2 * this.denominador
        this.denominador *= denominador2
    }

    multiplicar(numerador2, denominador2) {
        this.numerador *= numerador2
        this.denominador *= denominador2 
    }

    simplificar() {
        let mcd = 1
        let min = Math.min(this.numerador, this.denominador)
        for (let i = 2; i <= min; i++) {
            if (this.numerador % i === 0 && this.denominador % i === 0) {
                mcd = i
            }
        }
        this.numerador /= mcd
        this.denominador /= mcd
    }

    toString(){
        console.log(`${this.numerador}/${this.denominador}`)
    }
}

const fraccion1 = new Fraccion(1, 2)
fraccion1.toString()
fraccion1.sumar(1, 2); fraccion1.toString()
fraccion1.simplificar(); fraccion1.toString()

espacio()

const fraccion2 = new Fraccion(4, 8)
fraccion2.toString()
fraccion2.simplificar(); fraccion2.toString()

espacio()

const fraccion3 = new Fraccion(3, 4)
fraccion3.toString()
fraccion3.multiplicar(3, 4); fraccion3.toString()
fraccion3.simplificar(); fraccion3.toString()

espacio();



// ============================================================================
// HERENCIA
// ============================================================================

// ----------------------------------------------------------------------------
// EJERCICIO 7: Jerarquía de figuras geométricas
// Define clase base Figura con color y métodos describir() y area() (lanza Error). 
// Crea tres subclases (Circulo, Rectangulo, Triangulo) usando extends. 
// Llama a super(), sobreescribe describir() e implementa area().
// Calcula el área total de un array de instancias.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 7: Herencia de Figuras");

class Figura {
    nombre

    constructor(nombre) {
        this.nombre = nombre
    }

    describir() {
        console.log("La clase Figura no tiene descripción")
    }

    area() {
        throw new Error("La clase Figura no tiene area")
    }
}

class Circulo extends Figura {
    radio

    constructor(nombre, radio) {
        super(nombre)
        this.radio = radio
    }

    describir() {
        console.log(`Soy un círculo con nombre: ${this.nombre}, radio: ${this.radio} y area: ${this.area()} m2`)
    }
    // Pi * r*r
    area() {
        return Math.PI * this.radio * this.radio
    }
}

class Rectangulo extends Figura {
    constructor(nombre, base, altura) {
        super(nombre)
        this.base = base
        this.altura = altura
    }

    describir() {
        console.log(`Soy un rectángulo con nombre: ${this.nombre}, base: ${this.base}, altura: ${this.altura} y area: ${this.area()} m2`)
    }
    // base*altura
    area() {
        return this.base * this.altura
    }
}

class Triangulo extends Figura {
    constructor(nombre, base, altura) {
        super(nombre)
        this.base = base
        this.altura = altura
    }

    describir() {
        console.log(`Soy un triángulo con nombre: ${this.nombre}, base: ${this.base}, altura: ${this.altura} y area: ${this.area()} m2`)
    }
    // (base*altura) / 2
    area() {
        return (this.base * this.altura) / 2
    }
}

const circulo1 = new Circulo("circulito", 2)
circulo1.describir() 

const rectagunlo1 = new Rectangulo("rectangulito", 4, 2)
rectagunlo1.describir()

const triangulo1 = new Triangulo("triangulito", 3, 3)
triangulo1.describir()

espacio();


// ----------------------------------------------------------------------------
// EJERCICIO 8: Herencia en varios niveles y uso de super
// Jerarquía: Empleado -> Gestor -> Director. 
// Cada subclase añade propiedades y sobreescribe presentacion() llamando a 
// super.presentacion(). Crea instancias y verifica con instanceof.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 8: Herencia multinivel y super");

class Empleado {
    nombre

    constructor(nombre) {
        this.nombre = nombre
    }

    presentacion() {
        console.log(`Me llamo ${this.nombre} y soy un empleado`)
    }
}


class Gestor extends Empleado {
    departamento

    constructor(nombre, departamento) {
        super(nombre)
        this.departamento = departamento
    }

    presentacion() {
        super.presentacion()
        console.log(`Además, trabajo en departamento ${this.departamento}`)
    }
}

class Director extends Gestor {
    despacho

    constructor(nombre, departamento, despacho) {
        super(nombre, departamento)
        this.despacho = despacho
    }

    presentacion() {
        super.presentacion()
        console.log(`Además, soy director y estoy en el despacho: ${this.despacho}`)
    }
}

espacio();

const empleado = new Empleado("Lucas")
empleado.presentacion()
console.log(empleado instanceof Empleado)

const gestor = new Gestor("Marta", "Comercio")
gestor.presentacion()
console.log(gestor instanceof Empleado)
console.log(gestor instanceof Gestor)

const director = new Director("Dani", "Dirección", "A")
director.presentacion()
console.log(director instanceof Empleado)
console.log(director instanceof Gestor)
console.log(director instanceof Director)


// ============================================================================
// ENCAPSULACIÓN
// ============================================================================

// ----------------------------------------------------------------------------
// EJERCICIO 9: Propiedades privadas y getters/setters
// Define clase Temperatura con propiedad privada #celsius. 
// Implementa getters (celsius, fahrenheit, kelvin) y un setter celsius 
// que valide que no sea inferior a -273.15 °C. Intenta acceder a #celsius 
// desde fuera para comprobar el SyntaxError.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 9: Getters, Setters y Privados");

class Temperatura {
    #celsius

    constructor(celsius) {
        this.#celsius = celsius
    }

    getCelsius() {
        return this.#celsius
    }
    getFahrenheit() {
        return this.#celsius * 9/5 + 32 
    }
    getKelvin(){
        return  this.#celsius + 273.15
    }
    
    setCelsius(celsius) {
        if (celsius < -273.15) {
            throw new Error("Inferior a lo posible: ", celsius)
        } else {
            this.#celsius = celsius
        }
    }
}

const temperatura = new Temperatura(15)
console.log(temperatura.getCelsius())
console.log(temperatura.getFahrenheit())
console.log(temperatura.getKelvin())
// console.log(temperatura.setCelsius(-300))
// console.log(temperatura.#celsius) // SyntaxError: Private field '#celsius' must be declared in an enclosing class

espacio();


// ----------------------------------------------------------------------------
// EJERCICIO 10: Clase con métodos privados
// Define clase Contrasena con #hash y método privado #calcularHash(texto). 
// El constructor guarda solo el hash. Implementa verificar(texto) y 
// mostrarHash(). Prueba con contraseñas correctas e incorrectas.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 10: Métodos Privados");

class Contrasena {
    #hash

    constructor(textoPlano) {
        this.#hash = this.#calcularHash(textoPlano)
    }

    #calcularHash(texto) {
        let suma = 0
        for (let i = 0; i < texto.length; i++) {
            suma += texto.charCodeAt(i)
        }
        return suma.toString(16)
    }

    verificar(texto) {
        return this.#calcularHash(texto) === this.#hash
    }

    mostrarHash() {
        console.log(this.#hash)
    }
}

const contrasena = new Contrasena("miContraseña123")
console.log(contrasena.verificar("miContraseña123")) // true
console.log(contrasena.verificar("otraContraseña")) // false
contrasena.mostrarHash() // muestra el hash de "miContraseña123"

espacio();



// ============================================================================
// PROPIEDADES Y MÉTODOS ESTÁTICOS
// ============================================================================

// ----------------------------------------------------------------------------
// EJERCICIO 11: Clase con contador estático y método de fábrica
// Define clase Producto. Usa propiedad estática #contador para el id. 
// Implementa método de fábrica estático crearConDescuento() y 
// método estático totalCreados().
// ----------------------------------------------------------------------------
titulo("EJERCICIO 11: Miembros Estáticos y Fábrica");

class Producto {
    id
    nombre
    precio

    static #contador = 0

    constructor(nombre, precio) {
        this.id = ++Producto.#contador  // Nuevo concepto
        this.nombre = nombre
        this.precio = precio
    }

    static crearConDescuento(nombre, precio, porcentaje) {
        const precioNuevo = precio * - precio * porcentaje
        return new Producto(nombre, precioNuevo) // Constructor "adicional"
    }

    // También se podría hacer
    /*constructor(nombre, precio, porcentaje) {
        this.id = ++Producto.#contador
        this.nombre = nombre
        this.precio = precio - (precio * porcentaje)
    }*/

    static totalCreados() {
        console.log("Número de productos creados: ", Producto.#contador)
    }
}


espacio();

// Ejemplos y verificación
const producto1 = new Producto("Manzana", 1.0)
const producto2 = Producto.crearConDescuento("Pera", 2.0, 25) // 25% de descuento
const producto3 = new Producto("Plátano", 0.8)
const producto4 = Producto.crearConDescuento("Melón", 5.0, 10)

console.log("IDs:", producto1.id, producto2.id, producto3.id, producto4.id)
console.log("Precios:", producto1.precio, producto2.precio, producto3.precio, producto4.precio)
Producto.totalCreados()

// ----------------------------------------------------------------------------
// EJERCICIO 12: Clase utilitaria con solo métodos estáticos
// Define clase Validador estática (lanza error en constructor). 
// Implementa esEmail(), esContrasenaFuerte(), esEnteroPositivo(), esFecha() 
// y propiedad estática VERSION = "1.0". Prueba cada método.
// ----------------------------------------------------------------------------
titulo("EJERCICIO 12: Clase Utilitaria Estática");


function contieneMayuscula(texto) {
    let found = false

    for (let i = 0; i < texto.length && !found; i++) {
        if (texto.charCodeAt(i) >= 65 &&  texto.charCodeAt(i) <= 90) {
            found = true
        }
    }
    return found
}

function contieneMinuscula(texto) {
    let found = false

    for (let i = 0; i < texto.length && !found; i++) {
        if (texto.charCodeAt(i) >= 97 &&  texto.charCodeAt(i) <= 122) {
            found = true
        }
    }
    return found
}

function contieneDigito(texto) {
    let found = false

    for (let i = 0; i < texto.length && !found; i++) {
        if (texto.at(i) >= 0 &&  texto.at(i) <= 9) {
            found = true
        }
    }
    return found
}



class Validador {
    static #VERSION = "1.0"

    static esEmail(texto) {
        if (typeof texto !== 'string') return false
        
        const indexAt = texto.indexOf("@")
        if (indexAt == -1) return false
        
        // Busca un punto (.) después del @ (empieza la búsqueda en indexAt + 1)
        const indexPunto = texto.indexOf(".", indexAt + 1)
        return indexPunto != -1
    }

    static esContrasenaFuerte(texto) {
        return texto.length >= 8 && contieneMayuscula(texto) && 
            contieneMinuscula(texto) && contieneDigito(texto) 
    }

    static esEnteroPositivo(valor) {
        return Number.isInteger(valor) && valor > 0
    }

    static esFecha(texto) {
        // Devuelve true si el texto tiene el formato DD/MM/AAAA y la fecha es válida (por ejemplo, no existe el 31/02/2024).
        if (typeof texto !== 'string') return false

        // Expresión regular para validar el formato DD/MM/AAAA
        const m = texto.match(/^(\d{2})\/(\d{2})\/(\d{4})$/)
        if (!m) return false

        // Extraemos día, mes y año
        const dia = Number(m[1])
        const mes = Number(m[2])
        const anio = Number(m[3])

        // Validamos mes
        if (mes < 1 || mes > 12) return false

        // Validamos día según el mes y si el año es bisiesto
        const esBisiesto = (anio % 4 === 0 && (anio % 100 !== 0 || anio % 400 === 0))
        const diasPorMes = [31, esBisiesto ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        // Validamos día
        return dia >= 1 && dia <= diasPorMes[mes - 1]
    }
}

const email1 = "hola@ejemplo.com"
const email2 = "holaejemplo.com"
const email3 = "hola@ejemplo,com"

console.log(Validador.esEmail(email1))
console.log(Validador.esEmail(email2))
console.log(Validador.esEmail(email3))

espacio()

const contrasena1 = "Lucas1234"
const contrasena2 = "lucas1234"
const contrasena3 = "Lu"

console.log(Validador.esContrasenaFuerte(contrasena1))
console.log(Validador.esContrasenaFuerte(contrasena2))
console.log(Validador.esContrasenaFuerte(contrasena3))

espacio()

const fecha1 = "30/06/2004"
const fecha2 = "31/02/2024"
const fecha3 = "01/13/9999"

console.log(Validador.esFecha(fecha1))
console.log(Validador.esFecha(fecha2))
console.log(Validador.esFecha(fecha3))

espacio();