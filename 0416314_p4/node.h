#ifndef __NODE_H__
#define __NODE_H__

struct nodeType;
enum ntype {
    VALUE_INVALID
    ,VALUE_I_VALID
    ,VALUE_R_VALID
    ,NODE_prog
    ,NODE_declarations
    ,NODE_NUM
    ,NODE_String
    ,NODE_Char
    ,NODE_TYPE_ARRAY
    ,NODE_TYPE_INT
    ,NODE_TYPE_REAL
    ,NODE_TYPE_STRING
    ,NODE_TYPE_CHAR
    ,NODE_subprogram_declarations
    ,NODE_subprogram_declaration
    ,NODE_subprogram_head
    ,NODE_ASSIGNMENT
    ,NODE_SYM_REF
    ,NODE_statement
    ,NODE_variable
    ,NODE_tail
    ,NODE_procedure_statement
    ,NODE_expression
    ,NODE_factor
    ,NODE_OP
    ,NODE_TOKEN
    ,NODE_parameter_list
    ,NODE_identifier_list
    ,NODE_ID
    ,NODE_FUNCTION
    ,NODE_PROCEDURE
    ,NODE_END
    ,NODE_arguments
    ,NODE_if
    ,NODE_while
    ,NODE_compound_statement
    ,NODE_statement_list
    
};
/*
#define VALUE_INVALID   0
#define VALUE_I_VALID   1
#define VALUE_R_VALID   2

#define NODE_TOKEN          1
#define NODE_OP             2
#define NODE_INT            3
#define NODE_REAL           4
#define NODE_PROGRAM        5
#define NODE_VAR_DECL       6
#define NODE_TYPE_INT       7
#define NODE_TYPE_REAL      8
#define NODE_ASSIGN_STMT    9
#define NODE_SYM_REF        10*/

//#define NODE_LIST           50

//#define NODE_VAR_OR_PROC    99
#define NODE_ERROR          100
#define NODE_EMPTY          101

#define OP_PLUS  1
#define OP_MINUS  2
#define OP_MUL  3
#define OP_SLASH  4
#define OP_GT   5
#define OP_LT   6
#define OP_EQUAL   7
#define OP_GE   8
#define OP_LE   9
#define OP_notEQUAL   10
#define OP_NOT  11

#include "symtab.h"
struct nodeType {
    int nodeType;
    struct nodeType *parent;
    struct nodeType *child;
    struct nodeType *lsibling;
    struct nodeType *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    int iValue;
    double rValue;
    char valueValid;

    char *string;

    char op;
    int branch;

    enum StdType valueType;
    enum dataType dtype;
    struct SymTableEntry *entry;

    int argstart;
    int argsize;
    int arglevel;
    int argdtype;
    int argvtype;

    int lineno;
};

struct nodeType* newNode(int type);
void deleteNode(struct nodeType* node);
void addChild(struct nodeType *node, struct nodeType *child);
void printTree(struct nodeType *node, int ident);

#endif

