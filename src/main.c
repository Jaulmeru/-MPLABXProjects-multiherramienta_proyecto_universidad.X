/**
 * @file cont_sending.c
 * @brief Codigo de ejemplo
 * Envia continuamente un dato ingresado en CLI
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 14/10/2024
 * @version 1.0
 */
#include <xc.h>
#include "config.h"             
#include "librerias/clock.h"   
#include "librerias/UART.h"
#include "librerias/SPI.h"
#include "librerias/commandLine.h"
#include "CLHandler.h"
#include "pinConfig.h"
#include "librerias/ST7789.h"

void fillScreen(uint8_t hi,uint8_t lo){
  uint32_t pixel = 240*240;
  *(slaves[0].ss_pin) &= ~(slaves[0].mask);
  *(PIN_DCX) &= ~(PIN_DCX_MASK);
  __delay_us(15);
  SPI_ByteExchange(0,0x2C);
  __delay_us(5);
  *(PIN_DCX) |= PIN_DCX_MASK;
  __delay_us(5);
  while(pixel--){
    SPI_ByteExchange(0,hi);
    SPI_ByteExchange(0,lo);
  } 
  __delay_us(15);
  *(slaves[0].ss_pin) |= (slaves[0].mask);
}

int main(void)
{
    Clock_Init(16000);
    pinInit();
    UART_Init(9600);
    SPI_master_init();
    commandLineInit();
    
        
        ST7789Init();      
        __delay_ms(2000);
        
        // 000010xx
        //MADCTL(0x08);
        //fillScreen(0xFF,0xFF);
        // 000011xx
        //MADCTL(0x0C);
        //fillScreen(0xFF,0x00);
        // 000110xx
        //MADCTL(0x18);
        //fillScreen(0x00,0xFF);
        // 001010xx
        //MADCTL(0x28);
        //fillScreen(0x55,0x55);
        // 010010xx
        //MADCTL(0x48);
        //fillScreen(0x69,0x69);
        // 100010xx
        MADCTL(0x88);
        fillScreen(0x00,0x00);
        
    while(1)
    {
        if(UART_RxAvailable()){
            addToBuffer(UART_Rx());
        }
        CL_ErrorHandler(commandProcess());
        
               
        __delay_ms(500);
    }
}