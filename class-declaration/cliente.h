#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente
{
private:
    std::string dni;
    std::string nombre;
    int anioIngreso;
    std::string estado;

public:
    Cliente(std::string dni, std::string nombre, int anioIngreso, std::string estado);
    virtual ~Cliente() = default;

    std::string getDni() const;
    std::string getNombre() const;
    virtual std::string getTipoCliente() const = 0;
    int getAnioIngreso() const;
    std::string getEstado() const;
    void setEstado(std::string estado);

};
#endif

