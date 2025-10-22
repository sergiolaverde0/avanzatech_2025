#include <stdio.h>

int my_str_len(char* str)
{
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

int main(void)
{
    int arr[5] = { 11, 22, 33, 44, 55 };
    const int* pos = arr;

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(pos + i));
    }
    printf("\n");

    char* string = "Hello darkness my old friend";
    printf("%d\n", my_str_len(string));

    return 0;
}
