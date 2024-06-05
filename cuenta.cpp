#include "./class-declaration/cuenta.h"
#include <stdexcept>

Cuenta::Cuenta(std::string dniCliente, double saldoPesos, double saldoDolares)
    : dniCliente(dniCliente), saldoPesos(saldoPesos), saldoDolares(saldoDolares) {}

std::string Cuenta::getDniCliente() const { return dniCliente; }
double Cuenta::getSaldoPesos() const { return saldoPesos; }
double Cuenta::getSaldoDolares() const { return saldoDolares; }

void Cuenta::depositarPesos(double monto)
{
    saldoPesos += monto;
}

void Cuenta::extraerPesos(double monto)
{
    if (saldoPesos >= monto)
    {
        saldoPesos -= monto;
    }
    else
    {
        throw std::runtime_error("Saldo insuficiente en pesos.");
    }
}

void Cuenta::depositarDolares(double monto)
{
    saldoDolares += monto;
}

void Cuenta::extraerDolares(double monto)
{
    if (saldoDolares >= monto)
    {
        saldoDolares -= monto;
    }
    else
    {
        throw std::runtime_error("Saldo insuficiente en dolares.");
    }
}
