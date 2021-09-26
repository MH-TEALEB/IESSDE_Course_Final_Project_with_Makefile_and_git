/*
 * @file stats.h
 * @brief Header File for stats.c
 *
 * It has a functions prototypes and documentation for each function that implemented in stats.c file.
 *
 * @author MH_TEALEB
 * @date 3 October 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief A function that prints the array on the Screen.
 *
 * It is the function that taking the test array values and print them on the screen.
 *
 * @param unsigned char pointer as pointer to test array.
 * @param unsigned char as the length of the test array.
 *
 * @return Doesn't Return any Values.
 */
void print_array(unsigned char *test_ptr, unsigned char length);


/**
 * @brief A function that sort the array.
 *
 * It is the function that taking the test array elements and sort them from the largest to the smallest.
 *
 * @param unsigned char pointer as pointer to test array.
 * @param unsigned char as the length of the test array.
 *
 * @return Doesn't Return any Values.
 */
void sort_array(unsigned char *test_ptr, unsigned char length);


/**
 * @brief A function that finds the maximum value of the array.
 *
 * It is the function that taking the sorted test array elements and return the Zeroth element as its maximum.
 *
 * @param unsigned char pointer as pointer to test array.
 * @param unsigned char as the length of the test array.
 *
 * @return unsigned char as the maximum value of the array.
 */
unsigned char find_maximum(unsigned char *test_ptr, unsigned char length);


/**
 * @brief A function that finds the minimum value of the array.
 *
 * It is the function that taking the sorted test array and return the last element as its minimum.
 *
 * @param unsigned char pointer as pointer to test array.
 * @param unsigned char as the length of the test array.
 *
 * @return unsigned char as the minimum value of the array.
 */
unsigned char find_minimum(unsigned char *test_ptr, unsigned char length);


/**
 * @brief A function that finds the mean value of the array.
 *
 * It is the function that taking the sorted test array values and add them together then divide by its length to find the mean value and return it.
 *
 * @param unsigned char pointer as pointer to test array.
 * @param unsigned char as the length of the test array.
 *
 * @return unsigned char as the mean value of the array.
 */
unsigned char find_mean(unsigned char *test_ptr, unsigned char length);


/**
 * @brief A function that finds the median value of the array.
 *
 * It is the function that taking the sorted test array then taking the 19th and 20th elements and adding them together then divide by 2 to get median value and return it.
 *
 * @param unsigned char pointer as pointer to test array.
 * @param unsigned char as the length of the test array.
 *
 * @return unsigned char as the median value of the array.
 */
unsigned char find_median(unsigned char *test_ptr, unsigned char length);


/**
 * @brief A function that prints the statistics of the array including maximum, minimum, mean, and median.
 *
 * It is the function that taking the values of maximum, minimum, mean, and median and print them on the screen.
 *
 * @param unsigned char as the maximum value of the array that returned from find_maximum().
 * @param unsigned char as the minimum value of the array that returned from find_minimum().
 * @param unsigned char as the mean value of the array that returned from find_mean().
 * @param unsigned char as the median value of the array that returned from find_median().
 *
 * @return Doesn't Return any Values.
 */
void print_statistics(unsigned char maximum, unsigned char minimum, unsigned char mean, unsigned char median);




#endif /* __STATS_H__ */

