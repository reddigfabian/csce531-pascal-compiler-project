(* Test file for 100% level of CSCE 531 Pascal compiler Project III *)

(* There are no errors in this file *)

program T3L100_ok;

var
   i,j,k : Integer;
   f	 : Single;
   c	 : Char;
   iaa	 : array[0..13, 0..11] of Integer;
   raaa	 : array[2..4, 0..5, 1..4] of Real;
   r	 : Real;


procedure print_nl; External;
procedure print_dot; External;
procedure print_even; External;
procedure print_odd; External;
procedure print_j; External;
procedure print_i_j_values; External;
procedure print_oops; External;
procedure print_iaa; External;
procedure print_raaa; External;
procedure print_r; External;


begin
   for i := 1 to 10 do
      print_dot;
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
	 print_j;
   end;
   print_nl;
   print_i_j_values;

   for j := 10 downto 1 do
      print_i_j_values;

   for i := 0 to 9 do;
   print_oops;

   (* Pascal's triangle again, this time with a 2-d array *)
   for j := 0 to 11 do
      iaa[0,j] := 1;
   for i := 1 to 13 do begin
      iaa[i,0] := 1;
      for j := 1 to 11 do
	 iaa[i,j] := (iaa[i,j-1] + iaa[i-1,j]) mod 10000
   end;

   print_iaa;

   r := 9.0;
   for i := 2 to 4 do
      for j := 0 to 5 do
	 for k := 1 to 4 do begin
	    raaa[i,j,k] := r;
	    r := r * 0.9
	 end;

   print_raaa;

   i := 1;
   j := 2;
   r := raaa[i*3,2*j,3];

   print_r;

end.
