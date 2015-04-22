long int I,J,K;
float F;
unsigned char C;
long int Iaa[14][12];  // Indices start at 0, 0
double Raaa[3][6][4];  // indices start at 2, 0, 1
double R;

void Print_nl();
void Print_dot();
void Print_even();
void Print_odd();
void Print_j();
void Print_i_j_values();
void Print_oops();
void Print_iaa();
void Print_raaa();
void Print_r();


int main()
{
    for (I = 1; I <= 10; I++)
        Print_dot();
    Print_nl();

    I = 15;
    for (I = 1; I <= 15; I++)
        Print_dot();
    Print_nl();

    for (C = 1; C <= 10; C++)
        Print_dot();
    Print_nl();

    for (I = 0; I <= 9; I++) {
        switch (I) {
            case 0:
            case 2:
            case 4:
            case 6:
            case 8:
                Print_even(); break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 9:
                Print_odd();
        }
        if (I == 1) I = 3;
        for (J = 1; J <= I-1; J++)
            Print_j();
    }
    Print_nl();
    Print_i_j_values();

    for (J = 10; J >= 1; J--)
        Print_i_j_values();

    for (I = 0; I <= 9; I++);
    Print_oops();

        /* Pascal's triangle again, this time with a 2-d array */
    for (J = 0; J <= 11; J++)
        Iaa[0][J] = 1;
    for (I = 1; I <= 13; I++) {
        Iaa[I][0] = 1;
        for (J = 1; J <= 11; J++)
            Iaa[I][J] = (Iaa[I][J-1] + Iaa[I-1][J]) % 10000;
    }

    Print_iaa();

    R = 9.0;
    for (I = 2; I <= 4; I++)
        for (J = 0; J <= 5; J++)
            for (K = 1; K <= 4; K++) {
                Raaa[I-2][J][K-1] = R;
                R = R * 0.9;
            }

    Print_raaa();

    I = 1;
    J = 2;
    R = Raaa[I*3-2][2*J][3-1];

    Print_r();
    return 0;
}
