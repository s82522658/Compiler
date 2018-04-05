
/*** Definition section ***/
%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>

 /*my version*/

#define   PROGRAM 1
#define   ELSE 2
#define   WHILE 3
#define   DO 4
#define   THEN 5

#define   IF 6
#define   OF 7
#define   FUNCTION 8
#define   PROCEDURE 9
#define   begin 10

#define   END 11
#define   ARRAY 12
#define   VAR 13
#define   NOT 14
#define   ID 15

#define   STRING 16
#define   ASSIGNMENT 17
#define   COLON 18
#define   COMMA 19
#define   INTEGER 20

#define   DOT 21
#define   DOTDOT 22
#define   EQUAL 23
#define   notEQUAL 24
#define   GE 25

#define   GT 26
#define   LBRAC 27
#define   LE 28
#define   LPAREN 29
#define   LT 30

#define   MINUS 31
#define   PLUS 32
#define   RBRAC 33
#define   REAL 34
#define   RPAREN 35

#define   SEMICOLON 36
#define   SLASH 37
#define   STAR 38
#define   CHAR 39
#define   NUM 40
#define   FNUM 41




int line_no = 1;


%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

%%

{P}{R}{O}{G}{R}{A}{M}       return(PROGRAM);
{E}{L}{S}{E}                return(ELSE);
{W}{H}{I}{L}{E}             return(WHILE);
{D}{O}                      return(DO);
{T}{H}{E}{N}                return(THEN);
{I}{F}                      return(IF);
{O}{F}                      return(OF);
{F}{U}{N}{C}{T}{I}{O}{N}    return(FUNCTION);
{P}{R}{O}{C}{E}{D}{U}{R}{E} return(PROCEDURE);
{B}{E}{G}{I}{N}             return(begin);
{E}{N}{D}                   return(END);
{A}{R}{R}{A}{Y}             return(ARRAY);
{V}{A}{R}                   return(VAR);
{N}{O}{T}                   return(NOT);
{I}{N}{T}{E}{G}{E}{R}       return(INTEGER);
{R}{E}{A}{L}                return(REAL);
[\'][a-zA-Z][\']            return(CHAR);
[\"].*[\"]                  return(STRING);
[a-zA-Z]([a-zA-Z0-9\_])*   return(ID);


([\-][0-9]+)|([0-9]+) {  return(NUM); }
([\-][0-9]+[E][\+\-][0-9]+)|([\-][0-9]+"."[0-9]+[E][\+\-][0-9]+) {return(FNUM);}
([\-][0-9]+"."[0-9]+)|([0-9]+"."[0-9]+) {return(FNUM);}
([0-9]+[E][\+\-][0-9]+)|([0-9]+"."[0-9]+[E][\+\-][0-9]+) {return(FNUM);}



":="                         return(ASSIGNMENT);
":"                          return(COLON);
","                          return(COMMA);
"."                          return(DOT);
".."                         return(DOTDOT);
"="                          return(EQUAL);
"!="                         return(notEQUAL);
">="                         return(GE);
">"                          return(GT);
"["                          return(LBRAC);
"<="                         return(LE);
"("                          return(LPAREN);
"<"                          return(LT);
"-"                          return(MINUS);
"+"                          return(PLUS);
"]"                          return(RBRAC);
")"                          return(RPAREN);
";"                          return(SEMICOLON);
"/"                          return(SLASH);
"*"                          return(STAR);






"//".*[\r\n]        {
                      fprintf (stderr, "This is a comment at line %d: %s\n ",line_no,yytext);
                      line_no++;
                    }



[ \t\f]    ;

\r         ;
\n    line_no++;

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%

/*** Ccode section ***/

int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("test.txt", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok,line_no, yytext);
  }
  return(0);
} /* end of main */

int yywrap() {
  fclose(yyin);
  exit(1);
}

