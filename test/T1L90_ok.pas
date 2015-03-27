{ There are no errors in this file! }
program T1L90ok;

type
   IntPtr             = ^Integer;
   IntPtrFunPtr       = ^Function : IntPtr;
   IntPtrFunPtrFunPtr = ^Function : IntPtrFunPtr;

var
   { procedures and functions without parameters }
   f : ^Function : Integer;
   g : ^Function : Real;
   h : ^Procedure;
   { type modifier combinations }
   i : ^Function : IntPtr;
   k : Array[1..10] of ^Function : Integer;
   l : ^Function : IntPtrFunPtrFunPtr;

begin
end.
