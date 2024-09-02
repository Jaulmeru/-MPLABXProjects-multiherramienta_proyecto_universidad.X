# UART  

## Que es y como funciona  

[WIP] Explicacion y base teorica sobre UART

## Impliementación en PIC18F45K50  

El PIC seleccionado cuenta con un modulo EUSART (Enhanced Universal Synchronous Asynchronous Receiver Transmitter) por lo que se podra trabajar en modo asincrono o sincrono.

La operacion del modulo EUSART es controlada por 3 registros  

- Transmit Status and Control (TXSTAx)
- Receive Status and Control (RCSTAx)
- Baud Rate Control (BAUDCONx)

| Primera columna | Segunda columna | Tercera columna |
| -- | -- | -- |
| Contenido 1-1 | Contenido 1-2 | Contenido 1-3 |
| Contenido 2-1 | Contenido 2-2 | Contenido 2-3 |
| Contenido 3-1 | Contenido 3-2 | Contenido 3-3 |
