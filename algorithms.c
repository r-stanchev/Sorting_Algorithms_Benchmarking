#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "print_data.h"


//The function that swaps two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//The function that partitions the array
int partition (int * array, int low, int high) {

    //The pivot
    int pivot = array[high];

    //The index for the smaller element
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {

        // If current element is smaller than or equal to the pivot
        if (array[j] <= pivot) {

            //The index of the smaller element gets incremented
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}




void quickSort(int * array, int low, int high, int members) {
    if (low < high) {

        //That is the partitioning index
        int part_index = partition(array, low, high);


        //Sort elements before and after partition
        quickSort(array, low, part_index - 1, members);
        quickSort(array, part_index + 1, high, members);
    }
}


void bubbleSort(int * array, int members, int see_numbers) {
   int temp;
   int i,j;
   struct timeval start, end;
   int normal_seconds,micro_seconds;

   gettimeofday(&start, NULL);
   bool swapped = false;

   //Loop through all numbers
   for(i = 0; i < members-1; i++) {
       swapped = false;

       //Loop through numbers falling ahead
       for(j = 0; j < members-1-i; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j],&array[j+1]);
                swapped = true;
            }
        }

        //If no number was swapped that means array is sorted now,therefore break the loop.
        if(!swapped) {
            break;
        }
    }
    gettimeofday(&end, NULL);
    normal_seconds = (end.tv_sec - start.tv_sec);
    micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);

    write_data(micro_seconds, "Bubblesort");

    if (see_numbers == 1) {
        printf("     Done!\n\n");
        printSorted(array,members,normal_seconds,micro_seconds);
    }
    else if (see_numbers == 0) {
        printf("     Done!\n\n");
        print_time(normal_seconds,micro_seconds);
    }

    //Free memory
    free( array );
}


void selectionSort(int * array, int members, int see_numbers) {
    int i, j;
    int min_index;
    struct timeval start, end;
    int normal_seconds,micro_seconds;

    gettimeofday(&start, NULL);

    //One by one move the boundary of the unsorted subarray
    for (i = 0; i < members-1; i++)
    {
        //Finds the minimum element in the unsorted array
        min_index = i;
        for (j = i+1; j < members; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        //Swap the found minimum element with the first element
        swap(&array[min_index], &array[i]);
    }
    gettimeofday(&end, NULL);
    normal_seconds = (end.tv_sec - start.tv_sec);
    micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);

    write_data(micro_seconds, "Selectionsort");

    if (see_numbers == 1) {
        printf("     Done!\n\n");
        printSorted(array,members,normal_seconds,micro_seconds);
    }
    else if (see_numbers == 0) {
        printf("     Done!\n\n");
        print_time(normal_seconds,micro_seconds);
    }

    //Free memory
    free( array );
}


void insertionSort(int * array, int members, int see_numbers) {
   int i, key, j;
   struct timeval start, end;
   int normal_seconds,micro_seconds;

   gettimeofday(&start, NULL);

   for (i = 1; i < members; i++)
   {
       key = array[i];
       j = i-1;

       //Move the elements of arr[0..i-1], that are greater than the key, to one position ahead of their current position
       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
   }

   gettimeofday(&end, NULL);
   normal_seconds = (end.tv_sec - start.tv_sec);
   micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);

   write_data(micro_seconds, "Insertionsort");

   if (see_numbers == 1) {
       printf("     Done!\n\n");
       printSorted(array,members,normal_seconds,micro_seconds);
   }
   else if (see_numbers == 0) {
       printf("     Done!\n\n");
       print_time(normal_seconds,micro_seconds);
   }

   //Free memory
   free( array );
}
