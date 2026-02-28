#include <stdio.h>
#include "hal_estacion.h"


static bool estadoEstacion = true; 

bool HAL_Estacion_Leer_estado(void) {
    
    return estadoEstacion;
}

