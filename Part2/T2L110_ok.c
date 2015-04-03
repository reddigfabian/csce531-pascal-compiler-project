long int I,J,K;
float X,Y;
double D;
unsigned char C;
char B;


void Printf();


void Swap(float *a, float *b)
{
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void inner1(long int *c)
{
    long int i;	
    i = K;
    Printf("f.inner1: c = %ld; i = %ld\n", *c, i);
}

void inner2(long int *c)
{
    float i;	
    i = D;
    *c = *c+1;
    Printf("f.inner2: c = %ld; i = %e\n", *c, i);
    K = K - 1;
    inner1(c);
}

void f(long int c)
{
    long int i;
    i = 19;
    Printf("f: c = %ld; i = %ld\n", c, i);
    inner1(&c);
    Printf("f: c = %ld; i = %ld\n", c, i);
    inner2(&c);
    i = i + 1;
    Printf("f: c = %ld; i = %ld\n", c, i);
}

double innerinner(unsigned char *c1, long int *i1, long int *i2,
                  double *d1, double *d2)
{
    *c1 = (unsigned char)96;
    f(*(long int *)c1);
    return I + *i1 + *i2 + D + *d1 + *d2;
}

void inner(unsigned char *c1, long int *i1, double *d1)
{
    long int i2;
    double d2;
    i2 = 28;
    d2 = 1.414;
    Printf("g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n",
           *c1, *i1, i2, *d1, d2);
    *d1 = innerinner(c1, i1, &i2, d1, &d2);
    Printf("g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n",
           *c1, *i1, i2, *d1, d2);
}

void g(unsigned char *c1)
{
    long int i1;
    double d1;
    i1 = 496;
    d1 = 2.71;
    *c1 = (unsigned char)14;
    Printf("g: c1 = %d; i1 = %ld; d1 = %lg\n", *c1, i1, d1);
    inner(c1, &i1, &d1);
    *c1 = *c1;
    Printf("g: c1 = %d; i1 = %ld; d1 = %lg\n", *c1, i1, d1);
}

void Main()
{
    long int i;
    float x,y;
    K = 19;
    D = K * 2;
    C = (unsigned char)K;

    i = K;
    x = i;
    y = D;

    i = i+3;
    J = i-2;
    x = x-1;
    Printf("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n",
           C, D, i, J, K, x, y);

    f((long int)C);

    Printf("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n",
           C, D, i, J, K, x, y);

    g(&C);

    Printf("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n",
           C, D, i, J, K, x, y);

    Swap(&x,&y);

    Printf("main: c = %d; d = %lg; i = %d;\nj = %d; k = %d; x = %e; y = %e\n",
           C, D, i, J, K, x, y);
}

int main()
{
    I = -60;
    D = 1.732;
    X = 0.0;
    Y = 0.0;
    C = (unsigned char)0;
    Printf("i = %ld; d = %lg; x = %e; y = %e; c = %d\n", I, D, X, Y, C);
    Main();
    Printf("i = %ld; d = %lg; x = %e; y = %e; c = %d\n", I, D, X, Y, C);
    return 0;
}
