#include <stdio.h>

int calc_steps(int num)
{
    int counter = 0;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = (num * 3) + 1;
        }
        counter += 1;
    }
    return counter;
}

int main(void)
{
    int num;
    printf("Enter the number to walk into 1:\n");
    scanf("%d", &num);
    printf("%d\n", calc_steps(num));
    return 0;
}
