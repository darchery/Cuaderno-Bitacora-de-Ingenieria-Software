botonAnadir = document.querySelector("#boton-anadir");
botonBorrar = document.querySelector("#boton-borrar");
lista = document.querySelector("ul");

botonAnadir.addEventListener("click", () => {
  const textoElemento = document.querySelector("#elemento-compra");
  if (textoElemento.value.trim() !== "") {
    const nuevoElemento = document.createElement("li");
    nuevoElemento.textContent = textoElemento.value;
    lista.appendChild(nuevoElemento);
    textoElemento.value = "";
  }
});

botonBorrar.addEventListener("click", () => {
    while (lista.lastChild) {
        lista.removeChild(lista.lastChild);
    }
/*
    let c = lista.children.length;
    while (c > 0) {
        lista.removeChild(c[0]);
    }
*/
});
