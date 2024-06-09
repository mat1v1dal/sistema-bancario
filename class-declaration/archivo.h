#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "banco.h"
#include "clienteFactory.h"
#include "transaccionFactory.h"
#include <fstream>
#include <sstream>
#include <string>
#include "cuentaFactory.h"
void cargarDatosDesdeArchivos(Banco *banco);
void guardarDatosEnArchivos(Banco *banco);

#endif // ARCHIVO_H
