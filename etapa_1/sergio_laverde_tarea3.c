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

typedef struct {
    int year;
    int semester;
    int estudents;
    int male_under;
    int female_under;
    int male_grad;
    int female_grad;
} entry;

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

void create_data(entry* data, int num_year, int min_year, int num_semester, int min_semester)
{
    for (int i = 0; i < num_year; i++) {
        for (int j = 0; j < num_semester; j++) {
            entry current = data[(i * num_semester) + j];
            current.year = min_year + i;
            current.semester = min_semester + j;
            current.estudents = 0;
            current.male_under = 0;
            current.female_under = 0;
            current.male_grad = 0;
            current.female_grad = 0;

            data[(i * num_semester) + j] = current;
        }
    }
}

void populate_entry(entry* entry, const enroll* enroll, student* plantel, int* seen)
{
    if (seen[enroll->student - 1] == 0) {
        seen[enroll->student - 1] = 1;
        entry->estudents += 1;
        int gender = (plantel[enroll->student - 1]).gender;
        int grad = (plantel[enroll->student - 1]).tier;
        if (gender && grad) {
            entry->female_grad += 1;
            return;
        }
        if (gender && !grad) {
            entry->female_under += 1;
            return;
        }
        if (!gender && grad) {
            entry->male_grad += 1;
            return;
        }
        if (!gender && !grad) {
            entry->male_under += 1;
            return;
        }
    }
}

void populate_array(const enroll* matricula, entry* data, int num_enroll, int num_entries, student* plantel, int num_students)
{
    for (int j = 0; j < num_entries; j++) {
        int seen[num_students];
        memset(seen, 0, sizeof(seen));

        entry entry = data[j];
        for (int i = 0; i < num_enroll; i++) {
            enroll enroll = matricula[i];
            if ((enroll.year == entry.year) && (enroll.semester == entry.semester)) {
                populate_entry(&entry, &enroll, plantel, seen);
                data[j] = entry;
            }
        }
    }
}

void print_data(const entry* data, unsigned int num_entries)
{
    for (unsigned int i = 0; i < num_entries; i++) {
        entry current = data[i];
        printf("%d\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", current.year,
            current.semester, current.male_under, current.female_under,
            current.male_grad, current.female_grad);
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

    student plantel[header.student_count];
    for (int i = 0; i < header.student_count; i++) {
        student student;
        read_student(file, &student);
        plantel[i] = student;
    }

    // curso pensum[header.course_count];
    for (int i = 0; i < header.course_count; i++) {
        curso curso;
        read_curso(file, &curso);
        // pensum[i] = curso;
    }

    int min_year = 64000, max_year = 0, min_semester = 64000, max_semester = 0;
    enroll matricula[header.enrollment_count];
    for (int i = 0; i < header.enrollment_count; i++) {
        enroll enroll;
        read_enrollment(file, &enroll);
        if (enroll.year > max_year) {
            max_year = enroll.year;
        }
        if (enroll.year < min_year) {
            min_year = enroll.year;
        }
        if (enroll.semester > max_semester) {
            max_semester = enroll.semester;
        }
        if (enroll.year < min_semester) {
            min_semester = enroll.semester;
        }
        matricula[i] = enroll;
    }

    unsigned int num_year = max_year - min_year + 1;
    unsigned int num_semester = max_semester - min_semester + 1;
    unsigned int num_entries = num_year * num_semester;

    entry data[num_entries];
    create_data(data, num_year, min_year, num_semester, min_semester);
    populate_array(matricula, data, header.enrollment_count, num_entries, plantel, header.student_count);
    printf("Year\tSemester\tMale Undergrad\t\tFemale Undergrad\tMale Grad\t\tFemale Grad\n");
    print_data(data, num_entries);

    fclose(file);
}
