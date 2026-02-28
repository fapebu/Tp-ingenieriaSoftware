#ifndef GESTOR_MOVIMIENTO_H
#define GESTOR_MOVIMIENTO_H

#include "estacion.h"
#include "motor.h"
#include "brazo.h"

typedef enum { 
    RESULTADO_EXITO, 
    ERROR_OCUPADO, 
    ERROR_MOTOR_ANDANDO, 
    ERROR_BRAZO_DESPLEGADO 
} ResultadoOperacion;


void Gestor_init(Estacion* e, Motor* m, Brazo* b);
ResultadoOperacion Gestor_ProcesarOrden(int id_destino);

#endif