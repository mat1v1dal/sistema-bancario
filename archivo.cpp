#include "./class-declaration/archivo.h"
using namespace std;
void cargarDatosDesdeArchivos(Banco *banco)
{
    ifstream archivoClientes("./archivos-txt/clientes.txt");
    ifstream archivoTransacciones("./archivos-txt/transacciones.txt");
    ifstream archivoCuentas("./archivos-txt/cuentas.txt");
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
        banco->registrarTransaccion(transaccion, 0);
    }
    // cargar cuentas
    while (getline(archivoCuentas, linea))
    {
        istringstream iss(linea);
        string dniCliente, tipoCuenta, saldoStr;
        getline(iss, dniCliente, ',');
        getline(iss, saldoStr, ',');
        getline(iss, tipoCuenta, ',');

        double saldo = stod(saldoStr);

        for (Cliente *cliente : banco->obtenerTodosLosClientes())
        {
            if (cliente->getDni() == dniCliente)
            {
                Cuenta cuenta = CuentaFactory::crearCuenta(dniCliente, saldo, tipoCuenta);
                cliente->agregarCuenta(cuenta);
            }
        }
    }
}

void guardarDatosEnArchivos(Banco *banco)
{
    ofstream archivoClientes("./archivos-txt/clientes.txt");
    ofstream archivoTransacciones("./archivos-txt/transacciones.txt");
    ofstream archivoCuentas("./archivos-txt/cuentas.txt");

    // Guardar clientes
    vector<Cliente *> clientes = banco->obtenerTodosLosClientes();
    for (const auto &cliente : clientes)
    {
        archivoClientes << cliente->getDni() << ","
                        << cliente->getNombre() << ","
                        << cliente->getTipoCliente() << ","
                        << cliente->getAnioIngreso() << ","
                        << cliente->getEstado() << endl;

        // Guardar cuentas
        vector<Cuenta> cuentasPesos = cliente->getCuentasPesos();
        vector<Cuenta> cuentasDolares = cliente->getCuentasDolares();
        for (const auto &cuenta : cuentasPesos)
        {
            archivoCuentas << cliente->getDni() << ","
                           << cuenta.getSaldo() << ","
                           << "pesos" << endl;
        }
        for (const auto &cuenta : cuentasDolares)
        {
            archivoCuentas << cliente->getDni() << ","
                           << cuenta.getSaldo() << ","
                           << "dolares" << endl;
        }
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
