/**
 * @file print_ascii.c
 * @brief Codigo de ejemplo
 * Valida el envio de caracteres uno a uno por UART
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 02/10/2024
 * @version 1.0
 */
#include <xc.h>
#include "config.h"             
#include "librerias/clock.h"   
#include "librerias/UART.h"

void main(void)
{
    Clock_Init(16000);
    UART_Init(9600);
    uint8_t data = 33;
    while(1)
    {
        if(data > 126){
            data = 33;
        }else UART_Tx(data++);
        __delay_ms(500);
    }    
}
