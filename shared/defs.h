#ifndef DEFS_H
#define DEFS_H

typedef enum {
    RESULTADO_EXITO = 0,
    ERROR_OCUPADO,
    ERROR_MOTOR_ANDANDO,
    ERROR_BRAZO_DESPLEGADO,
    ERROR_FALLO_HARDWARE
} ResultadoOperacion;
#endif