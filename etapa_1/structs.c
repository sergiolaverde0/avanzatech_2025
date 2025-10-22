#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *car, float price){
    car->price = price;
}

int main(void)
{
    struct car saturn = {.speed = 75, .name = "Saturn SL/2"};
    set_price(&saturn, 799.99);
    printf("Price: %.2f\n", saturn.price);
    return 0;
}
