(* test file for 100% level of project part 2, CSCE 531 *)

(* there are errors in this file *)

program T2L100_err;

var
   i,j,k : Integer;
   x,y,z : Single;
   d	 : Real;
   c	 : Char;
   ip	 : ^Integer;
   rp	 : ^Real;

Procedure printf; External;
Function getchar : Char; External;

Procedure xyz;
   begin
      d := 19.99
   end; { print_globals }

Procedure rst;
   begin
      rst := 10; { error }
      j := abc	{ error }
   end; { rst }

Function abc : Integer;
   begin
      h := 20; { error }
      i := xyz; { error }
      abc := 19
   end; { abc }


begin
   
   printf('this is a debugging message\n');
   
   xyz;
   rst;
   k := abc

end.
