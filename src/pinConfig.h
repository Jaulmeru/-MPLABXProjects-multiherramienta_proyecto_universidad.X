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
#include <stdint.h>

// SPI
#define SPISLAVES 6
#define PIN_TFT     &LATB,_LATB_LATB2_MASK
#define PIN_TOUCH   &LATB,_LATB_LATB4_MASK
#define PIN_SD      &LATD,_LATD_LATD7_MASK
#define PIN_SS1     &LATB,_LATB_LATB5_MASK
#define PIN_SS2     &LATB,_LATB_LATB6_MASK
#define PIN_SS3     &LATB,_LATB_LATB7_MASK

#define PIN_DCX     &LATD
#define PIN_DCX_MASK _LATD_LATD6_MASK

void pinInit();

#endif	/* PINCONFIG_H */

