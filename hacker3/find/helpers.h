/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

// implement the binary search
bool binary_search(int value, int array[], int start, int end);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);

//implement the merge sort
void merge_sort(int *values, int start, int end);

//merge two list
void merge(int *values, int start, int middle, int end);
