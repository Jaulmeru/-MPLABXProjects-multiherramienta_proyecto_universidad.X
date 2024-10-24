/**
 * @file ST7789.c
 * @brief Funciones para el manejo de del chip ST7789
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 20/10/2024
 * @version 0.1
 */

#include "ST7789.h"

void DCXcommand(){
    __delay_us(5);
    *(DCX_PIN) &= ~(DCX_MASK);
    __delay_us(5);
}
void DCXparam(){
    __delay_us(5);
    *(DCX_PIN) |= DCX_MASK;
    __delay_us(5);
}

void ST7789Init(){
    SWRESET();
    SLPOUT();
    COLMOD(0x55);
    MADCTL(0x08);
    CASET(xOffset,DISP_WIDTH + xOffset);
    RASET(yOffset,DISP_HEIGHT + yOffset);
    INVOFF();
    NORON ();
    DISPON();
}

void SWRESET(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x01);
    __delay_ms(120);
}
void RDDST(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x09);
    DCXparam();
    ST7789_send(ST7789_SLAVE,0x00);
    ST7789_send(ST7789_SLAVE,0x00);
    ST7789_send(ST7789_SLAVE,0x00);
    ST7789_send(ST7789_SLAVE,0x00);
    ST7789_send(ST7789_SLAVE,0x00);
}
void SLPIN(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x10);
    __delay_ms(120);
}
void SLPOUT(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x11);
    __delay_ms(5);
}
void NORON (){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x13);
}
void INVOFF(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x20);
}
void INVON(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x21);
}
void GAMSET(uint8_t gamma){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x26);
    DCXparam();
    ST7789_send(ST7789_SLAVE,gamma);
}
void DISPOFF(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x28);
}
void DISPON(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x29);
}
void CASET(uint16_t xs, uint16_t xe){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x2A);
    DCXparam();
    ST7789_send(ST7789_SLAVE,xs >> 8);
    ST7789_send(ST7789_SLAVE,xs & 0xFF);
    ST7789_send(ST7789_SLAVE,xe >> 8);
    ST7789_send(ST7789_SLAVE,xe & 0xFF);
}
void RASET(uint16_t ys, uint16_t ye){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x2B);
    DCXparam();
    ST7789_send(ST7789_SLAVE,ys >> 8);
    ST7789_send(ST7789_SLAVE,ys & 0xFF);
    ST7789_send(ST7789_SLAVE,ye >> 8);
    ST7789_send(ST7789_SLAVE,ye & 0xFF);
}
void RAMWR(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x2C);
    DCXparam();
}
void RAMRD(){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x2E);
    DCXparam();
}
void MADCTL(uint8_t config){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x36);
    DCXparam();
    ST7789_send(ST7789_SLAVE,config);
}
void COLMOD(uint8_t config){
    DCXcommand();
    ST7789_send(ST7789_SLAVE,0x3A);
    DCXparam();
    ST7789_send(ST7789_SLAVE,config);
}