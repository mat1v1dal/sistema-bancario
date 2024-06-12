#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "cuenta.h"
#include "credito.h"

class Cliente
{
public:
    Cliente(const std::string &dni, const std::string &nombre, int anioIngreso, const std::string &estado);
    std::string getDni() const;
    std::string getNombre() const;
    int getAnioIngreso() const;
    std::string getEstado() const;
    void setEstado(const std::string &estado);
    void agregarCuenta(Cuenta *cuenta);
    virtual void getTarjeta() = 0;
    TarjetaDeCredito *returnTarjeta() const { return tarjeta; }
    std::vector<Cuenta *>
    getCuentasPesos() const;
    std::vector<Cuenta *> getCuentasDolares() const;
    virtual std::string getTipoCliente() const = 0;
    ~Cliente()
    {
        for (auto cuenta : cuentasPesos)
        {
            delete cuenta;
        }
        for (auto cuenta : cuentasDolares)
        {
            delete cuenta;
        }
        delete tarjeta;
    }

private:
    std::string dni;
    std::string nombre;
    int anioIngreso;
    std::string estado;
    std::vector<Cuenta *> cuentasPesos;
    std::vector<Cuenta *> cuentasDolares;

protected:
    TarjetaDeCredito *tarjeta = nullptr;
};

#endif // CLIENTE_H