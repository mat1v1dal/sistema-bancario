#ifndef BANCO_H
#define BANCO_H

#include "cliente.h"
#include "cuenta.h"
#include "transaccion.h"
#include <vector>
#include <string>

class Banco
{
private:
    static Banco *instancia;
    std::vector<Cliente *> clientes;
    std::vector<Cuenta> cuentas;
    std::vector<Transaccion> transacciones;

    Banco() {}

public:
    // Método estático para obtener la instancia única
    static Banco *getInstancia();

    // Métodos para gestionar clientes, cuentas y transacciones
    void agregarCliente(Cliente *cliente);
    void agregarCuenta(const Cuenta &cuenta);
    void eliminarCliente(const std::string &dni);
    Cliente *obtenerCliente(const std::string &dni) const;
    void registrarTransaccion(const Transaccion &transaccion, int nroCuenta);
    void cargarTransacciones(const Transaccion &transaccion);

    // Métodos para consultas
    std::vector<Cliente *> obtenerTodosLosClientes() const;
    std::vector<Cuenta> obtenerTodasLasCuentas() const;
    std::vector<Transaccion> obtenerTransaccionesPorCliente(const std::string &dni) const;
    std::vector<Transaccion> obtenerTransaccionesPorMes(int mes, int anio) const;
    std::vector<Transaccion> obtenerTransaccionesPorAnio(int anio) const;
    std::vector<Transaccion> obtenerTodasLasTransacciones() const;

    void solicitarTarjetaDeCredito(const std::string &dniCliente)
    {
        for (Cliente *cliente : clientes)
        {
            if (cliente->getDni() == dniCliente)
            {
                cliente->getTarjeta();
                return;
            }
        }
        throw std::runtime_error("Cliente no encontrado");
    }

    ~Banco();
};

#endif // BANCO_H
