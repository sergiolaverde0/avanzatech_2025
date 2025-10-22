#include <stdio.h>
#include <string.h>

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

typedef struct {
    int id;
    char nombre[32];
    int hours;
} curso;

typedef struct {
    int student;
    int curso;
    int year;
    int semester;
} enroll;

void parse_int(FILE* file, int* field)
{
    int sentinel = fread(field, 4, 1, file);
    if (!sentinel) {
        printf("Failed to parse.\n");
    }
}

void parse_course_name(FILE* file, char field[32])
{
    int sentinel = fread(field, 1, 32, file);
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

void read_curso(FILE* file, curso* curso)
{
    parse_int(file, &curso->id);
    parse_course_name(file, curso->nombre);
    parse_int(file, &curso->hours);
}

void read_enrollment(FILE* file, enroll* enroll)
{
    parse_int(file, &enroll->student);
    parse_int(file, &enroll->curso);
    parse_int(file, &enroll->year);
    parse_int(file, &enroll->semester);
}

void print_average(const char pensum[][32], const int* suma, const int* count, int max)
{
    for (int i = 0; i < max; i++) {
        printf("%-32.32s\t%.2f\n", pensum[i], ((double)suma[i] / (double)count[i]));
    }
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        printf("Arguments needed: Binary file, minimum age, maximum age.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    unsigned char magic[2];
    int sentinel = fread(&magic, 1, 2, file);
    if (sentinel == 0) {
        printf("Failed to parse.\n");
    }

    header header;
    read_header(file, &header);

    int suma_edad[header.course_count];
    memset(suma_edad, 0, sizeof(suma_edad));
    int count[header.course_count];
    memset(count, 0, sizeof(count));

    student plantel[header.student_count];
    for (int i = 0; i < header.student_count; i++) {
        student student;
        read_student(file, &student);
        plantel[i] = student;
    }

    char pensum[header.course_count][32];
    for (int i = 0; i < header.course_count; i++) {
        curso curso;
        read_curso(file, &curso);
        strcpy(pensum[i], curso.nombre);
    }

    for (int i = 0; i < header.enrollment_count; i++) {
        enroll enroll;
        read_enrollment(file, &enroll);
        suma_edad[enroll.curso - 1] += plantel[enroll.student - 1].edad;
        count[enroll.curso - 1] += 1;
    }

    printf("Course name                     \tAverage Age\n");
    print_average(pensum, suma_edad, count, header.course_count);

    fclose(file);
}
