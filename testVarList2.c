#include <stdio.h>
#include <stdarg.h>

void myPrintf1(const char *format, ...);

int main()
{
  printf("%d\t%d\n", 1, 2);
  myPrintf1("%d\t%d\n", 1, 2);
  return 0;
}

void myPrintf1(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}