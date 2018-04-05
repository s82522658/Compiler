PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR c: ARRAY[0..1] of ARRAY[2..3] of ARRAY[4..5] of INTEGER;
BEGIN
    a := 1;
    //c[1][3][5] := 8;

    // Should report 3 errors
    c[a][a+2][a+4][a+6] := 10;      // wrong array dimension
    c[1][3][5][0][77] := 5566;      // Wrong array dimension
    c[0] := 8                       // Wrong array dimension
END.

