/* 
 * File:   SPI.h
 * Author: admin
 *
 * Created on September 9, 2024, 1:50 PM
 */

#include "variables.h"

#define SPI_clk_idle_high() do{ SSPCON1bits.CKP = 1; }while(0)
#define SPI_clk_idle_low() do{ SSPCON1bits.CKP = 0; }while(0)
#define SPI_clk_idle_active() do{ SSPSTATbits.CKE = 0; }while(0)
#define SPI_clk_active_idle() do{ SSPSTATbits.CKE = 1; }while(0)
#define SPI_enable() do{SSPEN = 1;}while(0)
#define SPI_disenable() do{SSPEN = 0;}while(0)
#define SPI_sample_end() do{SSPSTATbits.SMP = 1;}while(0)
#define SPI_sample_mid() do{SSPSTATbits.SMP = 0;}while(0)



#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void SPI_config_show();
void SPI_master_init();
void SPI_BaudRateGen(int32_t);
void SPI_master_reset();
void SPI_write(uint8_t);
uint8_t SPI_read();
const char* SPI_print(const char*);
int32_t SPI_actual_frec();

uint8_t SPI1_ByteExchange(uint8_t);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

