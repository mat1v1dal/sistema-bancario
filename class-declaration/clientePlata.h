#ifndef CLIENTEPLATA_H
#define CLIENTEPLATA_H

#include "Cliente.h"

class ClientePlata : public Cliente
{
public:
    ClientePlata(std::string dni, std::string nombre, int anioIngreso, std::string estado)
        : Cliente(dni, nombre, anioIngreso, estado) {}
    std::string getTipoCliente() const { return "Plata"; }
};

#endif
