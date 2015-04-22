long int I,J;
float F;
unsigned char C;
long int Iaa[14][12];  // starting indices: 0, 0
double Raaa[3][6][4]; // starting indices 2, 0, 1
double R;


void Print_nl();
void Print_dot();
void Print_even();
void Print_odd();
void Print_j();
void Print_i_j_values();
void Print_oops();

int main()
{
    for (I = 1; I <= 10; I++)
        Print_dot();
    Print_nl();

    for (I = 1; I <= 100; I++) {
        Print_dot();
        if (I == 10) break;
    }
    
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
                Print_odd(); break;
        }
        if (I == 1) I = 3;
        for (J = 1; J <= I-1; J++)
            if (J == 7) break;
            else Print_j();
        if (I > 99) break;
    }
    Print_nl();
    Print_i_j_values();

    for (J = 10; J >= 1; J--)
        Print_i_j_values();

    for (I = 0; I <= 9; I++);
    Print_oops();

    for (I = 10; I >= 0; I--) {
        switch (I) {
            case 0:
            case 2:
            case 4:
            case 6:
            case 8:
            case 10:
                Print_even(); break;
            case 1:
            case 3:
            case 7:
            case 9:
                Print_odd(); break;
            case 5:
                break;
        }
        if (I == 5) break;
        Print_oops();
    }

    return 0;
}
