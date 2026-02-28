#ifndef HAL_MOTOR_H
#define HAL_MOTOR_H

#include <stdbool.h>

void HAL_Motor_IniciarMarcha(void);
void HAL_Motor_Detener(void);
bool HAL_Motor_ConfirmarEstado(void); // Retorna estado del motor

#endif