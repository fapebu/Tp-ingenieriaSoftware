#include "estacion.h"


void Estacion_init(Estacion* self) {
    self->id_destino = 0;
    self->ocupada = false;
}

bool Estacion_isLibre(Estacion* self) {
    return !self->ocupada; //si esta ocupada devuelve false, si esta libre devuelve true.
}

void Estacion_setDestino(Estacion* self, int id) {
    self->id_destino = id;
}

void Estacion_setOcupada(Estacion* self, bool estado) {
    self->ocupada = estado;
}