#ifndef __NODE_H__
#define __NODE_H__

struct nodeType;
enum ntype {
    VALUE_INVALID,NODE_PROGRAM,NODE_IF,NODE_ELSE,NODE_WHILE,
    NODE_DO,NODE_THEN,NODE_OF,NODE_FUNCTION,NODE_PROCEDURE,
    NODE_begin,NODE_END,NODE_ARRAY,NODE_VAR,NODE_NOT,
    NODE_STRING,NODE_ASSIGNMENT,NODE_COLON,NODE_COMMA,NODE_INTEGER,
    NODE_DOT,NODE_DOTDOT,NODE_EQUAL,NODE_notEQUAL,NODE_GE,
    NODE_GT,NODE_LBRAC,NODE_LE,NODE_LPAREN,NODE_LT,
    NODE_RBRAC,NODE_REAL,NODE_RPAREN,NODE_SEMICOLON,NODE_CHAR,
    NODE_NUM,NODE_String,NODE_Char,NODE_ID,OP_MINUS,
    OP_PLUS,OP_STAR,OP_SLASH,NODE_prog,NODE_identifier_list,
    NODE_declarations,NODE_type,NODE_standard_type,NODE_subprogram_declaration,NODE_subprogram_declarations,
    NODE_subprogram_head,NODE_arguments,NODE_parameter_list,NODE_optional_var,NODE_compound_statement,
    NODE_optional_statements,NODE_statement_list,NODE_variable,NODE_tail,NODE_procedure_statement,
    NODE_expression_list,NODE_expression,NODE_simple_expression,NODE_term,NODE_factor,
    NODE_addop,NODE_mulop,NODE_relop,NODE_statement
};

// #include "symtab.h"
struct nodeType {
    int nodeType;
    struct nodeType *parent;
    struct nodeType *child;
    struct nodeType *lsibling;
    struct nodeType *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    /* items for Array */
    int idxstart;
    int idxend;
    int arraydepth;
    struct nodeType *ref;

    /* Values for general use */
    int iValue;
    char* rValue;//for float,int,scientific sign
    char valueValid;
    char *string;
    
    /* Indicates which OP */
    char op;

};

struct nodeType* newNode(int type);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);

#endif

