#ifndef MOTOR_H
#define MOTOR_H

#include <stdbool.h>


typedef struct {
    bool encendido;
} Motor;


void Motor_init(Motor* self);
bool Motor_isParado(Motor* self);
void Motor_setEncendido(Motor* self, bool estado);

#endif