program EightQueens;
(*
 *  This program displays solutions to the Eight Queens puzzle.  After each
 *  solution is displayed, the user is asked whether she wants to see nore
 *  solutions.  The program continues until either the user says no or
 *  until no nore solutions are found.
 *
 *  Requirements for compiling:
 *    80% level of Project I
 *   100% level of Project II
 *    80% level of Project III
 *)

type
   QueenArray = array[1..8] of Integer;
   { Array for recording the position of the queen in each row of the board }

var
   Queens	 : QueenArray; { Records the position of the queen in each row }
   CurRow	 : Integer;
   i, j		 : Integer;
   answer	 : Char;
   Continue_Flag : Boolean;
   QueensOk_Flag : Boolean;
   GYON_Flag	 : Boolean;


procedure printf; External;
procedure putchar; External;
function getchar : Char; External;


Procedure DrawBoard;
{ Draws the current state of the board to stdout.  Uses the Queens array. }

begin
   i := 1;
   while i <= 8 do begin
      j := 1;
      while j <= 8 do begin
	 putchar(ord(' '));
	 if j = Queens[i] then
	    putchar(ord('Q'))
	 else
	    putchar(ord('.'));
         j := j+1
      end;
      putchar(10);   { Prints a newline character }
      i := i+1
   end
end; { DrawBoard }


function GetYesOrNo : Char;
{ Gets the first occurrence of [YyNn] from stdin and returns that character. }

begin
   answer := getchar;
   GYON_Flag := true;
   while GYON_Flag do begin
      if answer = 'Y' then
	 GYON_Flag := false
      else if answer = 'y' then
	 GYON_Flag := false
      else if answer = 'N' then
	 GYON_Flag := false
      else if answer = 'n' then
	 GYON_Flag := false;
      if GYON_Flag then
	 answer := getchar
   end;
   GetYesOrNo := answer
end;


function Stop : Boolean;
{ Returns true iff the user does not wish to see any more solutions. }

begin
   printf('Search for another solution? (y/n): ');
   Answer := GetYesOrNo;
   Stop := (Answer = 'N');
   if Answer = 'n' then
      Stop := true
end;


function QueensOk : Boolean;
{ Checks whether the queen in CurRow can attack any queens in rows 1 through
CurRow-1.  Returns true iff this is NOT the case. }

begin
   i := 1;
   QueensOk_Flag := (i < CurRow);
   QueensOk := true;
   while QueensOk_Flag do
      if Queens[i] = Queens[CurRow] then begin
         QueensOk_Flag := false;
         QueensOk := false
      end
      else if Queens[i] = Queens[CurRow] - (CurRow - i) then begin
         QueensOk_Flag := false;
	 QueensOk := false
      end
      else if Queens[i] = Queens[CurRow] + (CurRow - i) then begin
         QueensOk_Flag := false;
	 QueensOk := false
      end
      else begin
         i := i + 1;
	 QueensOk_Flag := (i < CurRow)
      end
end;


function Search : Boolean;
{ Assumes that queens have been placed on the board in rows 1 through CurRow-1
so that no queen can attack another.

Looks for a way to place additional queens on rows CurRow through 8 so that no
queen can attack another.

Returns true for success and false for failure.  (It places a queen
on row CurRow and uses recursive backtracking.)

If it finds queens on all eight rows, it prints the board (a solution) and
prompts the user for another solution.  If the user says yes, then false is
returned (simulating failure) so that searching will continue. }

begin
   if CurRow > 8 then begin
      DrawBoard;
      Search := Stop
   end
   else begin
      Queens[CurRow] := 1;
      Continue_Flag := true;
      while Continue_Flag do begin
         if QueensOk then begin
	    CurRow := CurRow + 1;
	    Continue_Flag := (Search = false);
            CurRow := CurRow - 1
         end;
	 if Continue_Flag then begin
	    Search := false;
	    Queens[CurRow] := Queens[CurRow] + 1;
	    Continue_Flag := (Queens[CurRow] <= 8)
         end
	 else
	    Search := true
      end
   end
end;


begin { main }
   CurRow := 1;
   Continue_Flag := Search;  { This is the main part of the program }
   if Continue_Flag then
      printf('There could be more solutions.\n')
   else
      printf('No more solutions.\n')
end.
