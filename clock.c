#include "clock.h"

ERROR_CODE Clock_Init(int16_t s16Timeout){
    ERROR_CODE returnCode = ERROR_CODE_OK;
    bool bItTimeEn = (0 >= s16Timeout) ? false : true;
    
    if(ERROR_CODE_OK == returnCode){
        bool bStatus = false;
        do{
            bStatus = OSCCON2bits.HFIOFR;
            s16Timeout--;
        }while((false == bStatus) && ((0 < s16Timeout) || (false == bItTimeEn)));
        if (false == bStatus){
            returnCode = ERROR_CODE_TIMEOUT;
        }
    }
    
    if(ERROR_CODE_OK == returnCode){
        OSCCON2bits.INTSRC = 1;  // 31.25KHz -> HF osc
        OSCCONbits.IRCF = 7;    // HF osc -> 16MHz
        
        bool bStatus = false;
        do{
            bStatus = OSCCONbits.HFIOFS;
            s16Timeout--;
        }while((false == bStatus) && ((0 < s16Timeout) || (false == bItTimeEn)));
        if (false == bStatus){
            returnCode = ERROR_CODE_TIMEOUT;
        }
    }
    
    if(ERROR_CODE_OK == returnCode){
        bool bStatus = false;
        do{
            bStatus = OSCCONbits.OSTS;
            s16Timeout--;
        }while((false == bStatus) && ((0 < s16Timeout) || (false == bItTimeEn)));
        if (false == bStatus){
            returnCode = ERROR_CODE_TIMEOUT;
        }
    }
        if(ERROR_CODE_OK == returnCode){
        OSCTUNEbits.SPLLMULT = 1;
        OSCCON2bits.PLLEN = 1;
        bool bStatus = false;
        do{
            bStatus = OSCCON2bits.PLLRDY;
            s16Timeout--;
        }while((false == bStatus) && ((0 < s16Timeout) || (false == bItTimeEn)));
        if (false == bStatus){
            returnCode = ERROR_CODE_TIMEOUT;
        }
    }
    
    
    if(ERROR_CODE_OK == returnCode){
        OSCCON2bits.PRISD = 0;  //
        OSCCONbits.SCS = 0;     // Sys Clock -> primary source
    }
    
    return (returnCode);
}
