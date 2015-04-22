(* Test file for level 100 of CSCE 531 Pascal compiler Project III *)

(* There are errors in this file *)

program T3L100;

var
   a,b : Integer;
   f   : Single;
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


   case b of
     5..10: print_oops;
     1..3:
        begin   
	   print_one;
	   print_two;
	   print_three
	end
   else
      print_dunno;
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

   print_newline;

   
   { Some errors }

   case b of
     1 : print_one;
     2 : print_two;
     1 : print_one
   end;

   case a of
     2	  : print_isnt;
     1..5 : print_just
   else
      print_isnt
   end; { case }

   case a of
     1..5 : print_just;
     4..7 : print_isnt
   else
      print_just
   end; { case }

   case b of
     3.14: print_oops;
     2.71: print_oops
   end; { case }

   case c of
     1 : print_isnt
   else
      print_just
   end; { case }

   case f of
     1 : print_oops
   else
      print_oops
   end; { case }

   { Remove the following code if you did not implement break statements. }

   case a of
     1 : break
   else
      print_oops
   end; { case }

end.
