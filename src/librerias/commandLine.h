/**
 * @file commandLine.h
 * @brief Linea de comandos lista para utilizar funciones de forma sencilla en tiempo de ejecucion
 *  
 * @author Javier Mendoza (javierulisesmruiz@gmail.com)
 * @date 06/10/2024
 * @version 1.0
 */

#ifndef COMMANDLINE_H
#define	COMMANDLINE_H


#include "UART.h"


#define BUFFLEN 100 //!< Longitud maxima del comando a recibir 
#define DELIMITER 0x20 //!< Valor que se utilizara para separar comandos y parametros
#define NUMPARAMS 5 //!< Maximo de parametros que tendra un comando
#define WORDLEN 17 //!< Longitud maxima de los parametros + 1

///////////////////////////////
//   Variables para buffer   //
///////////////////////////////
const uint8_t charStop = 0x0A; //!< Caracter que iniciara la ejecucion del comando   0x0D = [Enter]

uint8_t buffCount = 0; //!< Contador de los caractares guardados en buffer
uint8_t charBuff[BUFFLEN]; //!< Buffer de caracteres recibidos
bool commandLineEnable = 0; //!< Si no se activa este valor, los datos recibidos no se envian al buffer
bool flagCommandReady = 0; //!< Bandera que indica si el comando esta listo para ejecutarse
uint8_t command[WORDLEN]; //!< Comando extraido del buffer
uint8_t param[NUMPARAMS][WORDLEN]; //!< Parametros extraidos del buffers

typedef enum{
    EC_CL_OK,
    EC_CL_BUFFOVER,
    EC_CL_NOWORDS,
    EC_CL_WORDOVER,
    EC_CL_MAXNUMPARAMS,
    EC_CL_WRONGNUMPARAMS,
    EC_CL_WRONGCOMMAND,
}CL_ERROR_CODE;

/**
 * @brief Muestra las instrucciones y habilita la linea de comandos
 */
void commandLineInit();

/**
 * @brief Deshabilita la linea de comandos
 */
void commandLineDeinit();

/**
 * @brief Deja la linea de comando lista para volver a usarse de cero
 */
void commandLineReset();

/**
 * @brief Toma un caracter para integrarlo al buffer o arrancar una accion especial
 * @brief 0x0D [Enter] => Termina el comando y se comienza a procesar 
 * @brief 0x7F [BackSpace] =>  Borra el ultimo caracter
 * @brief 0x1B [Escape] =>  Borra todo lo escrito
 * @param newchar
 */
void addToBuffer(char newchar);

/**
 * @brief Deja en 0 el charBuff y el buffCount
 */
void clearBuff();

/**
 * @brief Limpia el ultimo caracter en el buffer y en la linea de comando
 */
void clearCharInLine();

/**
 * @brief Deja en 0x00 len posiciones de array
 * @param array
 * @param len
 */
void clearArray(uint8_t* array, uint8_t len);

/**
 * @brief Toma el buffer, separa el comando y los parametros y los ejecuta
 * @return Error
 */
CL_ERROR_CODE commandProcess();

/**
 * @brief Cantidad de palabras en el buffer
 * @return palabras = comando + parametros
 */
uint8_t countWords(void);

/**
 * @brief Guarda la palabra en la posicion wordNum del buffer en donde apunta pWord
 * @param wordNum 
 * @param pWord 
 * @return 
 */
bool getWord(uint8_t wordNum, uint8_t* pWord);

/**
 * @brief Manejador de errores de la linea de comandos
 * @param errorCode
 */
void CL_ErrorHandler(CL_ERROR_CODE);

#endif	/* COMMANDLINE_H */

