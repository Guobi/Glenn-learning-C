#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// define structure "Student"
typedef struct
{
    unsigned short id;
    char *name;
    int nameLength;
    bool gender;
    unsigned short age;
} Student;

void studentPrint(Student student);
int studentInput(Student *pStudent);
int studentModify(Student *pStudent);
int studentGetName(Student student);
int studentSetName(Student *pStudent);
int studentGetGender(Student student);
// int setGender();

// define structure "Class", a group of students
typedef struct
{
    unsigned short count;
    Student students[100];
    char formTeacher[100];
} Class;

void classPrint(Class class);
int classAddStudent(Class *pClass, Student student);
int classRemoveStudent(Class *pClass, unsigned short id);

int main()
{
    char buffer[1000];
    Student student[3];
    int i = 0;
    for (i = 0; i < 3; i++) //input information for 3 students
    {
    }

    for (i = 0; i < 3; i++)
    {
    }

    for (i = 0; i < 3; i++)
    {
        free(student[i].name);
    }

    return 0;
}

void studentPrint(Student student)
{
    printf("Name:%s\n (%d)", student.name, student.id);
    if (student.gender == true)
    {
        printf("Gender:Male\n");
    }
    else
    {
        printf("Gender:Female\n");
    }
    printf("Age:%hu\n", student.age);
    return;
}

int studentInput(Student *pStudent)
{
    Student student = *pStudent;
    // Enter name
    char buffer[1000];
    printf("ID:");
    fgets(buffer, 1000, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    student.id = atoi(buffer);

    printf("Name (must be < 1000 characters):");
    fgets(buffer, 1000, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    student.nameLength = strlen(buffer);
    //allocate memory for name
    student.name = (char *)malloc((student.nameLength + 1) * sizeof(char));
    strcpy(student.name, buffer);
    // printf("%s\n", student[i].name);
    // printf("%lu\n", strlen(student[i].name));

    // Enter gender
    while (true)
    {
        printf("Gender (0-Female,1-Male):");
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if (strlen(buffer) == 1 && (buffer[0] == '1' || buffer[0] == '0'))
        {
            student.gender = atoi(buffer);
            break;
        }
    }

    // Enter age
    printf("Age:");
    fgets(buffer, 1000, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    student.age = atoi(buffer);

    *pStudent = student;

    return 0;
}

int studentModify(Student *pStudent)
{
    Student student = *pStudent;

    char buffer[1000];
    printf("Name (must be < 1000 characters):");
    fgets(buffer, 1000, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    student.nameLength = strlen(buffer);
    //allocate memory for name
    student.name = (char *)malloc((student.nameLength + 1) * sizeof(char));
    strcpy(student.name, buffer);
    // printf("%s\n", student[i].name);
    // printf("%lu\n", strlen(student[i].name));

    // Enter gender
    while (true)
    {
        printf("Gender (0-Female,1-Male):");
        fgets(buffer, 1000, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if (strlen(buffer) == 1 && (buffer[0] == '1' || buffer[0] == '0'))
        {
            student.gender = atoi(buffer);
            break;
        }
    }

    // Enter age
    printf("Age:");
    fgets(buffer, 1000, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    student.age = atoi(buffer);

    *pStudent = student;
}

int studentGetName(Student student)
{
    printf("Name:%s\n (%d)", student.name, student.id);
}

int studentSetName(Student *pStudent)
{
    Student student = *pStudent;
    // Enter name
    char buffer[1000];
    printf("Name (must be < 1000 characters):");
    fgets(buffer, 1000, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    student.nameLength = strlen(buffer);
    //allocate memory for name
    student.name = (char *)malloc((student.nameLength + 1) * sizeof(char));
    strcpy(student.name, buffer);
    *pStudent = student;

    return 0;
}

int studentGetGender(Student student)
{
    if (student.gender == true)
    {
        printf("Gender:Male\n");
    }
    else
    {
        printf("Gender:Female\n");
    }

    return 0;
}

void classPrint(Class class)
{
    int i = 0;
    int numberOfStudents = sizeof(class.students) / sizeof(class.students[0]);
    for (i = 0; i < numberOfStudents; i++)
    {
        studentPrint(class.students[i]);
    }
}

int classAddStudent(Class *pClass, Student student)
{
    Class class = *pClass;
    int numberOfStudents = sizeof(class.students) / sizeof(class.students[0]);
    
    class.students[numberOfStudents] = student;
    *pClass = class;
}