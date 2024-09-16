#include "SPI.h"

void SPI_master_init(){
    SPI_BaudRateGen(100000);
    TRISAbits.RA5 = 1;      // SS -> Input
    TRISBbits.RB0 = 1;      // SDI -> Input
    TRISBbits.RB1 = 0;      // SCK -> Output
    TRISBbits.RB3 = 0;      // SDO -> Output
    SSPCON1bits.SSPM = 10;  // Modo -> SPI con (FOSC / (FClock * 4)) - 1
    SPI_enable();           // Serial Port -> Habilitado
    SPI_clk_idle_low();     // Polaridad reloj
    SPI_clk_rising();       // Se envian datos en flanco de subida
}   

void SPI_BaudRateGen(int32_t FClock){
    uint32_t baudReg = (FOSC / (FClock * 4)) - 1;
    if(baudReg > 0xFF){
        SPI_ErrorHandler(ERROR_CODE_SPI_BR_OVERRANGE);
        return;
    }
    SSP1ADD = baudReg;
}

void SPI_master_reset(){
    SPI_disenable();          // Serial Port -> Deshabilitado
    SPI_master_init();  // Vuelve a iniciar puerto
}

void SPI_write(char dato){
    SSPBUF = dato;
}

char SPI_read(){
    return SSPBUF;
}
