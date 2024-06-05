#include "./class-declaration/banco.h"
#include <stdexcept>
#include <algorithm>

Banco *Banco::instancia = nullptr;

Banco *Banco::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new Banco();
    }
    return instancia;
}

void Banco::agregarCliente(Cliente *cliente)
{
    clientes.push_back(cliente);
}

void Banco::eliminarCliente(const std::string &dni)
{
    for (Cliente *cliente : clientes)
    {
        if (cliente->getDni() == dni)
        {
            cliente->setEstado("BAJA");
            return;
        }
    }
    throw std::runtime_error("Cliente no encontrado");
}

Cliente *Banco::obtenerCliente(const std::string &dni) const
{
    for (Cliente *cliente : clientes)
    {
        if (cliente->getDni() == dni)
        {
            return cliente;
        }
    }
    throw std::runtime_error("Cliente no encontrado");
}
std::vector<Cliente *> Banco::obtenerTodosLosClientes() const
{
    return clientes;
}

void Banco::registrarTransaccion(const Transaccion &transaccion)
{
    transacciones.push_back(transaccion);
    for (auto &cuenta : cuentas)
    {
        if (cuenta.getDniCliente() == transaccion.getDniCliente())
        {
            if (transaccion.getMoneda() == "Pesos")
            {
                if (transaccion.getTipoTransaccion() == "Deposito")
                {
                    cuenta.depositarPesos(transaccion.getMonto());
                }
                else if (transaccion.getTipoTransaccion() == "Extraccion")
                {
                    cuenta.extraerPesos(transaccion.getMonto());
                }
            }
            else if (transaccion.getMoneda() == "Dolares")
            {
                if (transaccion.getTipoTransaccion() == "Deposito")
                {
                    cuenta.depositarDolares(transaccion.getMonto());
                }
                else if (transaccion.getTipoTransaccion() == "Extraccion")
                {
                    cuenta.extraerDolares(transaccion.getMonto());
                }
            }
            return;
        }
    }
    throw std::runtime_error("Cuenta no encontrada para la transacción");
}

std::vector<Transaccion> Banco::obtenerTransaccionesPorCliente(const std::string &dni) const
{
    std::vector<Transaccion> resultado;
    for (const auto &transaccion : transacciones)
    {
        if (transaccion.getDniCliente() == dni)
        {
            resultado.push_back(transaccion);
        }
    }
    return resultado;
}

std::vector<Transaccion> Banco::obtenerTransaccionesPorMes(int mes, int anio) const
{
    std::vector<Transaccion> resultado;
    for (const auto &transaccion : transacciones)
    {
        int transMes = std::stoi(transaccion.getFecha().substr(5, 2));
        int transAnio = std::stoi(transaccion.getFecha().substr(0, 4));
        if (transMes == mes && transAnio == anio)
        {
            resultado.push_back(transaccion);
        }
    }
    return resultado;
}

std::vector<Transaccion> Banco::obtenerTransaccionesPorAnio(int anio) const
{
    std::vector<Transaccion> resultado;
    for (const auto &transaccion : transacciones)
    {
        int transAnio = std::stoi(transaccion.getFecha().substr(0, 4));
        if (transAnio == anio)
        {
            resultado.push_back(transaccion);
        }
    }
    return resultado;
}

std::vector<Transaccion> Banco::obtenerTodasLasTransacciones() const
{
    return transacciones;
}

Banco::~Banco()
{
    for (auto cliente : clientes)
    {
        delete cliente;
    }
}
