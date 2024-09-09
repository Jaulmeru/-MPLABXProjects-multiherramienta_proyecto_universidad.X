#include "UART_variables.h"
#include "UART.h"


void UART_ErrorHandler(UART_ERROR_CODE errorCode){
    if(errorCode == ERROR_CODE_UART_OK) return;
    printf("Error: ");
    switch(errorCode){
        case ERROR_CODE_UART_OVERFLOW:
            printf("ERROR_CODE_UART_OVERFLOW");
        break;
        case ERROR_CODE_UART_FRAMING:
            printf("ERROR_CODE_UART_FRAMING");
        break;
        case ERROR_CODE_UART_CONFIG:
            printf("ERROR_CODE_UART_CONFIG \r\n");
        break;
    }
}