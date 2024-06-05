#ifndef CLIENTEFACTORY_H
#define CLIENTEFACTORY_H

#include "Cliente.h"
#include <stdexcept>

class ClienteFactory
{
public:
    static Cliente crearCliente(const std::string &tipoCliente, const std::string &dni, const std::string &nombre, int anioIngreso)
    {
        if (tipoCliente == "Plata")
        {
            return Cliente(dni, nombre, "Plata", anioIngreso, "ACTIVO");
        }
        else if (tipoCliente == "Oro")
        {
            return Cliente(dni, nombre, "Oro", anioIngreso, "ACTIVO");
        }
        else if (tipoCliente == "Platino")
        {
            return Cliente(dni, nombre, "Platino", anioIngreso, "ACTIVO");
        }
        else
        {
            throw std::invalid_argument("Tipo de cliente no válido");
        }
    }
};

#endif // CLIENTEFACTORY_H
