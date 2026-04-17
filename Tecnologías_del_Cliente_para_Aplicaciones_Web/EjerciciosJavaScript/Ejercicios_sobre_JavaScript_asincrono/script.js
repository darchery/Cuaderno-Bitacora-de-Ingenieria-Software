function seccion(seccion){
    console.log("===================================================================")
    console.log(seccion)
    console.log("===================================================================")
}

function titulo(titulo){
    console.log("--------------------------------------------------------------------------------------------------------------------------------------")
    console.log(titulo)
    console.log("--------------------------------------------------------------------------------------------------------------------------------------")
}

function espacio(){
    console.log("\n")
}

// ============================================================================
// TEMPORIZADORES E INTERVALOS
// ============================================================================
seccion("TEMPORIZADORES E INTERVALOS")

/*
 * 1. Semáforo con setInterval y clearInterval:
 * Crea una página HTML con un <div> que simule un semáforo. Usando setInterval, 
 * haz que el color cambie cíclicamente entre rojo (3 segundos), ámbar (1 segundo) 
 * y verde (3 segundos), modificando el backgroundColor del div con style. 
 * Añade un botón «Detener» que llame a clearInterval para parar el ciclo y otro 
 * botón «Reanudar» que lo reinicie. Muestra también por consola el color actual 
 * en cada cambio.
 */
titulo("1. Semáforo con setInterval y clearInterval: Crea una página HTML con un <div> que simule un semáforo. Usando setInterval, haz que el color cambie cíclicamente entre rojo (3 segundos), ámbar (1 segundo) y verde (3 segundos), modificando el backgroundColor del div con style. Añade botones para detener y reanudar, mostrando por consola el color actual.")
const detener = document.querySelector("#detener")
const reanudar = document.querySelector("#reanudar")

const luzRoja = document.querySelector("#luz-roja");
const luzAmarilla = document.querySelector("#luz-amarilla");
const luzVerde = document.querySelector("#luz-verde");

function apagarLuz(luz){
    if (luz.classList.contains("roja")) {
        luz.classList.remove("roja");
    }
    if (luz.classList.contains("amarilla")) {
        luz.classList.remove("amarilla");
    }
    if (luz.classList.contains("verde")) {
        luz.classList.remove("verde");
    }
    if (!luz.classList.contains("apagada")) {
        luz.classList.add("apagada");
    }
}

function encenderRojo() {
    if (luzRoja.classList.contains("apagada")) {
        luzRoja.classList.remove("apagada");
    }
    if (!luzRoja.classList.contains("roja")) {
        luzRoja.classList.add("roja");
    }

    apagarLuz(luzAmarilla);
    apagarLuz(luzVerde);
    console.log("Rojo")
}

function encenderVerde() {
    // Quitamos la clase "apagada" de la luz verde, si la tiene
    // y añadimos la clase "verde" si no la tiene
    if (luzVerde.classList.contains("apagada")) {
        luzVerde.classList.remove("apagada");
    }
    if (!luzVerde.classList.contains("verde")) {
        luzVerde.classList.add("verde");
    }
  apagarLuz(luzRoja);
  apagarLuz(luzAmarilla);
  console.log("Verde")
}

function encenderAmarillo() {
    // Quitamos la clase "apagada" de la luz amarilla, si la tiene
    // y añadimos la clase "amarilla" si no la tiene
    if (luzAmarilla.classList.contains("apagada")) {
        luzAmarilla.classList.remove("apagada");
    }
    if (!luzAmarilla.classList.contains("amarilla")) {
        luzAmarilla.classList.add("amarilla");
    }
  apagarLuz(luzRoja);
  apagarLuz(luzVerde);
  console.log("Amarillo")
}

let intervalId = null
let estadoActual = "rojo"
const ESTADOS = ["rojo", "verde", "amarillo"]
const DURACIONES = [3000, 3000, 1000]

function siguienteEstado(estado_actual) {
    const index = ESTADOS.indexOf(estado_actual)
    return ESTADOS[(index + 1) % ESTADOS.length]
}

function encenderSegunEstado(estadoActual) {
    if (estadoActual == "rojo") {
        encenderRojo()
    } else if (estadoActual == "verde") {
        encenderVerde()
    } else {
        encenderAmarillo()
    }
}

reanudar.addEventListener("click", () => {
    if (intervalId) {
        return
    }
    encenderSegunEstado(estadoActual)
    const duracionActual = DURACIONES[ESTADOS.indexOf(estadoActual)]

    function manejador() {
        clearInterval(intervalId)
        intervalId = null

        estadoActual = siguienteEstado(estadoActual)
        encenderSegunEstado(estadoActual)
        const nuevaDuracionActual = DURACIONES[ESTADOS.indexOf(estadoActual)]
        
        intervalId = setInterval(manejador, nuevaDuracionActual)
    }

    // Maneja el sigueinte estado y la nueva duración de ese estados
    intervalId = setInterval(manejador, duracionActual)
    console.log("Semáforo iniciado: ", estadoActual)
})

detener.addEventListener("click", () => {
    if (!intervalId) return 
    clearInterval(intervalId)
    intervalId = null
    console.log("Semáforo detenido")
})

espacio()

/*
 * 2. Cuenta atrás con setTimeout encadenado:
 * Implementa una cuenta atrás de 10 a 0 usando setTimeout de forma recursiva 
 * (sin setInterval): cada llamada a la función programa la siguiente con setTimeout. 
 * Muestra el valor actual en un elemento <span> del HTML. Cuando llegue a 0, 
 * muestra el mensaje «¡Tiempo!» y deja de programar nuevas llamadas. Añade un botón 
 * «Cancelar» que use clearTimeout para detener la cuenta en cualquier momento.
 */
titulo("2. Cuenta atrás con setTimeout encadenado: Implementa una cuenta atrás de 10 a 0 usando setTimeout de forma recursiva. Muestra el valor en el HTML y detén las llamadas al llegar a 0. Añade un botón para cancelar.")

const cuenta_atras = document.querySelector("#cuenta-atras")
const cancelar = document.querySelector("#cancelar")
const reiniciar = document.querySelector("#reiniciar")
let timeoutId = null

function ejecutarCuentaAtras(cnt_actual) {
    if (cnt_actual > 0) {
        cnt_actual--
        cuenta_atras.textContent = "¡Quedan " + cnt_actual + " segundos!"
        timeoutId = setTimeout(() => ejecutarCuentaAtras(cnt_actual), 1000)
    } else {
        cuenta_atras.textContent = "¡Tiempo!"
    }
}

cancelar.addEventListener("click", () => {
    clearTimeout(timeoutId)
    cuenta_atras.textContent = "¡Tiempo!"
})

reiniciar.addEventListener("click", () => { 
    clearTimeout(timeoutId)
    ejecutarCuentaAtras(11)
})

ejecutarCuentaAtras(11)

espacio()

/*
 * 3. Retraso configurable con setTimeout y parámetros adicionales:
 * Escribe una función mostrarMensajeConRetraso(mensaje, destinatario, retrasoMs) 
 * que use setTimeout para mostrar por consola el texto "Mensaje para [destinatario]: 
 * [mensaje]" tras el retraso indicado. Pasa mensaje y destinatario como parámetros 
 * adicionales de setTimeout (tercer y cuarto argumento), no dentro de la función flecha. 
 * Pruébala con tres llamadas simultáneas con retrasos distintos y observa el orden de salida.
 */
titulo("3. Retraso configurable con setTimeout y parámetros adicionales: Crea una función que muestre un mensaje con retraso usando parámetros adicionales en setTimeout. Pruébala con tres llamadas simultáneas.")

function mostrarMensajeConRetraso(mensaje, destinatario, retrasoMs){
    const timeoutId = setTimeout((msg, dest) => {
        console.log("Mensaje para " + dest  + ": " + msg)
    }, retrasoMs, mensaje, destinatario)
    return timeoutId
}

mostrarMensajeConRetraso("Hola", "Lucas", 1000)
mostrarMensajeConRetraso("Hola", "Marta", 2000)
mostrarMensajeConRetraso("Hola", "Dani", 3000)


// ============================================================================
// CALLBACKS
// ============================================================================
seccion("CALLBACKS")

/*
 * 4. Secuencia de operaciones con callbacks:
 * Implementa las cuatro funciones siguientes, cada una con un retardo simulado 
 * con setTimeout de entre 500 y 1500 ms:
 * - obtenerUsuario(id, callback): llama a callback con { id, nombre: "Ana" }.
 * - obtenerPedidos(usuario, callback): llama a callback con un array de 3 pedidos.
 * - calcularTotal(pedidos, callback): llama a callback con la suma de los importes.
 * - mostrarResumen(total, callback): muestra el total y llama a callback sin argumentos.
 * Encadénalas usando callbacks anidados para obtener el total de los pedidos del 
 * usuario con id 42. Observa la dificultad de lectura (callback hell).
 */
titulo("4. Secuencia de operaciones con callbacks: Simula operaciones asíncronas encadenando callbacks para obtener un usuario, sus pedidos, calcular el total y mostrar el resumen. Observa el callback hell.")

function obtenerUsuario(id, callback) {
    setTimeout(() => {
        callback({id, nombre: "Ana"})
    }, 500 + Math.random() * 1000)
}

function obtenerPedidos(usuario, callback) {
    const pedidos = [{id:1, importe: 10}, {id:2, importe: 20}, {id:3, importe: 30}]
    setTimeout(() => {
        callback(pedidos)
    }, 500 + Math.random() * 100)
}

function calcularTotal(pedidos, callback) {
    setTimeout(() => {    
        callback(
            pedidos.reduce(
                (total, pedido) => total += pedido.importe, 0
            )
        )
    }, 500 + Math.random() * 1000)
}

function mostrarResumen(total, callback) {
    setTimeout(() => {
        console.log("Ej4 - Total: ", total)
        callback()
    }, 500 + Math.random() * 1000)
}

obtenerUsuario(42, 
    usuario => {obtenerPedidos(usuario, 
        pedidos => {calcularTotal(pedidos, 
            total => {mostrarResumen(total, 
                () => { /* FIN */
                }
            )}
        )}
    )}
)

espacio()

/*
 * 5. Refactorización de callback hell:
 * Toma el código del ejercicio anterior y refactorízalo de dos formas distintas 
 * para mejorar su legibilidad sin usar Promises ni async/await: primero nombrando 
 * las funciones callback (en lugar de anónimas anidadas) y luego extrayendo cada paso 
 * a una función independiente. Compara las tres versiones y comenta cuál es más legible.
 */
titulo("5. Refactorización de callback hell: Toma el código del ejercicio 4 y refactorízalo nombrando las funciones y extrayendo los pasos. Compara y comenta la legibilidad.")
// Nombrar las callbacks: crea funciones con nombre y pásalas en lugar de anidar anónimos.
function onUsuario(usuario) {
    obtenerPedidos(usuario, onPedidos)
}

function onPedidos(pedidos) {
    calcularTotal(pedidos, onTotal)
}

function onTotal(total) {
    mostrarResumen(total, () => {/*FIN*/})
}

console.log("Ejericio 5 - Forma 1")
obtenerUsuario(42, onUsuario)


// Extraer cada paso a funciones independientes y llamar secuencialmente desde una 
// función controladora:

// NO FUNCIONA DEL TODO, LLEGA AL FINAL PERO NO MUESTRA EL RESULTADO
function obtenerYProcesar(id, callback) {
    obtenerUsuario(id, usuario => {
        obtenerPedidos(usuario, pedidos => {
            calcularTotal(pedidos, total => {
                mostrarResumen(total, () => {
                    if (typeof callback === 'function') callback()
                })
            })
        })
    })
}

console.log("Ejericio 5 - Forma 2")
obtenerYProcesar(42, () => console.log("Ej 5 - Forma 2 - Secuencia finalizada"))

espacio()

// ============================================================================
// PROMESAS: CREACIÓN Y USO BÁSICO
// ============================================================================
seccion("PROMESAS: CREACIÓN Y USO BÁSICO")

/*
 * NOTA: Para este grupo de ejercicios, consultar la creación de Promises en la 
 * documentación de MDN, referencia del objeto global Promise y referencia del 
 * constructor Promise().
 */

/*
 * 6. Crear una Promise con resolve y reject:
 * Escribe una función dividir(a, b) que devuelva una Promise. Si b es cero, la 
 * Promise debe rechazarse con un Error cuyo mensaje sea "División por cero". En caso 
 * contrario, la Promise debe resolverse con el resultado tras un retardo de 500 ms 
 * simulado con setTimeout. Usa .then() para mostrar el resultado y .catch() para el error. 
 * Pruébala con una llamada normal, una con divisor cero y una con negativos.
 */
titulo("6. Crear una Promise con resolve y reject: Crea una función dividir(a, b) que devuelva una Promise (rechaza si b=0, resuelve con retardo de 500ms). Pruébala manejando .then() y .catch().")

// Escribe tu código para el ejercicio 6 aquí:


espacio()

/*
 * 7. Encadenamiento de .then() con transformaciones:
 * Dado el array [1, 2, 3, 4, 5], crea una Promise que se resuelva con ese array 
 * tras 300 ms. Encadena tres .then() sucesivos: el primero filtra los números pares, 
 * el segundo los multiplica por 10 y el tercero los muestra por consola. Verifica 
 * que cada .then() recibe el valor del anterior. Añade un .catch() final.
 */
titulo("7. Encadenamiento de .then() con transformaciones: Resuelve una Promise con un array y encadena tres .then() para filtrar pares, multiplicar por 10 y mostrar el resultado, con un .catch() al final.")

// Escribe tu código para el ejercicio 7 aquí:


espacio()

/*
 * 8. Uso del método finally:
 * Simula la carga de datos de un servidor con una Promise que se resuelve o rechaza 
 * aleatoriamente (Math.random()). Muestra "Cargando..." antes de crearla. Usa .then() 
 * para el éxito, .catch() para el error, y .finally() para mostrar siempre "Carga 
 * finalizada". Verifica que finally se ejecuta en ambos casos.
 */
titulo("8. Uso del método finally: Simula una carga de datos aleatoria y verifica que el bloque .finally() se ejecuta tanto si la Promise se resuelve como si se rechaza.")

// Escribe tu código para el ejercicio 8 aquí:


espacio()

// ============================================================================
// FETCH Y PROMESAS
// ============================================================================
seccion("FETCH Y PROMESAS")

/*
 * 9. Petición básica con fetch y manejo de response.ok:
 * Usa fetch para hacer una petición a la URL de productos JSON de MDN. Encadena dos 
 * .then(): el primero comprueba response.ok (lanza Error si es false, o devuelve 
 * response.json() si es true); el segundo recorre el array con forEach mostrando nombre 
 * y precio. Añade un .catch() y prueba con una URL inexistente.
 */
titulo("9. Petición básica con fetch y manejo de response.ok: Haz un fetch a un JSON, valida response.ok y muestra los productos. Prueba también con una URL errónea para disparar el .catch().")

console.log("1 - antes del fetch")

fetch("https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/products.json")
    .then((response) =>  {
        if (response.ok == true) {
            console.log("3 - respuesta recibida");
            return response.json()
        } else {
            throw new Error("ERROR: la respuesta no está 'ok'")
        }
    })
    .then((data) => {
        console.log("4 - datos procesados ", data)
        console.log("INICIO - Ejercicio 9")
        data.forEach(elem => console.log("Nombre: ", elem.name, ", Precio: ", elem.price))
        /*for ( elem of data) {
            console.log("Nombre: ", elem.name, ", Precio: ", elem.price)
        }*/
       console.log("FIN - Ejercicio 9")
    })
    .catch((error) => {
        console.error(`No se han podido descargar los productos: ${error}`);
    })

console.log("2 - después del fetch, antes de la respuesta")

espacio()

/*
 * 10. Diferencia entre error de red y error HTTP:
 * Realiza dos peticiones con fetch: una a una URL con error 404 y otra a un dominio 
 * inexistente. Muestra por consola si la Promise se resolvió o rechazó, el valor de 
 * response.ok y el mensaje de error. Explica en comentarios la diferencia entre 
 * error HTTP y de red en fetch.
 */
titulo("10. Diferencia entre error de red y error HTTP: Compara el comportamiento de fetch ante un error 404 y un dominio inexistente. Documenta la diferencia.")

// Errores 4xx => de usuario, y 5xx => de servidor

const error_404__url = "https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/noexito.json"
const error_dominio_url = "https://www.esta-web-no-existe-123456.com"

fetch(error_404__url)
    .then((response) => {
        if (response.ok) {
            console.log("Fetch-> resuelta. response.ok =", response.ok, "status =", response.status);
            return response.json()
        } else {
            throw new Error("descripción: ", response.status)
        }
    })
    .catch((error) => {
        console.error("ERROR: " + error)
    })

// Actuó el then al recibir un false => por lo tanto no se accedió al contenido esperado
// aunque si, a una parte de la url, hasta que intentó acceder al json y falló

// ERROR: Error: no se pudo acceder a la respuesta

/*
El servidor ha respondido, se considera que la promesa se ha cumplido con éxito, incluso aunque 
la respuesta fuera un error como el  de página no encontrada.
*/

fetch(error_dominio_url)
    .then((response) => {
        if (response.ok) {
            console.log("Fetch-> resuelta. response.ok =", response.ok, "status =", response.status);
            return response.json()
        } else {
            throw new Error("descripción: ", response.status)
        }
    })
    .catch((error) => {
        console.error("ERROR: " + error)
    })

// Saltó el catch, por lo tanto la respuesta es true

/* Solicitud de origen cruzado bloqueada: La política de mismo origen no permite la lectura 
de recursos remotos en https://www.esta-web-no-existe-123456.como/.
(Razón: Solicitud CORS sin éxito). Código de estado: (null). 

El pedido HTTP que hace uso de CORS falló porque la conexión HTTP falló a nivel red o protocolo.
*/

// ERROR: TypeError: NetworkError when attempting to fetch resource.
// Tenemos un error de red porque no podemos acceder al recurso 

/*
Un fallo es cuando (entre otras razones) un error de red evita que se envíe la petición
*/

espacio()

/*
 * 11. Encadenamiento de dos peticiones dependientes:
 * Obtén la lista de productos del ejercicio 9. Selecciona el primero y simula una 
 * segunda petición (con setTimeout) a "https://api.ejemplo.com/stock/${producto.name}" 
 * que devuelva el stock. Encadena ambas operaciones y muestra el nombre y stock.
 */
titulo("11. Encadenamiento de dos peticiones dependientes: Obtén una lista de productos y usa el primero para simular una segunda petición de stock dependiente de la primera.")

fetch("https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/products.json")
    .then((response) =>  {
        if (response.ok == true) {
            return response.json()
        } else {
            throw new Error("descripción: " + response.status)
        }
    })
    .then((data) => {
        let primer_elemento = data[0]
        console.log("INICIO - Ejercicio 11")
        console.log("Seleccionamos el primer elemento => ", primer_elemento.name)

        const ej11_url_segunda_peticion = `https://api.ejemplo.com/stock/${primer_elemento.name}`

        // Simulamos la segunda petición con setTimeout (la URL de ejemplo no existe)
        const timeoutId = setTimeout(() => {
            fetch(ej11_url_segunda_peticion)
                .then((response) => {
                    if (response.ok) {
                        return response.json()
                    } else {
                        throw new Error(`status: ${response.status}`)
                    }
                })
                .then((data) => {
                    console.log("Ej 11 -  Nombre: nombre", " Stock: ", Math.floor(Math.random() * 100))
                    console.log("FIN - Ejercicio 11")
                })
            // No tiene stock
            
        }, 2000)

    })
    .catch((error) => {
        console.error(`No se han podido descargar los productos: ${error}`);
    })


espacio()

// ============================================================================
// PROMISE.ALL Y PROMISE.ANY
// ============================================================================
seccion("PROMISE.ALL Y PROMISE.ANY")

/*
 * 12. Promise.all con múltiples fetch:
 * Realiza simultáneamente tres fetch: dos a JSONs válidos de MDN y uno a una URL 
 * inexistente en el mismo servidor. Usa Promise.all(). En el .then(), muestra el 
 * status de cada respuesta. En el .catch(), muestra el error. Explica en comentarios 
 * por qué Promise.all rechaza en cuanto una falla.
 */
titulo("12. Promise.all con múltiples fetch: Usa Promise.all para esperar tres peticiones fetch simultáneas (una fallida). Observa y explica el rechazo inmediato (fail-fast).")

console.log("INICIO - Ejercicio 12")

const ej12_url_json_valido1 = "https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/products.json"
const ej12_url_json_valido2 = "https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/index.html"
const ej12_url_url_inexistente = "https://mdn.github.io/no-existo"

const ej12_promesaFetch1 = fetch(
    ej12_url_json_valido1
)

const ej12_promesaFetch2 = fetch(
    ej12_url_json_valido2
)

const ej12_promesaFetch3 = fetch(
    ej12_url_url_inexistente
)

Promise.all([ej12_promesaFetch1, ej12_promesaFetch2, ej12_promesaFetch3])
    .then((respuestas) => {
        for(const respuesta of respuestas)  {
            console.log(`${respuesta.url}: ${respuesta.status}`)
        }
    })
    .catch((error) => {
        console.error(`Fallo en la operación fetch: ${error}`)
    })

console.log("FIN - Ejercicio 12")

/*
Fallo en la operación fetch: TypeError: NetworkError when attempting to fetch resource.

Porque al intentar acceder a una URL inexistente en el mismo servidor, tenemos un error de red
al intentar acceder al recurso
*/

espacio()

/*
 * 13. Promise.any como mecanismo de redundancia:
 * Crea tres Promises simulando servidores con tiempos de 800, 300 y 1500 ms. 
 * Haz que el primero falle y el segundo sea el más rápido. Usa Promise.any() 
 * para obtener el que responda primero con éxito. Compara el comportamiento con 
 * Promise.all() usando los mismos datos.
 */
titulo("13. Promise.any como mecanismo de redundancia: Usa Promise.any con tres Promises (una rápida, una lenta, una fallida) para obtener el primer éxito. Compara con Promise.all.")

console.log("INICIO - Ejercicio 13")
const time1 = 800
const time2 = 300
const time3 = 1500

// Simulamos tres servidores con Promises y distintos tiempos
const p1 = new Promise((_, reject) => setTimeout(() => reject(new Error('Servidor1: fallo')), time1)) // falla
const p2 = new Promise((resolve) => setTimeout(() => resolve({ servidor: 2, dato: 'OK 2' }), time2)) // rápido
const p3 = new Promise((resolve) => setTimeout(() => resolve({ servidor: 3, dato: 'OK 3' }), time3)) // lento

// Promise.any: resuelve con el primer éxito (p2 en este caso)
Promise.any([p1, p2, p3])
    .then(resultado => {
        console.log('Promise.any - Primer éxito:', resultado)
    })
    .catch(aggregateError => {
        console.error('Promise.any - Todas fallaron:', aggregateError)
    })

// Promise.all: rechazará porque p1 falla
Promise.all([p1, p2, p3])
    .then(resultados => {
        console.log('Promise.all - Todos los resultados:', resultados)
    })
    .catch(error => {
        console.error('Promise.all - Falló porque al menos una promesa rechazó:', error.message)
    })

console.log("FIN - Ejercicio 13")


/*
Promise.any - Primer éxito: Object { servidor: 2, dato: "OK 2" }:
Al ser el segundo el más rápido, este se ejecuta primero y obtenemos un resultado, gracias a la
naturaleza flexible del any

Promise.all - Falló porque al menos una promesa rechazó: Servidor1: fallo:
Como promise espera que todos respondan, al fallar el primero => se eleva un error
*/

espacio()

// ============================================================================
// ASYNC / AWAIT
// ============================================================================
seccion("ASYNC / AWAIT")

/*
 * 14. Refactorización de cadena .then() a async/await:
 * Toma el código del ejercicio 9 (petición fetch) y reescríbelo usando una función 
 * async con await y un bloque try/catch. Añade un bloque finally equivalente al 
 * método .finally() de las promesas. Comenta qué versión te resulta más legible.
 */
titulo("14. Refactorización de cadena .then() a async/await: Reescribe una cadena fetch tradicional a sintaxis async/await con bloques try/catch/finally. Comenta sobre su legibilidad.")

console.log("INICIO - Ejercicio 14")

async function fetchProductos() {
    try {
        const response = await fetch(
            "https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/products.json"
        )
        if (!response.ok) {
            throw new Error(`HTTP error: ${response.status}`)
        }

        const data = await response.json()
        data.forEach(elem => console.log("Ej14 - Nombre: ", elem.name, ", Precio: ", elem.price))
        return data
    } catch (error) {
        console.error(`Ejercicio 14 - No se han podido traer los productos: ${error}`)
        throw error
    } finally {
        console.log("Ejercicio 14 - Bloque finally")
    }
}

fetchProductos()
    // Opcional
    .then(products => console.log('Ej14 - fetchProductos() devolvió', products))
    .catch(err => console.error('Ej14 - Error al obtener productos:', err))

console.log("FIN - Ejercicio 14")

/*
Esta versión es mas rápida de escribir, ambas son legibles en mi opinión.
*/

espacio()

/*
 * 15. Función async con valor de retorno y manejo externo:
 * Escribe una función async obtenerSuperheroes() que haga un fetch, compruebe 
 * response.ok, parsee el JSON y devuelva el array de miembros. No uses try/catch 
 * interno; deja que los errores se propaguen. Llámala desde fuera usando .then() 
 * y .catch(). Explica por qué propaga los errores como Promise rechazada.
 */
titulo("15. Función async con valor de retorno y manejo externo: Crea una función async sin try/catch interno para que propague errores, y absórbelos externamente con .catch(). Documenta el porqué.")

console.log("INICIO - Ejercicio 15")

// Nota: no usamos try/catch dentro de `obtenerSuperheroes()` a propósito.
// Si ocurre un error (por ejemplo red, HTTP no OK o JSON inválido), la
// función async rechazará su Promise y el llamador podrá manejarlo con
// `.catch()` o usando `try/catch` si usa `await`.
async function obtenerSuperheroes() {

    const response = await fetch(
      "https://mdn.github.io/learning-area/javascript/oojs/json/superheroes.json"
    )

    if (!response.ok) {
      throw new Error(`HTTP error: ${response.status}`);
    }
    return await response.json();
}

const promesa_superheroes = obtenerSuperheroes();
promesa_superheroes
  .then((data) => {
    console.log(`Ej 15 - Nombre del escuadrón: ${data.squadName}`)
    console.log(`Ej 15 - Ciudad natal: ${data.homeTown}`)
    console.log(`Ej 15 - Año de fundación: ${data.formed}`)
    console.log(`Ej 15 - Base secreta: ${data.secretBase}`)
    console.log("Ej 15 - Miembros actuales: ")
    data.members.forEach(elem => console.log(`  Ej 15 - Nombre: ${elem.name}, Edad: ${elem.age}, Identidad secreta: ${elem.secretIdentity}`))
  })
  .catch((error) => {
    console.error(`No se han podido obtener los superhéroes: ${error}`);
  });

console.log("FIN - Ejercicio 15")

espacio()