#include <stdio.h>

int sum_of_divisors(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main(void)
{
    int num;
    printf("Give the number to evaluate:\n");
    scanf("%d", &num);
    int sum = sum_of_divisors(num);
    if (sum > num) {
        printf("%d is an abundant number.\n", num);
    } else if (num > sum) {
        printf("%d is a deficient number.\n", num);
    } else {
        printf("%d is a perfect number.\n", num);
    }
    return 0;
}
