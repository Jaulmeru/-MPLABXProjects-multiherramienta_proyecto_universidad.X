/**
 * @file echo_char.c
 * @brief Codigo de ejemplo
 * Lee un caracter por UART y lo envia de vuelta
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 05/10/2024
 * @version 1.0
 */

#include <xc.h>
#include "config.h"             
#include "librerias/clock.h"   
#include "librerias/UART.h"

int main(void)
{
    Clock_Init(16000);
    UART_Init(9600);
    
    while(1)
    {
        if(UART_RxAvailable()){
            uint8_t x = UART_Rx();
            UART_Tx(x);
        }
    }
}