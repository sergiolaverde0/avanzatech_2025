#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int pocket = *a;
    *a = *b;
    *b = pocket;
}

void reverseArray(int* arreglo, int size)
{
    for (int i = 0; i < size / 2; i++) {
        swap(arreglo + i, arreglo + size - 1 - i);
    }
}

void printArray(const int* arreglo, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%2d ", *(arreglo + i));
    }
    printf("\n");
}

int main(void)
{
    int* arreglo = NULL;
    int size = 5;
    arreglo = malloc(sizeof(int) * size);

    if (arreglo == NULL) {
        return 1;
    }

    for (int i = 0; i < size; i++) {
        *(arreglo + i) = 10 * (i + 1);
    }

    printArray(arreglo, size);

    int new_size = 7;
    int* new_array = realloc(arreglo, new_size);

    if (new_array == NULL) {
        free(arreglo);
        return 1;
    }

    arreglo = new_array;

    for (int i = size; i < new_size; i++) {
        *(arreglo + i) = 10 * (i + 1);
    }

    printArray(arreglo, new_size);

    reverseArray(arreglo, new_size);
    printArray(arreglo, new_size);

    swap(&arreglo[1], &arreglo[3]);
    printArray(arreglo, new_size);

    free(arreglo);
}
