/* 
 * File:   SPI.h
 * Author: admin
 *
 * Created on September 9, 2024, 1:50 PM
 */

#include "variables.h"

#define SPI_clk_idle_high() do{ SSPCON1bits.CKP = 1; }while(0)
#define SPI_clk_idle_low() do{ SSPCON1bits.CKP = 0; }while(0)
#define SPI_clk_rising() do{ SSPCON1bits.CKP = 1; }while(0)
#define SPI_clk_falling() do{ SSPCON1bits.CKP = 0; }while(0)
#define SPI_enable() do{SSPEN = 1;}while(0)
#define SPI_disenable() do{SSPEN = 0;}while(0)


#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void SPI_master_init();
void SPI_BaudRateGen(int32_t);
void SPI_master_reset();
void SPI_write(char);
char SPI_read();

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

