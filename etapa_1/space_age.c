#include <stdio.h>
#define MERCURY 0.2408467
#define VENUS 0.61519726
#define MARS 1.8808158
#define JUPITER 11.862615
#define SATURN 29.447498
#define URANUS 84.016846
#define NEPTUNE 164.79132

/*Convert a number of Earth years into the respective number of years for the
 * given planet*/
float space_age(float earth_age, unsigned int planet_option)
{
    switch (planet_option) {
    case 1:
        return earth_age * MERCURY;
    case 2:
        return earth_age * VENUS;
    case 3:
        return earth_age * MARS;
    case 4:
        return earth_age * JUPITER;
    case 5:
        return earth_age * SATURN;
    case 6:
        return earth_age * URANUS;
    case 7:
        return earth_age * NEPTUNE;
    }
    return 0;
}

int main(void)
{
    float age;
    unsigned int planet;
    printf("Where are you landing next?:\n"
           "1. Mercury.\n"
           "2. Venus.\n"
           "3. Mars.\n"
           "4. Jupiter.\n"
           "5. Saturn.\n"
           "6. Uranus.\n"
           "7. Neptune.\n");
    scanf("%ud", &planet);
    printf("How old are you in Earth years?\n");
    scanf("%f", &age);
    printf("Your age in that planet is: %5.2f years.\n", space_age(age, planet));
}
