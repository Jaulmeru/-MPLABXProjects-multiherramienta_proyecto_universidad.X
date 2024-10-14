/**
 * @file CLHandler.h
 * @brief Definicion de comandos y su numero de parametros
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 11/10/2024
 * @version 0.1
 */

#ifndef CLHANDLER_H
#define	CLHANDLER_H

#include "librerias/commandLine.h"

#define NUMCOMMANDS 4 //!< Cantidad de comandos programados

int global_x = 0;

const char *comandos[] = {
    "cliDeinit", //1
    "help", //2
    "spiconfig",  //3
    "changevar"  //4
};
const uint8_t cantParams[] = {
    0, //1
    0, //2
    2,  //3
    2  //4
};


CL_ERROR_CODE CL_CommandHandler(uint8_t numParams);

void cliHelp();

#endif	/* CLHANDLER_H */

