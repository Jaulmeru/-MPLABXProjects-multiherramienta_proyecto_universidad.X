#include <xc.h>
#include "config.h"             
#include "librerias/clock.h"   
#include "librerias/UART.h"
#include "librerias/SPI.h"
#include "librerias/commandLine.h"
#include "CLHandler.h"

int main(void)
{
    Clock_Init(16000);
    UART_Init(9600);
    SPI_master_init();
    commandLineInit();
    
    while(1)
    {
        if(UART_RxAvailable()){
            addToBuffer(UART_Rx());
        }
        CL_ErrorHandler(commandProcess());
        SPI_write(global_x);
        UART_Tx(SPI_read());
        __delay_ms(500);
    }
}