#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof_at_home(const char s[])
{
    double val, power;
    int i, sign, exp, exp_sign;
    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    sign = (s[i] == '-') ? -1 : +1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = (val * 10.0) + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = (val * 10.0) + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
    }
    exp_sign = (s[i] == '-') ? -1 : +1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (exp = 0; isdigit(s[i]); i++) {
        exp = (exp * 10) + (s[i] - '0');
    }
    if (exp_sign == 1) {
        return (sign * val * pow(10.0, exp)) / power;
    }
    return (sign * val) / (power * pow(10.0, exp));
}

int main(void)
{
    char string[] = "123.45e-6";
    printf("%f\n", atof_at_home(string));
    return 0;
}
