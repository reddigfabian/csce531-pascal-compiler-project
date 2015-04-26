(* Test file for level 80 of CSCE 531 Pascal compiler Project III *)

(* There are no errors in this file. *)


program T3L80_ok;

var
   a,b,c : Integer;
   x	 : Integer;
   y	 : Char;
   z	 : Single;
   w	 : Real;
   i,j,k : Integer;
   ca	 : array[1..8] of Char;
   ia	 : array[5..10] of Integer;
   ra	 : array[7..9] of Real;
   (* Arrays of arrays *)
   iaa   : array[0..10] of array[0..10] of Integer;
   iaaa  : array[0..2] of array[2..5] of array[5..9] of Integer;

procedure print_abc; External;
procedure print_x; External;
procedure print_z; External;
procedure print_w; External;
procedure print_ca; External;
procedure print_ia; External;
procedure print_ra; External;
procedure print_iaa; External;
procedure print_iaaa; External;
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

   if x <> 0 then
      x := 0;


   x := 3;

   while x >= 0 do begin
      print_looping;
      b := 0;

      while b <= 1 do begin
	 print_looping_looping;
	 c := 8;

	 while c <= 10 do begin
	    print_looping_looping_looping;
	    c := c+1
	 end;
	 b := b + 1
      end;
      x := x - 1
   end;

   a := 1;
   b := 1;
   c := 1;

   while b < 99 do begin
      if a > 19 then begin
	 b := b * 2;
	 a := a + 3
      end
      else if a > 9 then begin
	 b := b - 5;
	 a := a + 1
      end
      else begin
	 b := b * 3;
	 a := a * 2
      end;

      print_abc;
      c := c+1
   end;

   print_newline;

   (* Array access *)

   y := 'a';
   i := 1;
   while i <> 9 do begin
      ca[i] := y;
      y := succ(succ(y));
      i := succ(i)
   end;

   print_ca;

   ca[3] := ca[5];

   print_ca;

   y := ca[4];
   ca[8] := y;

   print_ca;

   i := 1;
   while i < 7 do begin
      ia[i+4] := i+3;
      i := i+1
   end;

   print_ia;

   ia[ia[5]+6] := ia[ia[ia[ia[ia[ia[10]]]]]];

   print_ia;

   i := 7;
   while i <= 9 do begin
      ra[i] := ia[i] + 1.9;
      i := i+1
   end;

   print_ra;

   i := 7;
   w := 1;
   while i <= 9 do begin
      w := w * ra[i];
      i := i+1
   end;

   print_w;
   print_newline;

   (* Pascal's triangle *)
   j := 0;
   while j <= 10 do begin
      iaa[0][j] := 1;
      j := j+1
   end;
   i := 1;
   while i <= 10 do begin
      iaa[i][0] := 1;
      j := 1;
      while j <= 10 do begin
	 iaa[i][j] := (iaa[i][j-1] + iaa[i-1][j]) mod 10000;
	 j := j+1
      end;
      i := i+1
   end;

   print_iaa;

   i := 0;
   while i <= 2 do begin
      j := 2;
      while j <= 5 do begin
	 k := 5;
	 while k <= 9 do begin
	    iaaa[i][j][k] := 3*(2*i+j)+k;
	    k := k+1
	 end;
	 j := j+1
      end;
      i := i+1
   end;

   print_iaaa

end.
