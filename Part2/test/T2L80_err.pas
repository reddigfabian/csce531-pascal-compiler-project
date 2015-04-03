(* test file for 80% level of project part 2, CSCE 531 *)

(* there are errors in this file! *)

Program T2L80_err;

var
   i,j,k : Integer;
   x,y,z : Single;
   c	 : Char;
   d	 : Real;
   b	 : Boolean;

Procedure print_globals; External;

Function get_real : Real; External;

Function get_integer : Integer; External;

{ Some errors }

Function w : Real; External;

Function w : Char; External;

Function x : Single; External;


begin

   i := 5;		
   j := i;
   d := 19.1999;

   print_globals;		{ link in print_globals later }

   k := i + j;		
   j := i - k * k div (i + k);

   print_globals;

   i := get_integer + 9; 	{ get_integer also linked in }
   d := get_real + 9.9; 	{ get_real also linked in }

   print_globals;

   { some errors }
   q;
   c;
   (17);
   (17) := 18;
   get_integer := 19;
   i := print_globals;

   { more errors }
   q := 19;
   b := 19;
   i := 3.14;
   i := c;
   c := x;
   c := k;
   d := c;
   i := k > j;
   x := y = k;
   z := c * i + (-d) - x;
   b := (x < (i = 19));
   
end.
