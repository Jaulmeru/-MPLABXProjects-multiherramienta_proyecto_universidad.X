# Idea general  

La idea del proyecto es crear un dispositivo para ayudar en el manejo de señales dentro de un laboratorio electronico.

## Funciones  

Se plantea cumplir con las siguientes funciones como minimo producto viable  

- Leer, almacenar y emitir.  
  - [UART](UART.md) por puerto serial
  - I2C
  - SPI
  - Pulsos a travez de infrarrojo  

- Contar con una interfaz para cargar archivos desde PC  

## Requisitos de hardware  

- Utilizar bateria para no tener que estar conectado todo el tiempo
- Puerto USB C de carga y transmision de datos
- Contar con un display para la interaccion del usuario
- Diseñar una interfaz touch sencilla
- Interfaz Rx-Tx infrarojo

## Hardware y herramientas seleccionadas  

- PIC18F45K50 ([datasheet][pic])
  - MPLAB X IDE  
  - XC8
- Display 2.4" TFT 240x320 St7789 ([datasheet][display])

<sup style="display: inline-block;">[**README**](/README.md)</sup>


[pic]: referencias/Datasheet%20PIC18F2X_45K50.pdf
[display]: referencias/Datasheet%20ST7789.pdf