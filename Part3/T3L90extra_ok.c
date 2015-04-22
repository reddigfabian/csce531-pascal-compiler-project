long int A,B;
unsigned char C;


void Print_one();
void Print_two();
void Print_three();
void Print_dunno();
void Print_big();
void Print_just();
void Print_isnt();
void Print_hello();
void Print_oops();
void Print_712();
void Print_is_the();
void Print_grooviest();
void Print_newline();


int main()
{
    A = 3;

    if (A>=5 && A<=10)
        Print_oops();
    else if (A>=1 && A<=3) {
        Print_one();
        Print_two();
        Print_three();
    }
    else
        Print_dunno();

    A = 4;

    if (A>=5 && A<=10)
        Print_big();
    else if (A>=1 && A<=3) {
        Print_one();
        Print_two();
        Print_three();
    }
    else
        Print_dunno();
           
    A = 7;

    if (A>=5 && A<=10)
        Print_big();
    else if (A>=1 && A<=3) {
        Print_one();
        Print_two();
        Print_three();
    }
    else
        Print_dunno();
           
    Print_newline();
    return 0;
}
