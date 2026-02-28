#ifndef INTERFAZ_SUPERVISION_H
#define INTERFAZ_SUPERVISION_H
#include "defs.h"

void Interfaz_EnviarACK(void);
void Interfaz_EnviarNACK(ResultadoOperacion error);
void Interfaz_RecibirComando(int destino);
#endif