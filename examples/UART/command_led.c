/**
 * @file command_led.c
 * @brief Codigo de ejemplo
 * Valida la recepcion de un caracter por UART
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 02/10/2024
 * @version 1.0
 */

#include <xc.h>
#include "config.h"             
#include "librerias/clock.h"   
#include "librerias/UART.h"

#define LED_ON()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_OFF()             do { LATAbits.LATA1 = 0; } while(0)

static uint8_t readMessage;

int main(void)
{
    Clock_Init(16000);
    UART_Init(9600);
    TRISAbits.RA1 = 0;
    
    while(1)
    {
        if(PIR1bits.RC1IF){
            readMessage = UART_Rx();
            if(readMessage == '1') LED_ON();
            if(readMessage == '0') LED_OFF();        
        }
    }
}
