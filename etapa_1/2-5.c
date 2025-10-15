#include <stdio.h>

int first_dup(const char s[], const char t[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        int j = 0;
        while (t[j] != '\0') {
            if (s[i] == t[j]) {
                return i;
            }
            j++;
        }
    }
    return -1;
}

int main(void)
{
    char s[] = "This string will get butchered so hard.";
    char t[] = "It was me Barry.";
    int pos = first_dup(s, t);
    printf("%i\n", pos);
    return 0;
}
