#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


//Prints out how much time the sorting took

void print_time(int n_secs, int m_secs) {
    printf("======================= T I M E ======================\n");
    printf("Seconds used: %d\n", n_secs);
    printf("Micro seconds used: %d\n======================================================\n\n\n",m_secs);

}


//Prints the initial(unsorted) array

void printInitial(int *array, int members) {
    int i = 0;
    printf("\nThe initial ordering of the array is: \n============================ I N I T I A L ======================================\n");

    for(i=0;i< members;i++) {
       printf("%d   ",array[i]);
    }

    printf("\n=================================================================================\n\n\n");
}


//Prints the sorted array and how much time the sorting took

void printSorted(int *array, int members, int n_secs, int m_secs) {
    int k = 0;

    printf("SORTED: \n========================== S O R T E D ==========================================\n");

    for(k=0;k<members;k++) {
       printf("%d   ",array[k]);
    }

    printf("\n=================================================================================\n\n\n");

    //Show how much time the sorting took
    print_time(n_secs,m_secs);
}


int display_menu() {
    int choice;

    printf("\n\n           MAKE YOUR CHOICE           \n\n");
    printf("1.Quicksort vs Bubblesort vs Selectionsort vs Insertionsort\n\n");
    printf("2.Quicksort vs Bubblesort vs Selectionsort\n\n");
    printf("3.Quicksort vs Bubblesort vs Insertionsort\n\n");
    printf("4.Quicksort vs Selectionsort vs Insertionsort\n\n");
    printf("5.Bubblesort vs Selectionsort vs Insertionsort\n\n");
    printf("6.Quicksort vs Bubblesort\n\n");
    printf("7.Quicksort vs Selectionsort\n\n");
    printf("8.Quicksort vs Insertionsort\n\n");
    printf("9.Bubblesort vs Selectionsort\n\n");
    printf("10.Bubblesort vs Insertionsort\n\n");
    printf("11.Selectionsort vs Insertionsort\n\n");
    printf("12.Quicksort\n\n");
    printf("13.Bubblesort\n\n");
    printf("14.Selectionsort\n\n");
    printf("15.Insertionsort\n\n\n\n");
    printf("Please make your choice:   ");
    scanf("%d", &choice);
    return choice;
}


void write_data(int secs, char *algorithm) {
    FILE * file = fopen("times_data.dat", "a");

    fprintf(file, "%s     %d\n",algorithm, secs);
    fclose(file);
}
