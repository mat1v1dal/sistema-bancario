#ifndef CUENTA_H
#define CUENTA_H

#include <string>

class Cuenta
{
private:
    std::string dniCliente;
    double saldoPesos;
    double saldoDolares;

public:
    Cuenta(std::string dniCliente, double saldoPesos = 0, double saldoDolares = 0);
    std::string getDniCliente() const;
    double getSaldoPesos() const;
    double getSaldoDolares() const;
    void depositarPesos(double monto);
    void extraerPesos(double monto);
    void depositarDolares(double monto);
    void extraerDolares(double monto);
};

#endif // CUENTA_H
