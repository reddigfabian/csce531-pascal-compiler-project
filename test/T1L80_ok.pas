{ There are no errors in this file! }
program T1L80ok;

type
   IntPtr	     = ^Integer;
   IntPtrPtr	     = ^IntPtr;
   RealPtrPtr	     = ^RealPtr;
   RealPtr	     = ^Real;
   CharPtrPtrPtr     = ^CharPtrPtr;
   CharPtrPtr	     = ^CharPtr;
   CharPtr	     = ^Char;
   CharArrayPtrArray = Array[1..5] of ^CharArray;
   CharArray	     = Array[4..10] of Char;
   Cycle	     = ^Cycle;
   Cycle1	     = ^Cycle2;
   Cycle2	     = ^Cycle1;

var
   { basic types }
   a : Integer;
   b : Single;
   c : Real;
   d : Char;
   e : Boolean;
   { multiple variables for one type }
   f,g,h : Real;
   { subranges }
   i : 4..17;
   { pointers }
   p1 : ^Integer;
   p2 : IntPtr;
   p3 : ^RealPtrPtr;
   p4 : ^CharPtrPtrPtr;
   { arrays }
   ia : Array[0..9] of Integer;
   iaa : Array[1..10,2..11] of Integer;
   raaa : Array[1..10,2..9,3..8] of Real;
   { combinations }
   x1 : Array[1..5] of ^Char;
   x2 : Array[1..5] of Array[1..6] of ^CharPtr;
   x3 : ^CharArrayPtrArray;

begin
end.
