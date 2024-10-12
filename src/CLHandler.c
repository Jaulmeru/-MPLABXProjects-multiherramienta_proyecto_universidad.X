/**
 * @file CLHandler.c
 * @brief Definicion de funciones para ejecutar en la linea de comandos
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 11/10/2024
 * @version 0.1
 */
#include "CLHandler.h"

CL_ERROR_CODE CL_CommandHandler(uint8_t numParams){
    for (int i = 0; i < NUMCOMMANDS; i++) {
        if(strcmp(command, comandos[i]) == 0){
            // Ejecutar función correspondiente
            if(cantParams[i] != numParams) return EC_CL_WRONGNUMPARAMS;
            switch (i) {
                case 0:
                    commandLineDeinit();
                    break;
                case 1:
                    cliHelp();
                    break;
                case 2:
                    printf("comand 3\r\n");
                    break;
            }
            return EC_CL_OK;
        }
    }
    return EC_CL_WRONGCOMMAND;
}

void cliHelp(){
    printf("Lista de comandos:\r\n");
    for(uint8_t i = 0; i < NUMCOMMANDS; i++){
        printf("%s\r\n",comandos[i]);
    }
}