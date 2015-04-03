program T1L100err;

type
   IntPtr    = ^Integer;
   IntFun    = Function(c : Char) : Integer;
   IntFunPtr = ^Function(a: Real) : Integer;
   IntArray  = Array[1..3] of Integer;

var
   { procedures and functions with parameters }
   f : ^Function(a : Integer) : Integer;
   g : ^Function(a : Integer; b : Real) : Real;
   h : ^Procedure(a,b : Integer; c : Real);
   { var parameters }
   i : ^Procedure(var a : Integer);
   j : ^Function(var a,b : Real; c : Integer) : Integer;
   k : ^Procedure(a : Integer; var b : Integer; c : Integer; var d : Integer);
   { pointer types as parameters }
   l : ^Procedure(var a : IntPtr; f : IntFunPtr);
   { some errors }
   m : ^Function(a,b : Integer; a : Real) : Integer;
   { These are not really errors in all Pascals, but treat them as errors. }
   n : ^Function(a : IntArray) : Real;
   o : ^Procedure(var a : IntArray);
   p : ^Procedure(f : IntFun);
   q : ^Procedure(var f : IntFun);

begin
end.
