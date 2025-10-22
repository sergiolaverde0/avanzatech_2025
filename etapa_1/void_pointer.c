#include <stdio.h>
#include <stdlib.h>

struct animal {
    char* name;
    int leg_count;
};

int comp(const void* left, const void* right)
{
    const struct animal* animal_i = left;
    const struct animal* animal_r = right;

    return animal_i->leg_count >= animal_r->leg_count ? 1 : -1;
}

int main(void)
{
    struct animal arr[4] = {
        { .name = "Dog", .leg_count = 4 },
        { .name = "Monkey", .leg_count = 2 },
        { .name = "Antelope", .leg_count = 4 },
        { .name = "Snake", .leg_count = 0 },
    };

    qsort(arr, 4, sizeof(struct animal), comp);
    for (int i = 0; i < 4; i++) {
        printf("%s: %d\n", arr[i].name, arr[i].leg_count);
    }
    return 0;
}
