#ifndef CLIENTEFACTORY_H
#define CLIENTEFACTORY_H

#include "cliente.h"
#include "clienteOro.h"
#include "clientePlata.h"
#include "clientePlatino.h"
#include <stdexcept>

class ClienteFactory
{
public:
    static Cliente *crearCliente(const std::string &tipoCliente, const std::string &dni, const std::string &nombre, int anioIngreso)
    {
        if (tipoCliente == "Plata" || tipoCliente == "plata")
        {
            return new ClientePlata(dni, nombre, anioIngreso, "ACTIVO");
        }
        else if (tipoCliente == "Oro" || tipoCliente == "oro")
        {
            return new ClienteOro(dni, nombre, anioIngreso, "ACTIVO");
        }
        else if (tipoCliente == "Platino" || tipoCliente == "platino")
        {
            return new ClientePlatino(dni, nombre, anioIngreso, "ACTIVO");
        }
        else
        {
            throw std::runtime_error("Tipo de cliente no valido");
        }
    }
};

#endif
