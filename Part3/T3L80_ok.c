long int A,B,C;
long int X;
unsigned char Y;
float Z;
double W;
long int I,J,K;
unsigned char Ca[8];    // starting index: 1
long int Ia[6];         // starting index: 5
double Ra[3];           // starting index: 7
long int Iaa[11][11];   // starting indices: 0, 0
long int Iaaa[3][4][5]; // starting indices: 0, 2, 5

void Print_abc();
void Print_x();
void Print_z();
void Print_w();
void Print_ca();
void Print_ia();
void Print_ra();
void Print_iaa();
void Print_iaaa();
void Print_oops();
void Print_7();
void Print_1();
void Print_2();
void Print_newline();
void Print_is();
void Print_grooviest();
void Print_outer();
void Print_inner();
void Print_inner_inner();
void Print_looping();
void Print_looping_looping();
void Print_looping_looping_looping();

int main()
{
    X = 9;

    while (X >= 0) {
        Print_x();
        X = X - 1;
    }

    A = -1;
    B = 0;
    C = 1;

    if (A > B)
        Print_oops();
    else {
        if (B == C+A) {
            Print_7();
            Print_1();
            if (1) Print_2();
            Print_newline();
        }
        else
            Print_oops();
        Print_is();
    }

    Print_grooviest();

    A = -1;

    while (A > 3)
        Print_oops();

    while (A < 3) {
        
        Print_outer();

        B = 0;
        while (B < A+1) {
            Print_inner();

            C = 0;
            while (C < 5) {
                Print_inner_inner();
                C = C+1;
            }
            B = B+1;
        }
        A = A+1;
    }

    X = 9;

    while (X >= 0) {
        Print_looping();
        X = X - 1;
    }

    if (X != 0)
        X = 0;

    X = 3;

    while (X >= 0) {
        Print_looping();
        B = 0;

        while (B <= 1) {
            Print_looping_looping();
            C = 8;

            while (C <= 10) {
                Print_looping_looping_looping();
                C = C+1;
            }
            B = B + 1;
        }
        X = X - 1;
    }

    A = 1;
    B = 1;
    C = 1;

    while (B < 99) {
        if (A > 19) {
            B = B * 2;
            A = A + 3;
        }
        else if (A > 9) {
            B = B - 5;
            A = A + 1;
        }
        else {
            B = B * 3;
            A = A * 2;
        }

        Print_abc();
        C = C+1;
    }

    Print_newline();

        /* Array accesses */
    Y = 'a';
    I = 1;
    while (I != 9) {
        Ca[I-1] = Y;
        Y += 2;
        I++;
    }

    Print_ca();

    Ca[3-1] = Ca[5-1];

    Print_ca();

    Y = Ca[4-1];
    Ca[8-1] = Y;

    Print_ca();

    I = 1;
    while (I < 7) {
        Ia[I+4-5] = I+3;
        I = I+1;
    }

    Print_ia();

    Ia[Ia[5-5]+6-5] = Ia[Ia[Ia[Ia[Ia[Ia[10-5]-5]-5]-5]-5]-5];

    Print_ia();

    I = 7;
    while (I <= 9) {
        Ra[I-7] = Ia[I-5] + 1.9;
        I = I+1;
    }

    Print_ra();

    I = 7;
    W = 1;
    while (I <= 9) {
        W = W * Ra[I-7];
        I = I+1;
    }

    Print_w();
    Print_newline();

        /* Pascal's triangle */
    J = 0;
    while (J <= 10) {
        Iaa[0][J] = 1;
        J = J+1;
    }
    I = 1;
    while (I <= 10) {
        Iaa[I][0] = 1;
        J = 1;
        while (J <= 10) {
            Iaa[I][J] = (Iaa[I][J-1] + Iaa[I-1][J]) % 10000;
            J = J+1;
        }
        I = I+1;
    }

    Print_iaa();
    

    I = 0;
    while (I <= 2) {
        J = 2;
        while (J <= 5) {
            K = 5;
            while (K <= 9) {
                Iaaa[I][J-2][K-5] = 3*(2*I+J)+K;
                K = K+1;
            }
            J = J+1;
        }
        I = I+1;
    }

    Print_iaaa();
    return 0;
}
