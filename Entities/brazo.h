#ifndef BRAZO_H
#define BRAZO_H

#include <stdbool.h>


typedef struct {
    bool guardado; 
} Brazo;


void Brazo_init(Brazo* self);

void Brazo_setEstado(Brazo* self, bool guardado);

bool Brazo_isGuardado(Brazo* self);

#endif