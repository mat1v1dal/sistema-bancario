#include "./class-declaration/cuenta.h"
#include <stdexcept>

Cuenta::Cuenta(std::string dniCliente, double saldo, std::string tipo)
    : dniCliente(dniCliente), saldo(saldo), tipo(tipo) {}

std::string Cuenta::getDniCliente() const { return dniCliente; }
double Cuenta::getSaldo() const { return saldo; }
std::string Cuenta::getTipo() const { return tipo; }

void Cuenta::depositar(double monto)
{
    saldo += monto;
}

void Cuenta::extraer(double monto)
{
    if (monto > saldo)
    {
        throw std::runtime_error("Saldo insuficiente");
    }
    saldo -= monto;
}