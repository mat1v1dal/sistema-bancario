#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "cuentaFactory.h"

class Cliente
{
private:
    std::string dni;
    std::string nombre;
    int anioIngreso;
    std::vector<Cuenta> cuentasPesos;
    std::vector<Cuenta> cuentasDolares;
    std::string estado;

public:
    Cliente(std::string dni, std::string nombre, int anioIngreso, std::string estado);
    virtual ~Cliente() = default;

    std::string getDni() const;
    std::string getNombre() const;
    std::vector<Cuenta> getCuentasPesos() const;
    std::vector<Cuenta> getCuentasDolares() const;
    virtual std::string getTipoCliente() const = 0;
    void agregarCuenta(Cuenta cuenta);
    int getAnioIngreso() const;
    std::string getEstado() const;
    void setEstado(std::string estado);
};
#endif
