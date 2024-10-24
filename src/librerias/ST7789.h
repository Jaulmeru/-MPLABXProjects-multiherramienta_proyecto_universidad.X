/**
 * @file ST7789.h
 * @brief Libreria para el manejo de del chip ST7789
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 20/10/2024
 * @version 0.1
 */

#ifndef ST7789_H
#define	ST7789_H

#include "../pinConfig.h"
#include "SPI.h"

#define ST7789_SLAVE 0
#define ST7789_send(x,y) SPI_ByteExchange(x,y)

#define DISP_WIDTH 320
#define DISP_HEIGHT 240

uint16_t xOffset = 0;
uint16_t yOffset = 0;


void DCXcommand();
void DCXparam();

void ST7789Init();

void SWRESET();
void RDDST(); //!< @todo Metodo de recibir datos de los comandos
void SLPIN();
void SLPOUT();
void NORON ();
void INVOFF();
void INVON();
void GAMSET(uint8_t gamma);
void DISPOFF();
void DISPON();
void CASET(uint16_t xs, uint16_t xe);
void RASET(uint16_t ys, uint16_t ye);
void RAMWR();
void RAMRD();
void MADCTL(uint8_t config);
void COLMOD(uint8_t config);


#endif	/* ST7789_H */

