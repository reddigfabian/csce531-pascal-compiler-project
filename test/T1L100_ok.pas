{ There are no errors in this file! }
program T1L100ok;

type
   IntPtr    = ^Integer;
   IntFunPtr = ^Function(a : Real) : Integer;
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

begin
end.
