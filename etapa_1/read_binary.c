#include <stdio.h>

int main(void)
{
    FILE* file_write;
    const unsigned char bytes[6] = { 5, 37, 0, 88, 255, 12 };

    if ((file_write = fopen("files/binary.bin", "wb"))) {
        fwrite(bytes, sizeof(char), 6, file_write);
        fclose(file_write);
    }

    FILE* file_read;
    unsigned char c;

    if ((file_read = fopen("files/binary.bin", "rb"))) {
        while (fread(&c, sizeof(char), 1, file_read) > 0) {
            printf("%d ", c);
        }
        fclose(file_read);
        printf("\n");
    }

    return 0;
}
