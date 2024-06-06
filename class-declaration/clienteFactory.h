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
        if (tipoCliente == "Plata")
        {
            return new ClientePlata(dni, nombre, anioIngreso, "ACTIVO");
        }
        else if (tipoCliente == "Oro")
        {
            return new ClienteOro(dni, nombre, anioIngreso, "ACTIVO");
        }
        else if (tipoCliente == "Platino")
        {
            return new ClientePlatino(dni, nombre, anioIngreso, "ACTIVO");
        }
        else
        {
            throw std::invalid_argument("Tipo de cliente no valido");
        }
    }
};

#endif
