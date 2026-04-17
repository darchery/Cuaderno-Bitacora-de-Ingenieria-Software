const ej0_lista = document.getElementById("ej0_lista");
const ej0_boton = document.getElementById("ej0_boton");
let contador = 4;

ej0_boton.addEventListener("click", () => {
    const nuevoElemento = document.createElement("li");
    nuevoElemento.textContent = `Elemento ${contador}`;
    ej0_lista.appendChild(nuevoElemento);
    contador++;
});

/* ==========================================================================
 * EJERCICIO 1: Crear dinámicamente una tabla HTML
 * ==========================================================================
 * Crear una página web que inicialmente solo tenga un botón sobre el
 * que al pulsar se cree dinámicamente una tabla HTML desde JavaScript.
 * Inicialmente, será una tabla de dos filas y dos columnas.
 *
 * Para crear la tabla, vamos a suponer que sin cabecera, hay que usar
 * el método createElement para crear la tabla, para crear
 * cada una de las filas y para crear cada una de los elementos de cada
 * fila. Para crear el contenido de cada elemento de la tabla hay que
 * usar el método createTextNode con el texto que se vaya a
 * incluir.
 *
 * Después de crear cada elemento de cada tipo, hay que usar el método
 * appendChild para hacer que cada nuevo elemento sea hijo de
 * su antecesor (contenido textual -> elemento de la tabla -> fila de
 * la tabla -> tabla -> cuerpo del documento).
 *
 * Finalmente, ponga un borde de 2 píxeles a la tabla.
 *
 * En una segunda versión, puede añadir dos entradas de texto donde el
 * usuario puede incluir el número de filas y columnas que quiere para la
 * tabla. Controle que los valores están entre 1 y 7.
 */

const ej1_button = document.getElementById("ej1_button")

ej1_button.addEventListener("click", () => {
    const ej1_tabla = document.createElement("table")
    ej1_tabla.style.border = "2px solid black"
    let cnt = 1

    // 2 filas
    for (let i = 0; i < 2; i++) {
        const fila = document.createElement("tr")

        // 2 columnas
        for (let j = 0; j < 2; j++) {
            const celda = document.createElement("td")
            celda.style.border = "1px solid grey"
            const text = document.createTextNode("Elemento " + cnt + " en Fila: " + (i + 1) + " y Columna: " + (j + 1))
            cnt++
            celda.appendChild(text)
            fila.appendChild(celda)
        }

        ej1_tabla.appendChild(fila)
    }

    document.body.appendChild(ej1_tabla)
})

const ej1_button_v2 = document.getElementById("ej1_button_v2")
const ej1_A = document.getElementById("ej1_A")
const ej1_B = document.getElementById("ej1_B")


ej1_button_v2.addEventListener("click", () => {
    const a = Number(ej1_A.value)
    const b = Number(ej1_B.value)

    if ((a >= 1 && a <= 7) && (b >= 1 && b <= 7)) {
        const ej1_tabla = document.createElement("table")
        ej1_tabla.style.border = "2px solid black"
        let cnt = 1
        
        // 2 filas
        for (let i = 0; i < a; i++) {
            const fila = document.createElement("tr")

            // 2 columnas
            for (let j = 0; j < b; j++) {
                const celda = document.createElement("td")
                celda.style.border = "1px solid grey"
                const text = document.createTextNode("Elemento " + cnt + " en Fila: " + (i + 1) + " y Columna: " + (j + 1))
                cnt++
                celda.appendChild(text)
                fila.appendChild(celda)
            }

            ej1_tabla.appendChild(fila)
        }

        document.body.appendChild(ej1_tabla)
    } else {
        alert("ERROR: Las columnas y filas deben estar entre valores desde el 1 hasta el 7")
    }
})


/* ==========================================================================
 * EJERCICIO 2: Manejar un semáforo con botones
 * ==========================================================================
 * Crear una página web en la que se muestre un semáforo, hecho con tres
 * círculos colocados en vertical dentro de un borde con las esquinas
 * redondeadas, y que se maneje a través de tres botones que habrá debajo.
 * * Cada botón hace que el semáforo cambie al color de la etiqueta del
 * botón. El cambio hace que el círculo correspondiente se ponga en el
 * color adecuado y los otros dos se pongan de color gris. 
 * * Gestione los cambios añadiendo/borrando clases a los círculos del 
 * semáforo. Puede haber una clase común para darle la forma y el tamaño a 
 * los círculos y clases particulares para darle el color.
 */
const ej2_rojo = document.getElementById("ej2_rojo")
const ej2_ambar = document.getElementById("ej2_ambar")
const ej2_verde = document.getElementById("ej2_verde")

const ej2_circulo_a = document.querySelector(".ej2_circulo-a") // Rojo
const ej2_circulo_b = document.querySelector(".ej2_circulo-b") // Gris
const ej2_circulo_c = document.querySelector(".ej2_circulo-c") // Gris

function ej2_resetColores() {
    ej2_circulo_a.classList.remove("ej2_circulo-a", "ej2_circulo-b", "ej2_circulo-c")
    ej2_circulo_b.classList.remove("ej2_circulo-a", "ej2_circulo-b", "ej2_circulo-c")
    ej2_circulo_c.classList.remove("ej2_circulo-a", "ej2_circulo-b", "ej2_circulo-c")

}

ej2_rojo.addEventListener("click", () => {
    ej2_resetColores()
    ej2_circulo_a.classList.add("ej2_circulo-a")
})

ej2_ambar.addEventListener("click", () => {
    ej2_resetColores()
    ej2_circulo_b.classList.add("ej2_circulo-b")
})

ej2_verde.addEventListener("click", () => {
    ej2_resetColores()
    ej2_circulo_c.classList.add("ej2_circulo-c")
})



/* ==========================================================================
 * EJERCICIO 3: Mantener el tamaño de una lista dinámica
 * ==========================================================================
 * Ampliar el ejemplo de nuevos-elementos-tras-pulsar-boton.html para que 
 * la lista no pase de 10 elementos, borrando el primer elemento.
 */

const ej3_lista = document.getElementById("ej3_lista");
const ej3_boton = document.getElementById("ej3_boton");
let ej3_contador = 4;

function ej3_crearElemento() {
    const nuevoElemento = document.createElement("li");
    nuevoElemento.textContent = `Elemento ${ej3_contador}`;
    ej3_lista.appendChild(nuevoElemento);
    ej3_contador++;
}

ej3_boton.addEventListener("click", () => {
    if (ej3_lista.children.length >= 10) { // Si ya ha llegado al límite => eliminar hijo
        ej3_lista.removeChild(ej3_lista.firstElementChild)
    }
    // Si aún no, o ya hay hueco => crear 
    ej3_crearElemento()
});


/* ==========================================================================
 * EJERCICIO 4: Editor de tabla dinámica
 * ==========================================================================
 * Crea una página HTML con una tabla vacía y un formulario:
 *
 * <table id="tabla">
 * <thead>
 * <tr>
 * <th>Nombre</th>
 * <th>Apellido</th>
 * <th>Edad</th>
 * <th>Acciones</th>
 * </tr>
 * </thead>
 * <tbody id="cuerpo-tabla"></tbody>
 * </table>
 * <div id="formulario">
 * <input id="campo-nombre"   type="text"   placeholder="Nombre" />
 * <input id="campo-apellido" type="text"   placeholder="Apellido" />
 * <input id="campo-edad"     type="number" placeholder="Edad" />
 * <button id="btn-añadir-fila">Añadir fila</button>
 * </div>
 * <p id="contador">Total de filas: 0</p>
 *
 * Implementa la siguiente funcionalidad:
 * * a) Añadir fila. Al pulsar #btn-añadir-fila, se leen los valores de los 
 * tres campos con querySelector y se crea una nueva fila (<tr>) con cuatro 
 * celdas (<td>): una por cada campo y una cuarta con dos botones, 
 * «Editar» y «Eliminar». La nueva fila se añade al <tbody> con appendChild. 
 * Después de añadirla, los campos se limpian asignando "" a su value.
 * * b) Eliminar fila. El botón «Eliminar» de cada fila debe eliminar esa fila 
 * completa del DOM usando removeChild desde el <tbody>. Para ello, el 
 * manejador del evento necesita acceder al parentNode del botón para 
 * recorrer el árbol hasta llegar a la <tr>.
 * * c) Editar fila. El botón «Editar» convierte las tres celdas de datos en 
 * campos <input> editables (cambiando su textContent por un <input> 
 * creado con createElement y cuyo value sea el texto original). Al volver 
 * a pulsar el botón (que ahora dirá «Guardar»), los valores de los inputs 
 * se guardan de nuevo como texto en las celdas.
 * * d) Contador. El párrafo #contador debe actualizarse cada vez que se añade 
 * o elimina una fila, mostrando el número actual de filas en la tabla. 
 * Usa querySelectorAll sobre #cuerpo-tabla para contarlas.
 */

/*a) Añadir fila. Al pulsar #btn-añadir-fila, se leen los valores de los 
 * tres campos con querySelector y se crea una nueva fila (<tr>) con cuatro 
 * celdas (<td>): una por cada campo y una cuarta con dos botones, 
 * «Editar» y «Eliminar». La nueva fila se añade al <tbody> con appendChild. 
 * Después de añadirla, los campos se limpian asignando "" a su value.*/
let ej4_cnt = 0

ej4_btn_anyadir_fila = document.getElementById("btn-añadir-fila")

ej4_btn_anyadir_fila.addEventListener("click", () => {
    ej4_campo_nombre = document.querySelector("#campo-nombre")
    ej4_campo_apellido = document.querySelector("#campo-apellido")
    ej4_campo_edad = document.querySelector("#campo-edad")

    const ej4_tabla = document.querySelector("#tabla")
    const ej4_tbody = document.querySelector("#cuerpo-tabla")
    const ej4_contador = document.querySelector("#contador")
    ej4_tabla.style.border = "2px solid black"

    const fila = document.createElement("tr")
    
    const celda_1 = document.createElement("td")
    celda_1.textContent = ej4_campo_nombre.value // Le asignamos el texto del value de input

    const celda_2 = document.createElement("td")
    celda_2.textContent = ej4_campo_apellido.value

    const celda_3 = document.createElement("td")
    celda_3.textContent = ej4_campo_edad.value

    const celda_4 = document.createElement("td")

    const boton_editar_4 = document.createElement("button")
    boton_editar_4.type = "button"
    boton_editar_4.textContent = "Editar"
    
    const boton_eliminar_4 = document.createElement("button")
    boton_eliminar_4.type = "button"
    boton_eliminar_4.textContent = "Eliminar"

    celda_4.appendChild(boton_editar_4)
    celda_4.appendChild(boton_eliminar_4)

    fila.appendChild(celda_1)
    fila.appendChild(celda_2)
    fila.appendChild(celda_3)
    fila.appendChild(celda_4)

    ej4_tbody.appendChild(fila)
    ej4_tabla.appendChild(ej4_tbody)
    document.body.appendChild(ej4_tabla)

    ej4_updateCounter()

    ej4_campo_nombre.value = ""
    ej4_campo_apellido.value = ""
    ej4_campo_edad.value = ""
})

const ej4_tbody = document.querySelector("#cuerpo-tabla")
ej4_tbody.addEventListener("click", (e_button) => {
    /*
    * * b) Eliminar fila. El botón «Eliminar» de cada fila debe eliminar esa fila 
    * completa del DOM usando removeChild desde el <tbody>. Para ello, el 
    * manejador del evento necesita acceder al parentNode del botón para 
    * recorrer el árbol hasta llegar a la <tr>.*/

    if (e_button.target.matches("button") && e_button.target.textContent == "Eliminar") {
        const tr = e_button.target.closest("tr")
        const ej4_contador = document.querySelector("#contador")

        if (tr && tr.parentNode) {
            tr.parentNode.removeChild(tr)
            ej4_updateCounter()
        }
    }
    
    /*
    * * c) Editar fila. El botón «Editar» convierte las tres celdas de datos en 
    * campos <input> editables (cambiando su textContent por un <input> 
    * creado con createElement y cuyo value sea el texto original). Al volver 
    * a pulsar el botón (que ahora dirá «Guardar»), los valores de los inputs 
    * se guardan de nuevo como texto en las celdas.*/
    // Primer paso => sólo se ejecuta una vez por click
    if (e_button.target.matches("button") && e_button.target.textContent == "Editar") {
        // Obtenemos la fila más 
        const tr = e_button.target.closest("tr")
        
        // Nombre
        const tdNombre = tr.children[0] // Elgimos la primera celda
        const input_nombre = document.createElement("input") // Creamos un elemento input para el nombre
        input_nombre.type = "text"  // Tipo texto del input
        input_nombre.value = tdNombre.textContent   // Establecemos en el valor del input(texto escrito) el valor anterior de la celda  => listo para editar
        tdNombre.textContent = "" // Ya puesto en el value, lo borramos de la celda(solo de la celda)
        tdNombre.appendChild(input_nombre) // Lo añadimos a la celda(en vez del texto anterior)

        // Apellido
        const tdApellido = tr.children[1]
        const input_apellido = document.createElement("input")
        input_apellido.type = "text"
        input_apellido.value = tdApellido.textContent
        tdApellido.textContent = ""
        tdApellido.appendChild(input_apellido)

        // Edad
        const tdEdad = tr.children[2]
        const input_edad = document.createElement("input")
        input_edad.type = "number"
        input_edad.value = tdEdad.textContent
        tdEdad.textContent = ""
        tdEdad.appendChild(input_edad)

        // Nuevo boton
        e_button.target.textContent = "Guardar"

    }
    // Segundo paso => sólo se ejecuta una vez por click
    else  if (e_button.target.matches("button") && e_button.target.textContent == "Guardar") {
        const tr = e_button.target.closest("tr") 
        
        // Nombre
        const tdNombre = tr.children[0] // Elegimos la celda del nombre
        const input_nombre = tdNombre.querySelector("input") // Recuperamos el input de nombre
        if (input_nombre) {
            tdNombre.textContent = input_nombre.value // Sustiumos el value del input por un texto con el value => No input => solo texto en celda
        }

        // Apellido
        const tdApellido = tr.children[1]
        const input_apellido = tdApellido.querySelector("input")
        if (input_apellido) {
            tdApellido.textContent = input_apellido.value
        }

        // Edad
        const tdEdad = tr.children[2]
        const input_edad = tdEdad.querySelector("input")
        if (input_edad) {
            tdEdad.textContent = input_edad.value
        }

        // Renombramos el boton
        e_button.target.textContent = "Editar"
    }
})

/*
 * * d) Contador. El párrafo #contador debe actualizarse cada vez que se añade 
 * o elimina una fila, mostrando el número actual de filas en la tabla. 
 * Usa querySelectorAll sobre #cuerpo-tabla para contarlas.*/
function ej4_updateCounter() {
  const n = document.querySelectorAll('#cuerpo-tabla tr').length;
  document.querySelector('#contador').textContent = `Total de filas: ${n}`;
}