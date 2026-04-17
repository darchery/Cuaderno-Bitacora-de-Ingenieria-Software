// Funciones de utilidad para organizar la consola
function titulo(texto) {
    console.log(`\n==================================================`);
    console.log(`   ${texto.toUpperCase()}`);
    console.log(`==================================================\n`);
}

function separador() {
    console.log("\n--------------------------------------------------\n");
}

// Inicio de los ejercicios
titulo("Ejercicios sobre almacenamiento en el cliente");

titulo("Ejercicio 1: Selector de tema con localStorage");
/*
 * 1. Implementa una página web con un selector de tema (claro/oscuro) 
 * que recuerde la preferencia del usuario usando localStorage, de forma 
 * que al recargar la página se aplique automáticamente el tema elegido.
 */

const boton_claro = document.querySelector("#claro")
const boton_oscuro = document.querySelector("#oscuro")

if (localStorage.getItem("tema") == "claro") {
    document.body.classList.remove("theme-oscuro")
    document.body.classList.add("theme-claro")
} else if (localStorage.getItem("tema") == "oscuro") {
    document.body.classList.remove("theme-claro")
    document.body.classList.add("theme-oscuro")
} else {
    document.body.classList.add("theme-claro")
}

boton_claro.addEventListener("click", () => {
    document.body.classList.remove("theme-oscuro")
    document.body.classList.add("theme-claro")
    localStorage.setItem("tema", "claro")
}) 
boton_oscuro.addEventListener("click", () => {
    document.body.classList.remove("theme-claro")
    document.body.classList.add("theme-oscuro")
    localStorage.setItem("tema" ,"oscuro")
})


separador();

titulo("Ejercicio 3: Carrito de la compra con localStorage");
/*
 * 3. Implementa un carrito de la compra sencillo (añadir y eliminar productos) 
 * cuyo contenido se persista en localStorage para que no se pierda al cerrar el
 * navegador.
 */

// Si el carrito es null se le asigna un array JSON vacio
// tras eso convertimos el string JSON en un array de JavaScript
let carrito = JSON.parse(localStorage.getItem("carrito") || "[]");
const boton_anyadir = document.querySelector("#b-anyadir")
const campo_buscar = document.querySelector("#i-buscar")


function cargarActualizarCarrito() {
    const lista_productos = document.querySelector("#lista-carrito")
    lista_productos.innerHTML = ""

    // Recorremos el array carrito 
    carrito.forEach((producto, index) => {
        const elemento_lista = document.createElement("li")
        elemento_lista.classList.add("elemento-carrito")
    
        const boton_eliminar = document.createElement("button")
        boton_eliminar.classList.add("boton-eliminar")
        boton_eliminar.textContent = "×"
        boton_eliminar.onclick = () => eliminarProducto(index)

        const p_producto = document.createElement("p")
        p_producto.textContent = producto

        elemento_lista.appendChild(p_producto)
        elemento_lista.appendChild(boton_eliminar)
        lista_productos.appendChild(elemento_lista)
    })
}

function eliminarProducto(index) {
    carrito.splice(index, 1) // Elimina un elemento desde la posición index
    // Sube el array actualizado
    localStorage.setItem("carrito", JSON.stringify(carrito))
    // Lo añade o lo actualiza
    cargarActualizarCarrito()
}

boton_anyadir.addEventListener("click", () => {
    const producto = campo_buscar.value
    campo_buscar.value = ""

    if (producto) {
        // Añade un elemento al final de la lista
        carrito.push(producto)
        // Sube la lista actualizada
        localStorage.setItem("carrito", JSON.stringify(carrito))
        // Lo añade o lo actualiza
        cargarActualizarCarrito()
    }
})

cargarActualizarCarrito()


separador();

/**
 * MUY IMPORATANTE PARA PROBAR CADA EJERCICIO DE IndexDB
 * indexedDB.deleteDatabase("<nombre_base_datos>")
*/


titulo("Ejercicio 4: Aplicación de notas con IndexedDB");
/*
 * 4. Crea una pequeña aplicación de notas que use IndexedDB para guardar, listar 
 * y borrar notas. Cada nota tendrá un título y un cuerpo. Al cargar la página 
 * deben mostrarse las notas ya guardadas.
 */

let bd;
// Abrimos la base de datos
const peticionApertura = window.indexedDB.open("bd_notas", 1)
const titulo_nota = document.querySelector("#i-titulo")
const cuerpo_nota = document.querySelector("#t-cuerpo")
const boton_guardar_nota = document.querySelector("#b-guardar")
const boton_listar_notas = document.querySelector("#b-listar")
const lista_notas = document.querySelector("#lista-notas")


function listarNotas(bd) {
    const transaction = bd.transaction(["notas"], "readonly")
    const store = transaction.objectStore("notas")
    const request = store.getAll()

    request.addEventListener("success", () => {
        const notas = request.result

        lista_notas.innerHTML = ""

        if (notas.length == 0) {
            const li = document.createElement("li")
            li.textContent = "No hay notas disponibles"
            lista_notas.appendChild(li)
        } else {
            notas.forEach((nota) => {
                const li = document.createElement("li")
                const h4 = document.createElement("h4")
                const button = document.createElement("button")
                const p = document.createElement("p")

                li.setAttribute("data-note-id", nota.id)
                h4.textContent = nota.titulo
                p.textContent = nota.cuerpo
                button.textContent = "Eliminar"
                button.classList.add("boton-eliminar")
                button.onclick = () => {
                    const notaId = Number(li.getAttribute("data-note-id"))
                    const transaction = bd.transaction(["notas"], "readwrite")
                    const store = transaction.objectStore("notas")
                    const deleteRequest = store.delete(notaId)

                    transaction.addEventListener("complete", () => {
                        listarNotas(bd)
                    })
                }

                li.appendChild(h4)
                li.appendChild(p)
                li.appendChild(button)
                lista_notas.appendChild(li)
            })
        }
    })
}

// El evento "error" significa que la base de datos no se ha abierto correctamente
peticionApertura.addEventListener("error", (e) =>
  console.error("Error al abrir la base de datos", e.target.error));

// Establecer las tablas de la base de datos si no se ha hecho aún
peticionApertura.addEventListener("upgradeneeded", (e) =>{

    // Asociar una referencia a la base de datos abierta
    bd = e.target.result;

    // Crear un objectStore en la base de datos para almacenar notas 
    // un una clave autoincremental
    if (!bd.objectStoreNames.contains("notas")) {
        bd.createObjectStore("notas", {keyPath: "id", autoIncrement: true});
        console.log("ObjectStore 'notas' creado");
    } else {
        console.log("ObjectStore 'notas' ya existía");
    }
    console.log("Establecimient o completo de la base de datos");
});

// El evento "success" significa que la base de datos se ha abierto correctamente
peticionApertura.addEventListener("success", () => {
  console.log("Ejercicio 4 - Database opened successfully");

    // almacenar el objeto base de datos abierto en la variable global bd
    bd = peticionApertura.result;

    // Al cargar la página deben mostrarse las notas ya guardadas
    listarNotas(bd)

    boton_guardar_nota.addEventListener("click", () => {
        const titulo = titulo_nota.value
        const cuerpo = cuerpo_nota.value
        
        if (cuerpo && titulo) {
            titulo_nota.value = ""
            cuerpo_nota.value = ""
        
            const transaction = bd.transaction(["notas"], "readwrite") 
            const store = transaction.objectStore("notas")
            store.add({titulo, cuerpo})    
        }
    })

    boton_listar_notas.addEventListener("click", () => listarNotas(bd))
});


separador();

titulo("Ejercicio 5: Caché de imagen con IndexedDB");
/*
 * 5. Implementa una página que descargue una imagen de la red la primera vez que 
 * se visita y la almacene en IndexedDB como un blob. En las visitas posteriores 
 * debe cargarse directamente desde IndexedDB sin hacer ninguna petición de red.
 */

let bd_ej5;
const peticionApertura_ej5 = window.indexedDB.open("bd_imagenes", 1)

const boton_descargar = document.querySelector("#b-descargar-img")
const div_ej5 = document.querySelector("#div-ej5")

function mostrarImagen(datos) {
    div_ej5.innerHTML = ""

    const img = document.createElement("img")
    img.src = URL.createObjectURL(datos)

    div_ej5.appendChild(img)
}

function descargarImagen(bd,img) {
    fetch(img)
    .then(response => response.blob())
    .then(blob => {
        const transaction = bd.transaction(["imagenes"], "readwrite")
        const store = transaction.objectStore("imagenes")
        store.add({nombre: "mi-img", datos: blob})
        mostrarImagen(blob)
    })
}

// El evento "error" significa que la base de datos no se ha abierto correctamente
peticionApertura_ej5.addEventListener("error", (e) =>
  console.error("Error al abrir la base de datos: ", e.target.error));

peticionApertura_ej5.addEventListener("upgradeneeded", (e) =>{

    // Asociar una referencia a la base de datos abierta
    bd_ej5 = e.target.result;

    // Crear un objectStore en la base de datos para almacenar una imagen 
    bd_ej5.createObjectStore("imagenes", {keyPath: "nombre"});

    console.log("Establecimiento completo de la base de datos");

});

// El evento "success" significa que la base de datos se ha abierto correctamente
peticionApertura_ej5.addEventListener("success", () => {
  console.log("Ejercicio 5 - Database opened successfully");

    // almacenar el objeto base de datos abierto en la variable global bd
    bd_ej5 = peticionApertura_ej5.result;

    boton_descargar.addEventListener("click", () => {
        const transaction = bd_ej5.transaction(["imagenes"], "readonly")
        const store = transaction.objectStore("imagenes")
        const request = store.get("mi-img")

        request.addEventListener("success", () => {
            // Ya existe la imagen
            if (request.result) {
                console.log("Ya existe la imagen: Cargando desde IndexDB...")
                mostrarImagen(request.result.datos)
            } else { // No existe la imagen
                const img = `https://picsum.photos/200?random=${Date.now()}`
                console.log("No existe la imagen: Descargando de la red...")
                descargarImagen(bd_ej5, img)
            }
        })
    })
});

separador();

titulo("Ejercicio 6: Formulario de preferencias con localStorage");
/*
 * 6. Crea una página con un formulario de preferencias (idioma, tamaño de fuente, 
 * color de acento). Las preferencias deben guardarse en localStorage y aplicarse 
 * al cargar la página sin que el usuario tenga que volver a configurarlas.
 */


const select_idioma = document.querySelector("#idioma")
const select_tam_fuente = document.querySelector("#tam-fuente")
const select_color_acento = document.querySelector("#color-acento")
const form_pref = document.querySelector("#form-preferencias")

function cargarPreferencias() {
    const idioma = localStorage.getItem("idioma")
    const tam_fuente = localStorage.getItem("tam_fuente")
    const color_acento = localStorage.getItem("color_acento")


    if (idioma) {
        document.documentElement.lang = idioma
    }
    console.log("Idioma actual: ", idioma)

    if (tam_fuente) {
        document.body.style.fontSize = `${tam_fuente}px`
    }
    if (color_acento) {
        document.documentElement.style.setProperty("--color-acento", color_acento)
    }
}

form_pref.addEventListener("submit", (e) => {
    e.preventDefault() // Evita que la página se recargue

    const idioma = select_idioma.value
    const tam_fuente = select_tam_fuente.value
    const color_acento = select_color_acento.value

    localStorage.setItem("idioma", idioma)
    localStorage.setItem("tam_fuente", tam_fuente)
    localStorage.setItem("color_acento", color_acento)

    cargarPreferencias()
})

// Cargar preferencias al cargar la página
cargarPreferencias()

separador();

titulo("Ejercicio 7: Historial de búsqueda con sessionStorage");
/*
 * 7. Implementa un sistema de historial de búsqueda. Cada vez que el usuario escribe 
 * y envía una búsqueda, el término se guarda en sessionStorage y se muestra una lista 
 * con las búsquedas realizadas durante esa sesión, que desaparece al cerrar el navegador.
 */

const historial_busqueda = JSON.parse(sessionStorage.getItem("historial") || "[]")
const input_buscador = document.querySelector("#i-buscador")
const boton_buscador = document.querySelector("#b-buscador")
const lista_historial = document.querySelector("#historial")

function cargarHistorial() {
    historial_busqueda.forEach(busqueda => {
        const li = document.createElement("li")

        li.textContent = busqueda
        lista_historial.appendChild(li)
    })
}

boton_buscador.addEventListener("click", (e) => {
    e.preventDefault()
    const busqueda = input_buscador.value

    if (busqueda) {
        const li = document.createElement("li")
        input_buscador.value = ""
        li.textContent = busqueda
        lista_historial.appendChild(li)

        historial_busqueda.push(busqueda)
        sessionStorage.setItem("historial", JSON.stringify(historial_busqueda))
    }
})

cargarHistorial()

separador();

titulo("Ejercicio 8: Lista de contactos con IndexedDB");
/*
 * 8. Crea una aplicación que gestione una lista de contactos usando IndexedDB. Cada 
 * contacto tendrá nombre, email y teléfono. Crea un índice sobre el campo email 
 * para poder buscar un contacto directamente por su dirección de correo.
 */

let bd_contactos
const peticionApertura_contactos = window.indexedDB.open("bd_contactos", 1)
const form_contacto = document.querySelector("#form-contacto")
const input_nombre = document.querySelector("#nombre-contacto")
const input_email = document.querySelector("#email-contacto")
const input_telefono = document.querySelector("#telefono-contacto")
const div_lista_contactos = document.querySelector("#lista-contactos")
const boton_listar_contactos = document.querySelector("#b-listar-contactos")
const lista_emails = document.querySelector("#lista-emails")
const boton_buscar_email = document.querySelector("#b-email")
const input_buscar_email = document.querySelector("#i-buscar-email")

function mostrarContactos(bd) {
    const transaction = bd.transaction(["contactos"], "readonly")
    const store = transaction.objectStore("contactos")
    const request = store.getAll()

    div_lista_contactos.innerHTML = ""

    request.addEventListener("success", () => {
        const contactos = request.result

        if (contactos.length == 0) {
            const li = document.createElement("li")
            li.textContent = "No hay contactos actualmente"
            div_lista_contactos.appendChild(li)
        } else {
            contactos.forEach(contacto => {
                const li = document.createElement("li")
                const sub_lista = document.createElement("ul")
                const sub_li_email = document.createElement("li")
                const sub_li_telefono = document.createElement("li")
                const boton_eliminar = document.createElement("button")

                li.setAttribute("contacto-id", contacto.id)
                li.textContent = contacto.nombre
                sub_li_email.textContent = `Email: ${contacto.email}`
                sub_li_telefono.textContent = `Teléfono: ${contacto.telefono}`
                boton_eliminar.textContent = "Eliminar"
                boton_eliminar.onclick = () => {
                    const contactoID = Number(li.getAttribute("contacto-id"))
                    const transaction = bd.transaction(["contactos"], "readwrite")
                    const store = transaction.objectStore("contactos")
                    const request = store.delete(contactoID)

                    transaction.addEventListener("complete", () => mostrarContactos(bd))
                }

                sub_lista.appendChild(sub_li_email)
                sub_lista.appendChild(sub_li_telefono)
                sub_lista.appendChild(boton_eliminar)
                li.appendChild(sub_lista)
                div_lista_contactos.appendChild(li)
            }) 
        }
    })
}

// El evento "error" significa que la base de datos no se ha abierto correctamente
peticionApertura_contactos.addEventListener("error", () =>
  console.error("Ejercicio 8 - Error al abrir la base de datos"));

// Establecer las tablas de la base de datos si no se ha hecho aún
peticionApertura_contactos.addEventListener("upgradeneeded", (e) =>{

    // Asociar una referencia a la base de datos abierta
    bd_contactos = e.target.result;

    // Crear un objectStore en la base de datos para almacenar contactos
    const objectStore = bd_contactos.createObjectStore("contactos",{keyPath: "id", autoIncrement: true});
    objectStore.createIndex("email", "email", {unique: true})

    console.log("Ejercicio 8 - Establecimiento completo de la base de datos");

});

// El evento "success" significa que la base de datos se ha abierto correctamente
peticionApertura_contactos.addEventListener("success", () => {
  console.log("Ejercicio 8 - Database opened successfully");

    // almacenar el objeto base de datos abierto en la variable global bd
    bd_contactos = peticionApertura_contactos.result;

    form_contacto.addEventListener("submit", () => {
        const nombre = input_nombre.value
        const email = input_email.value
        const telefono = input_telefono.value
        
        input_nombre.value = ""
        input_email.value = ""
        input_telefono.value = ""
        
        if (nombre && email && telefono) {
            const transaction = bd_contactos.transaction(["contactos"], "readwrite")
            const store = transaction.objectStore("contactos")
            store.add({nombre, email, telefono})
            mostrarContactos(bd_contactos)
        }
    })

    boton_listar_contactos.addEventListener("click", () => mostrarContactos(bd_contactos))

    boton_buscar_email.addEventListener("click", () => {
        const email = input_buscar_email.value
        input_buscar_email.value = ""

        if (email) {
            const transaction = bd_contactos.transaction(["contactos"], "readonly")
            const store = transaction.objectStore("contactos")
            const index = store.index("email") // Accedemos al índice
            const request = index.get(email)

            request.addEventListener("success", () => {
                const li = document.createElement("li")
                lista_emails.innerHTML = ""

                if (request.result) {
                    li.textContent = `Se ha encontrado el email: ${email}!`                
                } else {
                    li.textContent = `No se ha encontrado el email: ${email}`
                }
                lista_emails.appendChild(li)
            })
        }
    })
});


separador();

titulo("Ejercicio 9: Versionado de IndexedDB");
/*
 * 9. Implementa el versionado de una base de datos IndexedDB que en su versión 1 
 * solo tiene un almacén de objetos 'productos' con índice 'nombre', y en su versión 2 
 * añade un nuevo almacén 'pedidos' y un índice 'categoria' al almacén 'productos'. El código 
 * debe funcionar correctamente tanto para usuarios nuevos como para los que ya tienen la versión 1.
 */

let bd_productos
const peticionApertura_productos = window.indexedDB.open("bd_productos", 2)
//const peticionApertura_productos = window.indexedDB.open("bd_productos", 2)

// Añadir productos
const input_producto_nombre = document.querySelector("#i-producto")
const input_producto_categoria = document.querySelector("#i-categoria")
const boton_anyadir_producto = document.querySelector("#b-producto")

// Buscar productos por nombre
const input_buscar_nombre = document.querySelector("#i-buscar-por-nombre")
const boton_buscar_nombre = document.querySelector("#b-buscar-nombre")
const lista_por_nombre = document.querySelector("#lista-por-nombre")

// Buscar productos por categoria
const input_buscar_categoria = document.querySelector("#i-buscar-por-categoria")
const boton_buscar_categoria = document.querySelector("#b-buscar-categoria")
const lista_por_categoria = document.querySelector("#lista-por-categoria")

// Listar todos los productos
const boton_listar_productos = document.querySelector("#b-listar-productos")
const lista_productos = document.querySelector("#lista-productos")

// Añadir pedidos
const input_pedido = document.querySelector("#i-pedido")
const boton_anyadir_pedido = document.querySelector("#b-pedido")
const lista_pedidos = document.querySelector("#lista-pedidos")


function mostrarProductos(bd) {
    const transaction = bd.transaction(["productos"], "readonly")
    const store = transaction.objectStore("productos")
    const request = store.getAll()

    lista_productos.innerHTML = ""

    request.addEventListener("success", () => {
        const productos = request.result

        if (productos.length == 0) {
            const li = document.createElement("li")
            li.textContent = "No hay contactos"
            lista_productos.appendChild(li)
        } else {
            productos.forEach(producto => {
                const li_nombre = document.createElement("li")
                const sub_lista = document.createElement("ul")
                const sub_li_categoria = document.createElement("li")

                li_nombre.textContent = producto.nombre
                sub_li_categoria.textContent = `Categoría: ${producto.categoria}`
            
                sub_lista.appendChild(sub_li_categoria)
                li_nombre.appendChild(sub_lista)
                lista_productos.appendChild(li_nombre)
            })
        }
    })
}

function mostrarPedidos(bd) {
    const transaction = bd.transaction(["pedidos"], "readonly")
    const store = transaction.objectStore("pedidos")
    const request = store.getAll()

    lista_pedidos.innerHTML = ""

    request.addEventListener("success", () => {
        const pedidos = request.result
        lista_pedidos.innerHTML = ""

        if (pedidos.length == 0) {
            const li = document.createElement("li")
            li.textContent = "No hay pedidos"
            lista_pedidos.appendChild(li)
        } else {
            pedidos.forEach((pedido) => {
                const li = document.createElement("li")
                li.textContent = pedido.nombre
                lista_pedidos.appendChild(li)
            })
        }
    })
}

// El evento "error" significa que la base de datos no se ha abierto correctamente
peticionApertura_productos.addEventListener("error", () => {
    console.error("Ejercicio 9 - Error al abrir la base de datos")
})  

peticionApertura_productos.addEventListener("upgradeneeded", (event) => {
    const db = event.target.result;
    const { oldVersion } = event;

    // Versión 1: 
    //  Almacen de objetos: 'producto'
    //  Índice de productos: 'nombre'
    if (oldVersion < 1) {
        const objectStore = db.createObjectStore("productos", { keyPath: "id" , autoIncrement: true});
        objectStore.createIndex("nombre", "nombre", {unique: false})
    }

    // Versión 2:
    //  Almacen de objetos: 'pedidos'
    //  Índice adicional de productos: 'categoria'
    if (oldVersion < 2) {
        db.createObjectStore("pedidos", {keyPath: "id", autoIncrement: true})

        // Línea clave para el funcionamiento => no llamar a db
        // usar el evento, su target y hacer una transacción llamando a un objectStore
        const store = event.target.transaction.objectStore("productos")
        store.createIndex("categoria", "categoria", { unique: false });
    }
    bd_productos = db
}) 

// El evento "success" significa que la base de datos se ha abierto correctamente
peticionApertura_productos.addEventListener("success", () => {
  console.log("Ejercicio 9 - Database opened successfully");

    // almacenar el objeto base de datos abierto en la variable global bd
    bd_productos = peticionApertura_productos.result;

    boton_anyadir_producto.addEventListener("click", () => {
        const nombre = input_producto_nombre.value
        const categoria = input_producto_categoria.value

        if (nombre && categoria) {
            input_producto_nombre.value = ""
            input_producto_categoria.value = ""

            const transaction = bd_productos.transaction(["productos"], "readwrite")
            const store = transaction.objectStore("productos")
            store.add({nombre, categoria})

            mostrarProductos(bd_productos)
        }
    })

    boton_buscar_nombre.addEventListener("click", () => {
        const nombre = input_buscar_nombre.value
        input_buscar_nombre.value = ""

        if (nombre) {
            const transaction = bd_productos.transaction(["productos"], "readonly")
            const store = transaction.objectStore("productos")
            const index = store.index("nombre") // Accedemos al índice
            const request = index.get(nombre)

            request.addEventListener("success", () => {
                const li = document.createElement("li")
                lista_por_nombre.innerHTML = ""

                if (request.result) {
                    li.textContent = `Se ha encontrado el nombre: ${nombre}!`                
                } else {
                    li.textContent = `No se ha encontrado el nombre: ${nombre}`
                }
                lista_por_nombre.appendChild(li)
            })
        }
    })
    boton_buscar_categoria.addEventListener("click", () => {
        const categoria = input_buscar_categoria.value
        input_buscar_categoria.value = ""

        if (categoria) {
            const transaction = bd_productos.transaction(["productos"], "readonly")
            const store = transaction.objectStore("productos")
            const index = store.index("categoria") // Accedemos al índice
            const request = index.getAll(categoria)

            request.addEventListener("success", () => {
                const productos = request.result
                
                if (productos.length == 0) {
                    const li = document.createElement("li")
                    li.textContent = `No se han encontrado productos en la categoría: ${categoria}`
                    lista_por_categoria.appendChild(li)
                } else {
                    productos.forEach((producto) => {
                        const li = document.createElement("li")
                        li.textContent = `${producto.nombre} - ${producto.categoria}`
                        lista_por_categoria.appendChild(li)
                    })
                }
            })
        }
    })

    boton_listar_productos.addEventListener("click", () => mostrarProductos(bd_productos))


    boton_anyadir_pedido.addEventListener("click", () => {
        const nombre = input_pedido.value

        if (nombre) {
            input_pedido.value = ""

            const transaction = bd_productos.transaction(["pedidos"], "readwrite")
            const store = transaction.objectStore("pedidos")
            store.add({nombre})

            mostrarPedidos(bd_productos)
        }
    })
});

separador();

titulo("Ejercicio 10: Caché de vídeos con IndexedDB");
/*
 * 10. Crea una página que muestre un listado de vídeos. La primera vez los descarga 
 * de la red y los almacena en IndexedDB. A partir de la segunda visita los sirve 
 * desde IndexedDB, mostrando en la consola en cada caso si el vídeo se ha cargado 
 * desde la red o desde la base de datos local.
 */

const videos_lista = [
    "mov_bbb.mp4",
    "movie.mp4",
    "flower.webm"
]

let bd_videos;
const peticionApertura_videos = window.indexedDB.open("bd_videos", 1)

const boton_descargar_video = document.querySelector("#b-descargar-video")
const div_ej10 = document.querySelector("#div-ej10")

function mostrarVideo(datos) {
    const video = document.createElement("video")
    video.src = URL.createObjectURL(datos)
    video.controls = true

    div_ej10.appendChild(video)
}

function descargarVideo(bd, video, name) {
    fetch(video)
    .then(response => response.blob())
    .then(blob => {
        const transaction = bd.transaction(["videos"], "readwrite")
        const store = transaction.objectStore("videos")
        store.add({nombre: name, datos: blob})
        mostrarVideo(blob)
    })
}

// El evento "error" significa que la base de datos no se ha abierto correctamente
peticionApertura_videos.addEventListener("error", (e) =>
  console.error("Ejercicio 10 - Error al abrir la base de datos: ", e.target.error));

peticionApertura_videos.addEventListener("upgradeneeded", (e) =>{

    // Asociar una referencia a la base de datos abierta
    bd_videos = e.target.result;

    // Crear un objectStore en la base de datos para almacenar una imagen 
    const store = bd_videos.createObjectStore("videos", {keyPath: "nombre"});

    console.log("Ejercicio 10 - Establecimiento completo de la base de datos");

});

// El evento "success" significa que la base de datos se ha abierto correctamente
peticionApertura_videos.addEventListener("success", () => {
  console.log("Ejercicio 10 - Database opened successfully");

    // almacenar el objeto base de datos abierto en la variable global bd
    bd_videos = peticionApertura_videos.result;
    
    boton_descargar_video.addEventListener("click", () => {
        const transaction = bd_videos.transaction(["videos"], "readonly")
        const store = transaction.objectStore("videos")
        const request = store.getAll()

        request.addEventListener("success", () => {
            const videos = request.result
            div_ej10.innerHTML = ""


            // Ya existe el vídeo
            if (videos.length == 0) {
                console.log("No existen los vídeos: Descargando de la red...")
                for (let index = 0; index < videos_lista.length; index++) {
                    descargarVideo(bd_videos, videos_lista[index], videos_lista[index])
                }
            } else { // No existen los vídeos
                console.log("Ya existen los vídeo: Cargando desde IndexDB...")
                for (let index = 0; index < videos_lista.length; index++) {
                    mostrarVideo(videos[index].datos)
                }
            }
        })
    })
});

separador();

titulo("Ejercicio 10.V2: Caché de vídeos con IndexedDB");
// Array de vídeos locales
const videos = [
    { nombre: "mov_bbb.mp4", url: "mov_bbb.mp4" },
    { nombre: "movie.mp4", url: "movie.mp4" },
    { nombre: "flower.webm", url: "flower.webm" }
]

let bd_videos_v2;

const peticionApertura_videos_v2 = window.indexedDB.open("bd_videos_v2", 1)

const div_ej10_v2 = document.querySelector("#div-ej10-v2")

// --- Funciones ---
function displayVideo(nombre, datos) {
    const video = document.createElement("video")
    video.controls = true
    
    const source = document.createElement("source")
    source.src = URL.createObjectURL(datos)
    source.type = nombre.endsWith(".webm") ? "video/webm" : "video/mp4"
    
    video.appendChild(source)
    div_ej10_v2.appendChild(video)
}
function storeVideo(nombre, blob) {
    const transaction = bd_videos_v2.transaction(["videos"], "readwrite")
    const store = transaction.objectStore("videos")
    store.add({ nombre: nombre, datos: blob })
}
function fetchVideoFromNetwork(nombre, url) {
    fetch(url)
        .then(response => response.blob())
        .then(blob => {
            console.log(`"${nombre}" descargado de la red`)
            storeVideo(nombre, blob)
            displayVideo(nombre, blob)
        })
}
function init() {
    videos.forEach(video => {
        const transaction = bd_videos_v2.transaction(["videos"], "readonly")
        const store = transaction.objectStore("videos")
        const request = store.get(video.nombre)
        
        request.addEventListener("success", () => {
            if (request.result) {
                console.log(`"${video.nombre}" cargado desde IndexedDB`)
                displayVideo(video.nombre, request.result.datos)
            } else {
                fetchVideoFromNetwork(video.nombre, video.url)
            }
        })
    })
}
// --- Eventos de IndexedDB ---
peticionApertura_videos_v2.addEventListener("error", (e) =>
    console.error("Ejercicio 10.V2 - Error al abrir la base de datos: ", e.target.error))

peticionApertura_videos_v2.addEventListener("upgradeneeded", (e) => {
    bd_videos_v2 = e.target.result
    bd_videos_v2.createObjectStore("videos", { keyPath: "nombre" })
    console.log("Ejercicio 10.V2 - Establecimiento completo de la base de datos")
})

peticionApertura_videos_v2.addEventListener("success", () => {
    console.log("Ejercicio 10.V2 - Database opened successfully")
    bd_videos_v2 = peticionApertura_videos_v2.result
    init()  // ← Llamar a init() al abrir la BD
})