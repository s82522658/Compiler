PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION tt : REAL;
VAR aaa : INTEGER;
BEGIN
  aaa := 3;
  tt := aaa // type mismatch for return value
END;

FUNCTION bb (a,b : REAL) : INTEGER;
VAR c : INTEGER;
VAR d : ARRAY[1..2] of INTEGER;
BEGIN
  a := tt+3.14;
  bb := 3
END;

BEGIN
    a := 3
END.
