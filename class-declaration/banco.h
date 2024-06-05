#ifndef BANCO_H
#define BANCO_H

#include "Cliente.h"
#include "Cuenta.h"
#include "Transaccion.h"
#include <vector>
#include <string>

class Banco
{
private:
    static Banco *instancia;
    std::vector<Cliente> clientes;
    std::vector<Cuenta> cuentas;
    std::vector<Transaccion> transacciones;

    // Constructor privado para evitar la creación directa
    Banco() {}

public:
    // Método estático para obtener la instancia única
    static Banco *getInstancia();

    // Métodos para gestionar clientes, cuentas y transacciones
    void agregarCliente(const Cliente &cliente);
    void eliminarCliente(const std::string &dni);
    Cliente obtenerCliente(const std::string &dni) const;
    void registrarTransaccion(const Transaccion &transaccion);

    // Métodos para consultas
    std::vector<Cliente> obtenerTodosLosClientes() const;
    std::vector<Transaccion> obtenerTransaccionesPorCliente(const std::string &dni) const;
    std::vector<Transaccion> obtenerTransaccionesPorMes(int mes, int anio) const;
    std::vector<Transaccion> obtenerTransaccionesPorAnio(int anio) const;
    std::vector<Transaccion> obtenerTodasLasTransacciones() const;
};

#endif // BANCO_H
