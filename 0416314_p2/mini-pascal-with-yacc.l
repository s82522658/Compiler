
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
 #include <string.h>
 #include "node.h"
 #include "y.tab.h"

struct nodeType* newTokenNode(int tokenType);

/*my version*/


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

{P}{R}{O}{G}{R}{A}{M}       {yylval.node = newTokenNode(PROGRAM); return(PROGRAM);}
{E}{L}{S}{E}                {yylval.node = newTokenNode(ELSE);return(ELSE);}
{W}{H}{I}{L}{E}             {yylval.node = newTokenNode(WHILE);return(WHILE);}
{D}{O}                      {yylval.node = newTokenNode(DO);return(DO);}
{T}{H}{E}{N}                {yylval.node = newTokenNode(THEN);return(THEN);}
{I}{F}                      {yylval.node = newTokenNode(IF);return(IF);}
{O}{F}                      {yylval.node = newTokenNode(OF);return(OF);}
{F}{U}{N}{C}{T}{I}{O}{N}    {yylval.node = newTokenNode(FUNCTION);return(FUNCTION);}
{P}{R}{O}{C}{E}{D}{U}{R}{E} {yylval.node = newTokenNode(PROCEDURE);return(PROCEDURE);}
{B}{E}{G}{I}{N}             {yylval.node = newTokenNode(begin);return(begin);}
{E}{N}{D}                   {yylval.node = newTokenNode(END);return(END);}
{A}{R}{R}{A}{Y}             {yylval.node = newTokenNode(ARRAY);return(ARRAY);}
{V}{A}{R}                   {yylval.node = newTokenNode(VAR);return(VAR);}
{N}{O}{T}                   {yylval.node = newTokenNode(NOT);return(NOT);}
{I}{N}{T}{E}{G}{E}{R}       {yylval.node = newTokenNode(INTEGER);return(INTEGER);}
{R}{E}{A}{L}                {yylval.node = newTokenNode(REAL);return(REAL);}
{S}{T}{R}{I}{N}{G}          {yylval.node = newTokenNode(STRING);return(STRING);}
{C}{H}{A}{R}                {yylval.node = newTokenNode(CHAR);return(CHAR);}
[\'][a-zA-Z][\']            {yylval.node = newTokenNode(NODE_Char);yylval.node->string=strdup(yytext);return(Char);}
[\"].*[\"]                  {yylval.node = newTokenNode(NODE_String);yylval.node->string=strdup(yytext);return(String);}
[a-zA-Z]([a-zA-Z0-9\_])*    {yylval.node = newTokenNode(NODE_TOKEN);yylval.node->string=strdup(yytext);printf("ID:%s\n",yylval.node->string);return(ID);}



":="                         {yylval.node = newTokenNode(ASSIGNMENT);return(ASSIGNMENT);}
":"                          {yylval.node = newTokenNode(COLON);return(COLON);}
","                          {yylval.node = newTokenNode(COMMA);return(COMMA);}
"."                          {yylval.node = newTokenNode(DOT);return(DOT);}
".."                         {yylval.node = newTokenNode(DOTDOT);return(DOTDOT);}
"="                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_EQUAL;return(EQUAL);}
"!="                         {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_notEQUAL;return(notEQUAL);}
">="                         {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_GE;return(GE);}
">"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_GT;return(GT);}
"["                          {yylval.node = newTokenNode(LBRAC);return(LBRAC);}
"<="                         {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_LE;return(LE);}
"("                          {yylval.node = newTokenNode(LPAREN);return(LPAREN);}
"<"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_LT;return(LT);}
"-"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_MINUS;return(MINUS);}
"+"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_PLUS;return(PLUS);}
"]"                          {yylval.node = newTokenNode(RBRAC);return(RBRAC);}
")"                          {yylval.node = newTokenNode(RPAREN);return(RPAREN);}
";"                          {yylval.node = newTokenNode(SEMICOLON);return(SEMICOLON);}
"/"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_SLASH;return(SLASH);}
"*"                          {yylval.node = newTokenNode(TOK_REL_OP);yylval.node->op = OP_MUL;return(STAR);}


([\-][0-9]+)|([0-9]+) {yylval.node = newTokenNode(NUM);yylval.node->valueValid = VALUE_I_VALID;yylval.node->iValue = atoi(yytext);return(NUM); }
([\-][0-9]+"."[0-9]+)|([0-9]+"."[0-9]+) {yylval.node = newTokenNode(NUM);yylval.node->valueValid = VALUE_R_VALID;yylval.node->rValue = atof(yytext);return(NUM); }
([\-][0-9]+[E][\+\-][0-9]+)|([\-][0-9]+"."[0-9]+[E][\+\-][0-9]+) {yylval.node = newTokenNode(NUM);yylval.node->valueValid = VALUE_R_VALID;yylval.node->rValue = atof(yytext);return(NUM); }
([0-9]+[E][\+\-][0-9]+)|([0-9]+"."[0-9]+[E][\+\-][0-9]+) {yylval.node = newTokenNode(NUM);yylval.node->valueValid = VALUE_R_VALID;yylval.node->rValue = atof(yytext);return(NUM); }




"//".*[\r\n]        {
                      //fprintf (stderr, "This is a comment at line %d: %s\n ",line_no,yytext);
                      line_no++;
                    }



[ \t\f]    ;

\r         ;
\n    line_no++;

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%

/*** Ccode section ***/


void commenteof()
{
 fprintf (stderr, "unexpected EOF inside comment at line %d\n",
  line_no);
 exit (1);
}


struct nodeType* newTokenNode(int tokenType) {
    struct nodeType *node = newNode(NODE_TOKEN);//all the node's default type is Node_Token.
    node->tokenType = tokenType;
    return node;
}



