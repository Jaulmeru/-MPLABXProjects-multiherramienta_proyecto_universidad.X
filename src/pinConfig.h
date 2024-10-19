/**
 * @file pinConfig.h
 * @brief Definicion de los pines que seran utilizados para distintas funciones
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 18/10/2024
 * @version 0.1
 */

#ifndef PINCONFIG_H
#define	PINCONFIG_H

#include <xc.h>

// SPI
#define PIN_TFT &LATBbits.LATB2 
#define PIN_TOUCH &LATBbits.LATB4
#define PIN_SD &LATDbits.LATD7
#define PIN_SS1 &LATBbits.LATB5
#define PIN_SS2 &LATBbits.LATB6
#define PIN_SS3 &LATBbits.LATB7


#endif	/* PINCONFIG_H */

