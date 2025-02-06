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
#define PIN_SS1     &LATD,_LATD_LATD4_MASK
#define PIN_SS2     &LATD,_LATD_LATD3_MASK
#define PIN_SS3     &LATD,_LATD_LATD2_MASK

#define PIN_DCX     &LATD
#define PIN_DCX_MASK _LATD_LATD6_MASK
#define PIN_TFT_RST &LATD
#define PIN_TFT_RST_MASK _LATD_LATD5_MASK

void pinInit();

#endif	/* PINCONFIG_H */

