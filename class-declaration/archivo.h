#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "banco.h"
#include <fstream>
#include <sstream>

void cargarDatosDesdeArchivos(Banco *banco)
{
    // Leer clientes
    std::ifstream archivoClientes("clientes.txt");
    if (archivoClientes.is_open())
    {
        std::string linea;
        while (getline(archivoClientes, linea))
        {
            std::stringstream ss(linea);
            std::string dni, nombre, tipoCliente, estado, anioIngresoStr;
            getline(ss, dni, ',');
            getline(ss, nombre, ',');
            getline(ss, tipoCliente, ',');
            getline(ss, anioIngresoStr, ',');
            getline(ss, estado, ',');
            int anioIngreso = std::stoi(anioIngresoStr);
            Cliente cliente(dni, nombre, tipoCliente, anioIngreso, estado);
            banco->agregarCliente(cliente);
        }
        archivoClientes.close();
    }

    // Leer cuentas
    std::ifstream archivoCuentas("cuentas.txt");
    if (archivoCuentas.is_open())
    {
        std::string linea;
        while (getline(archivoCuentas, linea))
        {
            std::stringstream ss(linea);
            std::string dniCliente, saldoPesosStr, saldoDolaresStr;
            getline(ss, dniCliente, ',');
            getline(ss, saldoPesosStr, ',');
            getline(ss, saldoDolaresStr, ',');
            double saldoPesos = std::stod(saldoPesosStr);
            double saldoDolares = std::stod(saldoDolaresStr);
            Cuenta cuenta(dniCliente, saldoPesos, saldoDolares);
            banco->agregarCuenta(cuenta);
        }
        archivoCuentas.close();
    }

    // Leer transacciones
    std::ifstream archivoTransacciones("transacciones.txt");
    if (archivoTransacciones.is_open())
    {
        std::string linea;
        while (getline(archivoTransacciones, linea))
        {
            std::stringstream ss(linea);
            std::string dniCliente, tipoTransaccion, montoStr, moneda, fecha;
            getline(ss, dniCliente, ',');
            getline(ss, tipoTransaccion, ',');
            getline(ss, montoStr, ',');
            getline(ss, moneda, ',');
            getline(ss, fecha, ',');
            double monto = std::stod(montoStr);
            Transaccion transaccion(dniCliente, tipoTransaccion, monto, moneda, fecha);
            banco->registrarTransaccion(transaccion);
        }
        archivoTransacciones.close();
    }
}

void guardarDatosEnArchivos(Banco *banco)
{
    // Guardar clientes
    std::ofstream archivoClientes("clientes.txt");
    for (const auto &cliente : banco->obtenerTodosLosClientes())
    {
        archivoClientes << cliente.getDni() << "," << cliente.getNombre() << ","
                        << cliente.getTipoCliente() << "," << cliente.getAnioIngreso()
                        << "," << cliente.getEstado() << std::endl;
    }
    archivoClientes.close();

    // Guardar cuentas
    std::ofstream archivoCuentas("cuentas.txt");
    for (const auto &cuenta : banco->obtenerTodasLasCuentas())
    {
        archivoCuentas << cuenta.getDniCliente() << "," << cuenta.getSaldoPesos() << ","
                       << cuenta.getSaldoDolares() << std::endl;
    }
    archivoCuentas.close();

    // Guardar transacciones
    std::ofstream archivoTransacciones("transacciones.txt");
    for (const auto &transaccion : banco->obtenerTodasLasTransacciones())
    {
        archivoTransacciones << transaccion.getDniCliente() << "," << transaccion.getTipoTransaccion()
                             << "," << transaccion.getMonto() << "," << transaccion.getMoneda()
                             << "," << transaccion.getFecha() << std::endl;
    }
    archivoTransacciones.close();
}

#endif
