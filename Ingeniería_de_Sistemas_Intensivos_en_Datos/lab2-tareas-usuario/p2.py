# Importamos la libreria redis
import redis

# Establecemos conexion con el puerto en el que el docker de redis se está ejecutando
r = redis.Redis(host='localhost', port=6379, db=2, decode_responses=True)
r.flushdb()

# Crea un usuario con sus datos e identificación
def crear_usuario(id, nombre, edad, email):
    clave = f"usuario:{id}"                                             # String con su clave
    r.hset(clave,                                                       # Añadimos a este usuario con hset
           mapping={"nombre":nombre, "edad": edad, "email": email})

def mostrar_usuario(id):
    """Obtener los datos de un usuario por su ID"""
    print("Informacion del usuario:")
    clave = f"usuario:{id}"
    print(r.hgetall(clave))

# Agrega tarea a la lista
def agregar_tarea(usuario_id, tarea):
    clave = f"tarea:{usuario_id}"       # Clave de la tarea con su identificación
    r.lpush(clave, tarea)               # Añadimos al principio de la lista 

# Eliminar un elemento de la lista
def eliminar_tarea_completada(usuario_id, tarea): 
    clave = f"tarea:{usuario_id}"
    r.lrem(clave, 1, tarea)

# Mostrar lista
def mostrar_tareas_pendientes(usuario_id):
    clave = f"tarea:{usuario_id}"
    tareas = r.lrange(clave, 0, -1)                     # Guardamos el recorrido de esta en un string
    print(f"Tareas de usuario {usuario_id}:")

    if not tareas:
        print("No hay tareas pendientes.")

    else: 
        for i, tarea in enumerate(tareas, start=1):
            print(f"{i}.{tarea}")

# Metodos auxiliares
def space():
    print("\n")


if __name__ == "__main__":

    crear_usuario(1, "Juan Perez", 30, "juan@email.coms")       # Creamos un usuario
    usuario = r.hgetall("usuario:1")                            # Obtenemos todos sus campos
    # Lo he simplificado con "mostrar_usuario" -> deprecado
    print(usuario)                                              # Imprimimos el resultado del hgetall
    print(r.hget("usuario:1", "nombre"))                        # Obtenemos todos los valores individualmente
    print(r.hget("usuario:1", "edad"))
    print(r.hget("usuario:1", "email"))

    space()

    agregar_tarea(1, "Estudiar Redis")                          # Agregamos 2 tareas
    agregar_tarea(1, "Salir de fiesta")
    mostrar_tareas_pendientes(1)
    
    space()

    eliminar_tarea_completada(1, "Salir de fiesta")
    mostrar_tareas_pendientes(1)

    space()

    eliminar_tarea_completada(1, "Estudiar Redis")
    mostrar_tareas_pendientes(1)

    space()

    mostrar_usuario(1)


