#include <stdio.h>
void bad_sort(const float input[], float output[], int size)
{
    for (int i = 0; i < size; i++) {
        output[i] = input[i];
    }
    int sorted_elements = 0;
    float pocket;
    while (sorted_elements < (size - 1)) {
        sorted_elements = 0;
        for (int i = 0; i < size - 1; i++) {
            if (output[i] < output[i + 1]) {
                pocket = output[i + 1];
                output[i + 1] = output[i];
                output[i] = pocket;
            } else {
                sorted_elements += 1;
            }
        }
    }
}

int main(void)
{
    float test[] = { 3.2, 4.5, 2.0, 4.5, 1.8, 5.0 };
    float result[6];
    bad_sort(test, result, 6);
    for (int i = 0; i < 6; i++) {
        printf("Value at position %d: %.1f\n", i, result[i]);
    }
    return 0;
}
