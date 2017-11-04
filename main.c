#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "algorithms.h"
#include "print_data.h"
#include "generate_array.h"

void main() {

    struct timeval start, end;
    int normal_seconds,micro_seconds;
    int members;
    int max;
    int i;
    int choice;
    int *array;
    int *array2;
    int *array3;
    int *array4;
    int see_numbers;


    //Ask the user for input
    choice = display_menu();
    printf("\nIf you want to see the actual numbers, press '1', if you do not, press '0':  ");
    scanf("%d", &see_numbers);
    printf("\nPlease choose how long the data list should be: ");
    scanf("%d", &members);
    printf("\nPlease choose how high you want the numbers to go to: ");
    scanf("%d", &max);

    //Generate initial array and (if the user wants to) display it
    array = generate_array1(max,members);
    if (see_numbers == 1) {
        printInitial(array,members);
    }

    FILE * file = fopen("times_data.dat", "w");
    fprintf(file, "#Algorithms      Time\n");
    fclose(file);

    switch(choice) {
        case 1:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            array3 = generate_array3(array,members);
            array4 = generate_array4(array,members);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            bubbleSort(array2,members,see_numbers);
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            selectionSort(array3,members,see_numbers);
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array4,members,see_numbers);
            break;

        case 2:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            array3 = generate_array3(array,members);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            bubbleSort(array2,members,see_numbers);
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            selectionSort(array3,members,see_numbers);
            break;

        case 3:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            array3 = generate_array3(array,members);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            bubbleSort(array2,members,see_numbers);
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array3,members,see_numbers);
            break;

        case 4:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            array3 = generate_array3(array,members);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            selectionSort(array2,members,see_numbers);
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array3,members,see_numbers);
            break;

        case 5:
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            array3 = generate_array3(array,members);
            bubbleSort(array,members,see_numbers);
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            selectionSort(array2,members,see_numbers);
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array3,members,see_numbers);
            break;

        case 6:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            bubbleSort(array2,members,see_numbers);
            break;

        case 7:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            selectionSort(array2,members,see_numbers);
            break;

        case 8:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array2,members,see_numbers);
            break;

        case 9:
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            bubbleSort(array,members,see_numbers);
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            selectionSort(array2,members,see_numbers);
            break;

        case 10:
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);
            bubbleSort(array,members,see_numbers);
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array2,members,see_numbers);
            break;

        case 11:
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            array2 = generate_array2(array,members);           selectionSort(array,members,see_numbers);
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array2,members,see_numbers);
            break;

        case 12:
            printf("\nSorting array with QUICKSORT. Please wait!");
            fflush(stdout);
            gettimeofday(&start, NULL);
            quickSort(array, 0, members-1, members);
            gettimeofday(&end, NULL);
            normal_seconds = (end.tv_sec - start.tv_sec);
            micro_seconds = ((normal_seconds*1000000) + end.tv_usec) - (start.tv_usec);
            write_data(micro_seconds, "Quicksort");
            if (see_numbers == 1) {
                printf("     Done!\n\n");
                printSorted(array,members,normal_seconds,micro_seconds);
            }
            else if (see_numbers == 0) {
                printf("     Done!\n\n");
                print_time(normal_seconds,micro_seconds);
            }
            free( array );
            break;

        case 13:
            printf("\nSorting array with BUBBLESORT. Please wait!");
            fflush(stdout);
            bubbleSort(array,members,see_numbers);
            break;

        case 14:
            printf("\nSorting array with SELECTIONSORT. Please wait!");
            fflush(stdout);
            selectionSort(array,members,see_numbers);
            break;

        case 15:
            printf("\nSorting array with INSERTIONSORT. Please wait!");
            fflush(stdout);
            insertionSort(array,members,see_numbers);
            break;

        default:
            printf("Invalid input!\n");
            break;
    }
    system("gnuplot -p instructions.gnu");
}
