#include "stdio.h"
#include <stdlib.h>

int better_fibonacci(int pos)
{
    if (pos == 0) {
        return 0;
    } else if (pos == 1) {
        return 1;
    } else {
        return better_fibonacci(pos - 1) + better_fibonacci(pos - 2);
    }
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
        printf("Position %2d: %9d\n", i + 1, better_fibonacci(i));
    }
    return 0;
}
