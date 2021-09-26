/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author MH_TEALEB
 * @date 6 June 2021
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>	// includes standard data types.
#include <stddef.h> // includes the definition of the size_t.
#include <stdlib.h>	// To can use the dynamic memory allocation functions.

/**
* @brief move data from the source location to the destination loaction. 
*
* It  takes two byte pointers (one source and one destination) and a length of bytes,
* to move from the source location to the destination. 
* It handles overlap of source and destination with no data corruption.
*
* @param src pointer to source location.
  @param dst pointer to destination location.
  @param length length of data to be moved.
*
* @return pointer to the destination location.		
*/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);


/**
* @brief copy data from the source location to the destination loaction. 
*
* It  takes two byte pointers (one source and one destination) and a length of bytes,
* to copy from the source location to the destination. 
* If overlaps happened of source and destination, the behavior is undefined and data will be corrupted.
*
* @param src pointer to source location.
  @param dst pointer to destination location.
  @param length length of data to be moved.
*
* @return pointer to the destination location.		
*/
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
* @brief  set all locations of a given memory to a given value.
*
* It takes a pointer to a source memory location, a length in bytes and sets all locations of that memory to a given value.
*
* @param src pointer to source location.
  @param length length of memory locations to be set.
  @param value value that will be set to these memory locations. 
*
* @return pointer to the source location after being set.		
*/
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);


/**
* @brief  zero out all of given memory locations.
*
* It takes a pointer to a source memory location, a length in bytes and zero out all of that memory.
*
* @param src pointer to source location.
  @param length length of memory locations to be zero. 
*
* @return pointer to the source location after being zero.		
*/
uint8_t * my_memzero(uint8_t * src, size_t length);


/**
* @brief  reverse the order of all of the bytes.
*
* It takes a pointer to a memory location and a length in bytes and reverses the order of all of the bytes.
*
* @param src pointer to memory location.
  @param length length of memory locations to be reversed. 
*
* @return pointer to the reversed memory location.		
*/
uint8_t * my_reverse(uint8_t * src, size_t length);


/**
* @brief  allocate number of words in dynamic memory.
*
* It takes number of words to allocate in dynamic memory, 
* and should return a pointer to memory if successful, or a Null Pointer if not successful.
*
* @param length length of memory locations to be allocated in dynamic memory. 
*
* @return a pointer to memory if successful, or a Null Pointer if not successful.		
*/
int32_t * reserve_words(size_t length);


/**
* @brief  free a dynamic memory allocation.
*
* It should free a dynamic memory allocation by providing the pointer src to the function.
*
* @param src pointer of dynamic memory allocation. 
*
* @return Nothing to return.		
*/
void free_words(uint32_t * src);


#endif /* __MEMORY_H__ */
