# SPI  

## Que es y como funciona  

[WIP] Explicacion y base teorica sobre SPI

## Impliementación en PIC18F45K50  

El pic cuenta con un modulo llamado MASTER SYNCHRONOUS
SERIAL PORT (MSSP) con el que se puede generar señales SPI y I2C tanto como maestro y esclavo.  

## Modo maestro

Al ser confugurado como maestro, nuestro PIC es el que debe proporcionar el reloj, por lo que se debe utilizar el modulo generador de BaudRate.  
Para esto solamente hay que agregar un valor al registro SSPxADD segun la formula:  

SSPxADD = (FOSC / (FClock * 4)) - 1

Siendo FOSC la frecuencia de trabajo del PIC y FClock la frecuencia buscada

Haciendo el calculo para nuestra frecuencia de 48MHz, hay que considerar que solo podremos generar frecuencias dentro de un rango.  
| SSPxADD | FClock |
| -- | -- |
| 0x00 | 12MHz |
| 0x77 | 100kHz |
| 0xFF | 46.875kHz |
