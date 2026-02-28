#include <stdio.h>
#include "interfazSupervision.h"
#include "gestorMovimiento.h" 

void Interfaz_EnviarACK(void) {
    printf("ACK (Orden aceptada)\n");
}

void Interfaz_EnviarNACK(ResultadoOperacion error) {
    printf("NACK (Error codigo: %d)\n", error);
}




void Interfaz_RecibirComando(int destino) {
    
    ResultadoOperacion resultado = Gestor_ProcesarOrden(destino);
    
    if (resultado == RESULTADO_EXITO) {
        Interfaz_EnviarACK();
    } else {
        Interfaz_EnviarNACK(resultado);
    }
}