#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion
{
private:
    std::string dniCliente;
    std::string tipoTransaccion; 
    double monto;
    std::string moneda; // Pesos o Dolares
    std::string fecha;

public:
    Transaccion(std::string dniCliente, std::string tipoTransaccion, double monto, std::string moneda, std::string fecha);
    std::string getDniCliente() const;
    std::string getTipoTransaccion() const;
    double getMonto() const;
    std::string getMoneda() const;
    std::string getFecha() const;
};

#endif // TRANSACCION_H
