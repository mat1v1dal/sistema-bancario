#include "./class-declaration/transaccion.h"

Transaccion::Transaccion(const std::string &dniCliente, const std::string &tipoTransaccion, double monto, const std::string &moneda, const std::string &fecha)
{
    if (tipoTransaccion != "deposito" && tipoTransaccion != "extraccion")
    {
        throw std::invalid_argument("Tipo de transaccion no valido");
    }

    if (moneda != "pesos" && moneda != "dolares")
    {
        throw std::invalid_argument("Moneda no valida");
    }

    if (monto <= 0)
    {
        throw std::invalid_argument("Monto debe ser mayor a cero");
    }

    // Validación de fecha en formato YYYY-MM-DD
    if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-')
    {
        throw std::invalid_argument("Fecha no tiene el formato correcto (YYYY-MM-DD)");
    }

    this->dniCliente = dniCliente;
    this->tipoTransaccion = tipoTransaccion;
    this->monto = monto;
    this->moneda = moneda;
    this->fecha = fecha;
}
