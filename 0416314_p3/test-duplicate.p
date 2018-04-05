PROGRAM foo(input, output, error) ;
   // This test checks duplicated identifier.
   var abc: integer;

   var abc: array [ 23 .. 57 ] of array [ 23 .. 57 ] of real; 

   function abc(x: integer) : integer;  // duplicate procedure names
      begin   x := x + 1   end;
      
   begin
      abc := 1 
   end.   // this is the end of the program
