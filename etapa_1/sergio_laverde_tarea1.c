#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int student_count;
    int course_count;
    int enrollment_count;
} header;

typedef struct {
    int id;
    int gender;
    int tier;
    char nombre[23];
    int edad;
} student;

void parse_int(FILE* file, int* field)
{
    int sentinel = fread(field, 4, 1, file);
    if (!sentinel) {
        printf("Failed to parse.\n");
    }
}

void parse_student_name(FILE* file, char field[23])
{
    int sentinel = fread(field, 1, 23, file);
    if (!sentinel) {
        printf("Failed to parse.\n");
    }
}

void read_header(FILE* file, header* header)
{
    parse_int(file, &header->student_count);
    parse_int(file, &header->course_count);
    parse_int(file, &header->enrollment_count);
}

void read_student(FILE* file, student* student)
{
    parse_int(file, &student->id);
    char flags;
    fread(&flags, 1, 1, file);
    if (flags & 0b10000000) {
        student->gender = 1;
    } else {
        student->gender = 0;
    }
    if (flags & 0b01000000) {
        student->tier = 1;
    } else {
        student->tier = 0;
    }
    parse_student_name(file, student->nombre);
    parse_int(file, &student->edad);
}

void print_student(student* student)
{
    printf("%-23s\t\t%d\t%s\n", student->nombre, student->edad,
        student->gender ? "Female" : "Male");
}

int main(int argc, const char* argv[])
{
    if (argc != 4) {
        printf("Arguments needed: Binary file, minimum age, maximum age.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        return 1;
    }

    int min_age = strtol(argv[2], NULL, 10);
    int max_age = strtol(argv[3], NULL, 10);

    unsigned char magic[2];
    int sentinel = fread(&magic, 1, 2, file);
    if (sentinel == 0) {
        printf("Failed to parse.\n");
    }

    header header;
    read_header(file, &header);

    printf("Name                   \t\tAge\tGender\n");
    for (int i = 0; i < header.student_count; i++) {
        student student;
        read_student(file, &student);
        if (min_age <= student.edad && student.edad <= max_age) {
            print_student(&student);
        }
    }

    fclose(file);
}
