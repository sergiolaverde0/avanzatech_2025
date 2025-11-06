#include <stdio.h>

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    float slope;
    float intercept;
} rect;

rect lesser_square(point* points, int size)
{
    float sum_x = 0;
    float sum_y = 0;
    float sum_xy = 0;
    float sum_x2 = 0;

    for (int i = 0; i < size; i++) {
        float x = points[i].x;
        float y = points[i].y;
        sum_x += x;
        sum_y += y;
        sum_xy += (x * y);
        sum_x2 += (x * x);
    }

    float slope = (sum_xy - (sum_x * sum_y) / size) / (sum_x2 - (sum_x * sum_x) / size);
    float intercept = (sum_y / size) - slope * (sum_x / size);

    rect result = { .slope = slope, .intercept = intercept };
    return result;
}

int main(void)
{
    point points[9];

    points[0].x = 7;
    points[0].y = 2;
    points[1].x = 1;
    points[1].y = 9;
    points[2].x = 10;
    points[2].y = 2;
    points[3].x = 5;
    points[3].y = 5;
    points[4].x = 4;
    points[4].y = 7;
    points[5].x = 3;
    points[5].y = 11;
    points[6].x = 13;
    points[6].y = 2;
    points[7].x = 10;
    points[7].y = 5;
    points[8].x = 2;
    points[8].y = 14;

    rect result = lesser_square(points, 9);
    printf("The slope is %.2f and the intercept is %.2f.\n", result.slope, result.intercept);
    return 0;
}
