(* Test file for level 90 of CSCE 531 Pascal compiler Project III *)

(* There are no errors in this file *)

program T3L90extra_ok;

var
   a,b : Integer;
   c   : Char;


procedure print_one; External;
procedure print_two; External;
procedure print_three; External;
procedure print_dunno; External;
procedure print_big; External;
procedure print_just; External;
procedure print_isnt; External;
procedure print_hello; External;
procedure print_oops; External;
procedure print_712; External;
procedure print_is_the; External;
procedure print_grooviest; External;
procedure print_newline; External;


begin

   a := 3;

   case a of
     5..10: print_oops;
     1..3:
        begin   
	   print_one;
	   print_two;
	   print_three
	end
   else
      print_dunno
   end; { case }

   a := 4;

   case a of
     5..10: print_big;
     1..3:
        begin   
	   print_one;
	   print_two;
	   print_three
	end
   else
      print_dunno
   end; { case }
   
   a := 7;

   case a of
     5..10: print_big;
     1..3:
        begin   
	   print_one;
	   print_two;
	   print_three
	end
   else
      print_dunno
   end; { case }
   
   print_newline

end.
