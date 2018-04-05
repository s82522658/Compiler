%{
/***************
*input type:String,Char,NUM
*number:int,float,scientific
****************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "node.h"
#include "node.c"

int yydebug=1;
int yylex();
struct nodeType *ASTROOT;

void yyerror (char const *s){
    extern char *yytext;
    extern int line_no;
    fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);
 }
/* 
 * this section is "c" code
 * my version
 * grammar.y
 *
 * Pascal grammar in Yacc format, based originally on BNF given
 * in "Standard Pascal -- User Reference Manual", by Doug Cooper.
 * This in turn is the BNF given by the ANSI and ISO Pascal standards,
 * and so, is PUBLIC DOMAIN. The grammar is for ISO Level 0 Pascal.
 * The grammar has been massaged somewhat to make it LALR, and added
 * the following extensions.
 *
 * constant expressions
 * otherwise statement in a case
 * productions to correctly match else's with if's
 * beginnings of a separate compilation facility
 */

%}

%union 
{
    struct nodeType * node;
    char* number;
    char* string;
}

%token <node> PROGRAM ELSE WHILE DO THEN IF OF FUNCTION PROCEDURE begin
%token <node> END ARRAY VAR NOT STRING ASSIGNMENT COLON COMMA INTEGER 
%token <node> DOT DOTDOT EQUAL notEQUAL GE GT LBRAC LE LPAREN LT 
%token <node> MINUS PLUS RBRAC REAL RPAREN SEMICOLON SLASH STAR CHAR  
%token <number> NUM
%token <string> String Char ID

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
	    	struct nodeType* id;
	    	id = newNode(NODE_ID);
            id->string = $2;
	    	$$=newNode(NODE_prog);
	    	addChild($$,newNode(NODE_PROGRAM));
	    	addChild($$,id);
	    	addChild($$,$4);
	    	addChild($$,$7);
	    	addChild($$,$8);
	    	addChild($$,$9);
	    	ASTROOT = $$;
	    	printf("Reduction(prog -> PROGRAM ID ( identifier_list ) ; declartions subprogram_declartions");
	    	printf("compound_statement.)\n");	
	    }
	 ;

identifier_list : ID{
			$$=newNode(NODE_identifier_list);
			struct nodeType* id;
	    	id = newNode(NODE_ID);
            id->string = $1;
			addChild($$,id);
			printf("Reduction(identifier_list -> ID)\n");
		}
	| identifier_list COMMA ID{
			$$=newNode(NODE_identifier_list);
			addChild($$,$1);
			addChild($$,newNode(NODE_COMMA));
			struct nodeType* id;
	    	id = newNode(NODE_ID);
            id->string = $3;
			addChild($$,id);
			printf("Reduction(identifier_list -> identifier_list , ID)\n");
		}
	;

declarations : declarations VAR identifier_list COLON type SEMICOLON{
			$$=newNode(NODE_declarations);
			addChild($$,$1);
			addChild($$,newNode(NODE_VAR));
			addChild($$,$3);
			addChild($$,newNode(NODE_COLON));
			addChild($$,$5);
			printf("Reduction(declartions -> declarations VAR identifier_list : type ;)\n");
		}
	| {
			$$=newNode(NODE_declarations);
			printf("Reduction(declartions -> )\n");
		}
	;

type : standard_type{
			$$=newNode(NODE_type);
			addChild($$,$1);
			printf("Reduction(type -> standard_type)\n");
		}
	| ARRAY LBRAC NUM DOTDOT NUM RBRAC OF type{
			struct nodeType* num;
			struct nodeType* num2;
	    	num = newNode(NODE_NUM);
	    	num2 = newNode(NODE_NUM);
			$$=newNode(NODE_type);
			addChild($$,newNode(NODE_ARRAY));
            num->rValue = $3;
            addChild($$,num);
			addChild($$,newNode(NODE_DOTDOT));
			num2->rValue = $5;
			addChild($$,num2);
			addChild($$,newNode(NODE_OF));
			addChild($$,$8);
			printf("Reduction(type -> ARRAY ( NUM .. NUM ) OF type)\n");
		}
	;


standard_type : INTEGER{
			$$=newNode(NODE_standard_type);
			addChild($$,newNode(NODE_INTEGER));
			printf("Reduction(standard_type -> INTEGER)\n");
		}
	| REAL{
			$$=newNode(NODE_standard_type);
			addChild($$,newNode(NODE_REAL));
			printf("Reduction(standard_type -> REAL)\n");
		}
    | STRING{
    		$$=newNode(NODE_standard_type);
			addChild($$,newNode(NODE_STRING));
			printf("Reduction(standard_type -> STRING)\n");
    	}
    | CHAR{
    		$$=newNode(NODE_standard_type);
			addChild($$,newNode(NODE_CHAR));
			printf("Reduction(standard_type -> CHAR)\n");
    	}
    ;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON{
			$$=newNode(NODE_subprogram_declarations);
			addChild($$,$1);
			addChild($$,$2);
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

subprogram_head : FUNCTION ID arguments COLON standard_type SEMICOLON{
			$$=newNode(NODE_subprogram_head);
			addChild($$,newNode(NODE_FUNCTION));
			struct nodeType* id;
	    	id = newNode(NODE_ID);
            id->string = $2;
            addChild($$,id);
			addChild($$,$3);
			addChild($$,newNode(NODE_COLON));
			addChild($$,$5);
			printf("Reduction(subprogram_head -> FUNCTION ID arguments : standard_type ;)\n");	
		}
	| PROCEDURE ID arguments{
			$$=newNode(NODE_subprogram_head);
			addChild($$,newNode(NODE_PROCEDURE));
			struct nodeType* id;
	    	id = newNode(NODE_ID);
            id->string = $2;
            addChild($$,id);
			addChild($$,$3);
			printf("Reduction(subprogram_head -> PROCEDURE ID arguments)\n");	
		} 
	;


arguments : LPAREN parameter_list RPAREN{
			$$=newNode(NODE_arguments);
			addChild($$,$2);
			printf("Reduction(arguments -> ( parameter_list ) )\n");
		}
	| {
		$$=newNode(NODE_arguments);
		printf("Reduction(arguments ->  )\n");
		}
	;


parameter_list : optional_var identifier_list COLON type{
			$$=newNode(NODE_parameter_list);
			addChild($$,$1);
			addChild($$,$2);
			addChild($$,newNode(NODE_COLON));
			addChild($$,$4);
			printf("Reduction(parameter_list -> optional_var identifier_list : type )\n");
		}
	| optional_var identifier_list COLON type SEMICOLON parameter_list{
			$$=newNode(NODE_parameter_list);
			addChild($$,$1);
			addChild($$,$2);
			addChild($$,newNode(NODE_COLON));
			addChild($$,$4);
			addChild($$,newNode(NODE_SEMICOLON));
			addChild($$,$6);
			printf("Reduction(parameter_list -> optional_var identifier_list : type ; parameter_list )\n");
		} 
	;

optional_var : VAR{
				$$=newNode(NODE_optional_var);
				addChild($$,newNode(NODE_VAR));
				printf("Reduction(optional_var -> VAR )\n");
			}
        | {
        	$$=newNode(NODE_optional_var);
        	printf("Reduction(optional_var ->  )\n");
        }
        ;

compound_statement : begin optional_statements END{
			$$=newNode(NODE_compound_statement);
			addChild($$,newNode(NODE_begin));
			addChild($$,$2);
			addChild($$,newNode(NODE_END));
			printf("Reduction(compound_statement -> begin optional_statements END )\n");
		}
	;



optional_statements : statement_list{
			$$=newNode(NODE_optional_statements);
			addChild($$,$1);
			printf("Reduction(optional_statements -> statement_list )\n");
		} 
	;


statement_list : statement {
			$$=newNode(NODE_statement_list);
			addChild($$,$1);
			printf("Reduction(statements_list -> statement )\n");
		}
	| statement_list SEMICOLON statement{
			$$=newNode(NODE_statement_list);
			addChild($$,$1);
			addChild($$,newNode(NODE_SEMICOLON));
			addChild($$,$3);
			printf("Reduction(statements_list -> statement_list ; statement )\n");
		}
	;


statement : variable ASSIGNMENT expression{
			$$=newNode(NODE_statement);
			addChild($$,$1);
			addChild($$,newNode(NODE_ASSIGNMENT));
			addChild($$,$3);
			printf("Reduction(statement -> variable := expression )\n");	
		}
	| procedure_statement{
			$$=newNode(NODE_statement);
			addChild($$,$1);
			printf("Reduction(statement -> procedure_statement )\n");
		}
	| compound_statement{
			$$=newNode(NODE_statement);
			addChild($$,$1);
			printf("Reduction(statement -> compound_statement )\n");
		}
	| IF expression THEN statement ELSE statement{
			$$=newNode(NODE_statement);
			addChild($$,newNode(NODE_IF));
			addChild($$,$2);
			addChild($$,newNode(NODE_THEN));
			addChild($$,$4);
			addChild($$,newNode(NODE_ELSE));
			addChild($$,$6);
			printf("Reduction(statement -> IF expression THEN statement ELSE statement )\n");
		}
	| WHILE expression DO statement{
			$$=newNode(NODE_statement);
			addChild($$,newNode(NODE_WHILE));
			addChild($$,$2);
			addChild($$,newNode(NODE_DO));
			addChild($$,$4);
			printf("Reduction(statement -> WHILE expression DO statement )\n");
		}
	| {
			$$=newNode(NODE_statement);
			printf("Reduction(statement ->  )\n");
		}
	;


variable : ID tail {
			$$=newNode(NODE_variable);
			struct nodeType* id;
	    	id = newNode(NODE_ID);
	    	id->string=$1;
			addChild($$,id);
			addChild($$,$2);
			printf("Reduction(variable -> ID tail )\n");
		}
	;


tail : LBRAC expression RBRAC tail{
			$$=newNode(NODE_tail);
			addChild($$,$2);
			addChild($$,$4);
			printf("Reduction(tail -> ( expression ) tail )\n");
		}
	|{
			$$=newNode(NODE_tail);	
			printf("Reduction(tail -> )\n");	
		} 
	;


procedure_statement : ID{
			$$=newNode(NODE_procedure_statement);
			struct nodeType* id;
	    	id = newNode(NODE_ID);
	    	id->string=$1;
			addChild($$,id);
			printf("Reduction(procedure_statement -> ID )\n");
		}
	| ID LPAREN expression_list RPAREN{
			$$=newNode(NODE_procedure_statement);
			struct nodeType* id;
	    	id = newNode(NODE_ID);
	    	id->string=$1;
			addChild($$,id);
			addChild($$,$3);
			printf("Reduction(procedure_statement -> ID ( expression_list ) )\n");
		}
	;


expression_list : expression{
			$$=newNode(NODE_expression_list);
			addChild($$,$1);
			printf("Reduction(expression_list -> expression )\n");
		}
	| expression_list COMMA expression{
			$$=newNode(NODE_expression_list);
			addChild($$,$1);
			addChild($$,newNode(NODE_COMMA));
			addChild($$,$3);
			printf("Reduction(expression_list -> expression_list COMMA expression )\n");
		}
	;


expression : simple_expression{
			$$=newNode(NODE_expression);
			addChild($$,$1);
			printf("Reduction(expression -> simple_expression )\n");
		}
	| simple_expression relop simple_expression{
			$$=newNode(NODE_expression_list);
			addChild($$,$1);
			addChild($$,$2);
			addChild($$,$3);
			printf("Reduction(expression -> simple_expression relop simple_expression )\n");
		}
	;


simple_expression : term{
			$$=newNode(NODE_simple_expression);
			addChild($$,$1);
			printf("Reduction(simple_expression -> term )\n");
		}
	| simple_expression addop term{
			$$=newNode(NODE_simple_expression);
			addChild($$,$1);
			addChild($$,$2);
			addChild($$,$3);
			printf("Reduction(simple_expression -> simple_expression addop term )\n");
		}
	;


term : factor{
			$$=newNode(NODE_term);
			addChild($$,$1);
			printf("Reduction(term -> factor )\n");
		}
	| term mulop factor{
			$$=newNode(NODE_term);
			addChild($$,$1);
			addChild($$,$2);
			addChild($$,$3);
			printf("Reduction(term -> term mulop factor )\n");
		}
	;


factor : ID tail{
			$$=newNode(NODE_factor);
			struct nodeType* id;
	    	id = newNode(NODE_ID);
	    	id->string=$1;
			addChild($$,id);
			addChild($$,$2);
			printf("Reduction(factor -> ID tail )\n");
		}
	| ID LPAREN expression_list RPAREN{
			$$=newNode(NODE_factor);
			struct nodeType* id;
	    	id = newNode(NODE_ID);
	    	id->string=$1;
			addChild($$,id);
			addChild($$,$3);
			printf("Reduction(factor -> ID ( expression_list ) )\n");
		}
	| NUM{
			$$=newNode(NODE_factor);
			struct nodeType* num;
	    	num = newNode(NODE_NUM);
	    	num->rValue=$1;
	    	addChild($$,num);
			printf("Reduction(factor -> NUM )\n");
		}
	| String{
			$$=newNode(NODE_factor);
			struct nodeType* str;
	    	str = newNode(NODE_String);
	    	str->string=$1;
	    	addChild($$,str);
			printf("Reduction(factor -> String )\n");
		}
	| Char{
			$$=newNode(NODE_factor);
			struct nodeType* str;
	    	str = newNode(NODE_Char);
	    	str->string=$1;
	    	addChild($$,str);
			printf("Reduction(factor -> Char )\n");
		}			
	| LPAREN expression RPAREN{
			$$=newNode(NODE_factor);
			addChild($$,$2);
			printf("Reduction(factor -> ( expression ) )\n");
		}
	| NOT factor{
			$$=newNode(NODE_factor);
			addChild($$,newNode(NODE_NOT));
			addChild($$,$2);
			printf("Reduction(factor -> ( NOT factor ) )\n");
		}
	;


addop : PLUS {
			$$=newNode(NODE_addop);
			addChild($$,newNode(OP_PLUS));
			printf("Reduction(addop -> PLUS )\n");
		}
	  | MINUS{
			$$=newNode(NODE_addop);
			addChild($$,newNode(OP_MINUS));
			printf("Reduction(addop -> MINUS )\n");
		}
	  ;


mulop : STAR {
			$$=newNode(NODE_mulop);
			addChild($$,newNode(OP_STAR));
			printf("Reduction(mulop -> STAR )\n");
		}
	  | SLASH{
			$$=newNode(NODE_mulop);
			addChild($$,newNode(OP_SLASH));
			printf("Reduction(mulop -> SLASH )\n");
		}
	  ;



relop : LT {
			$$=newNode(NODE_relop);
			addChild($$,newNode(NODE_LT));
			printf("Reduction(relop -> LT )\n");
		}
	| GT{
			$$=newNode(NODE_relop);
			addChild($$,newNode(NODE_GT));
			printf("Reduction(relop -> GT )\n");
		}
	| EQUAL{
			$$=newNode(NODE_relop);
			addChild($$,newNode(NODE_EQUAL));
			printf("Reduction(relop -> EQUAL )\n");
		}
	| LE{
			$$=newNode(NODE_relop);
			addChild($$,newNode(NODE_LE));
			printf("Reduction(relop -> LE )\n");
		}
	| GE{
			$$=newNode(NODE_relop);
			addChild($$,newNode(NODE_GE));
			printf("Reduction(relop -> GE )\n");
		}
	| notEQUAL{
			$$=newNode(NODE_relop);
			addChild($$,newNode(NODE_notEQUAL));
			printf("Reduction(relop -> notEQUAL )\n");
		}
	;

%%
/*
 * this forces you to check all this to be sure that only write and
 * writeln use the 2nd and 3rd forms, you really can't do it easily in
 * the grammar, especially since write and writeln aren't reserved
 */
 # include "lex.yy.c"
int yywrap()
{
    return 1;
} 
int main(int argc, char** argv) { 
    /*fprintf(stderr, "open file.\n");
    if(argc>1 && freopen(argv[1],"r",stdin)==NULL){
        exit(1);
    }*/
    
    fprintf(stderr, "call yyparse\n");
    yyparse();
    printf("-----------------------------------------------\n");
    printTree(ASTROOT, 0);
 
    return 0;
}


