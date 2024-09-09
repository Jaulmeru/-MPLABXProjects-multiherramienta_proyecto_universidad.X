/* 
 * File:   clock.h
 * Author: admin
 *
 * Created on 1 de septiembre de 2024, 07:34 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include "variables.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define _XTAL_FREQ 48000000
    
ERROR_CODE Clock_Init(int16_t s16Timeout);


#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_H */

