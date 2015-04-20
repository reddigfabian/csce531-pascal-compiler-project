(* test file for 110% level of project part 2, CSCE 531 *)

(* there are errors in this file *)

program T2L110_err;

var
   i,j,k : Integer;
   x,y	 : Single;
   d	 : Real;
   c	 : Char;
   b	 : Boolean;


Procedure printf; External;


Procedure swap(var a,b : Single);
   var
      tmp : Real;
   begin
      tmp := a;
      a := b;
      b := tmp
   end; { swap }


Procedure inner1;
   var
      i	: Integer;	
   begin
      i := k;
      printf('f.inner1: c = %ld; i = %ld\n', c, i)
   end; { inner1 }

Procedure inner2(var c : Integer);
   var
      i	: Single;	
   begin
      inner     { error }
   end; { inner2 }

Procedure f(c : Integer);
   var
      i	: Integer;
   begin
      i := 19;
      printf('f: c = %ld; i = %ld\n', c, i);
      inner1;
      printf('f: c = %ld; i = %ld\n', c, i);
      inner2(c);
      i := i + 1;
      printf('f: c = %ld; i = %ld\n', c, i)
   end; { f }

Function innerinner(var c1 : Char; var i1,i2 : Integer; var d1,d2 : Real):Real;
   begin
      c1 := chr(96);
      f(ord(c1));
      innerinner := i + i1 + i2 + d + d1 + d2
   end; { innerinner }

Procedure inner(var c1 : Char; var i1 : Integer; var d1 : Real);
   var
      i2 : Integer;
      d2 : Real;
   begin
      i2 := 28;
      d2 := 1.414;
      printf('g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n',
	     c1, i1, i2, d1, d2);
      d1 := innerinner(c1, i1, i2, d1, d2);
      printf('g.inner1: c1 = %d; i1 = %ld; i2 = %ld; d1 = %lg; d2 = %lg\n',
	     c1, i1, i2, d1, d2)
   end; { inner }

Procedure g(var c1 : Char);
   var
      i1 : Integer;
      c1 : Char;      { error }
      d1 : Real;
   begin
      i1 := 496;
      d1 := 2.71;
      c1 := chr(14);
      printf('g: c1 = %d; i1 = %ld; d1 = %lg\n', c1, i1, d1);
      inner(c1, i1, d1);
      c1 := c1;
      printf('g: c1 = %d; i1 = %ld; d1 = %lg\n', c1, i1, d1)
   end; { g }


{ This procedure name won't conflict with the program's entry point,
 since each Pascal identifier's initial letter is capitalized.  Thus,
 procedure "main" becomes "Main". }
Procedure main;
   var
      i	  : Integer;
      x,y : Single;

   begin

      { some errors }
      f(d);
      f(i,j);
      g(chr(i+5));
      swap(x,3.14)
      
   end; { main }

   
begin

   main;

end.
