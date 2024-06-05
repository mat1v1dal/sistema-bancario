
# Sistema bancario

Sistema de gestión que permita realizar el registro y
control de actividades


## Autor

- [@Vidal Matias 2302403](https://github.com/mat1v1dal)


## Tecnologias utilizadas

**Librerias:** fstream, sstream, iostream, vector




## Para compilar el proyecto



```bash
g++ -Wall main.cpp transaccion.cpp cuenta.cpp cliente.cpp banco.cpp archivo.cpp -o main
```
```bash
main | ./main
```

## Patrones de diseño utilizados
- Para realizar este proyecto me base en libro **Patrones de diseño de Erich Gamma**

- Se utiliza el patrón **Factory** en la clase **ClienteFactory** para crear instancias de diferentes tipos de clientes (Plata, Oro, Platino) sin exponer la lógica de creación en el código cliente. Esto permite una fácil extensibilidad al agregar nuevos tipos de clientes en el futuro, ya que la creación de clientes se gestiona de manera centralizada en la clase ClienteFactory

- Se utiliza el patrón **Singleton** en la clase **Banco** para asegurar que solo haya una instancia del banco en todo el sistema. Esto garantiza que los datos de los clientes y las transacciones se manejen de manera coherente y evita problemas de inconsistencia. 

# Clase Banco

## Métodos Principales

### `getInstancia()`
Implementa el patrón Singleton para garantizar una única instancia de la clase Banco en todo el sistema. Devuelve la instancia única del banco.

### `agregarCliente(Cliente *cliente)`
Agrega un cliente al banco.
- **Parámetro**: Puntero al objeto `Cliente` que se va a agregar.

### `eliminarCliente(const std::string &dni)`
Elimina un cliente del banco según su número de identificación (DNI).
- **Parámetro**: DNI del cliente que se va a eliminar.

### `obtenerCliente(const std::string &dni) const`
Obtiene un cliente del banco según su número de identificación (DNI).
- **Parámetro**: DNI del cliente que se desea obtener.

### `obtenerTodosLosClientes() const`
Devuelve todos los clientes del banco como un vector de punteros a objetos `Cliente`.

### `registrarTransaccion(const Transaccion &transaccion)`
Registra una nueva transacción en el banco.
- **Parámetro**: Transacción que se va a registrar.

## Métodos para Obtener Transacciones

### `obtenerTransaccionesPorCliente(const std::string &dni) const`
Permite filtrar las transacciones según el cliente especificado.
- **Parámetro**: DNI del cliente cuyas transacciones se desean obtener.

### `obtenerTransaccionesPorMes(int mes, int anio) const`
Permite filtrar las transacciones según el mes y año especificados.
- **Parámetros**: Mes y año de las transacciones que se desean obtener.

### `obtenerTransaccionesPorAnio(int anio) const`
Permite filtrar las transacciones según el año especificado.
- **Parámetro**: Año de las transacciones que se desean obtener.

### `obtenerTodasLasTransacciones() const`
Devuelve todas las transacciones registradas en el banco como un vector de objetos `Transaccion`.
# Enfoque y Métodos en la Clase Cliente y ClienteFactory

En la clase `Cliente` se utiliza un puntero a `Cliente` en la clase `ClienteFactory`. A continuación, se detalla por qué se utiliza este enfoque y se proporciona un resumen de los métodos principales:

## Uso de Punteros a Cliente

En la clase `ClienteFactory`, el método `crearCliente` devuelve un puntero a `Cliente`. Esto se debe a que se necesita polimorfismo para crear instancias de diferentes tipos de clientes (`ClientePlata`, `ClienteOro`, `ClientePlatino`) sin conocer el tipo exacto en tiempo de compilación. Al devolver un puntero a `Cliente`, se puede usar la subclase adecuada sin exponer la implementación concreta en la interfaz.

## Métodos Principales de Cliente

- `Cliente(std::string dni, std::string nombre, int anioIngreso, std::string estado)`:  
  Constructor de la clase `Cliente` que inicializa sus atributos.

- `getDni() const`:  
  Devuelve el DNI del cliente.

- `getNombre() const`:  
  Devuelve el nombre del cliente.

- `virtual std::string getTipoCliente() const = 0`:  
  Método virtual puro que devuelve el tipo de cliente. Debe ser implementado por las subclases.

- `getAnioIngreso() const`:  
  Devuelve el año de ingreso del cliente al banco.

- `getEstado() const`:  
  Devuelve el estado del cliente (activo, inactivo, etc.).

- `setEstado(std::string estado)`:  
  Establece el estado del cliente.

## Clase ClienteFactory

La clase `ClienteFactory` implementa el patrón Factory Method para crear instancias de diferentes tipos de clientes sin conocer las clases concretas. Utiliza un puntero a `Cliente` como tipo de retorno para lograr la abstracción necesaria y la flexibilidad en la creación de clientes.

Este enfoque proporciona una separación efectiva entre la creación de objetos y su uso, lo que facilita la extensión y mantenimiento del código. Además, permite agregar nuevos tipos de clientes sin modificar el código existente, lo que mejora la escalabilidad y la modularidad del sistema.
