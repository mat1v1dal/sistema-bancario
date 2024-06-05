#include "./class-declaration/archivo.h"
#include <fstream>
#include <sstream>

void cargarDatosDesdeArchivos(Banco *banco)
{
    std::ifstream archivoClientes("./archivos-txt/clientes.txt");
    std::ifstream archivoTransacciones("./archivos-txt/transacciones.txt");
    std::string linea;

    // Cargar clientes
    while (std::getline(archivoClientes, linea))
    {
        std::istringstream iss(linea);
        std::string dni, nombre, tipoCliente, anioIngresoStr, estado;
        std::getline(iss, dni, ',');
        std::getline(iss, nombre, ',');
        std::getline(iss, tipoCliente, ',');
        std::getline(iss, anioIngresoStr, ',');
        std::getline(iss, estado, ',');

        int anioIngreso = std::stoi(anioIngresoStr);
        Cliente *cliente = ClienteFactory::crearCliente(tipoCliente, dni, nombre, anioIngreso);
        cliente->setEstado(estado);
        banco->agregarCliente(cliente);
    }

    // Cargar transacciones
    while (std::getline(archivoTransacciones, linea))
    {
        std::istringstream iss(linea);
        std::string dniCliente, tipoTransaccion, montoStr, moneda, fecha;
        std::getline(iss, dniCliente, ',');
        std::getline(iss, tipoTransaccion, ',');
        std::getline(iss, montoStr, ',');
        std::getline(iss, moneda, ',');
        std::getline(iss, fecha, ',');

        double monto = std::stod(montoStr);
        Transaccion transaccion = TransaccionFactory::crearTransaccion(dniCliente, tipoTransaccion, monto, moneda, fecha);
        banco->registrarTransaccion(transaccion);
    }
}

void guardarDatosEnArchivos(Banco *banco)
{
    std::ofstream archivoClientes("./archivos-txt/clientes.txt");
    std::ofstream archivoTransacciones("./archivos-txt/transacciones.txt");

    // Guardar clientes
    std::vector<Cliente *> clientes = banco->obtenerTodosLosClientes();
    for (const auto &cliente : clientes)
    {
        archivoClientes << cliente->getDni() << ","
                        << cliente->getNombre() << ","
                        << cliente->getTipoCliente() << ","
                        << cliente->getAnioIngreso() << ","
                        << cliente->getEstado() << std::endl;
    }

    // Guardar transacciones
    std::vector<Transaccion> transacciones = banco->obtenerTodasLasTransacciones();
    for (const auto &transaccion : transacciones)
    {
        archivoTransacciones << transaccion.getDniCliente() << ","
                             << transaccion.getTipoTransaccion() << ","
                             << transaccion.getMonto() << ","
                             << transaccion.getMoneda() << ","
                             << transaccion.getFecha() << std::endl;
    }
}
