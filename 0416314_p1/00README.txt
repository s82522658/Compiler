README for the scanner project, 20141009


For all parts of the compiler project,
please see our course web page
	  
          http://people.cs.nctu.edu.tw/~wuuyang/homepage/Lecture/lecture.compiler.html

"Local On-Line Information" section for additional project material that might be helpful to your project.  Good luck.






For the first part of the compiler project, we will implement a scanner. Our target language is {\it Mini-Pascal}, whose syntax is given in the file ``MINI-PASCAL-GRAMMAR.txt''. Since we will use the lex tool, you will need to prepare the input for lex.

Your work is to study MINI-PASCAL-GRAMMAR.txt and define the tokens used in the Mini-Pascal language. If you do not know how to start the project, please study the file ``standard-pascal-no-yacc.l'', which is the lex specification for the complete
Pascal lagnuage. Simply delete tokens that are not used in Mini-Pascal and add whatever changes you need.  It should work.

In particular, you need to add regular expressions for num, strings and comments.

Comments in a program are marked with two slashes and continue to the end of the current line. For example,

           a := a + 1 ; // This is a comments

Your scanner should print a message for each comments.  Comments will not be returned to the parser.

A number could be prefixed with an optional positive/negative sign. A number could be an integer or a floating-point number. They both are considered as the token 'num'. You may define the regular expression for a number in an appropriate way. You may even define the scientific notation, such as 10.3E+5.

Furthermore, in the Mini-Pascal grammar, there is no provision for a string, such as "hello". A string is also considered as a number by the scanner. Similarly, a character, such as 'a', is also considered as a number by the scanner. You may define the regular expressions for strings and characters in a reasonable way.

Please come to discuss with me if you need help.  Do not leave the project blank.

The list of tokens for Mini-Pascal includes the following tokens:



program
id
(
)
;
.
,
var
:
array
[
]
num
of
integer
real
function
procedure
begin
end
:= (assignop)
if
then
else
while 
do
<
>
<=
>=
=
!=
+
-
*
/
not 
..



The GNU flex distribution is located at
	ftp://prep.ai.mit.edu/pub/gnu/
You may find the source there.  An easier way to obtain lex/yacc tools is to check the `flex&bison_for_Windows'' directory.


To generate a scanner, run the following commands:

>> flex standard-pascal-no-yacc.l
   The above command will generate a file named ``lex.yy.c''.
   Use a C compiler to compile the C file.

>> cc lex.yy.c -ll
   The above command will produce an executable file, say ``a.out''.
   Then execute the scanner:

>> a.out scanner-test01.p   (or "a.out < scanner-test01.p")
 
The output of your scanner should be the list of the tokens produced by the scanner, together with the line number and character position in the line:

  0-th token(type:28) on line 1 : PROGRAM
  1-th token(type:39) on line 1 : mytest
  2-th token(type:52) on line 1 : (
  3-th token(type:39) on line 1 : input
  4-th token(type:43) on line 1 : ,
  5-th token(type:39) on line 1 : output
  ... 


>> The real output is in the file output.txt.



Common problems in the scanner project:	
	1.  註解、字串和科學記號這三個比較常漏掉
	2.  input file寫死
	3.  資料夾沒有放置測試檔(test cases)

Wuu  20100225