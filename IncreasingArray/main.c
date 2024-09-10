#include <stdio.h>
#include <stdlib.h>

typedef struct Array{
    int* array;
    int length;
} Array;

void increaseArray(Array* array, int newSize);
void printArray(int* array, int size);
void freeArray(Array* arr);

int main(){
    /* Without being a pointer ----------------------------
    Array arr = {malloc(5 * sizeof(int)), 5};
    for(int i = 0; i < arr.length; i++)
    {
        arr.array[i] = i;
    }*/

    Array* arr = malloc(sizeof(Array));

    arr->array = malloc(5 * sizeof(int));
    arr->length = 5;

    for(int i = 0; i < arr->length; i++)
    {
        arr->array[i] = i;
    }

    printArray(arr->array, arr->length);

    increaseArray(arr, 20);

    return 0;
}

void increaseArray(Array* arr, int newSize){
    arr->array = realloc(arr->array, newSize * sizeof(int));
    arr->length = newSize;
    printArray(arr->array, arr->length);
    printf("\n");
}

void printArray(int* array, int size){
    for(int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            printf("%i", array[i]);
        }
        else
        {
            printf(", %i", array[i]);
        }
    }
    printf(" ---- print finished\n");
}

void freeArray(Array* arr){
    if(arr != NULL)
    {
        free(arr->array);
        free(arr);
    }
}