#ifndef CLIENTEORO_H
#define CLIENTEORO_H

#include "cliente.h"

class ClienteOro : public Cliente
{
public:
    ClienteOro(std::string dni, std::string nombre, int anioIngreso, std::string estado)
        : Cliente(dni, nombre, anioIngreso, estado) {}
    std::string getTipoCliente() const { return "Oro"; }

    void getTarjetaDeCredito() override
    {
        tarjetas.push_back(new TarjetaDeCredito("Credix", 250000));
    }
};

#endif
