PROGRAM foo(input, output, error) ;
      
   var a, b : integer;
   
   // test recursive functions
   function  sum(a, b: integer) : integer;
      begin
         if a <= 0 then sum := 0
         else sum := a + sum(a - 1, 0)  // correct
         // sum is the return value
      end;
   
   begin  
      a := sum(10);         // wrong function parameters
      a := sum(10, 20);     // correct
      b := sum(-10, 4, 7)   // wrong function parameters 
   end.   // this is the end of the program
