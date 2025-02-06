/**
 * @file SPI.h
 * @brief Libreria para manejo de modulo MSSP para SPI maestro
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 11/10/2024
 * @version 0.1
 */

#ifndef SPI_H
#define	SPI_H

#define SPI_clk_idle_high() do{ SSPCON1bits.CKP = 1; }while(0) //!< sdas dsdsa
#define SPI_clk_idle_low() do{ SSPCON1bits.CKP = 0; }while(0)
#define SPI_clk_idle_active() do{ SSPSTATbits.CKE = 0; }while(0)
#define SPI_clk_active_idle() do{ SSPSTATbits.CKE = 1; }while(0)
#define SPI_enable() do{SSPCON1bits.SSPEN = 1;}while(0)
#define SPI_disenable() do{SSPCON1bits.SSPEN = 0;}while(0)
#define SPI_sample_end() do{SSPSTATbits.SMP = 1;}while(0)
#define SPI_sample_mid() do{SSPSTATbits.SMP = 0;}while(0)

#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include <stdio.h>
#include <xc.h>
#include "clock.h"
#include "../pinConfig.h"
#include <inttypes.h>

typedef enum{
    EC_SPI_OK,   
    EC_SPI_BR_OVERRANGE,    
    EC_SPI_COLLISION,    
}SPI_ERROR_CODE;

typedef struct{
    volatile unsigned char *ss_pin;
    uint8_t mask;
    uint8_t SSPCON1;
    uint8_t SSPCON3;
    uint8_t SSPSTAT;
    int32_t baudRate;
}spiSlave;

spiSlave slaves[] = {
    {PIN_TFT,0x2A,0x10,0x00,500000},
    {PIN_TOUCH,0x2A,0x10,0x00,60000},
    {PIN_SD,0x2A,0x10,0x00,60000},
    {PIN_SS1,0x2A,0x10,0x00,60000},
    {PIN_SS2,0x2A,0x10,0x00,60000},
    {PIN_SS3,0x2A,0x10,0x00,60000}
};
    
void SPI_config_show();
void SPI_master_init();
void SPI_BaudRateGen(int32_t);
void disenableSlaves();
void SPI_master_reset();
void SPIClockMode(uint8_t mode);
void SPI_OpenCom(spiSlave *slave);
void SPI_CloseCom(spiSlave *slave);
void SPI_write(uint8_t);
uint8_t SPI_read();
int32_t SPI_actual_frec();

uint8_t SPI_ByteExchange(uint8_t slave,uint8_t data);

void SPI_ErrorHandler(SPI_ERROR_CODE);


#endif	/* SPI_H */