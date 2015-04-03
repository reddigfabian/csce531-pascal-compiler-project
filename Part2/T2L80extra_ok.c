long int I,J,K;
float X,Y,Z;
unsigned char C;
double D;
char B;

void Print_globals();

double Get_real();

long int Get_integer();

int main()
{
    I = 5;		
    J = I;
    K = 14;
    X = 3.14;
    Y = 2.71;
    Z = 0.0;
    D = 19.1999;
    B = 0;

    C = 'A';
    K = (long int)'B';

    Print_globals();

    K = I + J;
    J = I - K * K / (I + K);
    I = K % 7;
    B = K > J;
    C = C+1;

    Print_globals();

    Y = K;
    X = Y;
    D = K;
    C = (unsigned char)K - 1;
    Z = (long int)C * I + (-D) - X;
    B = C < (unsigned char)34;
    B = B <= (I == 19);

    Print_globals();

    I = Get_integer() + 9;
    D = Get_real() + 9.9;

    Print_globals();

    I = 99 + 17;
    X = -19.99;
    D = 99 * 17.76;
    C = (unsigned char)((long int)(unsigned char)65+10)+1;

    Print_globals();

    return 0;
}
