/**
 * @file interfaz.h
 * @brief Funciones para crear formas en la interfaz
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 05/02/2025
 * @version 0.1
 */

#ifndef INTERFAZ_H
#define	INTERFAZ_H

#include "librerias/ST7789.h"

void fillScreen(uint16_t color);
void print_rect(uint16_t x, uint16_t y, uint16_t size_x, uint16_t size_y, uint16_t color);
void cruz(uint16_t x, uint16_t y);
void initInter();

#endif	/* INTERFAZ_H */

