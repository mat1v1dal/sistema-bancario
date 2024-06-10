#include "./class-declaration/archivo.h"
using namespace std;

void cargarDatosDesdeArchivos(Banco *banco)
{
    ifstream archivoClientes("./archivos-txt/clientes.txt");
    ifstream archivoTransacciones("./archivos-txt/transacciones.txt");
    ifstream archivoCuentas("./archivos-txt/cuentas.txt");
    ifstream archivoTarjetas("./archivos-txt/tarjetasCredito.txt");
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
    // Cargar cuentas
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
                cliente->agregarCuenta(CuentaFactory::crearCuenta(dniCliente, saldo, tipoCuenta));
                break;
            }
        }
    }
    // Cargar tarjetas de crédito
    while (getline(archivoTarjetas, linea))
    {
        istringstream iss(linea);
        string dniCliente, limiteStr, nombre;
        getline(iss, dniCliente, ',');
        getline(iss, nombre, ',');
        getline(iss, limiteStr, ',');

        double limite = stod(limiteStr);
        for (Cliente *cliente : banco->obtenerTodosLosClientes())
        {
            if (cliente->getDni() == dniCliente)
            {
                cliente->getTarjetaDeCredito();
                break;
            }
        }
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
        banco->cargarTransacciones(transaccion);
    }
}

void guardarDatosEnArchivos(Banco *banco)
{
    ofstream archivoClientes("./archivos-txt/clientes.txt");
    ofstream archivoTransacciones("./archivos-txt/transacciones.txt");
    ofstream archivoCuentas("./archivos-txt/cuentas.txt");
    ofstream archivoTarjetas("./archivos-txt/tarjetasCredito.txt");

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
        vector<Cuenta *> cuentasPesos = cliente->getCuentasPesos();
        vector<Cuenta *> cuentasDolares = cliente->getCuentasDolares();
        for (const auto &cuenta : cuentasPesos)
        {
            archivoCuentas << cliente->getDni() << ","
                           << cuenta->getSaldo() << ","
                           << "pesos" << endl;
        }
        for (const auto &cuenta : cuentasDolares)
        {
            archivoCuentas << cliente->getDni() << ","
                           << cuenta->getSaldo() << ","
                           << "dolares" << endl;
        }
        for (const auto &tarjeta : cliente->getTarjeta())
        {
            archivoTarjetas << cliente->getDni() << ","
                            << tarjeta->getNombre() << ","
                            << tarjeta->getLimiteCredito() << endl;
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
