import pandas as pd
import numpy as np

def titulo(string):
    print("# ------------------------------------------------------------------------------")
    print(string)
    print("# ------------------------------------------------------------------------------")

def space():
    print("\n")

titulo("Ejercicio 1. Crea un DataFrame a partir del siguiente diccionario:")
datos = {
    'Producto': ['Laptop', 'Mouse', 'Teclado', 'Monitor', 'Tablet'],
    'Precio': [1200, 25, 80, 300, 450],
    'Stock': [15, 100, 50, 30, 25],
    'Categoria': ['Electrónica', 'Accesorio', 'Accesorio', 'Electrónica', 'Electrónica']
}
df_ej1 = pd.DataFrame(datos)
print(df_ej1)

space()

titulo("Ejercicio 2. Crear otro dataframe a partir de la siguiente lista:")
datos = [
    [1, 'Laptop', 1200, 15],
    [2, 'Mouse', 25, 100],
    [3, 'Teclado', 80, 50],
    [4, 'Monitor', 300, 30],
    [5, 'Tablet', 450, 25]
]
df_ej2 = pd.DataFrame(datos)
print(df_ej2)

space()

titulo("Ejercicio 3. Muestra los primeros 3 registros de cada DataFrame.")
print("3 primeros elementos del dt_ej1 dataframe:")
print(df_ej1.head(3))
print("3 primeros elementos del dt_ej2 dataframe:")
print(df_ej2.head(3))

space()

titulo("Ejercicio 4. Del DataFrame creado en el ejercicio 1, muestra:\n• Forma (shape) del DataFrame\n• Nombres de columnas\n• Tipos de datos de cada columna\n• Estadísticas descriptivas\n• Muestra las 2 últimas filas\n• Muestra 2 filas de manera aleatoria")
# Forma (shape) del DataFrame
print(df_ej1.shape)
space()
# Nombres de columnas
print(df_ej1.columns)
space()
# Tipos de datos de cada columna
print(df_ej1.dtypes)
space()
# Estadísticas descriptivas
print(df_ej1.describe())
space()
# Muestra las 2 últimas filas
print(df_ej1.tail(2))
space()
# Muestra 2 filas de manera aleatoria
print(df_ej1.sample(2))

space()

titulo("Ejercicio 5. Realizar las siguientes seleciones del DataFrame del ejercicio 1.\n• Selecciona solo la columna 'Producto'\n• Selecciona las columnas 'Producto' y 'Precio'\n• Selecciona la primera fila completa\n• Selecciona el elemento en la posición (1, 2)\n• Usa loc para seleccionar las primeras 2 filas")
# Selecciona solo la columna 'Producto'
print(df_ej1['Producto'])
space()
# • Selecciona las columnas 'Producto' y 'Precio'
print(df_ej1[['Producto', 'Precio']])
space()
# Selecciona la primera fila completa
print(df_ej1.iloc[0]) # por posición
space()
# Selecciona el elemento en la posición (1, 2)
print(df_ej1.iloc[1,2])
space()
# Usa loc para seleccionar las primeras 2 filas
print(df_ej1.loc[:1]) # por etiqueta

space()

titulo("Ejercicio 6. Ejecuta el código proporcionado para crear el DataFrame df_ventas con 100 registros\nFiltra y muestra:\n• Todas las ventas de 'Laptop'\n• Ventas con monto total mayor a $1000\n• Ventas realizadas por 'Maria' en la región 'Norte")
np.random.seed(42)
datos_ventas = {
'Fecha': pd.date_range('2024-01-01', periods=100, freq='D'),
'Producto': np.random.choice(['Laptop', 'Mouse', 'Teclado', 'Monitor',
'Tablet'], 100),
'Cantidad': np.random.randint(1, 10, 100),
'Precio_Unitario': np.random.choice([1200, 25, 80, 300, 450], 100),
'Region': np.random.choice(['Norte', 'Sur', 'Este', 'Oeste'], 100),
'Vendedor': np.random.choice(['Ana', 'Carlos', 'Maria', 'Pedro'], 100)
}

df_ventas = pd.DataFrame(datos_ventas)
print("Dataframe de ventas:")
print(df_ventas)
space()
print("Dataframe de ventas con la nueva columna(Venta total):")
df_ventas['Venta_Total'] = df_ventas['Cantidad'] * df_ventas['Precio_Unitario']
print(df_ventas)
space()
# Todas las ventas de 'Laptop'
print(df_ventas[df_ventas['Producto'] == 'Laptop'])
space()
# Ventas con monto total mayor a $1000
print(df_ventas[df_ventas['Venta_Total'] > 1000])
space()
# Ventas realizadas por 'Maria' en la región 'Norte'
print(df_ventas[(df_ventas['Vendedor'] == 'Maria') & (df_ventas['Region'] == 'Norte')])

space()

titulo("Ejercicio 7. Manejo de valores nulos\n• Crea una copia del DataFrame del ejercicio 6 e introduce valores nulos en algunas celdas\n• Identifica y cuenta los valores nulos por columna\n• Elimina las filas con valores nulos y compara el tamaño del DataFrame con el inicial\n• Rellena los valores nulos con estrategias apropiadas\n• Ordena el DataFrame por 'Venta_Total' de forma descendente")
# Crea una copia del DataFrame del ejercicio 6 e introduce valores nulos en algunas celdas
ej7_df_ventas_copia = df_ventas
ej7_df_ventas_copia.loc[5, 'Precio_Unitario'] = np.nan
ej7_df_ventas_copia.loc[10, 'Vendedor'] = np.nan
ej7_df_ventas_copia.loc[25, 'Region'] = np.nan
# Comprobación
print(ej7_df_ventas_copia.iloc[5])
print(ej7_df_ventas_copia.iloc[10])
print(ej7_df_ventas_copia.iloc[25])
space()

# Identifica y cuenta los valores nulos por columna
print(ej7_df_ventas_copia.isnull().sum())
space()
# Elimina las filas con valores nulos y compara el tamaño del DataFrame con el inicial
ej7_df_ventas_copia = ej7_df_ventas_copia.dropna()
# No tienen el mismo tamaño
print(f"Tamaño del df original: {df_ventas.size} Vs Tamaño del df aleterado: {ej7_df_ventas_copia.size}")
space()
# Rellena los valores nulos con estrategias apropiadas
'''
Precio_Unitario    1
Region             1
Vendedor           1
'''
# Para sustuir valores numéricos usaremos la media y para los valores categóricos usaremos
# la moda
ej7_df_ventas_copia_rellenado = ej7_df_ventas_copia.copy()
ej7_df_ventas_copia_rellenado['Precio_Unitario'] = ej7_df_ventas_copia_rellenado['Precio_Unitario'].fillna(ej7_df_ventas_copia_rellenado['Precio_Unitario'].mean())
ej7_df_ventas_copia_rellenado['Region'] = ej7_df_ventas_copia_rellenado['Region'].fillna(ej7_df_ventas_copia_rellenado['Region'].mode()[0])
ej7_df_ventas_copia_rellenado['Vendedor'] = ej7_df_ventas_copia_rellenado['Vendedor'].fillna(ej7_df_ventas_copia_rellenado['Vendedor'].mode()[0])
print(ej7_df_ventas_copia_rellenado.iloc[5])
print(ej7_df_ventas_copia_rellenado.iloc[10])
print(ej7_df_ventas_copia_rellenado.iloc[20])
space()
print(f"Tamaño del df original: {df_ventas.size} Vs Tamaño del df aleterado: {ej7_df_ventas_copia_rellenado.size}")
space()
# Ordena el DataFrame por 'Venta_Total' de forma descendente
print(ej7_df_ventas_copia_rellenado.sort_values(by='Venta_Total'))

space()

titulo("Ejercicio 8. Agrupaciones \n- Calcula la venta total, promedio, máxima y número de ventas del total del DataFrame del ejercicio 6\n- Agrupa por 'Producto' y calcula la suma de ventas por producto\n- Agrupa por 'Region' y calcula la venta total, promedio, máxima y número de ventas\n- Identifica los top 3 vendedores por ventas totales")
# Calcula la venta total, promedio, máxima y número de ventas del total del DataFrame del ejercicio 6
ej8_df_ventas = df_ventas.copy()
ej8_venta_total_global = ej8_df_ventas['Venta_Total'].sum()
ej8_venta_promedio = ej8_df_ventas['Venta_Total'].mean()
ej8_venta_maxima = ej8_df_ventas['Venta_Total'].max()
ej8_numero_ventas = ej8_df_ventas['Venta_Total'].count()
print("Venta total global:", ej8_venta_total_global)
print("Promedio de ventas:", ej8_venta_promedio)
print("Venta máxima:", ej8_venta_maxima)
print("Número total de ventas:", ej8_numero_ventas)
space()
# En una sola línea
print()
ej8_agrup_sumMeanMaxTot = ej8_df_ventas.groupby(lambda _: 0)['Venta_Total'].agg(['sum', 'mean', 'max', 'count'])
print(ej8_agrup_sumMeanMaxTot)
space()
# Agrupa por 'Producto' y calcula la suma de ventas por producto
ej8_agrup_producto = ej8_df_ventas.groupby('Producto')['Venta_Total'].sum()
print(ej8_agrup_producto)
# Agrupa por 'Region' y calcula la venta total, promedio, máxima y número de ventas
ej8_agrup_region = ej8_df_ventas.groupby('Region')['Venta_Total'].agg(['sum', 'mean', 'max', 'count'])
print(ej8_agrup_region)
space()
# Identifica los top 3 vendedores por ventas totales
ej8_top3_vendedores = (
    ej8_df_ventas
        .groupby('Vendedor')['Venta_Total']
        .sum()
        .sort_values(ascending=False)
        .head(3)
)
print(ej8_top3_vendedores)

space()

titulo("Ejercicio 9.\n- Crea en el DataFrame del ejercicio 6 una nueva columna 'Venta_Con_IVA' aplicando 21% de IVA\n- Crea una columna 'Categoria_Precio' que clasifique como 'Alto' ( mayor que 500) o 'Bajo' (menor o igual que 500) según el precio\n- Usa apply() para crear una columna 'Tipo_Venta' que clasifique las ventas como 'Pequeña' (menos de 500), 'Mediana' (menos de 2000) o 'Grande' (en otro caso)")
# Crea en el DataFrame del ejercicio 6 una nueva columna 'Venta_Con_IVA' aplicando 21% de IVA
ej9_ventas = df_ventas.copy()
ej9_ventas['Venta_Con_IVA'] =  ej9_ventas['Venta_Total'] + (ej9_ventas['Venta_Total'] * 0.21)
print(ej9_ventas)
space()
# Crea una columna 'Categoria_Precio' que clasifique como 'Alto' ( mayor que
# 500) o 'Bajo' (menor o igual que 500) según el precio
ej9_ventas['Categoria_Precio'] = np.where(
    ej9_ventas['Precio_Unitario'] > 500, 
    'Alto',
    'Bajo'
)
print(ej9_ventas)
space()
# Usa apply() para crear una columna 'Tipo_Venta' que clasifique las ventas
# como 'Pequeña' (menos de 500), 'Mediana' (menos de 2000) o 'Grande' (en otro caso)
def clasificar_venta(venta):
    if venta < 500:
        return "Pequeña"
    elif venta < 2000:
        return "Mediana"
    else:
        return "Grande"
    
ej9_ventas['Tipo_Venta'] = ej9_ventas['Venta_Total'].apply(clasificar_venta)
print(ej9_ventas)
space()


titulo("Ejercicio 10. Siendo los siguientes JSONs: \n- Crea dos DataFrames adicionales: info_productos y info_vendedores\n- Realiza un INNER JOIN entre df_ventas y info_productos\n- Realiza un LEFT JOIN entre df_ventas y info_vendedores\n- Concatena al DataFrame del ejercicio 6 la siguiente información")
info_producto= {
    'Producto': ['Laptop', 'Mouse', 'Teclado', 'Monitor', 'Tablet', 'Auriculares'],
    'Categoria': ['Electrónica', 'Accesorio', 'Accesorio', 'Electrónica',
    'Electrónica', 'Accesorio'],
    'Costo': [800, 15, 40, 200, 300, 20]
}
info_vendedores = {
    'Vendedor': ['Ana', 'Carlos', 'Maria', 'Pedro', 'Laura'],
    'Departamento': ['Ventas', 'Tecnología', 'Ventas', 'Marketing', 'Ventas'],
    'Salario_Base': [30000, 35000, 32000, 28000, 31000]
}

# Crea dos DataFrames adicionales: info_productos y info_vendedores
ej10_info_producto = pd.DataFrame(info_producto)
ej10_info_vendedores = pd.DataFrame(info_vendedores)
print(ej10_info_producto)
space()
print(ej10_info_vendedores)
space()
# Realiza un INNER JOIN entre df_ventas y info_productos
ej10_inner_join = pd.merge(
    df_ventas, 
    ej10_info_producto, 
    on='Producto',
    # ó
    #left_on='Producto', 
    #right_on='Producto', 
    how='inner'
)
print(ej10_inner_join)
space()
# Realiza un LEFT JOIN entre df_ventas y info_vendedores
ej10_left_join = pd.merge(
    df_ventas, 
    ej10_info_vendedores, 
    on='Vendedor',
    how='left'
)
print(ej10_left_join)
space()
# Concatena al DataFrame del ejercicio 6 la siguiente información
ej10_nueva_info = {
    'Fecha': ['2024-04-01'],
    'Producto': ['Auriculares'],
    'Cantidad': [2],
    'Precio_Unitario': [50],
    'Region': ['Norte'],
    'Vendedor': ['Laura'],
    'Venta_Total': [100]
}
ej10_nueva_info_df = pd.DataFrame(ej10_nueva_info)
df_ventas = pd.concat([df_ventas, ej10_nueva_info_df], ignore_index=True) # para que indexe bien al final
print(df_ventas)
space()

titulo("Ejercicio 11. Calcula las ventas entre el 2024-01-15 y el 2024-01-31")
# Convertimos las fechas a el formato datetime
df_ventas['Fecha'] = pd.to_datetime(df_ventas['Fecha'])
# Esablecemos el límite y final de las fechas en datetime
inicio = pd.to_datetime('2024-01-15')
fin = pd.to_datetime('2024-01-31')
# Usamos 2 máscaras booleanas anidadas con un AND
ej11_ventas_fechas = df_ventas[
    (df_ventas['Fecha'] >=  inicio) &
    (df_ventas['Fecha'] <= fin)
]
print(ej11_ventas_fechas)