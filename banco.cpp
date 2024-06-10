#include "./class-declaration/banco.h"
#include <stdexcept>
#include <vector>
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
    for (Cliente *c : clientes)
    {
        if (c->getDni() == cliente->getDni())
        {
            throw std::runtime_error("Cliente ya existe");
        }
    }
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

void Banco::cargarTransacciones(const Transaccion &transaccion)
{
    transacciones.push_back(transaccion);
}

void Banco::registrarTransaccion(const Transaccion &transaccion, int nroCuenta)
{
    // Encuentra el cliente
    Cliente *cliente = nullptr;
    for (Cliente *c : clientes)
    {
        if (c->getDni() == transaccion.getDniCliente())
        {
            cliente = c;
            break;
        }
    }

    if (cliente == nullptr)
    {
        throw std::runtime_error("Cliente no encontrado para la transacción");
    }

    // Encuentra la cuenta del cliente
    std::vector<Cuenta *> cuentaPesos = cliente->getCuentasPesos();
    std::vector<Cuenta *> cuentaDolares = cliente->getCuentasDolares();

    if (transaccion.getMoneda() == "pesos")
    {
        if (cuentaPesos.empty())
        {
            throw std::runtime_error("No hay cuenta en pesos para este cliente");
        }
        if (transaccion.getTipoTransaccion() == "deposito")
        {
            cuentaPesos[0]->depositar(transaccion.getMonto());
        }
        else if (transaccion.getTipoTransaccion() == "extraccion")
        {
            cuentaPesos[0]->extraer(transaccion.getMonto());
        }
    }
    else if (transaccion.getMoneda() == "dolares")
    {
        if (cuentaDolares.empty())
        {
            throw std::runtime_error("No hay cuenta en dólares para este cliente");
        }
        if (transaccion.getTipoTransaccion() == "deposito")
        {
            cuentaDolares[0]->depositar(transaccion.getMonto());
        }
        else if (transaccion.getTipoTransaccion() == "extraccion")
        {
            cuentaDolares[0]->extraer(transaccion.getMonto());
        }
    }

    // Registra la transacción
    transacciones.push_back(transaccion);
}

std::vector<Transaccion> Banco::obtenerTransaccionesPorCliente(const std::string &dni) const
{
    std::vector<Transaccion> resultado;
    for (const Transaccion &t : transacciones)
    {
        if (t.getDniCliente() == dni)
        {
            resultado.push_back(t);
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
