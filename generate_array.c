#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int *generate_array1(int max, int members) {
    int *array1;
    int i = 0;
    time_t t;

    //Generate data
    printf("\n\nThe initial array is being generated. Please wait!\n");
    array1 = (int *)calloc(members,sizeof(int));
    srand((unsigned) time(&t));

    for (i=0;i<members;i++) {
        array1[i] = rand() % (max+1);
    }
    return array1;
}

int *generate_array2(int *array1, int members) {
    int *array2;
    int i = 0;

    //Generate data
    array2 = (int *)calloc(members,sizeof(int));

    for (i=0;i<members;i++) {
        array2[i] = array1[i];
    }
    return array2;
}

int *generate_array3(int *array1, int members) {
    int *array3;
    int i = 0;

    //Generate data
    array3 = (int *)calloc(members,sizeof(int));

    for (i=0;i<members;i++) {
        array3[i] = array1[i];
    }
    return array3;
}

int *generate_array4(int *array1, int members) {
    int *array4;
    int i = 0;

    //Generate data
    array4 = (int *)calloc(members,sizeof(int));

    for (i=0;i<members;i++) {
        array4[i] = array1[i];
    }
    return array4;
}
