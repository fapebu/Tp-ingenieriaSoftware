#ifndef HAL_BRAZO_H
#define HAL_BRAZO_H

#include <stdbool.h>

bool HAL_Brazo_Leer_estado(void);

void HAL_Brazo_SimularHardware(bool estado_fisico);

#endif