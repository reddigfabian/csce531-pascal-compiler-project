#include <stdio.h>

extern long I,J,K;
extern float X,Y,Z;
extern double D;
extern char B;
extern unsigned char C;

void Print_globals()
{
  printf("i = %ld; j = %ld; k = %ld\n", I, J, K);
  printf("x = %f; y = %f; z = %f\n", X, Y, Z);
  printf("d = %lf\nb = %d\nc = %u\n", D, B, C);
}

long Get_integer()
{
  long ret;

  printf("Enter an integer:  ");
  scanf("%ld", &ret);
  return ret;
}

double Get_real()
{
  double ret;

  printf("Enter a double:    ");
  scanf("%lf", &ret);
  return ret;
}
