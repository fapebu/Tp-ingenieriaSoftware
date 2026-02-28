#ifndef ESTACION_H
#define ESTACION_H

#include <stdbool.h>


typedef struct {
    int id_destino;
    bool ocupada;
} Estacion;


void Estacion_init(Estacion* self);
bool Estacion_isLibre(Estacion* self);
void Estacion_setDestino(Estacion* self, int id);
void Estacion_setOcupada(Estacion* self, bool estado);
#endif