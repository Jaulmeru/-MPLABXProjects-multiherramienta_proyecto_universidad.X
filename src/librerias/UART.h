/* 
 * File:   UART_Tx.h
 * Author: Javier Mendoza
 *
 * Created on 29 de agosto de 2024, 09:25 PM
 */

#include "UART_variables.h"

#ifndef UART_TX_H
#define	UART_TX_H


#ifdef	__cplusplus
extern "C" {
#endif

/**
 * @brief Muestra por puerto serial la configuracion actual del modulo EUSART
 */
void UART_config_show();

/**
 * @brief Configura los registros basicos para comunicacion y llama a UART_config_show()
 * @param Baudrate Llamando a UART_select_baud()
 */
void UART_Init(uint32_t);

/**
 * @brief Configura SPBRGH y SPBRG para el baudrate ingresado
 * @param Baudrate
 * Admite 300, 1200, 2400, 9600, 10417, 19200, 57600, 115200.
 * En caso de ingresar otro valor, se configura por defecto a 9600.
 * @note Se planea cambiar a una funcion que realice el calculo al momento
 */
void UART_select_baud(uint32_t);

/**
 * @brief Revisa el registro FERR y limpia el error
 * @return ERROR_CODE_UART_FRAMING 
 * @return ERROR_CODE_UART_OK
 */
UART_ERROR_CODE UART_Rx_FRAMING();

/**
 * @brief Revisa el registro OERR y limpia el error
 * @return ERROR_CODE_UART_OVERFLOW 
 * @return ERROR_CODE_UART_OK
 */
UART_ERROR_CODE UART_Rx_OVERFLOW();

/**
 * @brief Envia el dato si ya esta vacio TSR
 * @param dato
 */
void UART_Tx(uint8_t);

/**
 * @brief Lee el ultimo dato recibido
 * @brief Valida los errores Framming y Overflow 
 * @return RCREG1
 */
uint8_t UART_Rx(void);

/**
 * @brief Valida si esta habilitada la recepcion y si el buffer esta lleno
 * @return 0 No listo para leer
 * @return 1 Listo para leer
 */
bool UART_RxAvailable(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

