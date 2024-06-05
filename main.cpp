#include "./class-declaration/Banco.h"
#include "./class-declaration/ClienteFactory.h"
#include "./class-declaration/TransaccionFactory.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

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
    std::cout << "===== Sistema de Gestión Bancaria =====" << std::endl;
    std::cout << "1. Agregar Cliente" << std::endl;
    std::cout << "2. Eliminar Cliente" << std::endl;
    std::cout << "3. Registrar Transacción" << std::endl;
    std::cout << "4. Detalle de Cliente por número de Cliente" << std::endl;
    std::cout << "5. Listado de todos los clientes" << std::endl;
    std::cout << "6. Listado de transacciones por clientes" << std::endl;
    std::cout << "7. Informes de extracciones y depósitos" << std::endl;
    std::cout << "8. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main()
{
    Banco *banco = Banco::getInstancia();

    int opcion;
    do
    {
        limpiarConsola();
        mostrarMenu();
        std::cin >> opcion;

        limpiarConsola();
        switch (opcion)
        {
        case 1:
        {
            std::string dni, nombre, tipoCliente;
            int anioIngreso;
            std::cout << "Ingrese DNI: ";
            std::cin >> dni;
            std::cout << "Ingrese Nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese Tipo de Cliente (Plata, Oro, Platino): ";
            std::cin >> tipoCliente;
            std::cout << "Ingrese Año de Ingreso: ";
            std::cin >> anioIngreso;
            Cliente nuevoCliente = ClienteFactory::crearCliente(tipoCliente, dni, nombre, anioIngreso);
            banco->agregarCliente(nuevoCliente);
            std::cout << "Cliente agregado con éxito." << std::endl;
            break;
        }
        case 2:
        {
            std::string dni;
            std::cout << "Ingrese DNI del cliente a eliminar: ";
            std::cin >> dni;
            try
            {
                banco->eliminarCliente(dni);
                std::cout << "Cliente eliminado con éxito." << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 3:
        {
            std::string dniCliente, tipoTransaccion, moneda, fecha;
            double monto;
            std::cout << "Ingrese DNI del Cliente: ";
            std::cin >> dniCliente;
            std::cout << "Ingrese Tipo de Transacción (Depósito, Extracción): ";
            std::cin >> tipoTransaccion;
            std::cout << "Ingrese Monto: ";
            std::cin >> monto;
            std::cout << "Ingrese Moneda (Pesos, Dolares): ";
            std::cin >> moneda;
            std::cout << "Ingrese Fecha (YYYY-MM-DD): ";
            std::cin >> fecha;
            try
            {
                Transaccion nuevaTransaccion = TransaccionFactory::crearTransaccion(dniCliente, tipoTransaccion, monto, moneda, fecha);
                banco->registrarTransaccion(nuevaTransaccion);
                std::cout << "Transacción registrada con éxito." << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 4:
        {
            std::string dni;
            std::cout << "Ingrese DNI del Cliente: ";
            std::cin >> dni;
            try
            {
                Cliente cliente = banco->obtenerCliente(dni);
                cliente.mostrarInformacion();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 5:
        {
            std::vector<Cliente> clientes = banco->obtenerTodosLosClientes();
            for (const auto &cliente : clientes)
            {
                cliente.mostrarInformacion();
            }
            break;
        }
        case 6:
        {
            std::string dni;
            std::cout << "Ingrese DNI del Cliente: ";
            std::cin >> dni;
            std::vector<Transaccion> transacciones = banco->obtenerTransaccionesPorCliente(dni);
            for (const auto &transaccion : transacciones)
            {
                std::cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                          << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                          << ", Fecha: " << transaccion.getFecha() << std::endl;
            }
            break;
        }
        case 7:
        {
            int criterio;
            std::cout << "Seleccione criterio: 1. Mes, 2. Año, 3. Todas: ";
            std::cin >> criterio;
            if (criterio == 1)
            {
                int mes, anio;
                std::cout << "Ingrese Mes (1-12): ";
                std::cin >> mes;
                std::cout << "Ingrese Año: ";
                std::cin >> anio;
                std::vector<Transaccion> transacciones = banco->obtenerTransaccionesPorMes(mes, anio);
                for (const auto &transaccion : transacciones)
                {
                    std::cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                              << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                              << ", Fecha: " << transaccion.getFecha() << std::endl;
                }
            }
            else if (criterio == 2)
            {
                int anio;
                std::cout << "Ingrese Año: ";
                std::cin >> anio;
                std::vector<Transaccion> transacciones = banco->obtenerTransaccionesPorAnio(anio);
                for (const auto &transaccion : transacciones)
                {
                    std::cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                              << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                              << ", Fecha: " << transaccion.getFecha() << std::endl;
                }
            }
            else if (criterio == 3)
            {
                std::vector<Transaccion> transacciones = banco->obtenerTodasLasTransacciones();
                for (const auto &transaccion : transacciones)
                {
                    std::cout << "DNI: " << transaccion.getDniCliente() << ", Tipo: " << transaccion.getTipoTransaccion()
                              << ", Monto: " << transaccion.getMonto() << ", Moneda: " << transaccion.getMoneda()
                              << ", Fecha: " << transaccion.getFecha() << std::endl;
                }
            }
            break;
        }
        case 8:
            std::cout << "Saliendo del sistema..." << std::endl;
            break;
        default:
            std::cout << "Opción no válida. Intente nuevamente." << std::endl;
            break;
        }

        if (opcion != 8)
        {
            std::cout << "Presione enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (opcion != 8);

    return 0;
}
