PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION tt : INTEGER;
VAR a, b : ARRAY[1 .. 2] of INTEGER;
BEGIN
  a[1] := 3;    // No error since this reference is to local variable
  b[1] := a[1]+4;
  tt := b[1]
END;

BEGIN
    a := 3;
    b := 4
END.
