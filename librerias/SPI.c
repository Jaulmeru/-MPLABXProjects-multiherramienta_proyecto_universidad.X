#include "SPI.h"

void SPI_BaudRateGen(int32_t FClock){
    uint32_t baudReg = (FOSC / (FClock * 4)) - 1;
    if(baudReg > 0xFF){
        SPI_ErrorHandler(ERROR_CODE_SPI_BR_OVERRANGE);
        return;
    }
    SSP1ADD = baudReg;
}
