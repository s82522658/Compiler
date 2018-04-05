PROGRAM aa(input, output, error); 
VAR a, b: INTEGER;
VAR rr: REAL;
VAR c: ARRAY[0..1] of ARRAY[2..3] of ARRAY[4..5] of INTEGER;
VAR d: ARRAY[3..4] of ARRAY[5..6] of REAL;
BEGIN
    rr := 3.14;
    c[1][3][5] := 8;
                                // Must report all 3 errors
    c[8][3][4] := 10;           // Array out of bound
    c[1][5+6][4*0] := 9;    // Can you do constant propagation?
    d[3][rr] := 8.33            // Real values can not be index
END.

