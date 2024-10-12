/**
 * @file commandLine.c
 * @brief Linea de comandos lista para utilizar funciones de forma sencilla en tiempo de ejecucion
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 06/10/2024
 * @version 1.0
 */

#include "commandLine.h"
#include "../CLHandler.h"
#include <string.h>

void commandLineInit(){
    printf("Linea de comandos iniciada\r\n");
    printf("Sintaxis:\r\n");
    printf("<comando> <parametro1> <parametroN>\r\n");
    printf("[Enter]     Para enviar el comando\r\n");
    printf("[Backspace] Para borrar un caracter\r\n");
    printf("[Escape]    Cancelar la escritura de un comando\r\n");
    clearBuff();
    commandLineEnable = 1;
    printf("\r\n> ");
}

void commandLineDeinit(){
    printf("\r\nLinea de comandos desactivada\r\n\r\n");
    clearBuff();
    commandLineEnable = 0;
}

void commandLineReset(){
    clearBuff();
    clearArray(&command[0],PARAMLEN);
    clearArray(&param[0][0],PARAMLEN * NUMPARAMS);
    printf("\r\n> ");
}

void addToBuffer(char newchar){
    if(commandLineEnable){
        switch(newchar){
            case 0x00: break;
            case charStop:
                flagCommandReady = 1;
                printf("\r\n");
                break;
            case 0x7F:
                if(buffCount>0)clearCharInLine();
                break;
            case 0x1B:
                while(buffCount>0){
                    clearCharInLine();
                }
                break;
            default:
                if(buffCount >= BUFFLEN){
                    CL_ErrorHandler(EC_CL_BUFFOVER);
                    break;
                }
                if(newchar > 0x7F) break;
                charBuff[buffCount] = newchar;
                buffCount++;
                UART_Tx(newchar);
        }
    }
}

void clearBuff(){
    for(uint8_t i = 0;i < BUFFLEN;i++){
        charBuff[i] = 0x0;
    }
    buffCount = 0x0;
}

void clearCharInLine(){
    charBuff[--buffCount] = 0x00;
    printf("\b \b");
}

void clearArray(uint8_t* array, uint8_t len){
    for(uint8_t i = 0; i < len; i++){
        *(array + i) = 0;
    }
}

CL_ERROR_CODE commandProcess(){
    if(!flagCommandReady) return EC_CL_OK;
    flagCommandReady = 0;
    CL_ERROR_CODE status = EC_CL_OK;
    
    uint8_t nWords = countWords();
    
    
    if(!nWords){
        status = EC_CL_NOWORDS;
    }
    
    if(nWords > NUMPARAMS){
        status = EC_CL_MAXNUMPARAMS;
    }
      
    if(status == EC_CL_OK){
        if(nWords){
            if(getWord(0,&command[0])) status = EC_CL_WORDOVER;
            else printf("Comando: %s\r\n",command);
        }
    }
    if(status == EC_CL_OK){
        for(uint8_t i = 0; i < nWords - 1; i++){
            if(getWord(i+1,&param[i][0])){
                 status = EC_CL_WORDOVER;
                 break;
            }
            else printf("Parametro %d: %s\r\n",i+1,param[i]);
        }
    }
    
    if(status == EC_CL_OK){
       status = CL_CommandHandler(nWords-1);    
    }
    
    commandLineReset();
    return status;
}

uint8_t countWords(void){
   uint8_t numWords = 0;   
   uint8_t currChar = charBuff[0];
   
   if(currChar) numWords++;
   for(uint8_t i=0;i<BUFFLEN && currChar;i++){
      currChar = charBuff[i];
      if(currChar==DELIMITER) numWords++;
   }
   return numWords;
}

bool getWord(uint8_t wordNum, uint8_t* pWord){
 
   uint8_t tmpWord[PARAMLEN];
   uint8_t delimitCount = 0;
   bool active = 0;
   uint8_t buffId;
   uint8_t wordId = 0;
   
   for(buffId = 0;buffId < BUFFLEN; buffId++){
       if(!wordNum) active = 1;
       if(charBuff[buffId] == DELIMITER && !active){
           delimitCount++;
           if(delimitCount == wordNum){
               active = 1;
               buffId++; // Al encontrar un espacio, avanza para tomar el caracter siguiente
           }
       }
       if(active){
           if(charBuff[buffId] == DELIMITER || charBuff[buffId] == 0x00) break;
           tmpWord[wordId++] = charBuff[buffId];
       }
   }
   
    if(wordId > PARAMLEN){
        return 1;
    }
    for(int i = 0; i < PARAMLEN; i++){
        *(pWord + i) = tmpWord[i];
    }
   return 0;
}

void CL_ErrorHandler(CL_ERROR_CODE errorCode){
    switch(errorCode){
        case EC_CL_OK: break;
        case EC_CL_BUFFOVER:
            printf("\r\nEC_CL_BUFFOVER\r\n");
            commandLineReset();
        break;
        case EC_CL_NOWORDS:
            printf("\r\nEC_CL_NOWORDS\r\n");
            commandLineReset();
        break;
        case EC_CL_WORDOVER:
            printf("\r\nEC_CL_WORDOVER\r\n");
            commandLineReset();
        break;
        case EC_CL_MAXNUMPARAMS:
            printf("\r\nEC_CL_MAXNUMPARAMS\r\n");
            commandLineReset();
        break;
        case EC_CL_WRONGNUMPARAMS:
            printf("\r\nEC_CL_WRONGNUMPARAMS\r\n");
            commandLineReset();
        break;
        case EC_CL_WRONGCOMMAND:
            printf("\r\nEC_CL_WRONGCOMMAND\r\n");
            commandLineReset();
        break;
    }
}