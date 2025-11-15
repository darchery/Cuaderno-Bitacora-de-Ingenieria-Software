import redis

# Metodos auxiliares
def space():
    print("\n")

class ListaTares:
    def __init__(self):
        """Conectar a la base de datos Redis"""
        try:
            self.r = redis.Redis(host='localhost', port=6379, db=2, decode_responses=True)
            self.r.flushdb()
        except redis.ConnectionError:
            print("Error: No se pudo conectar a la base de datos Redis")
            self.r = None

    def crear_usuario(self, id, nombre, edad, email):
        clave = f"usuario:{id}"
        self.r.hset(clave, 
            mapping={"nombre":nombre, "edad": edad, "email": email})

    def mostrar_usuario(self, id):
        """Obtener los datos de un usuario por su ID"""
        if self.r:
            print("Informacion del usuario:")
            clave = f"usuario:{id}"
            return self.r.hgetall(clave)
        else:
            print("No se pudo obtener los datos del usuario")
            return None

    def agregar_tarea(self, usuario_id, tarea):
        if self.r:
            clave = f"tarea:{usuario_id}"
            return self.r.lpush(clave, tarea)
        else:    
            print("No se pudo agregar la tarea")

    # Eliminar un elemento de la lista
    def eliminar_tarea_completada(self, usuario_id, tarea): 
        if self.r:
            clave = f"tarea:{usuario_id}"
            return self.r.lrem(clave, 1, tarea)
        else:
            print("No se pudo eliminar la tareas")

    # Mostrar lista
    def mostrar_tareas_pendientes(self, usuario_id):
        if self.r:

            clave = f"tarea:{usuario_id}"
            tareas = self.r.lrange(clave, 0, -1)             # Guardamos el recorrido de esta en un string
            print(f"Tareas de usuario {usuario_id}:")

            if not tareas:
               print("No hay tareas pendientes.")
            else: 
                for i, tarea in enumerate(tareas, start=1):
                    print(f"{i}.{tarea}")
        else:
            print("No se pudieron mostrar las tareas pendientes")
    
if __name__ == "__main__":
    lista_tareas = ListaTares()
    lista_tareas.crear_usuario(1, "Juan Perez", 30, "juan@gmail.com")
    print(lista_tareas.mostrar_usuario(1))

    space()

    lista_tareas.agregar_tarea(1, "Estudiar Redis")
    lista_tareas.agregar_tarea(1, "Salir de fiesta")
    lista_tareas.mostrar_tareas_pendientes(1)

    space()

    lista_tareas.eliminar_tarea_completada(1, "Salir de fiesta")
    lista_tareas.mostrar_tareas_pendientes(1)

    space()

    lista_tareas.eliminar_tarea_completada(1, "Estudiar Redis")
    lista_tareas.mostrar_tareas_pendientes(1)

    space()

    print(lista_tareas.mostrar_usuario(1))