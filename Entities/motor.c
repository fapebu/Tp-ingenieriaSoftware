#include "motor.h"

void Motor_init(Motor* self) {
    self->encendido = false; 
}


bool Motor_isParado(Motor* self) {
    return !self->encendido;
}


void Motor_setEncendido(Motor* self, bool estado) {
    self->encendido = estado;
}