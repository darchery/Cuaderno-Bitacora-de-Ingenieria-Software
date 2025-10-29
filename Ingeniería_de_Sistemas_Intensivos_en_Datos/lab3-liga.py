import redis
import json
import time

r = redis.Redis(host='localhost', port=6379, db=3, decode_responses=True)
r.flushdb()

# Ej1
def registrar_equipo(liga, id, nombre, ciudad, entrenador, anyo_fundacion):
    clave = f"equipos:{liga}:{id}"                                             
    r.hset(clave,                                                     
           mapping={"nombre":nombre, "ciudad":ciudad, "entrenador":entrenador, "anyofundacion":anyo_fundacion})

# Ej2
def registrar_equipo_clasificacion(liga, equipo, puntuacion):
    clave = f"clasificacion:{liga}"
    r.zadd(clave, {equipo: puntuacion})
    
def mostrar_clasificacion_equipos(liga):
    print("Clasificación de la liga por puntos:")
    clave = f"clasificacion:{liga}"
    # descendente
    clasificacion = r.zrevrange(clave, 0, -1, withscores=True)
    
    for index, (equipo, puntuacion) in enumerate(clasificacion, start=1):
        print(f"{index}. {equipo}: {int(puntuacion)} puntos")
    print()

# Ej3
def registrar_jugador(liga, id, nombre, edad, posicion, equipo):
    clave = f"jugadores:{liga}:{id}"                                             
    r.hset(clave,                                                     
           mapping={"nombre":nombre, "edad":edad, "posicion":posicion, "equipo":equipo})

# Ej4
def registrar_jugador_ranking_goleadores(liga, nombre, goles):
    clave = f"ranking:goleadores:{liga}"
    goles = int(goles)
    r.zadd(clave, {nombre: goles})

def mostrar_ranking_goleadores(liga):
    print("Ranking de goleadores:")
    clave = f"ranking:goleadores:{liga}"
    # descendente
    goleadores = r.zrevrangebyscore(clave, "+inf", "-inf", withscores=True)

    for index, (nombre, goles) in enumerate(goleadores, start=1):
        print(f"{index}. {nombre}: {int(goles)} goles")
    print()

# Ej5
def registrar_partido_historial(liga, local, goles_local, visitante, goles_visitante, orden):
    clave = f"partidos:historial:{liga}"
    datos_partido = {
        "local": local,
        "goles_local": goles_local,
        "visitante": visitante,
        "goles_visitante": goles_visitante
    }
    datos_json = json.dumps(datos_partido)

    r.zadd(clave, {datos_json: orden})

def mostrar_historial_partidos(liga):
    print("Historial de partidos:")
    clave = f"partidos:historial:{liga}"
    # ascendente
    partidos = r.zrangebyscore(clave , "-inf", "+inf",withscores=True)

    for partido_json, orden in partidos:
        partido = json.loads(partido_json)
        print(f"{int(orden)}. {partido['local']} {partido['goles_local']} - {partido['goles_visitante']} {partido['visitante']}")
    print()

# Ej6
def actualizar_clasificacion_equipo(liga, equipo, victorias, empates):
    clave = f"clasificacion:{liga}"
    puntos_victorias = int(victorias) * 3
    puntos_empates = int(empates)
    
    if victorias != "0":
        r.zadd(clave, {equipo: puntos_victorias}, incr=True)
    if empates != "0":
        r.zadd(clave, {equipo: puntos_empates}, incr=True)

# Ej7
def actualizar_ranking_goles(liga, nombre, goles):
    clave = f"ranking:goleadores:{liga}"
    goles = int(goles)
    r.zadd(clave, {nombre: goles}, incr=True)

# Ej8
def programar_partido_calendario(liga, local, visitante, fecha,orden):
    clave = f"calendario:{liga}"
    datos_partido = {
        "local": local,
        "visitante": visitante,
        "fecha": fecha
    }

    datos_partido_json = json.dumps(datos_partido)
    r.zadd(clave, {datos_partido_json: orden})

def mostrar_calendario(liga):
    clave = f"calendario:{liga}"
    # ascendente
    calendario = r.zrangebyscore(clave, "-inf", "+inf", withscores=True)

    print("Calendario de próximos partidos:")
    for calendario_json, orden in calendario:
        partido_calendario = json.loads(calendario_json)
        print(f"{int(orden)}. {partido_calendario['local']} Vs {partido_calendario['visitante']}({partido_calendario['fecha']})")
    print()

# Ej9
def registrar_trapaso_jugador_equipo(liga, id, equipoAntiguo, equipoActual, orden):
    clave = f"jugadores:{liga}:{id}"
    r.hset(clave,                                                     
           mapping={"equipo":equipoActual})
    
    clave_historial_traspasos = f"historial:traspasos:{liga}"
    datos_traspaso = {
        "nombre": nombre,
        "equipoAntiguo": equipoAntiguo,
        "equipoActual": equipoActual
    }
    datos_traspaso_json = json.dumps(datos_traspaso)

    r.zadd(clave_historial_traspasos, {datos_traspaso_json: orden})

def mostrar_historial_traspasos(liga):
    clave = f"historial:traspasos:{liga}"
    # ascendente
    historial_traspasos = r.zrangebyscore(clave, "-inf", "+inf", withscores=True)

    print("Historial de traspasos:")
    for historial_traspasos_json, orden in historial_traspasos:
        historial_traspasos = json.loads(historial_traspasos_json)
        print(f"{int(orden)}. {historial_traspasos['nombre']} se transfiere de {historial_traspasos['equipoAntiguo']} a {historial_traspasos['equipoActual']}")
    print()
    

if __name__ == "__main__":

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 1: Registrar equipos fundacionales 
    #   Crea tres equipos con sus datos completos:
    #   Equipo 1: "Leones FC", ciudad: "Madrid", entrenador: "Carlos Ruiz", fundación: 1920
    #   Equipo 2: "Águilas Deportivas", ciudad: "Barcelona", entrenador: "Ana Martínez", fundación: 1935
    #   Equipo 3: "Tiburones FC", ciudad: "Valencia", entrenador: "David González", fundación: 1948
    #---------------------------------------------------------------------------------------------------------------
    registrar_equipo("1" ,"1", "Leones FC", "Madrid", "Carlos Ruiz", "1920")
    registrar_equipo("1", "2", "Águilas Deportivas", "Barcelona", "Ana Martínez", "1935")
    registrar_equipo("1", "3", "Tiburones FC", "Valencia", "David González", "1948")   
    
    equipo1 = r.hgetall("equipos:1:1")
    equipo2 = r.hgetall("equipos:1:2")
    equipo3 = r.hgetall("equipos:1:3")
    print("Equipos registrados:")
    print(f"{equipo1}\n{equipo2}\n{equipo3}\n") 

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 2: Establecer clasificación inicial 
    #   Inicializa la clasificación de la liga con todos los equipos a 0 puntos. El sistema debe 
    #   permitir ordenar automáticamente por puntuación.
    #---------------------------------------------------------------------------------------------------------------
    registrar_equipo_clasificacion("1", "Leones FC", "0")
    registrar_equipo_clasificacion("1", "Águilas Deportivas", "0")
    registrar_equipo_clasificacion("1", "Tiburones FC", "0")
    
    mostrar_clasificacion_equipos("1")

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 3: Registrar jugadores clave Añade 4 jugadores distribuidos entre los equipos:
    #   Jugador 1: "Luis Torres", 25 años, delantero, equipo: Leones FC
    #   Jugador 2: "María Rodríguez", 28 años, centrocampista, equipo: Águilas Deportivas
    #   Jugador 3: "Javier López", 22 años, defensa, equipo: Tiburones FC
    #   Jugador 4: "Sofía García", 26 años, delantero, equipo: Leones FC
    #---------------------------------------------------------------------------------------------------------------
    registrar_jugador("1" ,"1", "Luis Torres", "25", "delantero", "Leones FC")
    registrar_jugador("1", "2", "María Rodríguez", "28", "centrocampista", "Águilas Deportivas")
    registrar_jugador("1", "3", "Javier López", "22", "defensa", "Tiburones FC")
    registrar_jugador("1","4", "Sofía García", "26", "delantero", "Leones FC")
    
    jugador1 = r.hgetall("jugadores:1:1")
    jugador2 = r.hgetall("jugadores:1:2")
    jugador3 = r.hgetall("jugadores:1:3")
    jugador4 = r.hgetall("jugadores:1:4")
    print("Jugadores registrados:")
    print(f"{jugador1}\n{jugador2}\n{jugador3}\n{jugador4}\n") 

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 4:Crear ranking de goleadores Inicializa la clasificación de máximos goleadores. 
    #    Todos los jugadores empiezan con 0 goles, pero el sistema debe ordenarlos automáticamente según marquen goles.
    #---------------------------------------------------------------------------------------------------------------
    registrar_jugador_ranking_goleadores("1", "Luis Torres", "0")
    registrar_jugador_ranking_goleadores("1", "María Rodríguez", "0")
    registrar_jugador_ranking_goleadores("1", "Javier López", "0")
    registrar_jugador_ranking_goleadores("1", "Sofía García", "0")
    
    mostrar_ranking_goleadores("1")

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 5: Registrar primeros partidos
    #   Juegan los primeros partidos de la temporada en este orden
    #       Partido 1: Leones FC 2 - 1 Águilas Deportivas
    #       Partido 2: Tiburones FC 0 - 0 Leones FC
    #       Partido 3: Águilas Deportivas 3 - 2 Tiburones FC
    #   Registra estos partidos manteniendo el orden cronológico
    #---------------------------------------------------------------------------------------------------------------
    registrar_partido_historial("1", "Leones FC", "2", "Águilas Deportivas", "1", "1")
    registrar_partido_historial("1", "Tiburones FC", "0", "Leones FC", "0", "2")
    registrar_partido_historial("1", "Águilas Deportivas", "3", "Tiburones FC", "2", "3")
    
    mostrar_historial_partidos("1")

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 6: Actualizar clasificación
    #    Después de los partidos, actualiza las puntuaciones:
    #       Victoria: 3 puntos, Empate: 1 punto
    #       Leones FC: 1 victoria + 1 empate = 4 puntos
    #       Águilas Deportivas: 1 victoria + 1 derrota = 3 puntos
    #       Tiburones FC: 1 empate + 1 derrota = 1 punto
    #---------------------------------------------------------------------------------------------------------------
    actualizar_clasificacion_equipo("1", "Leones FC", "1", "1")
    actualizar_clasificacion_equipo("1", "Águilas Deportivas", "1", "0")
    actualizar_clasificacion_equipo("1", "Tiburones FC", "0", "1")
    
    mostrar_clasificacion_equipos("1")

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 7: Registrar goles de jugadores
    #   En los partidos jugados:
    #       Luis Torres marcó 2 goles en el Partido 1
    #       María Rodríguez marcó 1 gol en el Partido 1 y 2 goles en el Partido 3
    #       Sofía García marcó 1 gol en el Partido 3
    #   Actualiza el ranking de goleadores.
    #---------------------------------------------------------------------------------------------------------------
    actualizar_ranking_goles("1", "Luis Torres", "2")
    actualizar_ranking_goles("1", "María Rodríguez", "3")
    actualizar_ranking_goles("1", "Sofía García", "1")

    mostrar_ranking_goleadores("1")

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 8: Programar próximos partidos
    #   Añade al calendario los próximos partidos:
    #       Leones FC vs Tiburones FC (próxima semana)
    #       Águilas Deportivas vs Leones FC (dentro de dos semanas)
    #   Mantén el orden temporal correcto.
    #---------------------------------------------------------------------------------------------------------------
    programar_partido_calendario("1", "Leones FC", "Tiburones FC", "próxima semana", "1")
    programar_partido_calendario("1", "Águilas Deportivas", "Leones FC", "dentro de dos semanas", "2")

    mostrar_calendario("1")
    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 9: Consultas de clasificación
    #   Muestra la clasificación actual de la liga ordenada por puntos
    #   Lista los tres máximos goleadores con sus estadísticas
    #   Muestra el historial completo de partidos en orden cronológico
    #---------------------------------------------------------------------------------------------------------------
    mostrar_clasificacion_equipos("1")

    print("Tres máximos goleadores:")
    clave =  f"ranking:goleadores:1"
    goleadores = r.zrevrange(clave, "0", "2", withscores=True)
    for index, (nombre, goles) in enumerate(goleadores, start=1):
        print(f"{index}. {nombre}: {int(goles)} goles")
    print()

    mostrar_historial_partidos("1")

    #---------------------------------------------------------------------------------------------------------------
    # Ejercicio 10: Traspaso de jugador
    #   Sofía García se transfiere de Leones FC a Águilas Deportivas:
    #       Registra este movimiento en el historial de traspasos
    #       Actualiza la información del equipo de la jugadora
    #       Verifica que el cambio se refleja correctamente
    #---------------------------------------------------------------------------------------------------------------
    
    print(f"Equipo de Sofía antes del traspaso: {r.hget("jugadores:1:4", "equipo")}")
    registrar_trapaso_jugador_equipo("1", "4", "Leones FC", "Águilas Deportivas", "1")
    mostrar_historial_traspasos("1")
    print(f"Equipo de Sofía después del traspaso: {r.hget("jugadores:1:4", "equipo")}")
