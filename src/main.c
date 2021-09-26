/**
 * @file main.c
 * @brief Main entry point to the Course1 Assessment.
 *
 * It is used to call course1() function if COURSE1 was defined before.
 * COURSE1 would be defined in Makefile to make compile time switch.
 *
 * @author MH_TEALEB
 * @date 4 June 2021
 *
 */

#include <stdint.h>
#include "course1.h"
#include "platform.h"
#include "memory.h"
#include "data.h"
#include "stats.h"


/* The entry point to main function. */
int main(void) {
  
  #ifdef COURSE1	// Call course1() if COURSE1 is defined.
  	
  	course1();	// Function Calling to course1().
  
  #endif
  
  return 0;
}
