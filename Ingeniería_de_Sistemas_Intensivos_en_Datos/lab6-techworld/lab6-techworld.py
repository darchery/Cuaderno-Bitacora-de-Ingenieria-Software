import pymongo
from datetime import datetime

def titulo(string):
    print("# ------------------------------------------------------------------------------")
    print(string)
    print("# ------------------------------------------------------------------------------")

def space():
    print("\n")

def reset_bases_datos(db):
    db.clientes.drop()
    db.productos.drop()
    db.ventas.drop()

def crear_conexion():
    # Conexión al servidor Mongo
    client = pymongo.MongoClient("mongodb://admin:admin@localhost:27017/")
    db = client["lab6"]
    reset_bases_datos(db)
    return client, db

# ------------------------------------------------------------------------------
# Tarea 1: Problado inicial de los catálagos
# ------------------------------------------------------------------------------
def insertar_clientes(db, clientes):
    db.clientes.insert_many(clientes)

def insertar_productos(db, productos):
    db.productos.insert_many(productos)

def insertar_ventas(db, ventas):
    db.ventas.insert_many(ventas)

# ------------------------------------------------------------------------------
# Tarea 2: Consultas
# ------------------------------------------------------------------------------

# Ejercicio 1: Obtener todos los recuros
def ej1_mostrar_todos_productos(db):
    productos = db.productos.find()
    print("Ejercicio 1: Obtener todos los recuros")
    for producto in productos:
        print(f"{producto['nombre']}:")
        print(producto)
# Ejercicio 2: Obtener los productos activos
def ej2_mostrar_productos_activos(db):
    productos_activos = db.productos.find({"activo": True})
    print("Ejercicio 2: Obtener los productos activos")
    for activo in productos_activos:
        print(f"{activo['nombre']}:")
        print(activo)
# Ejercicio 3: Obtener los productos de categoría “computadoras”
def ej3_mostrar_productos_categoria_computadoras(db):
    categoria_computadores = db.productos.find({"categoria": "computadoras"})
    print("Ejercicio 3: Obtener los productos de categoría computadoras")
    for producto in categoria_computadores:
        print(f"{producto['nombre']}:")
        print(producto)
# Ejercicio 4: Obtener los productos premium (precio >500€)
def ej4_mostrar_productos_premium_precioMayor500(db):
    productos_premium = db.productos.find({"precio": {"$gt": 500}})
    print("Ejercicio 4: Obtener los productos premium (precio >500€)")
    for producto in productos_premium:
        print(f"{producto['nombre']}:")
        print(producto)
# Ejercicio 5: Obtener los clientes premium
def ej5_mostrar_clientes_premium(db):
    clientes_premium = db.clientes.find({"premium": True})
    print("Ejercicio 5: Obtener los clientes premium")
    for cliente in clientes_premium:
        print(f"{cliente['nombre']}:")
        print(cliente)

# ------------------------------------------------------------------------------
# Tarea 3: Actualizaciones
# ------------------------------------------------------------------------------

# Ejercicio 6: Actualizar precio de "Auriculares Bluetooth" a 249
def ej6_actualizar_precio_auricularesBluetooth(db):
    print("Ejercicio 6: Actualizar precio de Auriculares Bluetooth a 249")
    auriculares = db.productos.find({"nombre": "Auriculares Bluetooth"})
    print("Precio de los auriculares bluetooth antes del cambio:")
    for auri in auriculares:
        print(auri['precio'])

    db.productos.update_one({"nombre": "Auriculares Bluetooth"}, {"$set": {"precio": 249}})
    
    auriculares = db.productos.find({"nombre": "Auriculares Bluetooth"})
    print("Precio de los auriculares bluetooth despues del cambio:")
    for auri in auriculares:
        print(auri['precio'])

# Ejercicio 7: Activar productos inactivos y ponerle un stock de 10
def ej7_activar_productos_inactivos_stock_a_10(db):
    print("Ejercicio 7: Activar productos inactivos y ponerle un stock de 10")
    db.productos.update_many({"activo": False}, {"$set": {"activo": True, "stock": 10}})
    productos = db.productos.find({"$and": [{"activo": True, "stock": 10}]})
    for produc in productos:
        print(produc['nombre'])
        print(produc)
# Ejercicio 8: Actualizar o añadir un descuento de 10 % para productos Apple
def ej8_actualizar_o_anyadir_descuento_10PorCiento_apple(db):
    db.productos.update_many({"marca": "Apple"}, {"$set": {"descuento": "10%"}})
    db.productos.find({"marca": "Apple"})
# Ejercicio 9: Aquellos productos que tengan un stock de menos de 10 unidades, 
# incrementar el stock en 5
def ej9_stock_menos_de_10_aumentar_en_5(db):
    titulo("Ejercicio 9: Aquellos productos que tengan un stock de menos de 10 unidades")
    productos = db.productos.find({"stock": {"$lt": 10}})
    print("Antes del update:")
    for produc in productos:
        print(produc['nombre'])
        print(produc)

    db.productos.update_many({"stock": {"$lt": 10}}, {"$inc": {"stock": 5}})
    productos = db.productos.find({"stock": {"$lt": 10}})
    print("Después del update:")
    for produc in productos:
        print(produc['nombre'])
        print(produc)

# ------------------------------------------------------------------------------
# Tarea 4: Índices
# ------------------------------------------------------------------------------

# Ejercicio 10: Crear índice en campo nombre
def ej10_indice_nombre(db):
    db.productos.create_index([("nombre", 1)])    
    productos_nombre = db.productos.index_information()    
    titulo("Ejercicio 10: Crear índice en campo nombre")
    for produc, value in productos_nombre.items():
        print(produc, value)
# Ejercicio 11: Crear índice compuesto con categoría ascendente y precio 
# descendente
def ej11_indice_compuesto_categoria_precio(db):
    db.productos.create_index([("categoria", 1), ("precio", -1)])    
    productos_compuesto = db.productos.index_information()    
    titulo("Ejercicio 11: Crear índice compuesto con categoría ascendente y precio descendente")
    for produc, value in productos_compuesto.items():
        print(produc, value)
# Ejercicio 12: Crear índice único en email
def ej12_indice_unico_email(db):
    db.clientes.create_index([("email", 1)], unique=True)    
    clientes_email = db.clientes.index_information()    
    titulo("Ejercicio 12: Crear índice único en email")
    for cliente, value in clientes_email.items():
        print(cliente, value)
# Ejercicio 13: Ver índices de productos
def ej13_mostrar_indices_productos(db):
    productos = db.productos.index_information()    
    titulo("# Ejercicio 13: Ver índices de productos")
    for produc, value in productos.items():
        print(produc, value)

# ------------------------------------------------------------------------------
# Tarea 5: Agregaciones
# ------------------------------------------------------------------------------

# Ejercicio 14: 
'''
    Analiza la distribución de productos a partir de las diferentes
    categorías y calcula métricas estadísticas para cada categoría. Este
    análisis te permitirá entender qué categorías tienen más productos, cuáles
    son las más valiosas y cómo se distribuye el inventario. 
    Agrupar todos los productos por su campo "categoría". Para cada categoría, calcular:
        o Cantidad total de productos
        o Precio promedio de los productos
        o Stock total disponible
        o Precio del producto más caro
        o Lista de todos los productos pertenecientes a esa categoría
        o Ordenar los resultados por la cantidad de productos de forma
        descendente
'''
def ej14_agregaciones_agrupar_productos_categoria(db):
    titulo("Ejercicio 14: agrupar productos por categoría")
    # o Cantidad total de productos
    titulo("o Cantidad total de productos")
    pipeline = [
        {"$group": {
            "_id": "$categoria",
            "totalProductos": {"$sum": 1}
        }}
    ]
    output = db.productos.aggregate(pipeline)
    for doc in output:
        print(f"Categoría: {doc['_id']}")
        print(f"Cantidad total de productos: {doc['totalProductos']}")
        space()
    # o Precio promedio de los productos
    titulo("o Precio promedio de los productos")
    pipeline = [
        {"$group": {
            "_id": "$categoria", 
            "avgPrecio": {"$avg": "$precio"}
        }}
    ]
    output = db.productos.aggregate(pipeline)
    for doc in output:    
        print(f"Categoría: {doc['_id']}")
        print(f"Precio promedio: {doc['avgPrecio']}")
        space()
    # o Stock total disponible
    titulo("o Stock total disponible")
    pipeline = [
        {"$group": {
            "_id": "$categoria",
            "stockTotal": {"$sum": "$stock"}
        }}
    ]
    output = db.productos.aggregate(pipeline)
    for doc in output:    
        print(f"Categoría: {doc['_id']}")
        print(f"Stock total: {doc['stockTotal']}")
        space()
    # o Precio del producto más caro
    titulo("Precio del producto más caro")
    pipeline = [
        {"$limit": 1},
        {"$sort": {"precio": -1}},
        {"$group": {
            "_id": "$categoria",
            "precio": {"$first": "$precio"},
            "nombre": {"$first": "$nombre"}
        }}
    ]
    output = db.productos.aggregate(pipeline)
    for doc in output:    
        print(f"Categoría del producto más caro: {doc['_id']}")
        print(f"Nombre: {doc['nombre']}")
        print(f"Precio: {doc['precio']}")
        space()
    # o Lista de todos los productos pertenecientes a esa categoría
    titulo("o Lista de todos los productos pertenecientes a esa categoría")
    pipeline = [
        {"$group": {
            "_id": "$categoria",
            "listaProductos": {"$push": "$nombre"}
        }}
    ]
    output = db.productos.aggregate(pipeline)
    for doc in output:    
        print(f"Categoría: {doc['_id']}")
        for producto in doc['listaProductos']:
            print(f"Nombre: {producto}")
        space()
    # o Ordenar los resultados por la cantidad de productos de forma
    # descendente
    titulo("o Ordenar los resultados por la cantidad de productos de forma descendente")
    pipeline = [
        {"$group": {
            "_id": "$categoria",
            "totalProductos": {"$sum": 1}
        }},
        {"$sort": {"totalProductos": -1}}
    ]
    output = db.productos.aggregate(pipeline)
    for doc in output:
        print(f"Categoria: {doc['_id']}")
        print(f"Cantidad de productos: {doc['totalProductos']}")
        space()
# Ejercicio 15: 
'''
    Combina información de ventas con datos detallados de
    productos para crear un reporte comprehensivo que muestre no solo las
    transacciones, sino también las características de los productos vendidos.
    Esto es esencial para entender qué se está vendiendo y a quién. Para cada
    venta, un documento con:
        o cliente: Email del cliente que realizó la compra
        o producto: Nombre del producto vendido
        o categoria: Categoría del producto
        o marca: Marca del producto
        o cantidad: Unidades vendidas
        o total: Monto total de la venta
        o ciudad: Ciudad donde se realizó la venta
'''
def ej15_lookup_ventas_productos(db):
    titulo("Ejercicio 15: look up desde ventas a productos")
    pipeline_ventas = [
        {"$lookup": {
            "from": "productos", # Unimos ventas con productos
            "localField": "producto_id", # Elegimos el producto_id de ventas(conexión con productos)
            "foreignField": "_id", # De productos elegimos su _id(así coinciden _id y prodcuto_id)
            "as": "info_producto" # Nuevo campo(array) que guarda los elementos que coincidan 
            # en producto_id(ventas) e _id(productos)
            }},
        {"$unwind": "$info_producto"}, # descomone el documento(array) en tantos 
        # documentos(subarrays) como elementos tenga el documento
        {"$project": { # Escoge o crea las características que avanzan a la siguiente etapa
            "cliente": "$cliente_email",
            "producto": "$info_producto.nombre", # por el "as" del lookup
            "categoria": "$info_producto.categoria",
            "marca": "$info_producto.marca",
            "cantidad": 1,
            "total": 1,
            "ciudad": 1
            }},
        {"$sort": {"total": -1}}
    ]
    resultado_ventas = list(db.ventas.aggregate(pipeline_ventas))
    for venta in resultado_ventas:
        print(f" - {venta['cliente']}: {venta['producto']} ({venta['marca']}) {venta['cantidad']} {venta['total']}")
    

# Ejercicio 16: 
'''
    Analiza el desempeño comercial por ubicación geográfica.
    Agrupa todas las ventas por ciudad para identificar patrones regionales,
    calcular métricas de rendimiento y determinar qué ciudades generan más
    ingresos. Para cada ciudad, calcular:
        o Total de ventas en euros
        o Cantidad total de transacciones realizadas
        o Promedio de venta por transacción
        o Ordenar los resultados por el total de ventas de forma descendente
'''
def ej16_agrupacion_ventas_por_ciudad(db):
    # o Total de ventas en euros
    titulo(" o Total de ventas en euros")
    pipeline = [
        {"$group": {
            "_id": "$ciudad",
            "totalVentas": {"$sum": "$total"}
        }}
    ]
    resultados = list(db.ventas.aggregate(pipeline))
    for venta in resultados:
        print(f"Ciudad: {venta['_id']}")
        print(f"Ventas totales: {venta['totalVentas']} €")
        space()
    # o Cantidad total de transacciones realizadas
    titulo("o Cantidad total de transacciones realizadas")
    pipeline = [
        {"$group": {
            "_id": "$ciudad",
            "transacciones": {"$sum": 1}
        }}
    ]
    resultados = list(db.ventas.aggregate(pipeline))
    for venta in resultados:
        print(f"Ciudad: {venta['_id']}")
        print(f"Transacciones totales: {venta['transacciones']}")
        space()
    # o Promedio de venta por transacción
    titulo("o Promedio de venta por transacción")
    pipeline = [
        {"$group": {
            "_id": "$ciudad",
            "avgPrecio": {"$avg": "$total"}
        }}
    ]
    resultados = list(db.ventas.aggregate(pipeline))
    for venta in resultados:
        print(f"Ciudad: {venta['_id']}")
        print(f"Promedio por venta: {venta['avgPrecio']} €")
        space()
    # o Ordenar los resultados por el total de ventas de forma descendente
    titulo("o Ordenar los resultados por el total de ventas de forma descendente")
    pipeline = [
        {"$group": {
            "_id": "$ciudad",
            "totalVentas": {"$sum": "$total"}
        }},
        {"$sort": {"totalVentas": -1}}
    ]
    resultados = list(db.ventas.aggregate(pipeline))
    for venta in resultados:
        print(f"Ciudad: {venta['_id']}")
        print(f"Ventas totales: {venta['totalVentas']} €")
        space()

# ------------------------------------------------------------------------------
# Tarea 6: Borrados
# ------------------------------------------------------------------------------

# Ejercicio 17: Inserta un nuevo producto con insert_one y bórralo. Los datos
# del producto son irrelevantes, puedes poner los que quieras
def ej17_anyadir_eliminar_producto(db):
    titulo("Ejercicio 17: Inserta un nuevo producto con insert_one y bórralo. Los datos del producto son irrelevantes, puedes poner los que quieras")
    laptop_asus = {
            "id": 666,
            "nombre": "ASUS TUF Gaming FX505G",
            "precio": 900,
            "stock": 1,
            "marca": "ASUS",
            "tags": ["gaming", "portatil", "economico"],
            "fecha_ingreso": datetime(2025, 9, 25),
            "activo": True
    }
    db.productos.insert_one(laptop_asus)
    productos = db.productos.find({"id": 666})
    print("Portatil añadido:")
    for produc in productos:
        print(produc['nombre'])
        print(produc)
    print("Portatil eliminado:")
    db.productos.delete_one({"id": 666})
    productos = db.productos.find({"id": 666})
    for produc in productos:
        print(produc['nombre'])
        print(produc)

if __name__ == "__main__":
    try:
        client, db = crear_conexion()

        # Cargamos los datos
        clientes = [
            {
                "nombre": "Ana García",
                "email": "ana@techworld.com",
                "ciudad": "Madrid",
                "premium": True,
                "fecha_registro": datetime(2023, 12, 1)
            },
            {
                "nombre": "Carlos López", 
                "email": "carlos@techworld.com",
                "ciudad": "Barcelona",
                "premium": False,
                "fecha_registro": datetime(2024, 1, 15)
            },
            {
                "nombre": "María Rodríguez",
                "email": "maria@techworld.com", 
                "ciudad": "Madrid",
                "premium": True,
                "fecha_registro": datetime(2023, 11, 20)
            }
        ]
        insertar_clientes(db, clientes)
        productos = [
            {
                "_id": 1,
                "nombre": "Laptop Gaming Pro",
                "categoria": "computadoras",
                "precio": 1500,
                "stock": 8,
                "marca": "ASUS",
                "tags": ["gaming", "portatil", "rendimiento"],
                "fecha_ingreso": datetime(2024, 1, 10),
                "activo": True
            },
            {
                "_id": 2,
                "nombre": "Smartphone Galaxy",
                "categoria": "moviles", 
                "precio": 799,
                "stock": 25,
                "marca": "Samsung",
                "tags": ["android", "5G", "camara"],
                "fecha_ingreso": datetime(2024, 2, 15),
                "activo": True
            },
            {
                "_id": 3,
                "nombre": "Tablet iPad",
                "categoria": "tablets",
                "precio": 599,
                "stock": 15,
                "marca": "Apple",
                "tags": ["apple", "creatividad", "portatil"],
                "fecha_ingreso": datetime(2024, 1, 25),
                "activo": True
            },
			{
				"_id": 4,
				"nombre": "Auriculares Bluetooth",
				"categoria": "audio",
				"precio": 299,
				"stock": 0,
				"marca": "Sony", 
				"tags": ["audio", "inalambrico", "calidad"],
				"fecha_ingreso": datetime(2024, 3, 1),
				"activo": False
			}
        ]
        insertar_productos(db, productos)

        ventas = [
            {
                "producto_id": 1,
                "cliente_email": "ana@techworld.com",
                "cantidad": 1,
                "total": 1500,
                "fecha": datetime(2024, 3, 15),
                "ciudad": "Madrid"
            },
            {
                "producto_id": 2,
                "cliente_email": "carlos@techworld.com", 
                "cantidad": 2,
                "total": 1598,
                "fecha": datetime(2024, 3, 16),
                "ciudad": "Barcelona"
            },
            {
                "producto_id": 3,
                "cliente_email": "maria@techworld.com",
                "cantidad": 1, 
                "total": 599,
                "fecha": datetime(2024, 3, 17),
                "ciudad": "Madrid"
            }
        ]
        insertar_ventas(db, ventas)

        ej1_mostrar_todos_productos(db)
        space()
        ej2_mostrar_productos_activos(db)
        space()
        ej3_mostrar_productos_categoria_computadoras(db)
        space()
        ej4_mostrar_productos_premium_precioMayor500(db)
        space()
        ej5_mostrar_clientes_premium(db)
        space()
        ej6_actualizar_precio_auricularesBluetooth(db)
        space()
        ej7_activar_productos_inactivos_stock_a_10(db)
        space()
        ej9_stock_menos_de_10_aumentar_en_5(db)
        space()
        ej10_indice_nombre(db)
        space()
        ej11_indice_compuesto_categoria_precio(db)
        space()
        ej12_indice_unico_email(db)
        space()
        ej13_mostrar_indices_productos(db)
        space()
        ej14_agregaciones_agrupar_productos_categoria(db)
        space()
        ej15_lookup_ventas_productos(db)
        space()
        ej16_agrupacion_ventas_por_ciudad(db)
        space()
        ej17_anyadir_eliminar_producto(db)
    except Exception as e:
        print(f"Error: {e}")
    finally:
        client.close
