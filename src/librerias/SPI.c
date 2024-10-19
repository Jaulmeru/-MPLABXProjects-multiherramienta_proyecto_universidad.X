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

void SPI_master_init(spiSlave *slave){
    TRISAbits.RA5 = 0;      // SS -> Ouput
    TRISBbits.RB0 = 1;      // SDI -> Input
    TRISBbits.RB1 = 0;      // SCK -> Output
    TRISBbits.RB3 = 0;      // SDO -> Output
    
    SPI_BaudRateGen(slave->baudRate);
    SSPCON1 = slave->SSPCON1;
    SSPCON3 = slave->SSPCON3;
    SSPSTAT = slave->SSPSTAT;
                
    ANSELA = 0x0;   //!< @todo Deshabilitar analogos en funcion para pines
    ANSELB = 0x0;   //!< @todo Deshabilitar analogos en funcion para pines
    
    LATAbits.LA5 = 1;
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

void SPI_master_reset(){
    SPI_disenable();          // Serial Port -> Deshabilitado
    SPI_master_init();  // Vuelve a iniciar puerto
}

void SPIClockMode(uint8_t mode){
    CKP = (mode & 1);
    CKE = (mode & 2) >> 1;
}

void SPI_write(uint8_t dato){
    LATAbits.LA5 = 0;
    SSPBUF = dato;      // Escribe para iniciar la transmision
    while(!BF);         // Espera a que se haya completado la recepccion
    while(!SSPIF);         // Espera a que se haya completado la recepccion
    SSPIF = 0;
    if(WCOL) SPI_ErrorHandler(EC_SPI_COLLISION); // Valida si habia un dato anterior en SSPBUF
    LATAbits.LA5 = 1;
}
uint8_t SPI_read(){ 
    while (!SSPSTATbits.BF);
    return SSP1BUF;
}


/*const char* SPI_print(const char *dataT){
    static char dataR[];
    int i = 0;
    LATAbits.LA5 = 0;
    while(*dataT){
        dataR[i] = SPI_write(*dataT);
        *dataT++;
        i++;
    }
    LATAbits.LA5 = 1;
    return dataR;
}*/

int32_t SPI_actual_frec(){
    int32_t baud = _XTAL_FREQ/((SSP1ADD+1)*4);
    return baud;
}



uint8_t SPI1_ByteExchange(uint8_t byteData)
{
    SSP1BUF = byteData;
    while (!PIR1bits.SSP1IF)
    {
        // Wait for flag to get set
    }
    PIR1bits.SSP1IF = 0;
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

void SPI_select_Slave(SPI_SLAVE slave){
    switch(slave){
        case SLAVE1:
            
            break;
        case SLAVE2:
            
            break;
        case SLAVE3:
            
            break;
    }
}