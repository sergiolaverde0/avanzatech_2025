#include "stdio.h"

int main(void)
{
    float lower, higher, step;

    lower = 0.0;
    higher = 900.0;
    step = 25.0;

    printf("Fahrenheit\tCelsius\n");

    for (float fahr = lower; fahr <= higher; fahr += step) {
        float celsius;
        celsius = (fahr - 32.0) * (5.0 / 9.0);
        printf("%6.1f\t%6.1f\n", fahr, celsius);
    }
    return 0;
}
