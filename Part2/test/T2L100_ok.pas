(* test file for 100% level of project part 2, CSCE 531 *)

(* there are no errors in this file *)

program T2L100_ok;

var
   i,j,k : Integer;
   x,y,z : Single;
   d	 : Real;
   c	 : Char;
   ip	 : ^Integer;
   rp	 : ^Real;

Procedure printf; External;
Procedure scanf; External;
Function getchar : Char; External;
Function abc : Integer; Forward;

Procedure rst;
   begin
      j := abc;
   end; { rst }

Procedure xyz;
   begin
      i := 1999
   end; { xyz }

Function abc : Integer;
   begin
      xyz;
      abc := 18;
      k := 20;
      abc := 19
   end; { abc }

Function get_integer : Integer;
   begin
      new(ip);
      printf('Enter an integer:   ');
      scanf('%ld', ip);
      get_integer := ip^;
      dispose(ip);
   end; { get_integer }

Function get_real : Real;
   begin
      new(rp);
      printf('Enter a real:   ');
      scanf('%lf', rp);
      get_real := rp^;
      dispose(rp);
   end; { get_real }

Function get_character : Char;
   begin
      printf('Enter a character:   ');
      get_character := getchar; { Reads previous newline }
      get_character := getchar;
   end; { get_character }

Procedure print_globals;
   begin
      printf('i = %ld; j = %ld; k = %ld\n', i, j, k);
      printf('x = %f; y = %f; z = %f\n', x, y, z);
      printf('d = %lf\nc = %u\n', d, c);
   end; { print_globals }


begin
   
   printf('this is a debugging message\n');
   
   rst;
   d := get_real;
   c := get_character;
   x := d;
   y := i div k;
   z := i mod k;

   print_globals;

   i := get_integer;
   d := x * 2;

   print_globals
   
end.
