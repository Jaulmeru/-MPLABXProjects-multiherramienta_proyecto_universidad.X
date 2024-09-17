#include "SPI.h"

void SPI_config_show(){
    printf("\r\nConfiguracion SPI:\r\n");
    
    printf("Frecuencia SPI: ");
    printf("%"PRId32 "\r\n",SPI_actual_frec());
    
    printf("SDI: ");
    (TRISBbits.RB0) ? printf("Input \r\t"):printf("Output\r\t");
    printf("SDO: ");
    (TRISBbits.RB3) ? printf("Input \r\t"):printf("Output\r\t");
    printf("SCK: ");
    (TRISBbits.RB1) ? printf("Input \r\t"):printf("Output\r\t");
    printf("SS: ");
    (TRISAbits.RA5) ? printf("Input \r\t"):printf("Output\r\t");
  
    printf("Puerto serial: ");
    (SSPEN) ? printf("habilitado\r\n"):printf("deshabilitado\r\n");
    printf("Polaridad: Idle ");
    (SSPCON1bits.CKP) ? printf("high\r\n"):printf("low\r\n");
    printf("Transmision en ");
    (SSPSTATbits.CKE) ? printf("active a idle\r\n"):printf("idle a active\r\n");
    printf("Muestra de dato entrante: ");
    (SSPSTATbits.SMP) ? printf("al final\r\n"):printf("en medio\r\n");
}

void SPI_master_init(){
    SPI_BaudRateGen(100000);
    TRISAbits.RA5 = 1;      // SS -> Input
    TRISBbits.RB0 = 1;      // SDI -> Input
    TRISBbits.RB1 = 0;      // SCK -> Output
    TRISBbits.RB3 = 0;      // SDO -> Output
    SSPCON1bits.SSPM = 10;  // Modo -> SPI con (FOSC / (FClock * 4)) - 1
    SPI_enable();           // Serial Port -> Habilitado
    SPI_clk_idle_low();     // Polaridad reloj
    SPI_clk_idle_active();  // Se envian datos en flanco de subida
    SPI_sample_end();       // Muestra de datos de entrada al final 
    
    SPI_config_show();
}   

void SPI_BaudRateGen(int32_t FClock){
    uint32_t baudReg = (_XTAL_FREQ / (FClock * 4)) - 1;
    if(baudReg > 0xFF){
        SPI_ErrorHandler(EC_SPI_BR_OVERRANGE);
        return;
    }
    SSP1ADD = baudReg;
}

void SPI_master_reset(){
    SPI_disenable();          // Serial Port -> Deshabilitado
    SPI_master_init();  // Vuelve a iniciar puerto
}

char SPI_write(char dato){
    SSPBUF = dato;
    if(WCOL) SPI_ErrorHandler(EC_SPI_COLLISION);
    while(!BF);
    return SSPBUF;
}

int32_t SPI_actual_frec(){
    int32_t baud = _XTAL_FREQ/((SSP1ADD+1)*4);
    return baud;
}