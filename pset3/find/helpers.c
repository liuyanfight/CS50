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
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm, 
    if (n <= 0)
        return false;
//    linear search
/*      for(int i = 0;i < n;i++)*/
/*     {*/
/*         if (values[i] == value)*/
/*             return true;*/
/*     }*/
/*     return false;*/
    
    //Binary Search,iterative ,of course u can use recursive 
    int low = 0, high = n - 1;
    while ((high - low) >= 0)
    {
        int middle = (low + high) / 2;
        if (values[middle] > value)
            high = middle - 1;
        else if (values[middle] < value)
            low = middle + 1;
        else
            return true;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm, insertion sort
    insertion_sort(values,n);
    for(int i = 0;i < n;i++)
    {
        printf("%d ",values[i]);
    }
    return;
}

// be careful!the pointer possed!
void insertion_sort(int *values, int n)
{
    for (int i = 1;i < n;i++)
    {
        if (values[i] < values[i - 1])
        {
            int temp = values[i],j;
            for (j = (i - 1);values[j] > temp && j >= 0;j--)
                values[j + 1] = values[j];
            values[j + 1] = temp;
        }
    }
}
