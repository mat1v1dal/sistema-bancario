#include "./class-declaration/cliente.h"
#include <iostream>

Cliente::Cliente(std::string dni, std::string nombre, std::string tipoCliente, int anioIngreso, std::string estado)
    : dni(dni), nombre(nombre), tipoCliente(tipoCliente), anioIngreso(anioIngreso), estado(estado) {}

std::string Cliente::getDni() const { return dni; }
std::string Cliente::getNombre() const { return nombre; }
std::string Cliente::getTipoCliente() const { return tipoCliente; }
int Cliente::getAnioIngreso() const { return anioIngreso; }
std::string Cliente::getEstado() const { return estado; }
void Cliente::setEstado(std::string estado) { this->estado = estado; }

void Cliente::mostrarInformacion() const
{
    std::cout << "DNI: " << dni << ", Nombre: " << nombre << ", Tipo de Cliente: " << tipoCliente
              << ", Año de Ingreso: " << anioIngreso << ", Estado: " << estado << std::endl;
}
