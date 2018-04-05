README, 20100524, 20110501

In the 3rd project, you need first to build an abstract syntax tree or translate the parse tree into an abstract syntax tree.  You should show me or the teaching assistants your abstract syntax tree on the computer screen.

For the third part of the project, you need to write code for symbol table manipulation and for type declaration. You code must print a message in the following occassions:

  1.  every time a new symbol is entered into the symbol table
  2.  every time a new scope is generated
  3.  every time a scope is closed
  4.  every time when a symbol table is created
  5.  every time when a symbol table is destroyed 
  6.  dump a symbol table when the symbol table is destroyed
  7.  dump all symbol tables at the end of the program

Appropriate information in each of the above occassion can also be printed.

Here is a check list for your symbol-table implementation:
  1.  Declare two variables with identical names in two scopes.
      Can you find the appropriate variable when that name is 
      used in an expression?
  2.  Declare two variables with identical names in the same scope.
      Can you catch the duplicate declarations?
  3.  Declare a variable and a function with identical names in
      the same scope.
      Can you catch the duplicate declarations?
  3.  Declare a variable and a function with identical names in
      the differnt scopes.
      Can you find the appropriate usage when that name is 
      used?

There is no additional software tool for the third part of the project.


You compiler should check semantic errors. Common semantic errors include

1. undeclared variables
2. undeclared types
3. undeclared functions
4. undeclared classes
5. Arguments' types and numbers are wrong.
6. type errors in arithmetic expressions
7. redeclared variables
8. redeclared types
9. redeclared functions
10. redeclared classes
11. cycles in inheritance hierarchy
12. cycles in structure containment
13. 


For all parts of the compiler project,
please see the web page

	http://people.cs.nctu.edu.tw/~wuuyang/homepage/Lecture/lecture.compiler.html

"Local On-Line Information" section for additional project material that might be helpful to your project.  Good luck.

Wuu  20110501