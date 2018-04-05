PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

PROCEDURE ss(a,b:INTEGER; c:REAL);
BEGIN
END;

FUNCTION tt : INTEGER;
BEGIN
  tt := 3
END;

BEGIN
    a := 3+tt;
    ss(a, tt, 0.5);
    ss(tt, tt)  // wrong number of parameters
END.
