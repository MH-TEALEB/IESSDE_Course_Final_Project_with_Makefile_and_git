/*
 * @file stats.c
 * @brief Implementation file to perform printing, sorting and statistical analytics on a dataset.
 *
 *
 * @author Mohamed Tealeb
 * @date 05 June 2021
 *
 */


#include <stdio.h>
#include "stats.h"
#include "platform.h"

/***********************************************************
 Function Definitions
***********************************************************/

 // The function that prints the array on the Screen.
   void print_array(unsigned char *test_ptr, unsigned char length){
 	#ifdef VERBOSE
        	for (unsigned char i = 0; i < length; ++i){
            		PRINTF("test[%d] = %d\t", i, *(test_ptr + i) );
        	}
        	PRINTF("\n\n");
	#endif   
   }


 // The function that Sorts the array from the Largest to the Smallest element.
    void sort_array(unsigned char *test_ptr, unsigned char length){
        unsigned char temp;
        for (unsigned char i = 0; i < (length - 1); ++i){
            for (unsigned char k = i+1; k < length; ++k){
                if (*(test_ptr + k) > *(test_ptr + i)){
                    temp = *(test_ptr + i);
                    *(test_ptr + i) = *(test_ptr + k);
                    *(test_ptr + k) = temp;
                }
            }
        }
        print_array(test_ptr, length);
    }


 // The function that finds the maximum value of the array.
   unsigned char find_maximum(unsigned char *test_ptr, unsigned char length){
        return *test_ptr;
   }


 // The function that finds the minimum value of the array.
   unsigned char find_minimum(unsigned char *test_ptr, unsigned char length){
        return *(test_ptr + length - 1);
   }


 // The function that finds the mean value of the array.
   unsigned char find_mean(unsigned char *test_ptr, unsigned char length){
       unsigned short sum = *test_ptr;
        for (unsigned char i = 1; i < length; ++i){
                sum += *(test_ptr + i);
        }
        return (sum/length);
   }


 // The function that finds the median value of the array.
   unsigned char find_median(unsigned char *test_ptr, unsigned char length){
        return ((*(test_ptr + 19) + *(test_ptr + 20)) / 2);
   }


 // The Function that prints the statistics of the array including maximum, minimum, mean, and median.
    void print_statistics(unsigned char maximum, unsigned char minimum, unsigned char mean, unsigned char median){
        PRINTF("The maximum value of the array = %d\n", maximum);
        PRINTF("The minimum value of the array = %d\n", minimum);
        PRINTF("The mean value of the array = %d\n", mean);
        PRINTF("The median value of the array = %d\n", median);
    }
