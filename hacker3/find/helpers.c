/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    // TODO: implement a searching algorithm,Binary search
    return binary_search(value, array, 0 ,n - 1);
}

bool binary_search(int value, int array[], int start, int end)
{
    if (start > end)
        return false;
    int middle = (start + end) / 2;
    if (value > array[middle])
        return binary_search(value, array, middle + 1, end);
    else if (value < array[middle])
        return binary_search(value, array, start, middle - 1);
    else
        return true;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm,merge sort
    merge_sort(values, 0, n - 1);
    for(int i = 0;i < n;i++)
    {
        printf("%d ",values[i]);
    }
    return;
}

// implement the merge sort
void merge_sort(int *values, int start, int end)
{
    if (end - start < 1)
        return;
    int middle = (start + end) / 2;
    merge_sort(values, start, middle);
    merge_sort(values, middle + 1,end);
    // merge the two list
    merge(values, start, middle, end);
}

// merge two list
void merge(int *values, int start, int middle, int end)
{
    // put numbers in another arrays
    int *B = (int *)malloc((end + 1) * sizeof(int));
    for (int i = start;i <= end;i++)
    {
        B[i] = values[i];
    }
    // compare the left an right then sort
    int i,j,k;
    for (i = start, j =middle + 1,k = start;i <= middle && j <= end;k++)
    {
        if (B[i] < B[j])
            values[k] = B[i++];
        else
            values[k] = B[j++];
    }
    while (i <= middle) 
        values[k++] = B[i++];
    while (j <= end)
        values[k++] = B[j++];
}
