PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION bb (a,b : INTEGER) : INTEGER;
VAR c : INTEGER;
VAR d : ARRAY[1..2] of INTEGER;
BEGIN
  a := 1;
  c := 0.5;     // type mismatch for assignment
  d[1] := a;
  b := c+d;     // type mismatch for operator
  bb := 5
END;

BEGIN
    a := 3
END.
