(* Test file for 100% level of CSCE 531 Pascal compiler Project III *)

(* There are errors in this file *)

program T3L100_err;

var
   i,j : Integer;
   f   : Single;
   c   : Char;
   iaa : array[1..10, 1..5] of Integer;


procedure print_nl; External;
procedure print_dot; External;
procedure print_even; External;
procedure print_odd; External;
procedure print_j; External;
procedure print_i_j_values; External;
procedure print_oops; External;


begin

   { Some errors }
   for f := 0 to 9 do
      print_dot;
   for c := 1 to 10 do
      print_dot;
   for i := 1.0 to 10.0 do
      print_dot;

   i := iaa[i];
   j := iaa[i,j,i];
   i := iaa[i,3.14];
   iaa[3,4] := 3.14;

end.
