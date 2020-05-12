#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int array2[2];
  int array1[2];
  int * pArr;

  array1[0] = 1;
  array1[1] = 2;
  array2[0] = 3;
  array2[1] = 4;


  int i = 3;
  printf("%p\n", &array1[0]);
  printf("%p\n", &array1[1]);
  printf("%p\n", &array2[0]);
  printf("%p\n", &array2[1]);

  printf("%d", array1[i]);

}