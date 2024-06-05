#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente
{
private:
    std::string dni;
    std::string nombre;
    std::string tipoCliente;
    int anioIngreso;
    std::string estado;

public:
    Cliente(std::string dni, std::string nombre, std::string tipoCliente, int anioIngreso, std::string estado);
    std::string getDni() const;
    std::string getNombre() const;
    std::string getTipoCliente() const;
    int getAnioIngreso() const;
    std::string getEstado() const;
    void setEstado(std::string estado);
    void mostrarInformacion() const;
};

#endif // CLIENTE_H
