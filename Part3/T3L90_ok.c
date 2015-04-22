long int A,B;
unsigned char C;


void Print_one();
void Print_two();
void Print_three();
void Print_dunno();
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
    A = 9;
    B = 3;

    switch (A) {
        case 1 : Print_one(); break;
        case 2 : Print_two(); break;
        case 3 : Print_three();
    }

    switch (A) {
        case 1 : Print_one(); break;
        case 2 : Print_two(); break;
        case 3 : Print_three(); break;
        default :
            Print_dunno();
    }

    A = 2;

    switch (A) {
        case 1 : Print_one(); break;
        case 2 : Print_two(); break;
        case 3 : Print_three(); break;
        default :
            Print_dunno();
    }

    A = 1;

    switch (A) {
        case 1 :
        case 2 : Print_one(); break;
        case 3 : Print_three(); break;
        default :
            Print_dunno();
    }

    A = 2;

    switch (A) {
        case 1 :
        case 2 : Print_one(); break;
        case 3   : Print_three(); break;
        default :
            Print_dunno();
    }

    A = 3;

    switch (A) {
        case 1 :
        case 2 : Print_one(); break;
        case 3 : Print_three(); break;
        default :
            Print_dunno();
    }


        /* This next part is a lot easier with constant-folding. */

    C = 3;

    switch (C) {
        case 3 :
        
            switch (C) {
                case 1 :
                case 2 :
                case 4 : Print_oops(); break;
                case 3 : 
	        
                    Print_712();
                    Print_is_the();
            }
            Print_grooviest(); break;
	
        default :	       
            Print_oops();
            switch (C) {
                case 1 :
                case 2 :
                case 3 :
                case 4 : Print_oops(); break;
                default :	
                    Print_oops();
            }
    }
   
    Print_newline();

    return 0;
}

