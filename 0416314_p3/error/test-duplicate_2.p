PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: REAL;

FUNCTION aaa(a, b: INTEGER) : INTEGER;
BEGIN
    aaa := 3
END;

FUNCTION bb : INTEGER;
VAR a, b, c : INTEGER;
VAR d, a, e : REAL;     // Duplicate declaration of a
BEGIN
END;

FUNCTION aaa(a, b: INTEGER) : REAL;  // Duplicate declaration of aaa
BEGIN
    aaa := 3.3
END;

BEGIN
    a := 333
END.
