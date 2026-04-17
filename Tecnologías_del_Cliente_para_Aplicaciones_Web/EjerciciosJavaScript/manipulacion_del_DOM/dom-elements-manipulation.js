const enlaceBuscador = document.querySelector("#enlace-buscador");
const botonCambiarBuscador = document.querySelector("#boton-cambiar-buscador");
botonCambiarBuscador.addEventListener("click", () => {
    if (enlaceBuscador.textContent.includes("Google")) {
        // Cambiar el texto del enlace
        enlaceBuscador.textContent = "Buscador: DuckDuckGo";
        // Cambiar el atributo href del enlace
        enlaceBuscador.setAttribute("href", "https://duckduckgo.com");
    } else {
        // Cambiar el texto del enlace
        enlaceBuscador.textContent = "Buscador: Google";
        // Cambiar el atributo href del enlace
        enlaceBuscador.setAttribute("href", "https://google.com");
    }
});

// --------------------------------------------------------------

// seleccion por id
botonAnyadir = document.querySelector("#anyadir");
botonBorrar = document.querySelector("#borrar");

let cont = 1;

function random(number) {
  return Math.floor(Math.random() * (number + 1));
}

botonAnyadir.addEventListener("click", () => {
  // para añadir un nuevo trozo de texto
  // creamos un párrafo y dentro del párrafo
  // un nodo de texto. Un nodo de texto no es
  // un elemento HTML y no se puede recuperar
  // con selectores CSS.
  // Se puede recuperar con JavaScript (ver
  // código al final de este archivo)
  nuevoParrafo = document.createElement("p");
  nuevoNodoTexto = document.createTextNode("nuevo párrafo " + cont + "; ");
  nuevoParrafo.appendChild(nuevoNodoTexto);
  cont++;
  contenedor = document.querySelector(".contenedor");
  contenedor.appendChild(nuevoParrafo);
});

botonBorrar.addEventListener("click", () => {
  // USANDO VARIABLES EN SELECTORES CSS
  const containerClass = "contenedor";
  const selector = "p:first-child";

  // CON TEMPLATE LITERALS
  contenedor = document.querySelector(`.${containerClass}`);
  //  parrafoAEliminar = document.querySelector(`${selector}`);
  // El selector "p.first-child" no funciona porque en el contenedor
  // hay un elemento previo, el <br>, por lo que ningún <p> es el
  // primer hijo, por eso uso el selector ":first-of-type"
  parrafoAEliminar = contenedor.querySelector("p:first-of-type");

  console.log(parrafoAEliminar);

  // Verificar que existe el párrafo antes de eliminarlo
  if (parrafoAEliminar) {
    contenedor.removeChild(parrafoAEliminar);
  }
});

/*
// Función para obtener el último nodo de texto de un párrafo
function getLastTextNode(paragraph) {
    const walker = document.createTreeWalker(
        paragraph,
        NodeFilter.SHOW_TEXT,
        null,
        false
    );
    
    let lastTextNode = null;
    let node;
    
    while (node = walker.nextNode()) {
        if (node.textContent.trim() !== '') {
            lastTextNode = node;
        }
    }
    
    return lastTextNode;
}

// Uso:
const paragraph = document.querySelector('p');
const lastTextNode = getLastTextNode(paragraph);
console.log(lastTextNode.textContent);
*/

/*
// Obtener todos los nodos de texto de un párrafo
function getTextNodes(element) {
    const textNodes = [];
    const walker = document.createTreeWalker(
        element,
        NodeFilter.SHOW_TEXT,
        node => node.textContent.trim() !== '' ? NodeFilter.FILTER_ACCEPT : NodeFilter.FILTER_REJECT
    );
    
    let node;
    while (node = walker.nextNode()) {
        textNodes.push(node);
    }
    
    return textNodes;
}

// Obtener el último nodo de texto
const paragraph = document.querySelector('p');
const textNodes = getTextNodes(paragraph);
const lastTextNode = textNodes[textNodes.length - 1];
*/

// --------------------------------------------------------------

const parrafoAModificar = document.querySelector("#parrafo-a-modificar-directamente");
const botonModificarParrafo = document.querySelector("#boton-cambiar-estilo");
botonModificarParrafo.addEventListener("click", () => {
    // Modificar el texto del párrafo directamente
    parrafoAModificar.style.color = "white";
    parrafoAModificar.style.backgroundColor = "black";
    parrafoAModificar.style.padding = "10px";
    parrafoAModificar.style.width = "250px";
    parrafoAModificar.style.textAlign = "center";
});


// --------------------------------------------------------------

const parrafoAModificarClases = document.querySelector("#parrafo-a-modificar-con-clases");
const botonModificarParrafoClases = document.querySelector("#boton-cambiar-estilo-con-clases");
botonModificarParrafoClases.addEventListener("click", () => {
    // Modificar el texto del párrafo directamente
    parrafoAModificarClases.classList.add("estilo-modificado");
});
