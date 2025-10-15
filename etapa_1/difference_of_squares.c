#include <stdio.h>

int square_of_first_num_sum(int num)
{
    int sum = (num * (num + 1)) / 2;
    return sum * sum;
}

int square_of_sum_of_first_num(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i * i;
    }
    return sum;
}

int main(void)
{
    int i;
    printf("Give a reasonable integer number to operate over\n");
    scanf("%d", &i);
    if (i < 0) {
        return -1;
    }
    int sum = square_of_first_num_sum(i) - square_of_sum_of_first_num(i);
    printf("%d\n", sum);
    return 0;
}
