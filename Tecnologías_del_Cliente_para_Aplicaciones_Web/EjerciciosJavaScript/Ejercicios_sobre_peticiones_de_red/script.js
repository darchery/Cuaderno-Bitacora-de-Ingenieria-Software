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

function inicio(ejercicio) {
    console.log(`${ejercicio} - INICIO`)
}

function fin(ejercicio) {
    console.log(`${ejercicio} - FIN`)
}

// ============================================================================
// PETICIONES HTTP AVANZADAS Y API REST
// ============================================================================
seccion("PETICIONES HTTP AVANZADAS Y API REST")

/*
 * 1. Petición básica de texto con fetch:
 * Crea una función cargarTexto(url) usando fetch(...).then(...).catch(...) que:
 * compruebe response.ok, lance un error con response.status si falla, y muestre 
 * el texto devuelto en un elemento HTML de la página.
 */
titulo("1. Petición básica de texto con fetch: Crea una función cargarTexto(url) con promesas que valide response.ok, gestione errores de estado y muestre el texto en el HTML.")

function cargarTexto_ej1(url) {
    fetch(url)
        .then((response) => {
            if (!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            }
            return response.text()
        })
        .then((text) => {
            inicio("Ejercicio 1")
            console.log("Cargando el contenido...")
            console.log("Ready: ", text)
            fin("Ejercicio 1")
        })
        .catch((error) => {
            console.error(`Ejercicio 1: No se ha podido cargar el contenido: ${error.message}`)
        })
}
cargarTexto_ej1("https://mdn.github.io/learning-area/javascript/oojs/json/superheroes.json")

espacio()

/*
 * 2. Refactorización a async/await:
 * Reescribe el ejercicio anterior (cargarTexto) utilizando sintaxis async/await 
 * manteniendo exactamente el mismo comportamiento de control de errores.
 */
titulo("2. Refactorización a async/await: Reescribe la función cargarTexto del ejercicio 1 utilizando async/await en lugar de cadenas de promesas .then().")


async function cargarTexto_ej2(url) {
    try {
        const response = await fetch(url)
        if(!response.ok) {
            throw new Error(`HTTP error: ${response.status}`)
        }
        
        const text = await response.text()
        inicio("Ejercicio 2")
        console.log("Ready: ", text)
    } catch(error) {
            console.error(`Ejercicio 2: No se ha podido cargar el contenido: ${error.message}`)
    } finally {
        fin("Ejercicio 2")
    }
}

cargarTexto_ej2("https://mdn.github.io/learning-area/javascript/oojs/json/superheroes.json")

espacio()

/*
 * 3. Procesamiento de JSON y renderizado en listas:
 * Implementa una petición a productos.json y procesa la respuesta con 
 * response.json(). Muestra los resultados renderizando en una lista HTML 
 * (<ul> o <ol>) al menos 5 propiedades por cada producto.
 */
titulo("3. Procesamiento de JSON y renderizado en listas: Obtén un archivo JSON de productos y renderiza al menos 5 de sus propiedades en una lista HTML.")

function procesamientoJSON_renderizadoListas_ej3(url) {
    fetch(url)
        .then((response) => {
            if(!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            }

            return response.json()
        })
        .then((data_raw) => {
            inicio("Ejericicio 3")
            const lista = document.createElement("ul")
            data_raw.forEach((elem) => {
                // Elemento
                const elem_lista = document.createElement("li")
                elem_lista.textContent = `Nombre: ${elem.name}`

                // Propiedades del elemento
                const sub_lista = document.createElement("ul")
                const precio = document.createElement("li")
                const imagen = document.createElement("li")
                const tipo = document.createElement("li")
                const cantidad = document.createElement("li")

                precio.textContent = `Precio: ${elem.price}`
                imagen.textContent = `Imagen: ${elem.image}`
                tipo.textContent = `Tipo: ${elem.type}`
                cantidad.textContent =`Cantidad: ${(Math.random()*20).toFixed(0)}`

                sub_lista.appendChild(precio)
                sub_lista.appendChild(imagen)
                sub_lista.appendChild(tipo)
                sub_lista.appendChild(cantidad)

                elem_lista.appendChild(sub_lista)

                lista.appendChild(elem_lista)
            })
            document.body.appendChild(lista)
            fin("Ejercicio 3")
        })
        .catch((error) => {
            console.error("Ejercicio 3 - No se han podido cargar los productos: ", error.message)
        })
}

procesamientoJSON_renderizadoListas_ej3("https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/products.json")

espacio()

/*
 * 4. Carga y visualización de imágenes con blob:
 * Implementa una carga de imagen haciendo uso de fetch + response.blob() + 
 * URL.createObjectURL(...). Asigna la URL resultante a la propiedad src de 
 * una etiqueta <img> del DOM.
 */
titulo("4. Carga y visualización de imágenes con blob: Descarga una imagen como blob mediante fetch y muéstrala en un elemento <img> usando URL.createObjectURL.")

function cargaVisualizacionImagenesBlob_ej4(url) {
    fetch(url)
        .then((response) => {
            if(!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            }
            return response.blob()
        })
        .then((image_blob) => {
            inicio("Ejercicio 4")
            const objectURL = URL.createObjectURL(image_blob)
            const img = document.createElement("img")

            img.src = objectURL // Lo que nos pide el ejercicio
            // Extra
            img.alt = "Imagen aleatoria de Piscum"
            img.style.border = "2px solid goldenrod"
            img.style.borderRadius = "10%"

            document.body.appendChild(img)
            console.log("Ejercicio 4 - Imagen descargada y renderizada con exito...")
            fin("Ejercicio 4")
        })
        .catch((error) => {
            console.error()
        })
}

cargaVisualizacionImagenesBlob_ej4("https://picsum.photos/200")

espacio()

/*
 * 5. Envío de datos POST (JSON):
 * Diseña un ejemplo de petición POST con un cuerpo JSON (usando JSON.stringify) 
 * y la cabecera Content-Type: application/json. Muestra por consola el payload 
 * enviado y el código de estado devuelto por el servidor.
 */
titulo("5. Envío de datos POST (JSON): Realiza una petición POST enviando un objeto JSON. Muestra por consola el cuerpo enviado y la respuesta del servidor.")

async function envioDatosPost_ej5(datos) {
    inicio("Ejercicio 5")
    try {
        const response = await fetch("https://jsonplaceholder.typicode.com/posts", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(datos)
        })
        if(!response.ok) {
            throw new Error(`HTTP error: ${response.status}`)
        }

        console.log("Payload enviado: ", datos)
        console.log("Reponse status: ", response.status)
    } catch(error) {
        console.error(`No se ha podido realizar el envío ${error.message}`)
    } finally {
        fin("Ejercicio 5")
    }


}
const datos_ej5 = {usuario: "lucas", password: "pass"}
envioDatosPost_ej5(datos_ej5)

espacio()

/*
 * 6. Envío de datos POST (Formulario URL-encoded):
 * Diseña otro POST, pero esta vez usando URLSearchParams (para lograr el 
 * formato application/x-www-form-urlencoded). Compara en un breve comentario 
 * en el código cuándo usarías este formato frente al formato JSON del ejercicio 5.
 */
titulo("6. Envío de datos POST (Formulario URL-encoded): Realiza un POST enviando datos con URLSearchParams. Añade un comentario explicando cuándo usar este formato frente a JSON.")

async function envioDatosPost_ej6(datos) {
    inicio("Ejercicio 6")
    try {
        const response = await fetch("https://jsonplaceholder.typicode.com/posts", {
            method: "POST",
            headers: {
                "Content-Type": "application/x-www-form-urlencoded"
            }, 
            body: new URLSearchParams(datos)
        })
        if(!response.ok) {
            throw new Error(`HTTP error: ${response.status}`)
        }

        console.log("Payload enviado: ", datos)
        console.log("Response status: ", response.status)
    } catch(error) {
        console.error(`No se ha podido realizar el envío ${error.message}`)
    } finally {
        fin("Ejercicio 6")
    }
}
/*
* - Usamos JSON (Ej 5) para: APIs modernas y estructuras de datos complejas (arrays, objetos anidados).
* - Usamos URL-Encoded (Ej 6) para: Formularios HTML tradicionales, APIs antiguas, 
* o endpoints de autenticación (como OAuth) que exigen este formato de clave=valor.
*/

const datos_ej6= {usuario: "danis", password: "pass"}
envioDatosPost_ej6(datos_ej6)

espacio()

/*
 * 7. Petición GET con parámetros de consulta:
 * Crea una petición GET con parámetros de consulta construidos dinámicamente 
 * usando URLSearchParams (ej. ?nombreusuario=...&...). Verifica y muestra 
 * en consola la URL final construida antes de hacer el fetch.
 */
titulo("7. Petición GET con parámetros de consulta: Construye dinámicamente una URL con parámetros de búsqueda usando URLSearchParams y realiza un GET.")


async function peticionGetParametrosConsulta_ej7(usuario, contrasenya) {
    inicio("Ejercicio 7")
    try {
        const url = "https://jsonplaceholder.typicode.com/gets"

        const parametros = {
            nombreusuario: usuario,
            password: contrasenya
        }

        // Definimos una url
        const url_def = new URL(url)
        // Añadimos los parámetros de búsqueda
        url_def.search = new URLSearchParams(parametros)

        console.log("URL final: ", url_def.toString())

        const response = await fetch(url_def)
        if(!response.ok) {
            throw new Error(`HTTP error: ${response.status}`)
        }

        console.log("Response status: ", response.status)
    } catch(error) {
        console.error(`No se ha podido realizar la petición ${error.message}`)
    } finally {
        fin("Ejercicio 7")
    }
}

peticionGetParametrosConsulta_ej7("marta", "pass")

espacio()

/*
 * 8. Construcción y clonación de Request:
 * Construye una Request explícita instanciando new Request(...) (pasando 
 * método, headers y body), úsala con fetch, y después clónala con el método 
 * .clone() para reutilizarla en una segunda petición idéntica.
 */
titulo("8. Construcción y clonación de Request: Crea un objeto Request explícito, envíalo con fetch y clónalo para realizar una segunda petición.")

async function construccionClonacionRequest_ej8(data) {
    inicio("Ejercicio 8")
    try {
        const request1 = new Request("https://jsonplaceholder.typicode.com/posts", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(data) // Es un Stream - Flujo de datos
        })
        const request2 = request1.clone()

        const response1 = await fetch(request1)
        if(!response1.ok) {
            throw new Error(`HTTP error Response 1: ${response1.status}`)
        }
        const response2 = await fetch(request2)
        if(!response2.ok) {
            throw new Error(`HTTP error Response 2: ${response2.status}`)        
        }
        
        console.log("Payload Response 1: ", data)
        console.log("Response 1 status: ", response1.status)
        console.log("Payload Response 2: ", data)
        console.log("Response 2 status: ", response2.status)

    } catch(error) {
        console.error(`No se ha podido realizar la construcción y clonación ${error.message}`)
    } finally {
        fin("Ejercicio 8")
    }
}
const datos_ej8= {usuario: "luquitas", password: "pass"}
construccionClonacionRequest_ej8(datos_ej8)

espacio()

/*
 * 9. Formas de definir Cabeceras (Headers):
 * Crea dos ejemplos de configuración de cabeceras para un fetch:
 * - Uno usando un objeto literal headers: { ... }
 * - Otro instanciando new Headers() y añadiendo con .append(...)
 * En ambos casos, envía exactamente la misma información.
 */
titulo("9. Formas de definir Cabeceras (Headers): Configura cabeceras HTTP de dos maneras diferentes (objeto literal y objeto Headers) enviando los mismos datos.")

async function formasDefinirCabeceras_ej9(url, data) {
    inicio("Ejercicio 9")
    try {
        const response1 = await fetch(url , {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(data)
        })
        if(!response1.ok) {
            throw new Error(`HTTP error Response 1: ${response1.status}`)
        }

        const cabecerasResponse2 = new Headers()
        cabecerasResponse2.append("Content-Type", "application/json")
        const response2 = await fetch(url, {
            method: "POST",
            headers: cabecerasResponse2,
            body: JSON.stringify(data)
        })
        if(!response2.ok) {
            throw new Error(`HTTP error Response 2: ${response2.status}`)
        }

        console.log("Response 1 status: ", response1.status)
        console.log("Response 1 payload: ", data)
        console.log("Response 2 status: ", response2.status)
        console.log("Response 2 payload: ", data)
        

    } catch(error) {
        console.error(`No se puedo realizar el envío: ${error.message}`)
    } finally {
        fin("Ejercicio 9")
    }
}

const data_ej9 = {usuario: "sergio", password: "pass"}
formasDefinirCabeceras_ej9("https://jsonplaceholder.typicode.com/posts", data_ej9)

espacio()

/*
 * 10. Cancelación de peticiones con AbortController:
 * Implementa un caso de cancelación en el HTML con dos botones: 
 * "Iniciar petición" y "Cancelar petición". Usa AbortController para cancelar 
 * el fetch en curso si se pulsa el segundo botón. Maneja el error específico 
 * AbortError mostrando un mensaje en pantalla informando de la cancelación.
 */
titulo("10. Cancelación de peticiones con AbortController: Usa AbortController para permitir cancelar una petición en curso mediante botones, gestionando el AbortError.")

async function cancelarPeticion(url){
    let controlador
    
    const botonFetch = document.querySelector("#fetch")
    botonFetch.addEventListener("click", async () => {
        inicio("Ejercicio 10")
        controlador = new AbortController()
        try {
            console.log("Iniciando fetch")
            const response = await fetch(url, {
                signal: controlador.signal
            })
            if(!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            } 
            console.log(`Response: ${response.status}`)
            
        } 
        catch(error) {
            if (error.name == "AbortError") {
                console.log("Fetch cancelado por el usuario")
            } else {
                console.error(`No se puedo realizar el envío: ${error.message}`)
            }
        } finally {
            fin("Ejercicio 10")
        }
    })

    const botonCancel = document.querySelector("#cancelar")
    botonCancel.addEventListener("click", () => {
        try {
            if (controlador) {
                controlador.abort()
                console.log("Fetch cancelada")
                fin("Ejercicio 10 - 2")    
            }      
        } catch (error) {
            console.error(`No se puedo realizar la cancelación del fetch: ${error.message}`)
        }
    })
} 

const data_ej10 = {usuario: "gojo_satoru", password: "pass"}
cancelarPeticion("https://httpbin.org/delay/3") // Espera 3 segundos antes de resolver la petición

espacio()

/*
 * 11. Utilidad de validación de JSON:
 * Crea una función de utilidad validarJSON(response) que revise la cabecera 
 * response.headers.get("content-type"). Si no incluye "application/json", 
 * la función debe lanzar (throw) un TypeError. Pruébala en una cadena fetch.
 */
titulo("11. Utilidad de validación de JSON: Crea una función que valide si el Content-Type de una respuesta es application/json, lanzando un TypeError si no lo es.")

function validarJSON(response) {
    try {
        const cabecera = response.headers.get("content-type")
        if(!cabecera || !cabecera.includes("application/json")) {
            // Error cuando una operación no puede ser completada, típicamente (pero no exclusivamente) cuando un valor no es del tipo esperado.
            throw new TypeError("No contiene la cabecera application/json en Content-Type")
        } else {
            return response
        }
    } catch(error) {
        console.error("no se pudo validar el JSON: ", error);
    }
}

const cabeceras_ej11= new Headers()
cabeceras_ej11.append("Content-Type", "application/json")

fetch("https://jsonplaceholder.typicode.com/posts")
    .then(response => {
        inicio("Ejercicio 10")
        return validarJSON(response)
    })
    .then(response => {
        return response.json()
    })
    .then(data => {
        console.log("Datos recibidos correctamente: ", data[0].title)
        fin("Ejercicio 10")
    })
    .catch(error => {
        console.error("Error en la cadena fetch:", error.name, error.message);
    }) 
espacio()

/*
 * 12. Diferencia práctica entre errores HTTP y de Red:
 * Simula y documenta con comentarios la diferencia entre:
 * - Un error HTTP (ej. 404), donde la promesa de fetch SÍ se resuelve pero 
 * la propiedad ok es false.
 * - Un error de red (ej. dominio inexistente o sin conexión), donde la promesa 
 * se rechaza directamente y el flujo salta al catch.
 */
titulo("12. Diferencia práctica entre errores HTTP y de Red: Escribe código que provoque un error HTTP y otro de red, documentando cómo actúa fetch en cada caso.")


async function diferenciaEntreErrroresHTTPyRED(url_http, url_red) {
    /*
        Tras no encontrar el json exacto en la can-store => la response no está ok, por lo tanto se eleva una excepción
        y se manda al catch el siguiente error con su mensaje.
        Se para la ejecución y el flujo va a el catch, tras esto se escribe un mensaje de error encadenado con el del new Error del 
        cuerpo try.
    */
    try {
        inicio("Ejericico 12 - HTTP")
        const response = await fetch(url_http)
        if(!response.ok) {
            throw new Error(`HTTP error: ${response.status}`)
        }
        
        const text = await response.text()
        console.log("Ready-HTTP: ", text)
    } catch(error) {
            console.error(`Ejercicio 12 HTTP - HTTP :No se ha podido cargar el contenido: ${error.message}`)
    } finally {
        fin("Ejercicio 12 - HTTP")
    }

    /*
        Al intentar hacer un fetch a una URL que no existe(desde el principio hasta el final) conseguimos que al intentarlo, ni 
        siquiera se llegue al if, por lo tanto, se eleva una excepción automáticamente, en este caso una NetworkError.
        El flujo sigue en el catch y se muestra el mensaje encadenado.
    */
    try {
        inicio("Ejericico 12 - Red")
        const response = await fetch(url_error_red)
        if(!response.ok) {
            throw new Error(`HTTP error: ${response.status}`)
        }
        
        const text = await response.text()
        console.log("Ready - Red: ", text)
    } catch(error) {
            console.error(`Ejercicio 12 Red - HTTP :No se ha podido cargar el contenido: ${error.message}`)
    } finally {
        fin("Ejercicio 12 - Red")
    }
}

function diferenciaEntreErrroresHTTPyRED_v2(url_http, url_red) {
    fetch(url_http)
        .then((response) => {
            inicio("Ejercicio 12 V2 HTTP")
            if (!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            }
            return response.text()
        })
        .then((text) => {
            console.log("Cargando el contenido...")
            console.log("Ready: ", text)
            fin("Ejercicio 12 V2 HTTP")
        })
        .catch((error) => {
            console.error(`Ejercicio 12 V2 HTTP: No se ha podido cargar el contenido: ${error.message}`)
        })
    
    inicio("Ejercicio 12 V2 Red")
    fetch(url_red)
        .then(response => {
            if (!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            }
            return response.text()
        })
        .then(datos => {
            console.log("Cargando el contenido...")
            console.log("Ready: ", datos)
            fin("Ejercicio 12 V2 Red")
        })
        .catch(error => {
            console.error(`Ejercicio 12 V2 Red: No se ha podido cargar el contenido: ${error.message}`)
        })
}

const url_http_error_404 = "https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/lechuguita.json"
const url_error_red = "https://www.esta-web-no-existe-123456.com"
diferenciaEntreErrroresHTTPyRED(url_http_error_404, url_error_red)
diferenciaEntreErrroresHTTPyRED_v2(url_http_error_404, url_error_red)

espacio()

/*
 * 13. Aplicación del Clima (OpenWeatherMap):
 * Crea una aplicación web que use la API abierta de OpenWeatherMap para mostrar 
 * el tiempo actual en una ciudad seleccionada mediante un input de texto.
 * - Endpoint: https://api.openweathermap.org/data/2.5/weather
 * - Método: GET
 * - Parámetros: 'q' (nombre ciudad en inglés, sin tildes) y 'appid' (clave API).
 * - Clave API a usar (appid): "<tu_api>"
 * * Requisitos:
 * El aspecto debe incluir el nombre de la ciudad, la temperatura (convirtiendo 
 * si es necesario o usando el parámetro units=metric), un icono/descripción 
 * del clima y un botón de "Obtener datos". Traduce al español los términos 
 * meteorológicos mostrados en la interfaz.
 */
titulo("13. Aplicación del Clima (OpenWeatherMap): Crea una mini-app que consulte la API de OpenWeatherMap usando una ciudad dada por el usuario y muestre los resultados traducidos al español.")

function iniciarWidgetClima() {
    const boton_buscar_ciudad = document.querySelector("#obtener-datos")
    const cuadro_texto_ciudad = document.querySelector("#ciudad")

    boton_buscar_ciudad.addEventListener("click", async () => {
        try {
            inicio("Ejercicio 13")
            /*
                Petición a la API
            */
            const url = "https://api.openweathermap.org/data/2.5/weather"

            const ciudad = cuadro_texto_ciudad.value
            cuadro_texto_ciudad.value = ""

            const parametros = {
                q: ciudad,
                appid: "<tu_api>",
                units: "metric",
                lang: "es"
            }

            // Definimos una url
            const url_def = new URL(url)
            // Añadimos los parámetros de búsqueda
            url_def.search = new URLSearchParams(parametros)

            console.log("URL final a OpenWeatherMap: ", url_def.toString())

            const response = await fetch(url_def)
            if(!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            }
            console.log("Response status: ", response.status)
        
            const data_json = await response.json()
            console.log("JSON de OpenWeatherMap: ", data_json)
            /*const data_text = await response.text()
            console.log("Txt de OpenWeatherMap: ", data_text)*/


            /* Modificar el HTML */
            const clima = document.querySelector(".clima")

            clima.innerHTML = ""

            const nombre = data_json.name
            const principal = data_json.weather[0].main
            const descripcion = data_json.weather[0].description
            const temperatura = `${data_json.main.temp}ºC`

            const h3_nombre = document.createElement("h3")
            const p_principal = document.createElement("p")
            const p_descripcion = document.createElement("p")
            const p_temperatura = document.createElement("p")

            h3_nombre.textContent = nombre
            p_principal.textContent = principal
            p_descripcion.textContent = descripcion
            p_temperatura.textContent = temperatura


            h3_nombre.classList.add("clima-nombre")
            p_temperatura.classList.add("clima-temperatura")
            p_principal.classList.add("clima-principal")
            p_descripcion.classList.add("clima-descripcion")

            clima.appendChild(h3_nombre)
            clima.appendChild(p_temperatura)
            clima.appendChild(p_principal)
            clima.appendChild(p_descripcion)


        } catch(error) {
            console.error(`No se ha podido realizar la petición ${error.message}`)
        } finally {
            fin("Ejercicio 13")
        }
    })
}
/*
{"coord":
    {"lon":-4.1005,
    "lat":36.7726},
"weather":
    [
        {"id":803,
        "main":"Clouds",=> SELECT 
        "description":"muy nuboso", => SELECT 
        "icon":"04n"}
    ], 
"base":"stations",
"main":
    {"temp":12.77,"feels_like":12.22, => SELECT
    "temp_min":12.77,
    "temp_max":13.62,
    "pressure":1019,"humidity":81,
    "sea_level":1019,
    "grnd_level":983},
    "visibility":10000,
"wind":
    {"speed":2.08,
    "deg":30,
    "gust":2.57},
"clouds":
    {"all":74},
"dt":1774654865,
"sys":
    {"type":2,
    "id":2008749,
    "country":"ES",
    "sunrise":1774678103,
    "sunset":1774722865},
"timezone":3600,
"id":2509769,
"name":"Vélez-Málaga", => SELECT
"cod":200}
 */


iniciarWidgetClima()

espacio()

/*
 * 14. Mini práctica integradora completa:
 * Crea una página con un formulario de búsqueda que englobe los conceptos vistos:
 * - Envíe parámetros de búsqueda por GET.
 * - Realice un fetch asíncrono.
 * - Valide correctamente el estado de respuesta (response.ok) y el tipo de contenido.
 * - Pinte los resultados estructurados en el DOM.
 * - Gestione la cancelación de la petición si se lanza una nueva muy rápido.
 * - Muestre mensajes de error amigables en el HTML (no solo en consola).
 */
titulo("14. Mini práctica integradora completa: Crea un buscador robusto que haga peticiones GET, valide respuestas, actualice el DOM, permita cancelación y maneje errores amigablemente.")


function devolverExistePersonaje(json, nombre) {
    let found = false
    let character = null
    for (let index = 0; index < json.length && !found; index++) {
        if ((json[index].character.name.toLowerCase()).includes(nombre.toLowerCase())) {
            found = true
            character = json[index]
        }    
    }
    return character
}

function buscadorPersonajesShigekiNoKyojin(){
    let controlador = null

    const boton_buscar_personaje = document.querySelector("#buscar")
    const boton_cancelar = document.querySelector("#cancelar-snk")

    const nombre = document.querySelector("#nombre")
    const mensaje_estado = document.querySelector("#mensaje-estado")
    const resultados = document.querySelector("#resultados")

    boton_buscar_personaje.addEventListener("click", async (event) => {
        event.preventDefault() // Evita que el formulario se recargue

        inicio("Ejercicio 14")

        mensaje_estado.innerHTML = ""
        resultados.innerHTML = ""

        // Si ya había una petición, la cancelamos
        if (controlador) {
            controlador.abort()
        }

        controlador = new AbortController()
        try {
            
            /*
                - Envíe parámetros de búsqueda por GET.
            */
            const url = "https://api.jikan.moe/v4/anime/16498/characters"
            const url_def = new URL(url)
            
            const nombre_personaje = nombre.value
            nombre.innerHTML= ""

            /*
                - Realice un fetch asíncrono.
            */
            console.log("SNK searcher: Iniciando búsqueda...")
            const response = await fetch(url_def, {
                headers: {
                    "Content-Type": "application/json"
                },
                signal: controlador.signal,
            })
            /*
                - Valide correctamente el estado de respuesta (response.ok) y el tipo de contenido.
            */
            const cabeceras = response.headers.get("content-type")
            if(!response.ok) {
                throw new Error(`HTTP error: ${response.status}`)
            }
            if (cabeceras && !cabeceras.includes("application/json")) {
                throw new Error(`El archivo no es un JSON`)
            }

            /*
                - Muestre mensajes de error amigables en el HTML (no solo en consola).
            */
            const msg_obtenida = "SNK searcher: Respuest obtenida..."
            const msg_status = `SNK searcher: Response status: ${response.status}`
            console.log(msg_obtenida)
            console.log(msg_status)
            const resp_obtenida = document.createElement("p")
            const resp_status = document.createElement("p")
            resp_obtenida.textContent = msg_obtenida
            resp_status.textContent = msg_status
            mensaje_estado.appendChild(resp_obtenida)
            mensaje_estado.appendChild(resp_status)

            const data_json = await response.json()
            const msg_datos_obtenidos = "SNK searcher: Datos obtenidos..."
            const msg_datos = `JSON de SNK: ${data_json}`
            console.log(msg_datos_obtenidos)
            console.log(msg_datos)
            const resp_datos_obtenidos = document.createElement("p")
            const resp_datos = document.createElement("p")
            resp_datos_obtenidos.textContent = msg_datos_obtenidos
            resp_datos.textContent = msg_datos
            mensaje_estado.appendChild(resp_datos_obtenidos)
            mensaje_estado.appendChild(resp_datos)

            /*
                - Pinte los resultados estructurados en el DOM.
            */
            const character = devolverExistePersonaje(data_json.data, nombre_personaje)

            if (character == null) {
                const p = document.createElement("p")
                
                p.textContent = `SNK searcher: No esta en la base de datos: ${nombre_personaje}`
                mensaje_estado.appendChild(p)
            
                console.error("SNK searcher: No está en la base de datos: ", nombre_personaje)

            } else {
                /* 
                    - Modificar el HTML 
                */
                const h3_intro = document.createElement("h3")
                const p_rol = document.createElement("p")
                const link = document.createElement("a")

                h3_intro.textContent = `Información de ${character.character.name}`
                p_rol.textContent = `Rol: ${character.role}`
                link.textContent = `Wiki de ${nombre_personaje}` 
                link.href = character.character.url
                link.target = "_blank"

                resultados.appendChild(h3_intro)
                resultados.appendChild(p_rol)
                resultados.appendChild(link)

            }

        } catch (error) {
            if (error.name == "AbortError") {
                console.log("SNK searcher: Fetch cancelado por el usuario")
            } else {
                console.error("SNK searcher: No se pudo accedera al personaje: ", error.message)
            
                const p_error = document.createElement("p");
                p_error.textContent = `Error de red: ${error.message}`;
                p_error.style.color = "red";
                mensaje_estado.appendChild(p_error);
            }
        }
        fin("Ejercicio 14")
    })
    
    /*
        - Gestione la cancelación de la petición si se lanza una nueva 
        muy rápido.
    */
    boton_cancelar.addEventListener("click", () => {
        try {
            if (controlador) {
                controlador.abort()
                console.log("SNK searcher: Búsqueda cancelada")
                fin("Ejercicio 14")
            }      
        } catch (error) {
            console.error(`SNK searcher: No se puedo realizar la cancelación del fetch: ${error.message}`)
        }
        fin("Ejercicio 14")
    })
}

buscadorPersonajesShigekiNoKyojin()

espacio()