#include <string>
// Path: class-declaration/credito.h
#ifndef TARJETADECREDITO_H
#define TARJETADECREDITO_H

class TarjetaDeCredito
{
private:
    std::string nombre;
    double limiteCredito;

public:
    TarjetaDeCredito(const std::string &nombre, double limiteCredito)
        : nombre(nombre), limiteCredito(limiteCredito) {}

    std::string getNombre() const { return nombre; }
    double getLimiteCredito() const { return limiteCredito; }
};
#endif
