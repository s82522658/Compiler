PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

PROCEDURE ss;
BEGIN
END;

FUNCTION tt : INTEGER;
BEGIN
  tt := 3
END;

BEGIN
    a := 3+tt;
    ss;ss;ss;
    b := 3+ss   // Procedure can not appear in expression
END.
