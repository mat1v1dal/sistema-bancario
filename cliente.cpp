#include "./class-declaration/cliente.h"
#include <iostream>

Cliente::Cliente(const std::string &dni, const std::string &nombre, int anioIngreso, const std::string &estado)
    : dni(dni), nombre(nombre), anioIngreso(anioIngreso), estado(estado) {}

std::string Cliente::getDni() const { return dni; }
std::string Cliente::getNombre() const { return nombre; }
int Cliente::getAnioIngreso() const { return anioIngreso; }
std::string Cliente::getEstado() const { return estado; }
void Cliente::setEstado(const std::string &estado) { this->estado = estado; }

void Cliente::agregarCuenta(Cuenta *cuenta)
{
    if (cuenta->getTipo() == "pesos")
    {
        cuentasPesos.push_back(cuenta);
    }
    else
    {
        cuentasDolares.push_back(cuenta);
    }
}

std::vector<Cuenta *> Cliente::getCuentasPesos() const { return cuentasPesos; }
std::vector<Cuenta *> Cliente::getCuentasDolares() const { return cuentasDolares; }