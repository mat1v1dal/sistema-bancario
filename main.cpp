using namespace std;

#include "./class-declaration/banco.h"
#include "./class-declaration/clienteFactory.h"
#include "./class-declaration/transaccionFactory.h"
#include "./class-declaration/cuentaFactory.h"
#include "./class-declaration/archivo.h"
#include <iostream>
#include <fstream>

void limpiarConsola()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarMenu()
{
    cout << "===== Sistema de Gestión Bancaria =====" << endl;
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Eliminar Cliente" << endl;
    cout << "3. Registrar Transacción" << endl;
    cout << "4. Detalle de Cliente por número de Cliente" << endl;
    cout << "5. Listado de todos los clientes" << endl;
    cout << "6. Listado de transacciones por clientes" << endl;
    cout << "7. Informes de extracciones y depósitos" << endl;
    cout << "8. Guardar y Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main()
{
    Banco *banco = Banco::getInstancia();

    // Cargar datos desde archivos
    cargarDatosDesdeArchivos(banco);

    int opcion;
    do
    {
        limpiarConsola();
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            string dni, nombre, tipoCliente;
            int anioIngreso;
            cout << "Ingrese DNI: ";
            cin >> dni;
            cout << "Ingrese Nombre: ";
            cin >> nombre;
            cout << "Ingrese Tipo de Cliente (Plata, Oro, Platino): ";
            cin >> tipoCliente;
            cout << "Ingrese Año de Ingreso: ";
            cin >> anioIngreso;
            Cliente *nuevoCliente = ClienteFactory::crearCliente(tipoCliente, dni, nombre, anioIngreso);

            // Crear cuentas para el cliente
            Cuenta cuentaPesos = CuentaFactory::crearCuenta(dni, 0, "pesos");
            Cuenta cuentaDolares = CuentaFactory::crearCuenta(dni, 0, "dolares");

            nuevoCliente->agregarCuenta(cuentaPesos);
            nuevoCliente->agregarCuenta(cuentaDolares);

            banco->agregarCliente(nuevoCliente);
            cout << "Cliente y cuentas creados con éxito." << endl;
            break;
        }
        case 2:
        {
            string dni;
            cout << "Ingrese DNI del cliente a eliminar: ";
            cin >> dni;
            try
            {
                banco->eliminarCliente(dni);
                cout << "Cliente eliminado con éxito." << endl;
            }
            catch (const exception &e)
            {
                cerr << e.what() << endl;
            }
            break;
        }
        case 3:
        {
            string dniCliente, tipoTransaccion, moneda, fecha;
            double monto;
            cout << "Ingrese DNI del Cliente: ";
            cin >> dniCliente;
            cout << "Ingrese Tipo de Transacción (Depósito, Extracción): ";
            cin >> tipoTransaccion;
            cout << "Ingrese Monto: ";
            cin >> monto;
            cout << "Ingrese Moneda (Pesos, Dolares): ";
            cin >> moneda;
            cout << "Ingrese Fecha (YYYY-MM-DD): ";
            cin >> fecha;
            try
            {
                Transaccion nuevaTransaccion = TransaccionFactory::crearTransaccion(dniCliente, tipoTransaccion, monto, moneda, fecha);
                banco->registrarTransaccion(nuevaTransaccion, 0);
                cout << "Transacción registrada con éxito." << endl;
            }
            catch (const exception &e)
            {
                cerr << e.what() << endl;
            }
            break;
        }
        case 4:
        {
            string dni;
            cout << "Ingrese DNI del Cliente: ";
            cin >> dni;
            try
            {
                Cliente *cliente = banco->obtenerCliente(dni);
                cout << cliente->getDni() << endl;
                cout << cliente->getNombre() << endl;
                cout << cliente->getTipoCliente() << endl;
                cout << cliente->getAnioIngreso() << endl;
                cout << cliente->getEstado() << endl;

                vector<Cuenta> cuentasPesos = cliente->getCuentasPesos();
                vector<Cuenta> cuentasDolares = cliente->getCuentasDolares();

                cout << "Cuentas en Pesos:" << endl;
                for (const auto &cuenta : cuentasPesos)
                {
                    cout << "Saldo: " << cuenta.getSaldo() << endl;
                }

                cout << "Cuentas en Dolares:" << endl;
                for (const auto &cuenta : cuentasDolares)
                {
                    cout << "Saldo: " << cuenta.getSaldo() << endl;
                }
            }
            catch (const exception &e)
            {
                cerr << e.what() << endl;
            }
            break;
        }
        case 5:
        {
            vector<Cliente *> clientes = banco->obtenerTodosLosClientes();
            for (const auto &cliente : clientes)
            {
                cout << cliente->getDni() << endl;
                cout << cliente->getNombre() << endl;
                cout << cliente->getTipoCliente() << endl;
                cout << cliente->getAnioIngreso() << endl;
                cout << cliente->getEstado() << endl;
            }
            break;
        }
        case 6:
        {
            string dni;
            cout << "Ingrese DNI del Cliente: ";
            cin >> dni;
            vector<Transaccion> transacciones = banco->obtenerTransaccionesPorCliente(dni);
            for (const auto &transaccion : transacciones)
            {
                cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                     << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                     << ", Fecha: " << transaccion.getFecha() << endl;
            }
            break;
        }
        case 7:
        {
            int criterio;
            cout << "Seleccione criterio: 1. Mes, 2. Año, 3. Todas: ";
            cin >> criterio;
            if (criterio == 1)
            {
                int mes, anio;
                cout << "Ingrese Mes (1-12): ";
                cin >> mes;
                cout << "Ingrese Año: ";
                cin >> anio;
                vector<Transaccion> transacciones = banco->obtenerTransaccionesPorMes(mes, anio);
                for (const auto &transaccion : transacciones)
                {
                    cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                         << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                         << ", Fecha: " << transaccion.getFecha() << endl;
                }
            }
            else if (criterio == 2)
            {
                int anio;
                cout << "Ingrese Año: ";
                cin >> anio;
                vector<Transaccion> transacciones = banco->obtenerTransaccionesPorAnio(anio);
                for (const auto &transaccion : transacciones)
                {
                    cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                         << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                         << ", Fecha: " << transaccion.getFecha() << endl;
                }
            }
            else if (criterio == 3)
            {
                vector<Transaccion> transacciones = banco->obtenerTodasLasTransacciones();
                for (const auto &transaccion : transacciones)
                {
                    cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                         << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                         << ", Fecha: " << transaccion.getFecha() << endl;
                }
            }
            break;
        }
        case 8:
            // Guardar datos en archivos
            guardarDatosEnArchivos(banco);
            cout << "Datos guardados con éxito. Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            break;
        }

        if (opcion != 8)
        {
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 8);

    return 0;
}
