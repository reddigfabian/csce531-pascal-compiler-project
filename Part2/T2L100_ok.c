#include <stdlib.h>

int I,J,K;
float X,Y,Z;
double D;
unsigned char C;
long int *Ip;
double *Rp;

void Printf();
void Scanf();
unsigned char Getchar();
long int Abc();

void Rst()
{
    J = Abc();
}

void Xyz()
{
    I = 1999;
}

long int Abc()
{
    long int ret;
    Xyz();
    ret = 18;
    K = 20;
    ret = 19;
    return ret;
}

long int Get_integer()
{
    long int ret;
    Ip = (long int *)malloc(sizeof(long int));
    Printf("Enter an integer:   ");
    Scanf("%ld", Ip);
    ret = *Ip;
    free(Ip);
    return ret;
}

double Get_real()
{
    double ret;
    Rp = (double *)malloc(sizeof(double));
    Printf("Enter a real:   ");
    Scanf("%lf", Rp);
    ret = *Rp;
    free(Rp);
    return ret;
}

unsigned char Get_character()
{
    unsigned char ret;
    Printf("Enter a character:   ");
    ret = Getchar();
    ret = Getchar();
    return ret;
}

void Print_globals()
{
    Printf("i = %ld; j = %ld; k = %ld\n", I, J, K);
    Printf("x = %f; y = %f; z = %f\n", X, Y, Z);
    Printf("d = %lf\nc = %u\n", D, C);
}

int main()
{
    Printf("this is a debugging message\n");
   
    Rst();
    D = Get_real();
    C = Get_character();
    X = D;
    Y = I / K;
    Z = I % K;

    Print_globals();

    I = Get_integer();
    D = X * 2;

    Print_globals();
    
    return 0;
}
