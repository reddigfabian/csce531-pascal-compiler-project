(* test file for 100% level of project part 2, CSCE 531 *)

(* there are errors in this file *)

program T2L100_err;

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


Procedure f(c : Integer);
   var
      i	: Integer;
   Procedure inner1;
      var
	 i : Integer;	
      begin
	 i := k;
	 inner2 { error }
      end; { inner1 }
   Procedure inner2;
      var
	 i : Single;	
      begin
	 inner { error }
      end; { inner2 }

   begin
      inner1;
      inner2
   end; { f }


Procedure g(var c1 : Char);
   var
      i1 : Integer;
      c1 : Char;     { error }
      d1 : Real;
   Procedure inner1;
      var
	 i2 : Integer;
	 d2 : Real;
      Function innerinner : Real;
         begin
	    f(ord(c1));
	    innerinner := i + i1 + i2 + d + d1 + d2
	 end; { innerinner }
      begin
	 d1 := innerinner
      end; { inner1 }

   begin
      inner2; { error }
      d1 := innerinner; { error }
      f(f) { error }
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
      swap(x,3.14);
      
   end; { main }

   
begin

   main

end.
