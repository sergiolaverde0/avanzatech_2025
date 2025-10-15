#include "stdio.h"
#include <stdlib.h>

long better_fibonacci(unsigned int num)
{
    if (num == 0) {
        return 0;
    }
    long array[num + 1];
    for (int i = 0; i < num + 1; i++) {
        if (i == 0) {
            array[0] = 0;
        } else if (i == 1) {
            array[1] = 1;
        } else {
            array[i] = array[i - 1] + array[i - 2];
        }
    }
    return array[num];
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        printf("Use: fibonacci <integer>\n");
        return -1;
    };
    int number = atoi(argv[1]);
    if (number < 1) {
        printf("Integer must be strictly possitive\n");
    };

    for (int i = 0; i < number; i++) {
        printf("Position %2d: %12ld\n", i + 1, better_fibonacci(i));
    }
    return 0;
}
