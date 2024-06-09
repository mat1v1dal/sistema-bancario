#include "./class-declaration/cuenta.h"
#include <stdexcept>

Cuenta::Cuenta(std::string dniCliente, double monto, std::string moneda)
    : dniCliente(dniCliente), saldo(monto), tipo(moneda) {}

std::string Cuenta::getDniCliente() const { return dniCliente; }
double Cuenta::getSaldo() const { return saldo; }
std::string Cuenta::getTipo() const { return tipo; }
void Cuenta::depositar(double monto)
{
    if (monto > 0)
    {
        saldo += monto;
    }
    else
    {
        throw std::runtime_error("El monto a depositar debe ser mayor a 0.");
    }
}

void Cuenta::extraer(double monto)
{
    if (saldo >= monto)
    {
        saldo -= monto;
    }
    else
    {
        throw std::runtime_error("Saldo insuficiente en pesos.");
    }
}