#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_names(char *name, char *gender, char *age);

int main()
{
    typedef struct
    {
        char *name;
        char gender[2];
        char age[3];
        int namelength;
    } student;
    int pax = 0;
    printf("Number of Students: \n");
    scanf("%d", &pax); // input number of students
    student S[pax];
    int i = 0;
    int n = 0;
    for (i = 0; i < pax; i++)
    {
        printf("How many characters in the name? \n");
        scanf("%d", &S[i].namelength);
        S[i].name = (char *)malloc((S[i].namelength + 1) * sizeof(char));
        printf("Name: \n");
        scanf("%s", S[i].name);
        printf("Gender (M/F): \n");
        scanf("%s", S[i].gender);
        printf("Age: \n");
        scanf("%s", S[i].age);
        printf("\n");
    }
    i = 0;
    for (i = 0; i < pax; i++)
    {
        print_names(S[i].name, S[i].gender, S[i].age);
        free(S[i].name);
    }
    return 0;
}
int print_names(char *name, char *gender, char *age)
{
    printf("Name: %s, Gender: %s, Age: %s\n", name, gender, age);
    return 0;
}