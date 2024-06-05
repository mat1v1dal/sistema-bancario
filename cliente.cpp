#include "./class-declaration/cliente.h"
#include <iostream>

Cliente::Cliente(std::string dni, std::string nombre, int anioIngreso, std::string estado)
    : dni(dni), nombre(nombre), anioIngreso(anioIngreso), estado(estado) {}

std::string Cliente::getDni() const { return dni; }
std::string Cliente::getNombre() const { return nombre; }
int Cliente::getAnioIngreso() const { return anioIngreso; }
std::string Cliente::getEstado() const { return estado; }
void Cliente::setEstado(std::string estado) { this->estado = estado; }
