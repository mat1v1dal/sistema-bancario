#include "./class-declaration/archivo.h"
#include <fstream>
#include <sstream>
using namespace std;
void cargarDatosDesdeArchivos(Banco *banco)
{
    ifstream archivoClientes("./archivos-txt/clientes.txt");
    ifstream archivoTransacciones("./archivos-txt/transacciones.txt");
    string linea;

    // Cargar clientes
    while (getline(archivoClientes, linea))
    {
        istringstream iss(linea);
        string dni, nombre, tipoCliente, anioIngresoStr, estado;
        getline(iss, dni, ',');
        getline(iss, nombre, ',');
        getline(iss, tipoCliente, ',');
        getline(iss, anioIngresoStr, ',');
        getline(iss, estado, ',');

        int anioIngreso = stoi(anioIngresoStr);
        Cliente *cliente = ClienteFactory::crearCliente(tipoCliente, dni, nombre, anioIngreso);
        cliente->setEstado(estado);
        banco->agregarCliente(cliente);
    }

    // Cargar transacciones
    while (getline(archivoTransacciones, linea))
    {
        istringstream iss(linea);
        string dniCliente, tipoTransaccion, montoStr, moneda, fecha;
        getline(iss, dniCliente, ',');
        getline(iss, tipoTransaccion, ',');
        getline(iss, montoStr, ',');
        getline(iss, moneda, ',');
        getline(iss, fecha, ',');

        double monto = stod(montoStr);
        Transaccion transaccion = TransaccionFactory::crearTransaccion(dniCliente, tipoTransaccion, monto, moneda, fecha);
        banco->registrarTransaccion(transaccion);
    }
}

void guardarDatosEnArchivos(Banco *banco)
{
    ofstream archivoClientes("./archivos-txt/clientes.txt");
    ofstream archivoTransacciones("./archivos-txt/transacciones.txt");

    // Guardar clientes
    vector<Cliente *> clientes = banco->obtenerTodosLosClientes();
    for (const auto &cliente : clientes)
    {
        archivoClientes << cliente->getDni() << ","
                        << cliente->getNombre() << ","
                        << cliente->getTipoCliente() << ","
                        << cliente->getAnioIngreso() << ","
                        << cliente->getEstado() << endl;
    }

    // Guardar transacciones
    vector<Transaccion> transacciones = banco->obtenerTodasLasTransacciones();
    for (const auto &transaccion : transacciones)
    {
        archivoTransacciones << transaccion.getDniCliente() << ","
                             << transaccion.getTipoTransaccion() << ","
                             << transaccion.getMonto() << ","
                             << transaccion.getMoneda() << ","
                             << transaccion.getFecha() << endl;
    }
}
