#include <stdio.h>

int main(void)
{
    FILE *quote;
    quote = fopen("files/quote.txt", "r");
    char line[255];
    int linecount = 0;

    while (fgets(line, sizeof(line), quote)) {
        printf("%d %s", ++linecount, line);
    }
    fclose(quote);

    printf("\n");

    FILE *whales;
    whales = fopen("files/whales.txt", "r");
    char name[255];
    float lenght;
    int weight;

    while (fscanf(whales, "%s %f %d", name, &lenght, &weight) != EOF) {
        printf("%s whale, %.2f meters, %d tons.\n", name, lenght, weight);
    }

    printf("\n");

    fputs("Hello world.\n", stdout);

    return 0;
}
