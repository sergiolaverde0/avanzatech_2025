#include <stdio.h>

void squeeze(const char s[], const char t[], char u[])
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        int dup, k;
        dup = k = 0;
        while (t[k] != '\0') {
            if (s[i] == t[k]) {
                dup = 1;
            }
            k++;
        }
        if (dup == 0) {
            u[j++] = s[i];
        }
    }
    u[j] = '\0';
}

int main(void)
{
    char s[] = "This string will get butchered so hard.";
    char t[] = "It was me Barry.";
    char u[255];
    squeeze(s, t, u);
    printf("%s\n", u);
    return 0;
}
