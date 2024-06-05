#include "./class-declaration/transaccion.h"

Transaccion::Transaccion(std::string dniCliente, std::string tipoTransaccion, double monto, std::string moneda, std::string fecha)
    : dniCliente(dniCliente), tipoTransaccion(tipoTransaccion), monto(monto), moneda(moneda), fecha(fecha) {}

std::string Transaccion::getDniCliente() const { return dniCliente; }
std::string Transaccion::getTipoTransaccion() const { return tipoTransaccion; }
double Transaccion::getMonto() const { return monto; }
std::string Transaccion::getMoneda() const { return moneda; }
std::string Transaccion::getFecha() const { return fecha; }
