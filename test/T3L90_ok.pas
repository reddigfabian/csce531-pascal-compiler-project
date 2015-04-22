(* Test file for level 100 of CSCE 531 Pascal compiler Project III *)

(* There are no errors in this file *)

program T3L100ok;

var
   a,b : Integer;
   c   : Char;


procedure print_one; External;
procedure print_two; External;
procedure print_three; External;
procedure print_dunno; External;
procedure print_just; External;
procedure print_isnt; External;
procedure print_hello; External;
procedure print_oops; External;
procedure print_712; External;
procedure print_is_the; External;
procedure print_grooviest; External;
procedure print_newline; External;


begin

   a := 9;
   b := 3;

   case a of
     1 : print_one;
     2 : print_two;
     3 : print_three
   end; { case }

   case a of
     1 : print_one;
     2 : print_two;
     3 : print_three
   else
      print_dunno
   end; { case }

   a := 2;

   case a of
     1 : print_one;
     2 : print_two;
     3 : print_three
   else
      print_dunno
   end; { case }

   a := 1;

   case a of
     1,2 : print_one;
     3   : print_three
   else
      print_dunno
   end; { case }

   a := 2;

   case a of
     1,2 : print_one;
     3   : print_three
   else
      print_dunno
   end; { case }

   a := 3;

   case a of
     1,2 : print_one;
     3   : print_three
   else
      print_dunno
   end; { case }


   { This next part is a lot easier with constant-folding. }

   c := chr(3);

   case c of
     chr(3) :
        begin
	   case c of
	     chr(1),chr(2),chr(4) : print_oops;
	     chr(3)		  : 
	        begin
		   print_712;
		   print_is_the
		end
	   end; { case }
	   print_grooviest
	end
   else	       
      print_oops;
      case ord(c) of
	1,2,3,4	: print_oops
      else	
	 print_oops
      end; { case }
   end; { case }
   
   print_newline

end.
