(* Test file for level 85 of CSCE 531 Pascal compiler Project III *)

(* There are errors in this file. *)


program T2L85;

var
   a,b,c : Integer;
   x	 : Integer;
   y	 : Char;
   z	 : Single;
   w	 : Real;
   ca	 : array[1..8] of Char;
   ia	 : array[5..10] of Integer;
   ra	 : array[7..9] of Real;


procedure print_abc; External;
procedure print_x; External;
procedure print_z; External;
procedure print_oops; External;
procedure print_7; External;
procedure print_1; External;
procedure print_2; External;
procedure print_newline; External;
procedure print_is; External;
procedure print_grooviest; External;
procedure print_outer; External;
procedure print_inner; External;
procedure print_inner_inner; External;
procedure print_looping; External;
procedure print_looping_looping; External;
procedure print_looping_looping_looping; External;


begin
   a := 1;
   b := 1;
   c := 1;

   while b < 99 do begin
      if a > 9 then begin
	 b := b * 2;
	 a := a + 3
      end else begin
	 b := b * 3;
	 a := a * 2
      end;

      print_abc;
      c := c+1
   end;

   x := 9;

   while x >= 0 do begin
      print_x;
      x := x - 1
   end;

   a := -1;
   b := 0;
   c := 1;

   if a > b then
      print_oops
   else begin
      if b = c+a then begin
	 print_7;
	 print_1;
	 if true then print_2;
	 print_newline
      end else
	 print_oops;
      print_is
   end;

   print_grooviest;


   a := -1;

   while a > 3 do
      print_oops;

   while a < 3 do begin

      print_outer;

      b := 0;
      while b < a+1 do begin
	 print_inner;

	 c := 0;
	 while c < 5 do begin
	    print_inner_inner;
	    c := c+1
	 end;

	 b := b+1
      end;

      a := a+1
   end;


   x := 9;

   while x >= 0 do begin
      print_looping;
      x := x - 1
   end;

   if a then           { error }
      a := a+1;

   while x do          { error }
      x := x + 1;

   if w then           { error }
      w := w+1
   else
      w := w-1;

   (* Array access-related errors *)

   ca[y] := chr(65);
   a := ca[3];
   a := ia[b+3.14];
   w := ra[w];
   w := ra;
   ra := w;
   a := b[x];
   w := ra[ia];

end.
