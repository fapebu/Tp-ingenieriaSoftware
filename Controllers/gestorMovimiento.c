#include <stdio.h>
#include "gestorMovimiento.h"
#include "hal_motor.h"
#include "hal_brazo.h"
#include "hal_estacion.h"

static Estacion* p_estacion = NULL;
static Motor* p_motor = NULL;
static Brazo* p_brazo = NULL;

void Gestor_init(Estacion* e, Motor* m, Brazo* b) {
    p_estacion = e;
    p_motor = m;
    p_brazo = b;
}


static void ActualizarSensores(void) {
    bool brazo_fisico = HAL_Brazo_Leer_estado();
    Brazo_setEstado(p_brazo, brazo_fisico); 
    
    bool motor_girando = HAL_Motor_ConfirmarEstado();
    Motor_setEncendido(p_motor, motor_girando);

    bool estadoEstacion = HAL_Estacion_Leer_estado();
    Estacion_setOcupada(p_estacion, estadoEstacion);
}


ResultadoOperacion Gestor_ProcesarOrden(int id_destino) {
    ActualizarSensores();
    
    if (!Estacion_isLibre(p_estacion)) return ERROR_OCUPADO;
    if (!Motor_isParado(p_motor)) return ERROR_MOTOR_ANDANDO;
    if (!Brazo_isGuardado(p_brazo)) return ERROR_BRAZO_DESPLEGADO;
    
    Estacion_setDestino(p_estacion, id_destino);
    HAL_Motor_IniciarMarcha();
    Motor_setEncendido(p_motor, true); 

    return RESULTADO_EXITO;
}