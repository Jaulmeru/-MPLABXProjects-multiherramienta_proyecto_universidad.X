/* 
 * File:   clk_variables.h
 * Author: admin
 *
 * Created on September 9, 2024, 12:24 PM
 */

#ifndef CLK_VARIABLES_H
#define	CLK_VARIABLES_H

#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include <stdio.h>
#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum{
        ERROR_CODE_OK,
        ERROR_CODE_TIMEOUT,
    }CLK_ERROR_CODE;


#ifdef	__cplusplus
}
#endif

#endif	/* CLK_VARIABLES_H */

