#ifndef CLIENTEPLATINO_H
#define CLIENTEPLATINO_H

#include "Cliente.h"

class ClientePlatino : public Cliente
{
public:
    ClientePlatino(std::string dni, std::string nombre, int anioIngreso, std::string estado)
        : Cliente(dni, nombre, anioIngreso, estado) {}
    std::string getTipoCliente() const { return "Platino"; }
};

#endif
