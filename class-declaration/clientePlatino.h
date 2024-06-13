#ifndef CLIENTEPLATINO_H
#define CLIENTEPLATINO_H

#include "cliente.h"

class ClientePlatino : public Cliente
{
public:
    ClientePlatino(std::string dni, std::string nombre, int anioIngreso, std::string estado)
        : Cliente(dni, nombre, anioIngreso, estado) {}
    std::string getTipoCliente() const { return "Platino"; }

    void getTarjeta() override
    {
        tarjeta = new TarjetaDeCredito("Premium", 500000);
    }
};

#endif
