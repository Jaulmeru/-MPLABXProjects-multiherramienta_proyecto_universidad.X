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

Estos son los pines que se utilizan para la comunicacion SPI y su configuracion TRIS, por lo que sera lo siguiente a configurar.

| Señal | Abreviatura | I/O | PIN | TRIS |
| -- | -- | -- | -- | -- |
| Serial Clock (Master) | SCK | RB1 | 34 | 0 |
| Serial Clock (Slave) | SCK | RB1 | 34 | 1 |
| Serial Data Out | SDO | RB3 | 36 | 0 |
| Serial Data In | SDI | RB0 | 33 | 1 |
| Slave Select | SS | RA5 | 7 | 1 |

Ya que estan configurados estos pines se debe habilitar el puerto con SSPEN

- SSPxCON1  

  - SSPEN: Synchronous Serial Port Enable bit  
In SPI mode:  
    - 1 = Enables serial port and configures SCK, SDO, SDI and SS as the source of the serial port pins  
    - 0 = Disables serial port and configures these pins as I/O port pins

  - CKP: Clock Polarity Select bit  
    In SPI mode:
    - 1 = Idle state for clock is a high level
    - 0 = Idle state for clock is a low level
  - SSPM<3:0>: Synchronous Serial Port Mode Select bits  
    - 1010 = SPI Master mode, clock = FOSC/(4 * (SSPxADD+1))

- SSPxSTAT
  - CKE: SPI Clock Edge Select bit (SPI mode only)  
    In SPI Master or Slave mode:
    - 1 = Transmit occurs on transition from active to Idle clock state
    - 0 = Transmit occurs on transition from Idle to active clock state

  - SMP: SPI Data Input Sample bit  
    SPI Master mode:  
    - 1 = Input data sampled at end of data output time
    - 0 = Input data sampled at middle of data output time

### Esclavos

En la tabla siguiente se muestran los esclavos que se utilizaran. 0 - 2 son usados para dispisitivos internos del producto y 3 - 5 son disponibles para el usuario.

| Nombre | Dispositivo | Pin SS | Nodo PCB | Nota |
| -- | -- | -- | -- | -- |
| SLAVE0 | Display TFT | RB2 | SS_TFT | Requiere un pin extra DC |
| SLAVE1 | Display Touch | RB4 | SS_Touch |  |
| SLAVE2 | SD card | RD7 | SS_SD |  |
| SLAVE3 | User SPI 1 | RB5 | SS_1 |  |
| SLAVE4 | User SPI 2 | RB6 | SS_2 |  |
| SLAVE5 | User SPI 3 | RB7 | SS_3 |  |

### Configuracion de los esclavos

Cada dispositivo puede tener una configuracion diferente. Para los habilitados para el usuario, esta configuracion sera variable.

#### SLAVE0 - Display TFT

| Registro | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 | HEX |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| SSPCON1 | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0x2A |
| SSPCON3 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0x10 |
| SSPSTAT | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0x00 |

#### SLAVE1 - Display Touch

| Registro | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 | HEX |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| SSPCON1 | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0x2A |
| SSPCON3 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0x10 |
| SSPSTAT | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0x00 |

#### SLAVE2 - SD Card

| Registro | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 | HEX |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| SSPCON1 | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0x2A |
| SSPCON3 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0x10 |
| SSPSTAT | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0x00 |

#### SLAVE3 a SLAVE5 - USER SPI

| Registro | Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 | HEX |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| SSPCON1 | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 0x2A |
| SSPCON3 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0x10 |
| SSPSTAT | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0x00 |
