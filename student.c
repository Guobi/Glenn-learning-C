#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// define structure "Student"
typedef struct
{
    char * name;
    int nameLength;
    bool gender;
    unsigned short age;
} Student;

void printStudent(Student student);

int main()
{
    char buffer[1000];
    Student student[3];
    int i = 0;
    for (i = 0; i < 3; i++) //input information for 3 students
    {
        // Enter name
        printf("Name (must be < 1000 characters):");
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        student[i].nameLength = strlen(buffer);
        //allocate memory for name
        student[i].name = (char *)malloc((student[i].nameLength + 1) * sizeof(char));
        strcpy(student[i].name, buffer);
        // printf("%s\n", student[i].name);
        // printf("%lu\n", strlen(student[i].name));

        // Enter gender
        while (true) {
            printf("Gender (0-Female,1-Male):");
            fgets(buffer, 1000, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            if (strlen(buffer) == 1 && (buffer[0] == '1' || buffer[0] == '0')) {
                student[i].gender = atoi(buffer);
                break;
            }
        }

        // Enter age
        printf("Age:");
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        student[i].age = atoi(buffer);
    }

    for (i = 0; i < 3; i++) {
       printStudent(student[i]);
    }

    for (i = 0; i < 3; i++) {
        free(student[i].name);
    }

    return 0;
}

void printStudent(Student student)
{
    printf("Name:%s\n", student.name);
    if (student.gender == true) {
        printf("Gender:Male\n");
    }
    else {
        printf("Gender:Female\n");
    }
    printf("Age:%hu\n", student.age);
    return;
}