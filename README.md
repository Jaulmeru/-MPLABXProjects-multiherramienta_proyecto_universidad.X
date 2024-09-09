# Idea general  

La idea del proyecto es diseñar un dispositivo compacto para estudiantes y profesionales técnicos e ingenieros de la electrónica con el fin recibir, almacenar y transmitir señales alámbricas e inalámbricas dentro de un laboratorio, con el fin de agilizar el proceso de diseño, pruebas y diagnóstico de errores.

## Funciones  

Se plantea cumplir con las siguientes funciones como minimo producto viable.  

- Leer, almacenar y emitir.  
  - [UART](documentacion/UART.md) por puerto serial
  - I2C
  - SPI
  - Pulsos infrarrojos  

- Contar con una interfaz para carga y descarga de archivos desde PC por puerto c  

## Requisitos de hardware  

- Utilizar bateria para facilitar su transporte y ampliar su verzatilidad.
- Puerto USB C de carga y transmision de datos
- Integrar un display TFT para la interacción del usuario
- Diseñar una interfaz touch sencilla y dinámica
- Interfaz Rx-Tx infrarojo

## Hardware y herramientas seleccionadas  

- PIC18F45K50 ([datasheet][pic])
  - MPLAB X IDE  
  - XC8
- Display 2.4" TFT 240x320 St7789 ([datasheet][display])

<sup style="display: inline-block;">[**README**](/README.md)</sup>


[pic]: documentacion/referencias/Datasheet%20PIC18F2X_45K50.pdf
[display]: documentacion/referencias/Datasheet%20ST7789.pdf