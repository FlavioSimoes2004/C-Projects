#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int size){
    for(int i = 0; i < size; i++)
    {
        if(i == size - 1)
        {
            printf("%i", array[i]);
        }
        else
        {
            printf("%i, ", array[i]);
        }
    }
    printf("\n");
}

int main(){
    int arraySize = 10;
    int* array = malloc(arraySize * sizeof(int));

    for(int i = 0; i < arraySize; i++)
    {
        array[i] = i;
    }

    printArray(array, arraySize);

    arraySize = 20;

    array = realloc(array, arraySize * sizeof(int));

    printArray(array, arraySize);

    for(int i = 10; i < arraySize; i++)
    {
        array[i] = i;
    }

    printArray(array, arraySize);

    return 0;
}