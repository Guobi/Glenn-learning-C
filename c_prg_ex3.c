#include <stdio.h>
#include <math.h>

double calculateTriangle(double a, double b, double c);

int main()
{
    calculateTriangle(3, 4, 5);
    return 0;
}

double calculateTriangle(double a, double b, double c)
{
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("-1");
    }
    else
    {
        double area = 0;
        double s = ((a + b + c) / 2);
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("%.2f", area);
    }
}