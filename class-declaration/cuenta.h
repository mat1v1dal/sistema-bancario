#ifndef CUENTA_H
#define CUENTA_H
#include <string>
class Cuenta
{
private:
    double saldo;
    std::string dniCliente;
    std::string tipo;

public:
    Cuenta(std::string dniCliente, double saldo = 0, std::string tipo = "");
    std::string getDniCliente() const;
    double getSaldo() const;
    std::string getTipo() const;
    void depositar(double monto);
    void extraer(double monto);
};

#endif // CUENTA_H
