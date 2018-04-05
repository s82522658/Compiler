%{
/***************
*input type:String,Char,NUM
*number:int,float,scientific
****************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "symtab.h"
#include "codegen.h"
//#include "symtab.c"
//#include "node.c"

extern int line_no;
int yydebug=1;
int yylex();
struct nodeType* newOpNode(int op);
extern struct nodeType* ASTRoot;


void yyerror (char const *s){
    extern char *yytext;
    extern int line_no;
    fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);
 }
%}

/* The union structure for yylval
   Here all terminals/nonterminals are represented by the same type
   you can add other types, and use yylval.type to access the union field */
%union {
    struct nodeType *node;
}

/* Declare the types for each terminal/nonterminal */
%token <node> PROGRAM ELSE WHILE DO THEN IF OF FUNCTION PROCEDURE begin
%token <node> END ARRAY VAR NOT STRING ASSIGNMENT COLON COMMA INTEGER 
%token <node> DOT DOTDOT EQUAL notEQUAL GE GT LBRAC LE LPAREN LT 
%token <node> MINUS PLUS RBRAC REAL RPAREN SEMICOLON SLASH STAR CHAR  
%token <node> NUM TOK_REL_OP
%token <node> String Char ID

%type <node> prog identifier_list declarations type standard_type subprogram_declarations
%type <node> subprogram_declaration subprogram_head arguments parameter_list optional_var
%type <node> compound_statement optional_statements statement_list statement variable
%type <node> tail procedure_statement expression_list expression simple_expression term
%type <node> factor addop mulop relop

%%


prog : PROGRAM ID LPAREN identifier_list RPAREN SEMICOLON
      declarations
      subprogram_declarations
      compound_statement
      DOT{
        $$=newNode(NODE_prog);
        $$->string=$2->string;//program name
        printf("program name:%s\n",$2->string);
        //addChild($$,$4);
        addChild($$,$7);
        addChild($$,$8);
        addChild($$,$9);
        ASTRoot = $$;
        deleteNode($1);
        deleteNode($3);
        deleteNode($5);
        deleteNode($6);
        deleteNode($10);
        printf("Reduction(prog -> PROGRAM ID ( identifier_list ) ; declartions subprogram_declartions");
        printf("compound_statement.)\n"); 
      }
   ;

identifier_list : ID{
      $$=newNode(NODE_identifier_list);
      $$->lineno=line_no;
      printf("lineno:%d",$$->lineno);
      $1->nodeType=NODE_ID;
      addChild($$,$1);
      printf("Reduction(identifier_list -> ID)\n");
    }
  | identifier_list COMMA ID{
      $$=$1;
      $3->nodeType=NODE_ID;
      addChild($$,$3);
      deleteNode($2);
      printf("Reduction(identifier_list -> identifier_list , ID)\n");
    }
  ;

declarations : declarations VAR identifier_list COLON type SEMICOLON{
      //$$=$1; 
      $$=newNode(NODE_declarations);
      addChild($$,$1);     
      addChild($$,$3);
      addChild($$,$5);
      deleteNode($2);
      deleteNode($4);
      deleteNode($6);
      printf("Reduction(declartions -> declarations VAR identifier_list : type ;)\n");
    }
  | {
      $$=newNode(NODE_declarations);
      printf("Reduction(declartions -> )\n");
    }
  ;

type : standard_type{
      $$=$1;
      printf("Reduction(type -> standard_type)\n");
    }
  | ARRAY LBRAC NUM DOTDOT NUM RBRAC OF type{ 
      $$=$1;
      $$->nodeType=NODE_TYPE_ARRAY;
      $3->nodeType = NODE_NUM;//init value
      addChild($$,$3);
      $5->nodeType = NODE_NUM;//size of array
      addChild($$,$5);
      addChild($$,$8);//type of array

      deleteNode($2);
      deleteNode($4);
      deleteNode($6);
      deleteNode($7);

      printf("Reduction(type -> ARRAY ( NUM .. NUM ) OF type)\n");
    }
  ;

standard_type : INTEGER{
      $$=$1;
      $$->nodeType = NODE_TYPE_INT;
      printf("Reduction(standard_type -> INTEGER)\n");
    }
  | REAL{
      $$=$1;
      $$->nodeType = NODE_TYPE_REAL;
      printf("Reduction(standard_type -> REAL)\n");
    }
    | STRING{
        $$=$1;
        $$->nodeType = NODE_TYPE_STRING;
        printf("Reduction(standard_type -> STRING)\n");
      }
    | CHAR{
        $$=$1;
        $$->nodeType = NODE_TYPE_CHAR;
        printf("Reduction(standard_type -> CHAR)\n");
      }
    ;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON{
      //$$=$1;
      $$=newNode(NODE_subprogram_declarations);
      addChild($$,$1);
      addChild($$,$2);
      //addChild($$,$1);
      
      deleteNode($3);
      printf("Reduction(subprogram_declarations -> subprogram_declarations subprogram_declaration ;)\n"); 
    }
  | {
      $$=newNode(NODE_subprogram_declarations);
      printf("Reduction(subprogram_declarations -> )\n"); 
    }
  ;

subprogram_declaration : subprogram_head declarations compound_statement{
              $$=newNode(NODE_subprogram_declaration);
              addChild($$,$1);
              addChild($$,$2);
              addChild($$,$3);
              printf("Reduction(subprogram_declaration -> subprogram_head declarations compound_statement)\n"); 
            } 
            ;

subprogram_head : FUNCTION ID arguments COLON standard_type SEMICOLON{//funcion declaration
      $$=newNode(NODE_subprogram_head);
      $2->nodeType=NODE_FUNCTION;
      addChild($$,$2);
      addChild($$,$3);
      addChild($$,$5);
      deleteNode($1);
      deleteNode($4);
      deleteNode($6);
      printf("Reduction(subprogram_head -> FUNCTION ID arguments : standard_type ;)\n");  
    }
  | PROCEDURE ID arguments SEMICOLON{//procedure declaration
      $$=newNode(NODE_subprogram_head);
      $2->nodeType=NODE_PROCEDURE;
      addChild($$,$2);
      addChild($$,$3);
      deleteNode($1);
      printf("Reduction(subprogram_head -> PROCEDURE ID arguments)\n"); 
    } 
  ;


arguments : LPAREN parameter_list RPAREN{
      $$=$2;
      deleteNode($1);
      deleteNode($3);
      printf("Reduction(arguments -> ( parameter_list ) )\n");
    }
  | {
      $$=newNode(NODE_arguments);  
      printf("Reduction(arguments ->  )\n");
    }
  ;


parameter_list : optional_var identifier_list COLON type{
      $$=newNode(NODE_parameter_list);
      addChild($$,$2);
      addChild($$,$4);
      deleteNode($3);
      printf("Reduction(parameter_list -> optional_var identifier_list : type )\n");
    }
  | optional_var identifier_list COLON type SEMICOLON parameter_list{
      $$=newNode(NODE_parameter_list);
      addChild($$,$2);
      addChild($$,$4);
      addChild($$,$6);
      deleteNode($3);
      deleteNode($5);
      printf("Reduction(parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
    } 
  ;

optional_var : VAR{
        
        printf("Reduction(optional_var -> VAR )\n");
      }
      | {
         
        printf("Reduction(optional_var ->  )\n");
      }
      ;

compound_statement : begin optional_statements END{
      $$=newNode(NODE_compound_statement);
      addChild($$,$2);
      $3->nodeType=NODE_END;
      addChild($$,$3);
      deleteNode($1);
      printf("Reduction(compound_statement -> begin optional_statements END )\n");
    }
  ;



optional_statements : statement_list{
      $$=$1;
      printf("Reduction(optional_statements -> statement_list )\n");
    } 
  ;


statement_list : statement {
      //$$=$1;
      $$=newNode(NODE_statement_list);
      addChild($$,$1);
      printf("Reduction(statements_list -> statement )\n");
    }
  | statement_list SEMICOLON statement{
      //$$=$1;
      $$=newNode(NODE_statement_list);
      addChild($$,$1);
      addChild($$,$3);
      deleteNode($2);
      printf("Reduction(statements_list -> statement_list ; statement )\n");
    }
  ;


statement : variable ASSIGNMENT expression{
      $$=$2;
      $$->nodeType=NODE_ASSIGNMENT;
      addChild($$,$1);
      addChild($$,$3);
      printf("Reduction(statement -> variable := expression )\n");  
    }
  | procedure_statement{
      $$=$1;

      printf("Reduction(statement -> procedure_statement )\n");
    }
  | compound_statement{
      $$=$1;
      printf("Reduction(statement -> compound_statement )\n");
    }
  | IF expression THEN statement ELSE statement{
      $$=newNode(NODE_if);
      addChild($$,$2);
      addChild($$,$4);
      addChild($$,$6);
      deleteNode($1);
      deleteNode($3);
      deleteNode($5);
      printf("Reduction(statement -> IF expression THEN statement ELSE statement )\n");
    }
  | WHILE expression DO statement{
      $$=newNode(NODE_while);
      addChild($$,$2);
      addChild($$,$4);
      deleteNode($1);
      deleteNode($3);
      printf("Reduction(statement -> WHILE expression DO statement )\n");
    }
  | {
      $$=newNode(NODE_statement);
      printf("Reduction(statement ->  )\n");
    }
  ;


variable : ID tail {
      $$=$1;
      $1->nodeType=NODE_SYM_REF;
      addChild($$,$2);
      printf("Reduction(variable -> ID tail )\n");
    }
  ;


tail : LBRAC expression RBRAC tail{
      $$=newNode(NODE_tail);
      //$$=$2;
      addChild($$,$2);
      addChild($$,$4);
      deleteNode($1);
      deleteNode($3);
      printf("Reduction(tail -> ( expression ) tail )\n");
    }
  |{
      $$=newNode(NODE_tail);  
      printf("Reduction(tail -> )\n");  
    } 
  ;


procedure_statement : ID{
      $$=newNode(NODE_procedure_statement);
      $1->nodeType=NODE_ID;
      addChild($$,$1);
      printf("procedureid:%s\n",$1->string);
      printf("Reduction(procedure_statement -> ID )\n");
    }
  | ID LPAREN expression_list RPAREN{
      $$=newNode(NODE_procedure_statement);
      $1->nodeType=NODE_ID;
      addChild($$,$1);
      addChild($$,$3);
      deleteNode($2);
      deleteNode($4);
      printf("procedureid:%s\n",$1->string);
      printf("Reduction(procedure_statement -> ID ( expression_list ) )\n");
    }
  ;


expression_list : expression{
      $$=$1;
      printf("Reduction(expression_list -> expression )\n");
    }
  | expression_list COMMA expression{
      $$=$1;
      addChild($$,$3);
      deleteNode($2);
      printf("Reduction(expression_list -> expression_list COMMA expression )\n");
    }
  ;


expression : simple_expression{
      $$=$1;
      //$$=newNode(NODE_expression);
      //addChild($$,$1);
      printf("Reduction(expression -> simple_expression )\n");
    }
  | simple_expression relop simple_expression{
      //$$=newNode(NODE_expression);
      $$=$2;
      //addChild($$,$2);
      addChild($$,$1);
      addChild($$,$3);
      printf("Reduction(expression -> simple_expression relop simple_expression )\n");
    }
  ;


simple_expression : term{
      $$=$1;

      printf("Reduction(simple_expression -> term )\n");
    }
  | simple_expression addop term{
      $$=$2;
      addChild($$,$1);
      addChild($$,$3);
      printf("Reduction(simple_expression -> simple_expression addop term )\n");
    }
  ;


term : factor{
      $$=$1;
      printf("Reduction(term -> factor )\n");
    }
  | term mulop factor{
      $$=$2;
      addChild($$,$1);
      addChild($$,$3);
      printf("Reduction(term -> term mulop factor )\n");
    }
  ;


factor : ID tail{
      $$=$1;
      $$->nodeType=NODE_ID;
      addChild($$,$2);
      printf("Reduction(factor -> ID tail )\n");
    }
  | ID LPAREN expression_list RPAREN{
      //$$=newNode(NODE_factor);
      $$=$1;
      $$->nodeType=NODE_ID;
      //addChild($$,$1);
      addChild($$,$3);
      deleteNode($2);
      deleteNode($4);
      printf("Reduction(factor -> ID ( expression_list ) )\n");
    }
  | NUM{
      $$=$1;
      $$->nodeType=NODE_NUM;
      printf("Reduction(factor -> NUM )\n");
    }
  | String{
      $$=$1;
      $$->nodeType=NODE_String;
      printf("Reduction(factor -> String )\n");
    }
  | Char{
      $$=$1;
      $$->nodeType=NODE_Char;
      printf("Reduction(factor -> Char )\n");
    }     
  | LPAREN expression RPAREN{
      $$=$2;
      deleteNode($1);
      deleteNode($3);
      printf("Reduction(factor -> ( expression ) )\n");
    }
  | NOT factor{
      $$=newNode(NODE_factor);
      int lineno=$1->lineno;
      $1=newOpNode(OP_NOT);
      $1->lineno=lineno;

      addChild($$,$1);
      addChild($$,$2);
      printf("Reduction(factor -> ( NOT factor ) )\n");
    }
  ;


addop : PLUS {
      $$=newOpNode(OP_PLUS);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(addop -> PLUS )\n");
    }
    | MINUS{
      $$=newOpNode(OP_MINUS);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(addop -> MINUS )\n");
    }
    ;


mulop : STAR {
      $$=newOpNode(OP_MUL);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(mulop -> STAR )\n");
    }
    | SLASH{
      $$=newOpNode(OP_SLASH);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(mulop -> SLASH )\n");
    }
    ;



relop : LT {
      $$=newOpNode(OP_LT);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(relop -> LT )\n");
    }
  | GT{
      $$=newOpNode(OP_GT);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(relop -> GT )\n");
    }
  | EQUAL{
      $$=newOpNode(OP_EQUAL);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(relop -> EQUAL )\n");
    }
  | LE{
      $$=newOpNode(OP_LE);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(relop -> LE )\n");
    }
  | GE{
      $$=newOpNode(OP_GE);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(relop -> GE )\n");
    }
  | notEQUAL{
      $$=newOpNode(OP_notEQUAL);
      $$->lineno=$1->lineno;
      deleteNode($1);
      printf("Reduction(relop -> notEQUAL )\n");
    }
  ;

%%
//# include "lex.yy.c"
int yywrap()
{
    return 1;
} 

struct nodeType *ASTRoot;

struct nodeType* newOpNode(int op) {
    struct nodeType *node = newNode(NODE_OP);
    node->op = op;

    return node;
}

int main(int argc, char** argv) {
    yyparse();
    printf("********************************\n"
           "*       No syntax error!       *\n"
           "********************************\n");

    //printTree(ASTRoot, 0);

    SymbolTable.size = 0;
    SymbolTable.status=1;
    ScopeStack[0]=&SymbolTable;
    printf("Create a new Scope\n");
    printf("Create a new SymbolTable\n");
    semanticCheck(ASTRoot);
    printf("Close a scope\n");
    printf("Close a SymbolTable\n");
    char name[20];
    strcat(name,ASTRoot->string);
    strcat(name,".j");
    FILE* pfile;
    pfile=fopen(name,"w");
    Codegenstart(ASTRoot,pfile);
    fprintf(pfile,"\treturn\n");
    fprintf(pfile,".end method\n");
    fclose(pfile);
    printf("********************************\n"
           "*      No semantic error!      *\n"
           "********************************\n");

    return 0;
}

