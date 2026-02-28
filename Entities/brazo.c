#include "brazo.h" 


void Brazo_init(Brazo* self) {
    self->guardado = true; 
}

bool Brazo_isGuardado(Brazo* self) {
    return self->guardado;
}

void Brazo_setEstado(Brazo* self, bool guardado) {
    self->guardado = guardado;
}