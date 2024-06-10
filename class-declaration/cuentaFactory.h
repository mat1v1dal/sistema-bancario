#ifndef CUENTAFACTORY_H
#define CUENTAFACTORY_H

#include "cuenta.h"
#include <stdexcept>

class CuentaFactory
{
public:
    static Cuenta *crearCuenta(std::string dniCliente, double saldo = 0, std::string tipo = "")
    {
        if (tipo == "pesos")
        {
            return new Cuenta(dniCliente, saldo, "pesos");
        }
        else if (tipo == "dolares")
        {
            return new Cuenta(dniCliente, saldo, "dolares");
        }
        else
        {
            throw std::invalid_argument("Tipo de cuenta no válido");
        }
    }
};

#endif // CUENTAFACTORY_H
