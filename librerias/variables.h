/* 
 * File:   variables.h
 * Author: admin
 *
 * Created on 1 de septiembre de 2024, 07:31 PM
 */

#ifndef VARIABLES_H
#define	VARIABLES_H

#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include <stdio.h>
#include <xc.h>
#include "clock.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum{
        ERROR_CODE_UART_OK,   
        ERROR_CODE_UART_OVERFLOW,        
        ERROR_CODE_UART_FRAMING,        
        ERROR_CODE_UART_CONFIG,        
    }UART_ERROR_CODE;
    
    typedef enum{
        ERROR_CODE_SPI_OK,   
        ERROR_CODE_SPI_BR_OVERRANGE,    
    }SPI_ERROR_CODE;

void UART_ErrorHandler(UART_ERROR_CODE);
void SPI_ErrorHandler(SPI_ERROR_CODE);
    
#ifdef	__cplusplus
}
#endif

#endif	/* VARIABLES_H */

