#ifndef TRANSACCIONFACTORY_H
#define TRANSACCIONFACTORY_H

#include "transaccion.h"
#include <stdexcept>

class TransaccionFactory
{
public:
    static Transaccion crearTransaccion(const std::string &dniCliente, const std::string &tipoTransaccion, double monto, const std::string &moneda, const std::string &fecha)
    {
        if (tipoTransaccion == "Depósito" || tipoTransaccion == "Extracción")
        {
            return Transaccion(dniCliente, tipoTransaccion, monto, moneda, fecha);
        }
        else
        {
            throw std::invalid_argument("Tipo de transacción no válido");
        }
    }
};

#endif // TRANSACCIONFACTORY_H
