// This test program includes many errors.
// Check if your compiler can catch all the errors and the quality of the error messages.
// 20142021

PROGRAM foo(input, output, error) ;
   // variable declaraions
   var a, b, c: integer;
   var d, e: array [ 1 .. 10 ] of integer; 
   var g, h: real;
   var k: array [ 23 .. 57 ] of array [ 23 .. 57 ] of real; 
   var a: array [ 23 .. 57 ] of array [ 23 .. 57 ] of real;  // WRONG 1: redefined variables


   // procedure and function declarations
   procedure sort(a: array [ 1 .. 10 ] of integer);
      var a, b, c: integer; // duplicated declaration
      begin
        e := a + d        // WRONG 2: a is an int variable while d is an array.
	a := qqq - rrr;   // WRONG 3: qqq and rrr are undefined variables
        d := f(k, e);     // WRONG 4: f is undefined function
      end;


   function  addition(a, b: integer) : integer;
      var c: integer;  // local declaration
      begin
         addition := a + b   // this is the return value
      end;


   function  addition(c, d: integer) : integer;
   // WRONG 5: redefine a function, even though the arguments have different names
      var e: integer;  // local declaration
      begin
         addition := c + d   // this is the return value
      end;


   function  addition(a, b: real) : real;
   // WARNING 6: Does you compiler allow over-loading? 
      var c: integer;  // local declaration
      begin
         addition := a + b   // this is the return value
      end;


   begin
      a := 1;
      while a < 10 do
      begin
         sum := sum + a;
         a   := a + 1 
      end;
      begin  // nested compound statement
         b := 1;
         while b < 11 do
         begin  // array initialization
            d[b] := b + b * (b - 1);
            b := b +1
         end;
         sort(d)   // a procedure call          
      end;
      k[25][26] := 3;        // wrong element type
      k[25][26] := 3.14;     // good
      k[25][26] := k[25][26] + 3;     // good
      k[25][126]  := 3.14;   // index out of bound
      k[125][26]  := 3.14;   // index out of bound
      k[125][126] := 3.14    // index out of bound
      a := extf(20, sum);    // WARNING 7: can your compiler handle external functions?



      // Warning 8: Can you compiler handle #include
   #include <abc.h>     // include
      a = bbb(20, sum);



       // Warning 9: How do your compiler handle conditional compilation?
 
      #if !defined(__unix__)
      #include Long40.h¡¨
       k[25][26] := k[25][26] + 5;     // good
      #elif defined(_TMS320C6200)
      #define assert(a)
       k[25][26] := k[25][26] + 333;     // good
      #else
      #include ¡¨Long40.h¡¨
       k[25][26] := k[25][26] + 6666;     // good
      #include <assert.h>
      #endif




       // Warning 9: How do your compiler handle pragma?
       #pragma    __promise((k % 16) == 0);
       b := 1;
       while b <= k do
       begin
         sum := sum + a[b];
         b   := b + 1 
       end;


   end.   // this is the end of the program
