#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include <stdexcept>

class Transaccion
{
private:
    std::string dniCliente;
    std::string tipoTransaccion;
    double monto;
    std::string moneda;
    std::string fecha;

public:
    Transaccion(const std::string &dniCliente, const std::string &tipoTransaccion, double monto, const std::string &moneda, const std::string &fecha);

    std::string getDniCliente() const { return dniCliente; }
    std::string getTipoTransaccion() const { return tipoTransaccion; }
    double getMonto() const { return monto; }
    std::string getMoneda() const { return moneda; }
    std::string getFecha() const { return fecha; }
};

#endif // TRANSACCION_H