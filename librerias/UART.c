#include <xc.h>

#include "UART.h"

void UART_config_show(){
    printf("Modo: ");
    (SYNC1) ? printf("Sincrono "):printf("Asincrono ");
    (BRGH1) ? printf("alta velocidad \r\n"):printf("baja velocidad \r\n");
    printf("Baudrate: ");
    (BRG161) ? printf("16 bits "):printf("8 bits ");
    printf("x baudios \r\n");
    printf("Puerto: ");
    (SPEN) ? printf("Habilitado \r\n"):printf("Deshabilitado \r\n");
    printf("Transor: ");
    (TXEN1) ? printf("Habilitado \r\n"):printf("Deshabilitado \r\n");
    printf("Receptor: ");
    (CREN) ? printf("Habilitado \r\n"):printf("Deshabilitado \r\n");
}

void UART_init(uint32_t baudrate){
    TXSTA1bits.SYNC1 = 0;        // Modo asincrono
    TXSTA1bits.BRGH1 = 1;        // Modo de alta velocidad
    BAUDCON1bits.BRG161 = 1;     // Se habilitan 16bits en el generador de Baud Rate
    UART_select_baud(baudrate);     // Se configura por defecto a 9600
    TRISC6 = 1;                 // Pin Tx -> Tri estado (Input)
    TRISC7 = 1;                 // Pin Rx -> Tri estado (Input)
    RCSTAbits.SPEN = 1;         // Serial Port -> Habilitado
    TXSTAbits.TXEN1 = 1;         // Transmision -> Habilitada
    RCSTAbits.CREN = 1;         // Recepcion -> Habiltada
    UART_config_show();
};

void UART_select_baud(uint32_t baudrate){
    switch (baudrate){
        case 300: // 39999
            SPBRGH = 0x9C;
            SPBRG = 0x3F;
            break;
        case 1200: // 9999
            SPBRGH = 0x27;
            SPBRG = 0x0F;
            break;
        case 2400: // 4999
            SPBRGH = 0x13;
            SPBRG = 0x87;
            break;
        case 10417: // 1151
            SPBRGH = 0x04;
            SPBRG = 0x7F;
            break;
        case 19200: // 624
            SPBRGH = 0x02;
            SPBRG = 0x70;
            break;
        case 57600: // 207
            SPBRGH = 0x00;
            SPBRG = 0xCF;
            break;
        case 115200: // 103
            SPBRGH = 0x00;
            SPBRG = 0x67;
            break;
        default: // 9600 bauds -> 1249
            SPBRGH = 0x04;
            SPBRG = 0xE1;
            break;
    }
}

void UART_Tx(char dato){
    while(TRMT == 0);
    TXREG1 = dato;
}

void putch(char data){
    UART_Tx(data);
}

UART_ERROR_CODE UART_Rx_OVERFLOW(){
    if (RCSTAbits.OERR) {  // Error de sobrecarga
        RCSTAbits.CREN = 0;  // Desactiva y vuelve a activar la recepci�n
        RCSTAbits.CREN = 1;
        return ERROR_CODE_UART_OVERFLOW;
    }
    return ERROR_CODE_OK;
}

UART_ERROR_CODE UART_Rx_FRAMING(){
    if (RCSTAbits.FERR) {  // Error de framing
        char dummy = RCREG;  // Leer RCREG para limpiar el error
        return ERROR_CODE_UART_FRAMING;
    }
    return ERROR_CODE_OK;
}

char UART_Rx(void){
    ErrorHandler(UART_Rx_OVERFLOW());
    ErrorHandler(UART_Rx_FRAMING());
    return RCREG1;
}

bool UART_Available(){
    if (!RCSTAbits.SPEN || !RCSTAbits.CREN){
        ErrorHandler(ERROR_CODE_UART_CONFIG);
        return 0;
    }    
    if (!RC1IF){
        return 0;
    }
    return 1;
}