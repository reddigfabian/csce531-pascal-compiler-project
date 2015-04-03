(*
 *  test file for EXTRA CREDIT for the 80% level of project part 2, CSCE 531
 *)

(* there are no errors in this file! *)

Program T2L80extra_ok;

var
   i,j,k : Integer;
   x,y,z : Single;
   c	 : Char;
   d	 : Real;
   b	 : Boolean;

Procedure print_globals; External;

Function get_real : Real; External;

Function get_integer : Integer; External;

begin

   i := 5;		
   j := i;
   k := 14;
   x := 3.14;
   y := 2.71;
   z := 0.0;
   d := 19.1999;
   b := False;

   { Converting a length-one string constant to a character constant,
     if needed }
   c := 'A';
   k := ord('B');

   print_globals;		{ link in print_globals later }

   k := i + j;
   j := i - k * k div (i + k);
   i := k mod 7;
   b := k > j;
   c := succ(c);

   print_globals;

   y := k;
   x := y;
   d := k;
   c := pred(chr(k));
   z := ord(c) * i + (-d) - x;
   b := c < chr(34);
   b := b <= (i = 19);

   print_globals;

   i := get_integer + 9; 	{ get_integer also linked in }
   d := get_real + 9.9; 	{ get_real also linked in }

   print_globals;

   { constant folding }
   i := 99 + 17;
   x := -19.99;
   d := 99 * 17.76;
   c := succ(chr(ord(chr(65))+10));

   print_globals

end.
