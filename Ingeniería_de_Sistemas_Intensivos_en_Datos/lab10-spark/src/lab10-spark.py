import pandas as pd
import numpy as np

from pyspark.sql import SparkSession
from pyspark.sql.types import StructType, StructField, StringType, DoubleType, IntegerType, BooleanType
from pyspark.sql.functions import col, concat, filter, upper, substring, lit, current_date, datediff, to_date


def titulo(titulo):
    print("\n#---------------------------------------------------------#\n")
    print(" ", titulo)
    print("\n#---------------------------------------------------------#\n")
    
def subtitulo(titulo):
    print("\n#---------------------------------------------------------#")
    print(" ", titulo)
    print("#---------------------------------------------------------#\n")

def space():
    print("\n")

# ==========================================
# EJERCICIO 1: CONFIGURACIÓN Y LECTURA DE DATOS
# ==========================================
# Crea una sesión de Spark y carga el archivo empleados.csv definiendo un esquema explícito.
titulo("EJERCICIO 1: CONFIGURACIÓN Y LECTURA DE DATOS")
subtitulo("Crea una sesión de Spark y carga el archivo empleados.csv definiendo un esquema explícito.")

titulo("# EJERCICIO 1: CONFIGURACIÓN Y LECTURA DE DATOS\n- Crea una sesión de Spark y carga el archivo empleados.csv definiendo un esquema explícito.")
spark = (
    SparkSession
        .builder
        .appName("Lab10-Spark")
        .getOrCreate()
)

logger = spark._jvm.org.apache.log4j
logger.LogManager.getLogger("org").setLevel(logger.Level.WARN)

fields = [
    StructField("id_empleado", IntegerType(), True),
    StructField("nombre", StringType(), True),
    StructField("apellido", StringType(), True),
    StructField("edad", IntegerType(), True),
    StructField("departamento", StringType(), True),
    StructField("puesto", StringType(), True),
    StructField("salario", DoubleType(), True),
    StructField("fecha_contratacion", StringType(), True),
    StructField("ciudad", StringType(), True),
    StructField("activo", BooleanType(), True)
]

esquema = StructType(fields)

df = (spark
      .read
      .format("csv")
      .option("header", "true")
      .schema(esquema)
      .load("datos/empleados.csv")
)

# ==========================================
# EJERCICIO 2: INSPECCIÓN DE DATOS
# ==========================================
# Examina la estructura del DataFrame:
# - Muestra el esquema.
# - Visualiza las primeras 10 filas.
# - Obtén estadísticas básicas.
titulo("EJERCICIO 2: INSPECCIÓN DE DATOS")

subtitulo("Muestra el esquema.")
df.printSchema()

subtitulo("Visualiza las primeras 10 filas.")
df.show(10)

subtitulo("Obtén estadísticas básicas.")
df.describe().show()

# ==========================================
# EJERCICIO 3: SELECCIÓN Y PROYECCIÓN
# ==========================================
# Selecciona las siguientes columnas de empleados: nombre, apellido y departamento.
# Luego crea una selección que incluya solo empleados del departamento de "Ventas".
titulo("EJERCICIO 3: SELECCIÓN Y PROYECCIÓN")

subtitulo("Selecciona las siguientes columnas de empleados: nombre, apellido y departamento.")
df.select("nombre", "apellido", "departamento").show()

subtitulo("Luego crea una selección que incluya solo empleados del departamento de 'Ventas'.")
df.where(col("departamento") == "Ventas").show()

# ==========================================
# EJERCICIO 4: TRANSFORMACIÓN DE COLUMNAS
# ==========================================
# Crea una nueva columna que combine nombre y apellido, por ejemplo: “Pepe García”.
# Crea otra columna que calcule un bono del 5% sobre el salario.
# Renombra la columna "puesto" a "cargo".
titulo("EJERCICIO 4: TRANSFORMACIÓN DE COLUMNAS")

subtitulo("Crea una nueva columna que combine nombre y apellido, por ejemplo: “Pepe García”.")
df.withColumn("NombreApellido", concat("nombre",lit(" "), "apellido")).show()

subtitulo("Crea otra columna que calcule un bono del 5% sobre el salario.")
df.withColumn("Bono", col("salario")*0.05 + col("salario")).show()

subtitulo("Renombra la columna 'puesto' a 'cargo'.")
df.withColumnRenamed("puesto", "cargo").show()

# ==========================================
# EJERCICIO 5: FILTRADO BÁSICO
# ==========================================
# - Filtra los empleados que tienen un salario mayor a 45000 y muestra su nombre, apellido, departamento y salario.
# - Filtra aquellos empleados que trabajan en "Madrid" y muestra su nombre, apellido, ciudad y puesto.
# - Filtra los empleados que están activos en la empresa y muestra su nombre, apellido y activo.
titulo("# EJERCICIO 5: FILTRADO BÁSICO")

subtitulo("- Filtra los empleados que tienen un salario mayor a 45000 y muestra su nombre, apellido, departamento y salario.")
df.filter(col("salario") > 45000).select("nombre", "apellido", "departamento", "salario").show()

subtitulo("- Filtra aquellos empleados que trabajan en Madrid y muestra su nombre, apellido, ciudad y puesto.")
df.filter(col("ciudad") == "Madrid").select("nombre", "apellido", "ciudad", "puesto").show()

subtitulo("- Filtra los empleados que están activos en la empresa y muestra su nombre, apellido y activo.")
df.filter(col("activo") == True).select("nombre", "apellido", "activo").show()

# ==========================================
# EJERCICIO 6: AGRUPACIONES SIMPLES
# ==========================================
# Agrupa los empleados por departamento y calcula:
# - El número de empleados.
# - El salario promedio.
# - El salario máximo por departamento.
titulo("# EJERCICIO 6: AGRUPACIONES SIMPLES")

subtitulo("- El número de empleados.")
df.groupBy("departamento").count().show()

subtitulo("- El salario promedio.")
df.groupBy("departamento").avg("salario").show()

subtitulo("- El salario máximo por departamento.")
df.groupBy("departamento").max("salario").show()

# ==========================================
# EJERCICIO 7: ORDENAMIENTO
# ==========================================
# Ordena los empleados por salario de forma descendente y luego por nombre de forma ascendente.
# Muestra solo los top 10 empleados con mayor salario.
titulo("# EJERCICIO 7: ORDENAMIENTO")

subtitulo("- Ordena los empleados por salario de forma descendente y luego por nombre de forma ascendente.")
df.orderBy(col("salario").desc(), col("nombre").asc()).show() 
df.sort("nombre", ascending=True).sort("salario", ascending=False).show() # El último sort tiene la prioridad

subtitulo("- Muestra solo los top 10 empleados con mayor salario.")
df.orderBy(col("salario").desc()).show(10)
df.sort("salario", ascending=False).show(10)

# ==========================================
# EJERCICIO 8: FUNCIONES DE STRING
# ==========================================
# Utiliza funciones de string para añadir al dataframe las siguientes columnas:
# - Convertir los nombres a mayúsculas.
# - Crear emails corporativos con el formato: nombre.apellido@empresa.com.
# - Extraer las primeras tres letras del apellido.
titulo("# EJERCICIO 8: FUNCIONES DE STRING")

subtitulo("# - Convertir los nombres a mayúsculas.")
df1 = df.withColumn("nombre", upper("nombre"))
df1.show()

subtitulo("# - Crear emails corporativos con el formato: nombre.apellido@empresa.com.")
df2 = df1.withColumn("email", concat("nombre", lit("."), "apellido", lit("@empresa.com")))
df2.show()

subtitulo("# - Extraer las primeras tres letras del apellido.")
df3 = df2.withColumn("iniciales_apellido", substring("apellido", 1, 3))
df3.show()

# ==========================================
# EJERCICIO 9: FUNCIONES DE FECHA
# ==========================================
# Calcula la antigüedad de cada empleado en días y añádela como una columna nueva.
titulo("# EJERCICIO 9: FUNCIONES DE FECHA")

subtitulo("# Calcula la antigüedad de cada empleado en días y añádela como una columna nueva.")
df.withColumn("dias_antigüedad", datediff(current_date(), to_date("fecha_contratacion", "yyyy-MM-dd"))).show()

# ==========================================
# EJERCICIO 10: CONSULTAS SQL
# ==========================================
# Crea una vista temporal.
# Ejecuta una consulta SQL que muestre nombre, departamento y salario de empleados
# con salario mayor a 40000, ordenados por salario descendente.
titulo("# EJERCICIO 10: CONSULTAS SQL")

subtitulo("# Crea una vista temporal.")
df.createTempView("vista_temporal_empleados")

subtitulo("# Ejecuta una consulta SQL que muestre nombre, departamento y salario de empleados\ncon salario mayor a 40000, ordenados por salario descendente.")
spark.sql("SELECT nombre, departamento, salario FROM vista_temporal_empleados WHERE salario > 40000 ORDER BY salario DESC").show()

# ==========================================
# EJERCICIO 11: ESCRITURA
# ==========================================
# Guarda en un CSV el DataFrame obtenido en el ejercicio 8.
titulo("# EJERCICIO 11: ESCRITURA")

subtitulo("# Guarda en un CSV el DataFrame obtenido en el ejercicio 8.")
df3.write.mode("overwrite").option("header", "true").csv("datos/resultado_ej_8")
print("Archivo guardado en su respectiva carpeta 'datos/resultado_ej_8'\n")
