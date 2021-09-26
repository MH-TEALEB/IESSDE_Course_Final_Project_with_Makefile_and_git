/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author MH_TEALEB
 * @date 6 June 2021
 *
 */
#include "memory.h"

/***********************************************************
 Functions Definition
***********************************************************/

//	Move data from the source location to the destination loaction. 
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	// Create a temporary Array to hold data of src.
   uint8_t temp[length];
  
   // Copy data from src to temp.
   for (size_t i = 0; i < length; ++i){
       *(temp + i) = *(src + i);
   }
  
   // Copy data from temp to dst.
   for (size_t i = 0; i < length; ++i){
       *(dst + i) = *(temp + i);
   }   
   
   return dst; // Return the destination location.
}


//	Copy data from the source location to the destination loaction. 
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	// Copy contents of src to dst.
   for (size_t i = 0; i < length; ++i){
       *(dst + i) = *(src + i);
   }
   
	return dst;	// Return the destination location.
}


//	Set all locations of a given memory to a given value.
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	// Set value to each memory location.
	for (size_t i = 0; i < length; ++i){	// Loop for each memory location.
		*(src + i) = value;	// Set the value to each memory location.
	}
	
	return src;	// Return the source location after being set.
}


//	Zero out all of given memory locations.
uint8_t * my_memzero(uint8_t * src, size_t length){
	
	// Zero out of each memory location.
	for (size_t i = 0; i < length; ++i){	// Loop for each memory location.
		*(src + i) = 0;	// Zero out each memory location.
	}
	
	return src;	// Return the pointer to the source location after being zeroed. 
}


//	Reverse the order of all of the bytes.
uint8_t * my_reverse(uint8_t * src, size_t length){
	
	// Define Temporary variable to hold data temporary and initialize it to zero.
	uint8_t temp = 0;
	
	// Reverse all of the bytes of the given memory.
	for (size_t i = 0; i < (length / 2); ++i){	// Loop for each memory location until the middle.
		temp = *(src + i);		//	Put the data in the forward i memory location temporary in temp variable.
		*(src + i) = *(src + length - i - 1); 	// Put the data in the corresponding backward i memory location in its reversed forward corresponding memory location.
		*(src + length - i - 1) = temp;	// Put the temp data in its reversed corresponding backward i memory location.
	}
	
	return src;	// Return the  pointer to reversed memory location.
}


//	Allocate number of words in dynamic memory.
int32_t * reserve_words(size_t length){
	
	// Define a dynamic pointer to hold the address of the dynamic memory.
	int32_t * ptr;
	
	// Make ptr pointer points to dynamic memory of length number of words.
	ptr = (int32_t*) malloc(length * sizeof(int32_t));
	
	// Test to see if not successful, return NULL pointer or successful to return the pointer.
	if (ptr == NULL){
		return NULL;	// Return NULL pointer if NOT successful.
	}
	
	return ptr; // Return ptr pointer if successful.
}


//	Free a dynamic memory allocation.
void free_words(uint32_t * src){

	free((uint32_t *) src);	// free the dynamic memory allocation.
}
