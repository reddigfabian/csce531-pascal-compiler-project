(* Test file for 100% level of CSCE 531 Pascal compiler Project III *)

(* There are no errors in this file *)

program T3L100_ok;

var
   i,j  : Integer;
   f    : Single;
   c    : Char;
   iaa  : array[0..13, 0..11] of Integer;
   raaa : array[2..4, 0..5, 1..4] of Real;
   r    : Real;


procedure print_nl; External;
procedure print_dot; External;
procedure print_even; External;
procedure print_odd; External;
procedure print_j; External;
procedure print_i_j_values; External;
procedure print_oops; External;


begin
   for i := 1 to 10 do
      print_dot;
   print_nl;

   for i := 1 to 100 do begin
      print_dot;
      if i = 10 then break
   end;
   print_nl;

   i := 15;
   for i := 1 to i do
      print_dot;
   print_nl;

   for c := chr(1) to chr(10) do
      print_dot;
   print_nl;

   for i := 0 to 9 do begin
      case i of
	0,2,4,6,8: print_even;
	1,3,5,7,9: print_odd
      end;
      if i = 1 then i := 3;
      for j := 1 to i-1 do
	 if j = 7 then break
	 else print_j;
      if i > 99 then break
   end;
   print_nl;
   print_i_j_values;

   for j := 10 downto 1 do
      print_i_j_values;

   for i := 0 to 9 do;
   print_oops;

   for i := 10 downto 0 do begin
      case i of
	0,2,4,6,8,10: print_even;
	1,3,7,9     : print_odd;
	5           : break;
      end; { case }
      print_oops
   end

end.
