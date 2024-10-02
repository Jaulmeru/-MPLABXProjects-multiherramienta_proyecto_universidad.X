/*
 * File:   main.c
 * Author: Javier Mendoza
 *
 * Created on 29 de agosto de 2024, 08:00 PM
 */


#include <xc.h>
#include "config.h"             //Configuracion de fuses 
#include "librerias/clock.h"    //Configuracion de reloj a 48MHz
#include "librerias/UART.h"

void main(void) {
    Clock_Init(16000);
    UART_Init(9600);
    while(1){
        char x = UART_Rx();
        if(x){
            UART_Tx(x);
            x = 0;
        }
    }
}
