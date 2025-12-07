import pandas as pd
import numpy as np

def titulo(string):
    print("# ------------------------------------------------------------------------------")
    print(string)
    print("# ------------------------------------------------------------------------------")

def space():
    print("\n")

# -------------------------------------------------
# EJERCICIO 1: CARGA DE DATOS Y EXPLORACIÓN INICIAL
# -------------------------------------------------
titulo("# EJERCICIO 1: CARGA DE DATOS Y EXPLORACIÓN INICIAL")
# 1. Cargar clientes.csv y pedidos.csv en DataFrames
titulo("# 1. Cargar clientes.csv y pedidos.csv en DataFrames")
df_clientes = pd.read_csv("data/clientes.csv")
df_pedidos = pd.read_csv("data/pedidos.csv")
print("CSV's convertidos a datafram: clientes y pedidos")
# 2. Mostrar las primeras 5 filas de cada DataFrame
titulo("# 2. Mostrar las primeras 5 filas de cada DataFrame")
print(df_clientes.head())
print(df_pedidos.head())
space()
# 3. Obtener información de tipos de datos y formas (shape)
titulo("# 3. Obtener información de tipos de datos y formas (shape)")
print(df_clientes.info())
print(df_pedidos.info())
space()
print(df_clientes.shape)
print(df_pedidos.shape)
# 4. Mostrar estadísticas descriptivas básicas
titulo("# 4. Mostrar estadísticas descriptivas básicas")
print(df_clientes.describe())
print(df_pedidos.describe())

# ------------------------------------
# EJERCICIO 2: CONSULTAS BÁSICAS
# ------------------------------------
titulo("# EJERCICIO 2: CONSULTAS BÁSICAS")
# 1. Clientes de Madrid mayores de 30 años
titulo("# 1. Clientes de Madrid mayores de 30 años")
ej2_1_clientes__madrid_mayores_30 = df_clientes[
    (df_clientes['edad'] > 30) & 
    (df_clientes['ciudad'] == 'Madrid')
]
print(ej2_1_clientes__madrid_mayores_30.to_string())
# 2. Clientes Premium o que tengan más de 3000 puntos de fidelidad
titulo("# 2. Clientes Premium o que tengan más de 3000 puntos de fidelidad")
ej2_2_clientes_premium_o_3000_puntos = df_clientes[
    (df_clientes['categoria'] == 'Premium') | 
    (df_clientes['puntos_fidelidad'] > 3000)
]
print(ej2_2_clientes_premium_o_3000_puntos)
# 3. Pedidos con total mayor a 500 euros
titulo("# 3. Pedidos con total mayor a 500 euros")
ej2_3_pedidos_total_mayor_500 = df_pedidos[
    df_pedidos['total'] > 500
]
print(ej2_3_pedidos_total_mayor_500)
# 4. Pedidos pendientes del año 2023
titulo("# 4. Pedidos pendientes del año 2023")
ej2_4_pedidos_pendients_2023_v1 = df_pedidos[
    (df_pedidos['estado'] == 'Pendiente') & 
    (df_pedidos['fecha_pedido'].str.startswith('2023'))
]
ej2_4_pedidos_pendients_2023_v2 = df_pedidos[
    (df_pedidos['estado'] == 'Pendiente') & 
    (df_pedidos['fecha_pedido'] >= '2023-01-01') & 
    (df_pedidos['fecha_pedido'] <= '2023-12-31')
]
print(ej2_4_pedidos_pendients_2023_v1)
print(ej2_4_pedidos_pendients_2023_v2)

# ------------------------------------
# EJERCICIO 3: OPERACIONES DE AGREGACIÓN
# ------------------------------------
titulo("# EJERCICIO 3: OPERACIONES DE AGREGACIÓN")
# 1. Calcula el número de clientes por ciudad
titulo("# 1. Calcula el número de clientes por ciudad")
ej3_1_agregacion_clientes_por_ciudad = (
    df_clientes
        .groupby('ciudad')['ciudad']
        .count()
)
print(ej3_1_agregacion_clientes_por_ciudad)
# 2. Obtén las ventas totales por estado de pedido
titulo("# 2. Obtén las ventas totales por estado de pedido")
ej3_2_agregacion_ventas_totales_por_estado_pedido = (
    df_pedidos
        .groupby('estado')['total'].sum()
)
print(ej3_2_agregacion_ventas_totales_por_estado_pedido)
# 3. Calcula el promedio de edad de clientes por categoría
titulo("# 3. Calcula el promedio de edad de clientes por categoría")
ej3_3_agregacion_media_edad_por_categoria = (
    df_clientes
        .groupby('categoria')['edad'].mean()
)
print(ej3_3_agregacion_media_edad_por_categoria)
# 4. Obtén el top 3 ciudades con más pedidos
titulo("# 4. Obtén el top 3 ciudades con más pedidos")
ej3_4_agregacion_top3_ciudades_mas_pedidos = (
    df_clientes
        .groupby('ciudad').size().sort_values(ascending=False).head(3)
        # Agrupo por ciudad => cuantos hay de cada uno => los ordeno descendentemente => cojo los 3 primeros
)
print(ej3_4_agregacion_top3_ciudades_mas_pedidos)

# ------------------------------------
# EJERCICIO 4: JOINS ENTRE TABLAS
# ------------------------------------
titulo("# EJERCICIO 4: JOINS ENTRE TABLAS")
# 1. Mostrar nombre del cliente junto con sus pedidos
titulo("# 1. Mostrar nombre del cliente junto con sus pedidos")
ej4_1_join_nombre_cliente_pedidos = pd.merge(
    df_clientes,
    df_pedidos,
    on='cliente_id',
    how='inner'
)
print(ej4_1_join_nombre_cliente_pedidos[['nombre', 'pedido_id', 'fecha_pedido']])
# 2. Mostrar todos los clientes con sus pedidos, deben aparecer también los que no tienen pedidos
titulo("# 2. Mostrar todos los clientes con sus pedidos, deben aparecer también los que no tienen pedidos")
ej4_2_join_clientes_pedidos_todos = pd.merge(
    df_clientes,
    df_pedidos,
    on='cliente_id',
    how='left'
)
print(ej4_2_join_clientes_pedidos_todos)
# 3. Muestra los pedidos que no tienen cliente asignado
titulo("# 3. Muestra los pedidos que no tienen cliente asignado")
ej4_3_join_pedidos_sin_clientes = pd.merge(
    df_pedidos,
    df_clientes,
    on='cliente_id',
    how='left',
    indicator=True # Crea una columa llamada _merge que nos inidica el resultado del merge
                    # both(coincidencia), left_only(left existe, right no)
)
print(ej4_3_join_pedidos_sin_clientes[
    ej4_3_join_pedidos_sin_clientes['_merge'] == 'left_only'
])
# 4. Muestra los clientes que nunca han hecho un pedido
titulo("# 4. Muestra los clientes que nunca han hecho un pedido")
ej4_4_join_cliente_sin_pedido =  pd.merge(
    df_clientes,
    df_pedidos,
    on='cliente_id',
    how='left',
    indicator=True
)
print(ej4_4_join_cliente_sin_pedido[
    ej4_4_join_cliente_sin_pedido['_merge'] == 'left_only'
])

# ------------------------------------
# EJERCICIO 5: LIMPIEZA DE DATOS
# ------------------------------------
titulo("# EJERCICIO 5: LIMPIEZA DE DATOS")
# 1. Identificar columnas con valores nulos en ambos DataFrames
titulo("# 1. Identificar columnas con valores nulos en ambos DataFrames")
ej5_1_col_nulos_clientes = df_clientes.isnull().sum()
print(ej5_1_col_nulos_clientes)
ej5_1_col_nulos_pedidos = df_pedidos.isnull().sum()
print(ej5_1_col_nulos_pedidos)
# 2. Rellenar las edades nulas con la media de edad de los clientes
titulo("# 2. Rellenar las edades nulas con la media de edad de los clientes")
df_clientes['edad'] = df_clientes['edad'].fillna(df_clientes['edad'].mean())
print("Valores nulos de edad:")
print(df_clientes['edad'].isnull().sum())
# 3. Rellenar puntos_fidelidad nulos con 0
titulo("# 3. Rellenar puntos_fidelidad nulos con 0")
df_clientes['puntos_fidelidad'] = df_clientes['puntos_fidelidad'].fillna(0)
print("Valores nulos de puntos de fidelidad:")
print(df_clientes['puntos_fidelidad'].isnull().sum())
# 4. Eliminar pedidos donde cantidad es nula
titulo("# 4. Eliminar pedidos donde cantidad es nula")
df_pedidos = df_pedidos.dropna(subset=['cantidad'])
print(print("Valores nulos de cantidad:"))
print(df_pedidos['cantidad'].isnull().sum())

# ------------------------------------
# EJERCICIO 6: CREACIÓN DE NUEVAS COLUMNAS
# ------------------------------------
titulo("# EJERCICIO 6: CREACIÓN DE NUEVAS COLUMNAS")
# 1. Añadir columna 'rango_edad' (Joven: <30, Adulto: 30-60, Senior: >60)
titulo("# 1. Añadir columna 'rango_edad' (Joven: <30, Adulto: 30-60, Senior: >60)")
df_clientes['rango_edad'] = np.where(
    df_clientes['edad'] < 30, 'Joven',
    np.where(
        ((df_clientes['edad'] >= 30) & (df_clientes['edad'] <= 60) ), 'Adulto',
        'Senior'
    )
)
print(df_clientes[['edad','rango_edad']])

# 2. Crear columna 'año_mes_pedido' en formato YYYY-MM a partir de fecha_pedido
titulo("# 2. Crear columna 'año_mes_pedido' en formato YYYY-MM a partir de fecha_pedido")
df_pedidos['año_mes_pedido'] = df_pedidos['fecha_pedido'].str[0:7]
# 2023-01-01
print(df_pedidos[['fecha_pedido','año_mes_pedido']])
# 3. Añadir columna 'tipo_producto' basada en el nombre del producto:
#       - Dispositivo: laptop, smartphone, tablet, smartwatch
#       - Periféricos: monitor, teclado, ratón, web
#       - Audio: auriculares, altavoz
#       - Otros: resto de productos
titulo("# 3. Añadir columna 'tipo_producto' basada en el nombre del producto:\n - Dispositivo: laptop, smartphone, tablet, smartwatch\n- Periféricos: monitor, teclado, ratón, web\n- Audio: auriculares, altavoz\n- Otros: resto de productos")
def clasificar_producto(producto):
    producto = str.lower(producto)
    
    # Para cualquier x en producto para x en la lista de cadenas(x es un elemento de la lista)
    if any(x in producto for x in ['laptop', 'smartphone', 'tablet', 'smartwatch']):
        return "Dispositivo"
    elif any(x in producto for x in ['monitor', 'teclado', 'raton', 'web']):
        return "Periféricos"
    elif any(x in producto for x in ['auriculares', 'altavoz']):
        return "Audio"
    else:
        return "Otros"

df_pedidos['tipo_producto'] = df_pedidos['producto'].apply(clasificar_producto)
print(df_pedidos['tipo_producto'])
# 4. Crear columna 'cliente_activo' (sí/no según si tiene pedidos)
titulo("# 4. Crear columna 'cliente_activo' (sí/no según si tiene pedidos)")
df_clientes['cliente_activo'] = np.where(
    df_clientes['cliente_id'].isin(df_pedidos['cliente_id']), 'sí',
    'no'
)
print(df_clientes['cliente_activo'])

# ------------------------------------
# EJERCICIO 7: CONSULTAS COMPLEJAS
# ------------------------------------
titulo("# EJERCICIO 7: CONSULTAS COMPLEJAS")
# 1. Clientes de Barcelona que han hecho pedidos > 1000€
titulo("# 1. Clientes de Barcelona que han hecho pedidos > 1000€")
ej7_1_aux = pd.merge(
        df_clientes,
        df_pedidos,
        on='cliente_id',
        how='left'
    )
print(
    ej7_1_aux[
        (ej7_1_aux['total'] > 1000) &
        (ej7_1_aux['ciudad'] == 'Barcelona')
    ][['nombre','ciudad', 'total']]
)
# 2. Productos más vendidos por ciudad
titulo("# 2. Productos más vendidos por ciudad")
ej7_2_aux = pd.merge(
        df_pedidos,
        df_clientes,
        on='cliente_id',
        how='left'
    )
# Grupos comibados de ciduad y producto => suma sus cantidades
ej7_2 = ej7_2_aux.groupby(['ciudad', 'producto'])['cantidad'].sum().reset_index()
# Los ordena por ciudad y cantidad descendentemente(para obtener los más altos primero)
ej7_2 = ej7_2.sort_values(['ciudad', 'cantidad'], ascending=False)
# Borra los duplicados(eliminamos todas las existencias, menos la primera -> más grande)
print(ej7_2.drop_duplicates(subset=['ciudad']))
# 3. Clientes Premium con mayor gasto total
titulo("# 3. Clientes Premium con mayor gasto total")
ej7_3_aux = pd.merge(
        df_clientes,
        df_pedidos,
        on='cliente_id',
        how='left'
    )
ej7_3 = ej7_3_aux[ej7_3_aux['categoria'] == 'Premium']
# Sumo todos los totales por nombre
ej7_3 = ej7_3.groupby('nombre')['total'].sum().sort_values(ascending=False)
print(ej7_3)
# 4. Evolución mensual de ventas en 2023
titulo("# 4. Evolución mensual de ventas en 2023")
ej7_4 = df_pedidos[df_pedidos['año_mes_pedido'].str[0:4] == '2023']
ej7_4 = (
    df_pedidos
        .groupby('año_mes_pedido')['total'].sum()
)
print(ej7_4)
# 5. Media del total de ventas y número de pedidos por cliente
titulo("# 5. Media del total de ventas y número de pedidos por cliente")
ej7_5_aux = pd.merge(
        df_clientes,
        df_pedidos,
        on='cliente_id',
        how='left'
    )
ej7_5 = ej7_5_aux.groupby(['cliente_id', 'nombre']).agg(
    gasto_medio=('total', 'mean'),
    num_pedidos=('pedido_id', 'sum')
)
print(ej7_5)

# 6. Dos productos con mejor desempeño por categoría de cliente (mejor desempeño = mayor suma t
titulo("# 6. Dos productos con mejor desempeño por categoría de cliente (mejor desempeño = mayor suma t")
ej7_6_aux = pd.merge(
        df_clientes,
        df_pedidos,
        on='cliente_id',
        how='left'
    )
# Agrupamos por categoría y producto, de los atributos cogemos el total y la cantidad y se acumulan
# (para la misma categoría y producto se acumulan el total y la cantidad) y se resetean los índices
ej7_6 = ej7_6_aux.groupby(['categoria', 'producto'])[['total', 'cantidad']].sum().reset_index()
# Se ordenan los parámetros
ej7_6 = ej7_6.sort_values(['categoria', 'total', 'cantidad'], ascending=[True, False, False])
# Se agrupa nuevamente por categoría y se escoge de cada categoría los 2 productos con mayor desempeño
print(ej7_6.groupby('categoria').head(2))
