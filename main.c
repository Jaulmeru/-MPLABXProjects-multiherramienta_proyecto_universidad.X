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
    SPI_master_init();
    SPI_write('b');
    printf("hola");
    printf(SPI_read());
    while(1){
    }
}
