/* 
 * File:   UART_Tx.h
 * Author: Javier Mendoza
 *
 * Created on 29 de agosto de 2024, 09:25 PM
 */

#include "variables.h"

#ifndef UART_TX_H
#define	UART_TX_H


#ifdef	__cplusplus
extern "C" {
#endif

void UART_config_show();
void UART_Init(uint32_t);
void UART_select_baud(uint32_t);
UART_ERROR_CODE UART_Rx_FRAMING();
UART_ERROR_CODE UART_Rx_OVERFLOW();
void UART_Tx(char);
char UART_Rx(void);    
bool UART_Available(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */
