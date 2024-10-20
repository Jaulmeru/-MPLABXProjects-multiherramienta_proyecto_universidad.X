/**
 * @file SPI.c
 * @brief Funciones para manejo de modulo MSSP para SPI maestro
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 11/10/2024
 * @version 0.1
 */

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
    SPI_BaudRateGen(slaves[0].baudRate);
    SSPCON1 = slaves[0].SSPCON1;
    SSPCON3 = slaves[0].SSPCON3;
    SSPSTAT = slaves[0].SSPSTAT;
    disenableSlaves();
    SPI_config_show();
}   

void SPI_BaudRateGen(int32_t FClock){ // Recibe un valor de frecuencia esperada y configura 
    uint32_t baudReg = (_XTAL_FREQ / (FClock * 4)) - 1;
    if(baudReg > 0xFF){
        SPI_ErrorHandler(EC_SPI_BR_OVERRANGE);
        return;
    }
    SSP1ADD = baudReg;
}

void disenableSlaves(){
    for(uint8_t i = 0; i < SPISLAVES; i++){
        *(slaves[i].ss_pin) |= slaves[i].mask;
    }
}

void SPI_master_reset(){
    SPI_disenable();          // Serial Port -> Deshabilitado
    SPI_master_init();  // Vuelve a iniciar puerto
}

void SPIClockMode(uint8_t mode){
    CKP = (mode & 1);
    CKE = (mode & 2) >> 1;
}

void SPI_OpenCom(spiSlave *slave){
    SPI_BaudRateGen(slave->baudRate);
    SSPCON1 = slave->SSPCON1;
    SSPCON3 = slave->SSPCON3;
    SSPSTAT = slave->SSPSTAT;
    *(slave->ss_pin) &= ~(slave->mask);
}

void SPI_CloseCom(spiSlave *slave){
    *(slave->ss_pin) |= slave->mask;
}

void SPI_write(uint8_t dato){
    SSPBUF = dato;      
    while(!BF);       
    while(!SSPIF);       
    SSPIF = 0;
    if(WCOL) SPI_ErrorHandler(EC_SPI_COLLISION); 
}
uint8_t SPI_read(){ 
    while (!SSPSTATbits.BF);
    return SSP1BUF;
}

int32_t SPI_actual_frec(){
    int32_t baud = _XTAL_FREQ/((SSP1ADD+1)*4);
    return baud;
}

uint8_t SPI_ByteExchange(uint8_t dato){
    SSPBUF = dato;      
    while(!BF);         
    while(!SSPIF);      
    SSPIF = 0;
    if(WCOL) SPI_ErrorHandler(EC_SPI_COLLISION);
    return SSP1BUF; 
}

void SPI_ErrorHandler(SPI_ERROR_CODE errorCode){
    if(errorCode != EC_SPI_OK) return;
    printf("Error: ");
    switch(errorCode){
        case EC_SPI_OK:
            
        break;
        case EC_SPI_BR_OVERRANGE:
            printf("ERROR_CODE_SPI_BR_OVERRANGE");
        break;
        case EC_SPI_COLLISION:
            printf("ERROR_CODE_SPI_COLLISION");
        break;
    }
}
