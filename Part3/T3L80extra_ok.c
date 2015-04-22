long int A,B,C;
long int X;
float Z;
unsigned char Ca[8];
long int Ia[6];
double Ra[3];

void Print_abc();
void Print_x();
void Print_z();
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

    X = 9;

    while (1) {
        if (X < 0)
            break;
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
        } else
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

    while (1) {
        if (X < 0) break;
        Print_looping();
        X = X - 1;
    }

    if (X != 0)
        X = 0;


    X = 3;

    while (1) {
        if (X < 0) break;
        Print_looping();
        B = 0;

        while (1) {
            if (B > 1) break;
            Print_looping_looping();
            C = 8;

            while (1) {
                if (C > 10) break;
                Print_looping_looping_looping();
                C = C+1;
            }
            B = B + 1;
        }
        X = X - 1;
    }

    return 0;
}
