#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "banco.h"
#include "clienteFactory.h"
#include "transaccionFactory.h"
void cargarDatosDesdeArchivos(Banco *banco);
void guardarDatosEnArchivos(Banco *banco);

#endif // ARCHIVO_H
