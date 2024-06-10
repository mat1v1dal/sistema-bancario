#ifndef TRANSACCIONFACTORY_H
#define TRANSACCIONFACTORY_H

#include "transaccion.h"

class TransaccionFactory
{
public:
    static Transaccion crearTransaccion(const std::string &dniCliente, const std::string &tipoTransaccion, double monto, const std::string &moneda, const std::string &fecha)
    {
        return Transaccion(dniCliente, tipoTransaccion, monto, moneda, fecha);
    }
};

#endif // TRANSACCIONFACTORY_H