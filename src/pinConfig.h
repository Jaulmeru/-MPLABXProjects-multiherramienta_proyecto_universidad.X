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

#define LED_REG LATAbits
#define LED_MASK _LATA_LATA1_MASK

#define TFT_PIN         &LATB
#define TFT_MASK        _LATB_LATB2_MASK
#define TOUCH_PIN       &LATB
#define TOUCH_MASK      _LATB_LATB4_MASK
#define IRQ_REG         &LATB
#define IRQ_MASK        _LATB_LATB5_MASK

#define SS3_PIN         &LATD
#define SS3_MASK        _LATD_LATD2_MASK
#define SS2_PIN         &LATD
#define SS2_MASK        _LATD_LATD3_MASK
#define SS1_PIN         &LATD
#define SS1_MASK        _LATD_LATD4_MASK
#define RST_TFT_PIN     &LATD
#define RST_TFT_MASK    _LATD_LATD5_MASK
#define DCX_PIN         &LATD
#define DCX_MASK        _LATD_LATD6_MASK
#define SD_PIN          &LATD
#define SD_MASK        _LATD_LATD7_MASK
    
    

void pinInit();

#endif	/* PINCONFIG_H */

