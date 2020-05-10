#include <stdio.h>
// #include <stdlib.h>

int print_names(char * name, char * gender, char * age);

int main()
{
    typedef struct //define structure "student"
    {
        char name[40];
        char gender[2];
        char age[3];
    } student;
    static student S[3];
    int i = 0;
    for (i = 0; i < 3; i++) //input information for 3 students
    {
    printf("Name: \n");
    scanf("%s", S[i].name);
    printf("Gender (M/F): \n");
    scanf("%s", S[i].gender);
    printf("Age: \n");
    scanf("%s", S[i].age);
    printf("\n");
    }
    i = 0;
    for (i = 0; i < 3; i++) {
        print_names(S[i].name, S[i].gender, S[i].age); // display information for all 3 students
    }
    return 0;
}
int print_names(char * name, char * gender, char * age)
{
    printf("Name: %s, Gender: %s, Age: %s\n", name, gender, age);
    return 0;
}