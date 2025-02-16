/**
 * @file interfaz.c
 * @brief Funciones para crear formas en la interfaz
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 05/02/2025
 * @version 0.1
 */

#include "interfaz.h"

void fillScreen(uint16_t color){
    DISPOFF();
    RAMWR();
    for(int i = 0; i<240;i++){
        for(int j = 0; j<320;j++){
            SPI_ByteExchange(0,color >> 8);
            SPI_ByteExchange(0,color & 0xFF);
        }
    } 
    DISPON();
    *(slaves[0].ss_pin) |= (slaves[0].mask);
}

void print_rect(uint16_t x, uint16_t y, uint16_t size_x, uint16_t size_y, uint16_t color){
    CASET(x,x+size_x-1);
    RASET(y,y+size_y-1);
    RAMWR();
    for(int i =0;i<size_x*size_y;i++){
        SPI_ByteExchange(0, color >> 8);
        SPI_ByteExchange(0, color & 0xFF);
    }
}

void cruz(uint16_t x, uint16_t y){
    print_rect(x-2,y-15,4,15,0x0);
    print_rect(x+2,y-2,15,4,0xF800);
    print_rect(x-2,y+2,4,15,0x7E0);
    print_rect(x-15,y-2,15,4,0x1F);
}

void initInter(){
    MADCTL(0xA0);
    fillScreen(0xFF1F);
}