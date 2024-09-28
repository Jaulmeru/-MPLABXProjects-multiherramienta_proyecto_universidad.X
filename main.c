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
#include "librerias/SPI.h"

void main(void) {
    Clock_Init(16000);
    UART_Init(9600);
    //SPI_master_init();
    
    
//    PIE1bits.SSP1IE  = 0;
//    TRISA1 = 0;
//    LATAbits.LATA1 = 1;
//    __delay_ms(500);
//    LATAbits.LATA1 = 0;
//    __delay_ms(500);
//    LATAbits.LATA1 = 1;
//    __delay_ms(500);
//    LATAbits.LATA1 = 0;
//    __delay_ms(500);
    
    //SPI_write(c1);
    while(1){
        char rx = UART_Rx();
        if(rx) UART_Tx(rx);
    }
}
