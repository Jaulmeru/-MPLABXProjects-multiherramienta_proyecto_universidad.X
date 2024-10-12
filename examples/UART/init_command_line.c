/**
 * @file init_command_line.c
 * @brief Codigo de ejemplo
 * Arranca la linea de comandos
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 11/10/2024
 * @version 1.0
 */

#include <xc.h>
#include "config.h"             
#include "librerias/clock.h"   
#include "librerias/UART.h"
#include "librerias/commandLine.h"


int main(void)
{
    Clock_Init(16000);
    UART_Init(9600);
    commandLineInit();
    
    while(1)
    {
        if(UART_RxAvailable()){
            addToBuffer(UART_Rx());
        }
        CL_ErrorHandler(commandProcess());
    }
}