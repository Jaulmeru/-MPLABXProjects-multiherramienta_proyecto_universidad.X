/**
 * @file pinConfig.c
 * @brief Configuracion de los pines que seran utilizados para distintas funciones
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 18/10/2024
 * @version 0.1
 */

#include "pinConfig.h"

void pinInit(){
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
        
    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0; //!RA1 < LED indicador
    TRISAbits.RA2 = 0;
    TRISAbits.RA3 = 0;
    TRISAbits.RA4 = 0;
    TRISAbits.RA5 = 0;
    TRISAbits.RA6 = 0;
    TRISAbits.RA7 = 0;
        
    TRISBbits.RB0 = 1;  //!RB0 < SPI - SDI (MISO), I2C - SDA
    TRISBbits.RB1 = 0;  //!RB1 < SPI - SCK
    TRISBbits.RB2 = 0;  //!RB2 < SPI - SS_TFT
    TRISBbits.RB3 = 0;  //!RB3 < SPI - SDO (MOSI)
    TRISBbits.RB4 = 0;  //!RB4 < SPI - SS_TOUCH
    TRISBbits.RB5 = 1;  //!RB5 < TOUCH - IRQ
    TRISBbits.RB6 = 0;  //!RB6 < ICSP - PGC
    TRISBbits.RB7 = 0;  //!RB7 < ICSP - PGD
        
    TRISCbits.RC0 = 0;  
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    TRISCbits.RC6 = 1;  //!RC6 < UART - TX
    TRISCbits.RC7 = 1;  //!RC7 < UART - RX
        
    TRISDbits.RD0 = 0;
    TRISDbits.RD1 = 0;
    TRISDbits.RD2 = 0;  //!< SPI - SS_3
    TRISDbits.RD3 = 0;  //!< SPI - SS_2
    TRISDbits.RD4 = 0;  //!< SPI - SS_1
    //** @todo Agregar reset a ST7789
    TRISDbits.RD5 = 0;  //!< TFT - RESET
    TRISDbits.RD6 = 0;  //!< TFT - DCX
    TRISDbits.RD7 = 0;  //!< SPI - SS_SD
        
    TRISEbits.RE0 = 0;
    TRISEbits.RE1 = 0;
    TRISEbits.RE2 = 0;      
}