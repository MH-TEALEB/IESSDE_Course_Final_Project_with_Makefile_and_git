/*
 * @file data.h
 * @brief This file is data.h header file that do some very basic data manipulation.
 *
 * This header file provides the define of each Base, Integer-to-ASCII function that can convert data from a standard integer type into an ASCII string,
 * and ASCII-to-Integer function that can convert data back from an ASCII represented string into an integer type.
 * 
 * @author MH_TEALEB
 * @date 7 June 2021
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

// Include the other used header files.
#include <stdint.h>	// include stdint header file for using standard data types.
#include "memory.h"	// include memory header file to call the my_reverse() function.

// Define the Base.
#define BASE_2	2
#define BASE_8	8
#define BASE_10	10
#define BASE_16	16

/**
* @brief convert data from a standard integer type into an ASCII string. 
*
* Integer-to-ASCII function that converts data from a standard integer type into an ASCII string.
* The data is passed in as a signed 32-bit integer.
* It supports bases 2, 8, 10, and 16. 
* The converted character string (including the null terminator at the end) will be held using  the uint8_t* pointer passed in as a parameter (ptr).
*  It returns the length of the converted data (including a negative sign).
*
* @param data a signed 32-bit integer number that needed to be converted.
  @param ptr pointer to the converted character string.
  @param base specifying the integer value of the base you wish to convert to (base).
*
* @return  the length of the converted data (including a negative sign and Null terminator).
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
* @brief convert data back from an ASCII represented string into an integer type.. 
*
* ASCII-to-Integer function that converts data back from an ASCII represented string into an integer type.
* The data is passed in as a signed 32-bit integer.
* It supports bases 2, 8, 10, and 16. 
* The character string to convert is passed in as a uint8_t * pointer (ptr).
* The number of digits in the character set is passed in as a uint8_t integer (digits).
*  It returns The converted 32-bit signed integer.
*
* @param ptr a pointer points to the character string to be converted. 
  @param digits holds the number of digits in the character set.  
  @param base holds the integer value of the base you wish to convert to (base).
*
* @return  the converted 32-bit signed integer.
*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
