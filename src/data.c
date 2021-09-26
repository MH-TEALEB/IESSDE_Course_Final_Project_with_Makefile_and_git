/*
 * @file data.c
 * @brief do some very basic data manipulation like Convert Integer-to-ASCII and ASCII-to-Integer.
 *
 * In this file, we make some very basic data manipulation like convert Integer-to-ASCII(my_itoa) and ASCII-to-Integer(my_atoi).
 *
 * @author MH_TEALEB
 * @date 7 June 2020
 *
 */
 
 
#include "data.h"


// Integer-to-ASCII function that converts data from a standard integer type into an ASCII string.
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	
	uint8_t  rem = 0;
    uint8_t sign = 0;	// To know if data is positive(sign will be 0) or negative( sign will be 1).
	uint8_t length = 0;
  
	// Handled The giving negative data.
    if (data < 0)
    {
        sign = 1;	// Mark as data is negative.
		data = - data;	// Convert data to positive to can process operations over it.
    }
  
    // Handle if data is 0.
    if (data == 0)
    {
        *ptr = '0';
        *(++ptr) = '\0';
        return 2;
    }
  
    // If the base is 10,take each digit of the data and convert it individually.
    while ( (data > 0) ){
			++length;
			rem = data  %  base;
			if (rem > 9){
				*(ptr + length - 1) = (rem - base) + 'a';
			} else {
				*(ptr + length - 1) = rem + '0';
			}
			data = data / base;
    }
	
  
    // If the data was negative, put negative character '-'.
    if (sign == 1){
		++length;	// increment the length by 1.
		*(ptr + length - 1) = '-';
	}
  
	// The string is reversed, so we should reverse it to be right.
    ptr = my_reverse(ptr, length);
	
	// Handling Null terminator.
	++length;	// increment the length by 1.
    *(ptr + length - 1) = '\0'; // Putting Null terminator at the end of the string.
  
    return length;	// Return the length of the converted string.
}


// ASCII-to-Integer function that converts data back from an ASCII represented string into an integer type.
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

    int32_t res = 0;		// Initialize result to be zro.
    int8_t sign = 1;	    // Initialize sign as positive.
    uint8_t i = 0;	    // Initialize index of first digit.

	 // Handle if sending empty ASCII string, return 0;
	 if (*ptr == '\0'){
			return 0;
	 }

	// If number is negative, then put sign negative.
	if (*(ptr + i) == '-'){
		sign = -1;
		++ptr; // make ptr points to element coming after the sign.
		--digits; // Decrease the count by 1, because i already count the '-' digit.
	}

	// Handling if send not numeric number. if so, send just the numeric numbers in the string and avoid the rest of the characters.
	// Also, remove the Null Terminator.
	while ( i < digits){
		if (*(ptr + i) >= '0' && *(ptr + i) <= '9'){
			++i;
		} else{
			digits = i;	// put the number of numeric digits that will be converted.
			i = 0;	// put zero to i index to let point to first digit.
			break;	// if find non numeric number, git out of the loop.
		}
	}

    // Convert from character number(ASCII) to integer number depend on the base.
    while (i < digits ){
        res = res * base + (*(ptr + i) - '0');
		++i; // increment the index by 1 to point to next element.
    }
    
    return (res * sign);	// Return result with sign

}
