program T1L90err;

type
   IntPtr             = ^Integer;
   IntPtrFunPtr       = ^Function : IntPtr;
   IntPtrFunPtrFunPtr = ^Function : IntPtrFunPtr;
   IntFun             = Function : Integer;
   SingleArray        = Array[1..3] of Single;

var
   { procedures and functions without parameters }
   f : ^Function : Integer;
   g : ^Function : Real;
   h : ^Procedure;
   { type modifier combinations }
   i : ^Function : IntPtr;
   k : Array[1..10] of ^Function : Integer;
   l : ^Function : IntPtrFunPtrFunPtr;
   { treat these as errors! (although they are okay in some Pascal dialects) }
   m : ^Function : IntFun;
   n : ^Function : SingleArray;
   o : Array[1..5] of Function : Real;
   p : Function : Integer;

begin
end.
