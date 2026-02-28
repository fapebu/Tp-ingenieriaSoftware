#include <stdio.h>
#include "hal_brazo.h"


static bool estadoBrazo = true; 

bool HAL_Brazo_Leer_estado(void) {
    
    return estadoBrazo;
}


void HAL_Brazo_SimularHardware(bool estado_fisico) {
    estadoBrazo = estado_fisico;
    
}