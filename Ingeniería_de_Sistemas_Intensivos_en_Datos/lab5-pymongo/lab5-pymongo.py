import pymongo

def space():
    print("\n")

def reset_bases_datos(db):
    db.cursos.drop()
    db.calificaciones.drop()
    db.estudiantes.drop()

def crear_conexion():
    # Conexión al servidor Mongo
    client = pymongo.MongoClient("mongodb://admin:admin@localhost:27017/")
    db = client["lab5"]
    reset_bases_datos(db)

    return client, db

def insertar_cursos(db, cursos):
    db.cursos.insert_many(cursos)

def insertar_calificaciones(db, calificaciones):
    db.calificaciones.insert_many(calificaciones)

def insertar_estudiantes(db, estudiantes):
    db.estudiantes.insert_many(estudiantes)

def ejercicio1_todos_los_estudiantes(db):
    estudiantes = db.estudiantes.find()
    print(f"Tipo de dato devuelto por find(): {type(estudiantes)}")

    for estudiante in estudiantes:
        print(estudiante['nombre'])
        print(estudiante)

def ejercicio2_estudiantes_madrid(db):
    estudiantes = db.estudiantes.find({"ciudad": "Madrid"})
    
    print("Estudiantes de Madrid:")
    for estudiante in estudiantes:
        print(estudiante['nombre'])
        print(estudiante)

def ejercicio3_cursos_duracion_mayor50_horas(db):
    cursos = db.cursos.find({"duracion_horas": {"$gt": 50}})
    
    print("Cursos con duración mayor a 50 horas:")
    for curso in cursos:
        print(curso)

def ejercicio4_actualizar_edad_laura(db):
    print("Edad de laura antes del cambio:")
    estudiantes_antes = db.estudiantes.find({"nombre": "Laura Martínez"}, {"edad": 1, "_id": 0})
    for laura in estudiantes_antes:
        print(laura)
    
    db.estudiantes.update_one({"nombre": "Laura Martínez"}, {"$set": {"edad": 23}})

    estudiantes_antes = db.estudiantes.find({"nombre": "Laura Martínez"}, {"edad": 1, "_id": 0})
    print("Edad de laura despues del cambio:")
    for laura in estudiantes_antes:
        print(laura)

# Todos los estudiantes => activo:true => updateMany => $set
def ejercicio5_anyadir_campo_activo(db):
    resultado = db.estudiantes.update_many(
        {},
        {"$set": {"activo": True}}
    )
    print(f"Documentos modificados: {resultado.modified_count}")

def ejercicio6_anyadir_eliminar_temporal(db):
    db.estudiantes.insert_one({
        "_id": 777,
        "nombre": "Temporal",
        "edad": 20,
        "email": "email@com",
        "ciudad": "Test"
        })
    print("Insertado:")
    temporal = db.estudiantes.find({"nombre": "Temporal"})
    for temp in temporal:
        print(temp)

    db.estudiantes.delete_one({
        "_id": 777,
        "nombre": "Temporal",
        "edad": 20,
        "email": "email@com",
        "ciudad": "Test"
        })
    print("Borrado: No sale nada")
    temporal = db.estudiantes.find({"nombre": "Temporal"})
    for temp in temporal:
        print(temp)

#def ejercicio7_look_up(db):

if __name__ == "__main__":
    try:
        client, db = crear_conexion()

        #-------------------------------------------------------------------------------------------------------------------------------------
        # INSERTAR DATOS DE LOS JSON'S
        #-------------------------------------------------------------------------------------------------------------------------------------
        cursos = [{
            "_id": 1,
            "nombre": "Python Básico",
            "profesor": "Ana García",
            "duracion_horas": 40,
            "nivel": "Principiante"
            },
            {
            "_id": 2, 
            "nombre": "Web Development",
            "profesor": "Carlos López",
            "duracion_horas": 60,
            "nivel": "Intermedio"
            },
            {
            "_id": 3,
            "nombre": "Data Science",
            "profesor": "María Rodríguez", 
            "duracion_horas": 80,
            "nivel": "Avanzado"
            }
        ]
        insertar_cursos(db ,cursos)

        calificaciones = [
            {"estudiante_id": 1, "curso_id": 1, "calificacion": 8.5},
            {"estudiante_id": 2, "curso_id": 2, "calificacion": 9.0},
            {"estudiante_id": 3, "curso_id": 1, "calificacion": 7.5},
            {"estudiante_id": 4, "curso_id": 3, "calificacion": 8.0}
        ]
        insertar_calificaciones(db, calificaciones)

        estudiantes = [
            {
            "_id": 1,
            "nombre": "Laura Martínez",
            "edad": 22,
            "email": "laura@email.com",
            "ciudad": "Madrid",
            "curso_id": 1
            },
            {
            "_id": 2,
            "nombre": "David Chen",
            "edad": 25, 
            "email": "david@email.com",
            "ciudad": "Barcelona",
            "curso_id": 2
            },
            {
            "_id": 3,
            "nombre": "Sofía Pérez",
            "edad": 20,
            "email": "sofia@email.com", 
            "ciudad": "Madrid",
            "curso_id": 1
            },
            {
            "_id": 4,
            "nombre": "Javier Ruiz",
            "edad": 28,
            "email": "javier@email.com",
            "ciudad": "Valencia", 
            "curso_id": 3
            }
        ]
        insertar_estudiantes(db, estudiantes)


        ejercicio1_todos_los_estudiantes(db)
        space()
        ejercicio2_estudiantes_madrid(db)
        space()
        ejercicio3_cursos_duracion_mayor50_horas(db)
        space()
        ejercicio4_actualizar_edad_laura(db)
        space()
        ejercicio5_anyadir_campo_activo(db)
        space()
        ejercicio6_anyadir_eliminar_temporal(db)
    except Exception as e:
        print(f"Error: {e}")
    finally:
        client.close