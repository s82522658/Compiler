PROGRAM foo(input, output, error) ;
   // variable declaraions
   var a: integer;
   var d, e: array [ 1 .. 10 ] of integer; 

   // multi-dimensional array
   var k: array [ 23 .. 57 ] of array [ 23 .. 57 ] of real; 

   begin
      a := a + 1;  // un-initialized variable
                   // Can your compiler find this error?
                   // Will your compiler generate run-time checks?
      k[25][20] := k[25][20] + 3.14  // un-initialized variable
   end.   // this is the end of the program
