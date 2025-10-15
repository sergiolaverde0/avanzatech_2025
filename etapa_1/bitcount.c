#include <stdio.h>

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= x - 1) {
        b++;
    }
    return b;
}

int main(void)
{
    unsigned int x;
    printf("Enter the variable to have its bits counted\n");
    scanf("%u", &x);
    printf("%u has %d bits\n", x, bitcount(x));
    return 0;
}
