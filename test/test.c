#include "unity.h"
#include "gestorMovimiento.h"
#include "estacion.h"
#include "motor.h"
#include "brazo.h"
#include <stdbool.h>

//Instancias de entidades
Estacion est; 
Motor mot;
Brazo brz;

//Mocks Hardware
bool motor_fue_iniciado_mock = false;
static bool mock_estado_brazo = true;
static bool mock_estado_motor = false;
static bool mock_estado_estacion = false;

//Funciones HAL para pruebas
void HAL_Motor_IniciarMarcha(void) { motor_fue_iniciado_mock = true; }
bool HAL_Brazo_Leer_estado(void) { return mock_estado_brazo; }
bool HAL_Motor_ConfirmarEstado(void) { return mock_estado_motor; }
bool HAL_Estacion_Leer_estado(void) { return mock_estado_estacion; }


void setUp(void) {  
    Estacion_init(&est);
    Motor_init(&mot);
    Brazo_init(&brz);
    
    
    Gestor_init(&est, &mot, &brz);
    
    motor_fue_iniciado_mock = false;
    mock_estado_brazo = true;      // Brazo guardado
    mock_estado_motor = false;     // Motor detenido
    mock_estado_estacion = false;  // Estación libre
}

void tearDown(void) {} //funciones post-test



// CP-1: Camino Feliz - Exito
void test_CP1_ValidacionExitosa(void) {
    int destino_solicitado = 10;

    ResultadoOperacion res = Gestor_ProcesarOrden(destino_solicitado);
    
    TEST_ASSERT_EQUAL(RESULTADO_EXITO, res);
    TEST_ASSERT_TRUE(motor_fue_iniciado_mock);
    TEST_ASSERT_EQUAL(destino_solicitado, est.id_destino);
}

// CP-2: Rechazo por Estacion Ocupada
void test_CP2_RechazoPorEstacionOcupada(void) {
   
    mock_estado_estacion = true; //estacion ocupada
    Estacion_setDestino(&est, 5); // Destino previo

    
    ResultadoOperacion res = Gestor_ProcesarOrden(12);
    
    TEST_ASSERT_EQUAL(ERROR_OCUPADO, res);
    TEST_ASSERT_EQUAL(5, est.id_destino); // El destino nuevo no se escribe
    TEST_ASSERT_FALSE(motor_fue_iniciado_mock); // El motor no arranco
}

// CP-3: Rechazo por Vehiculo en Movimiento
void test_CP3_RechazoPorVehiculoEnMovimiento(void) {
   
    mock_estado_motor = true;

    ResultadoOperacion res = Gestor_ProcesarOrden(8);
    
    TEST_ASSERT_EQUAL(ERROR_MOTOR_ANDANDO, res);
    TEST_ASSERT_FALSE(motor_fue_iniciado_mock); // No se vuelve a mandar la orden de inicio
}

// CP-4: Rechazo por Brazo Desplegado
void test_CP4_RechazoPorSeguridadBrazo(void) {
    
    mock_estado_brazo = false; //brazo desplegado

  
    ResultadoOperacion res = Gestor_ProcesarOrden(8);
    
   
    TEST_ASSERT_EQUAL(ERROR_BRAZO_DESPLEGADO, res);
    TEST_ASSERT_FALSE(motor_fue_iniciado_mock);
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_CP1_ValidacionExitosa);
    RUN_TEST(test_CP2_RechazoPorEstacionOcupada);
    RUN_TEST(test_CP3_RechazoPorVehiculoEnMovimiento);
    RUN_TEST(test_CP4_RechazoPorSeguridadBrazo);
    
    return UNITY_END();
}