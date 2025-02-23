/**
 * @file cont_sending.c
 * @brief Codigo de ejemplo
 * Envia continuamente un dato ingresado en CLI
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 14/10/2024
 * @version 1.0
 */
#include <xc.h>
#include "config.h"             
#include "librerias/clock.h"   
#include "librerias/UART.h"
#include "librerias/SPI.h"
#include "librerias/commandLine.h"
#include "CLHandler.h"
#include "pinConfig.h"
#include "librerias/ST7789.h"
#include "interfaz.h"


int main(void)
{
    Clock_Init(16000);
    pinInit();
    UART_Init(9600);
    SPI_master_init();
    commandLineInit();
    ST7789Init();
    initInter();
              
        
    while(1)
    {
        if(UART_RxAvailable()){
            addToBuffer(UART_Rx());
        }
        CL_ErrorHandler(commandProcess());
        
               
        __delay_ms(500);
    }
}