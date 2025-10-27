#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void initArrayList(int* listArray, int* listSize)
{
    int* result = malloc(sizeof(int) * MAX_SIZE);
    if (result == NULL) {
        printf("Failed to resize array.\n");
        free(listArray);
        return;
    }
    *listArray = *result;
    *listSize = 0;
    free(result);
}

void InsertAtBeginning(int* listArray, int* listSize, int data)
{
    if (*listSize == MAX_SIZE) {
        printf("List array already at max size.\n"
               "Please delete an entry before inserting a new one.\n");
        return;
    }
    for (int i = *listSize -1; i >= 0; i--) {
        listArray[i + 1] = listArray[i];
    }
    listArray[0] = data;
    *listSize += 1;
}

void insertAtEnd(int* listArray, int* listSize, int data)
{
    if (*listSize == MAX_SIZE) {
        printf("List array already at max size.\n"
               "Please delete an entry before inserting a new one.\n");
        return;
    }
    listArray[*listSize] = data;
    *listSize += 1;
}

void insertAfterIndex(int* listArray, int* listSize, int data, int index)
{
    for (int i = *listSize-1; i >= index; i--) {
        listArray[i + 1] = listArray[i];
    }
    listArray[index+1] = data;
    *listSize += 1;
}

void deleteAtIndex(int* listArray, int* listSize, int index)
{
    *listSize -= 1;
    for (int i = index; i < *listSize; i++) {
        listArray[i] = listArray[i+1];
    }
}

int findLength(const int* listSize)
{
    return *listSize;
}

void printArrayList(const int* listArray, const int* listSize)
{
    for (int i =0; i < *listSize; i++) {
        printf("-> %2d ", listArray[i]);
    }
    printf("\n");
}

int main(void)
{
    int listArray[MAX_SIZE];
    int listSize = 0;
    initArrayList(listArray, &listSize);

    insertAtEnd(listArray, &listSize, 10);
    insertAtEnd(listArray, &listSize, 20);
    insertAtEnd(listArray, &listSize, 30);
    printArrayList(listArray, &listSize);

    InsertAtBeginning(listArray, &listSize, 5);
    printArrayList(listArray, &listSize);

    insertAfterIndex(listArray, &listSize, 25, 2);
    printArrayList(listArray, &listSize);

    deleteAtIndex(listArray, &listSize, 1);
    printArrayList(listArray, &listSize);

    int length = findLength(&listSize);
    printf("Length of the array list: %d\n", length);

    return 0;
}
