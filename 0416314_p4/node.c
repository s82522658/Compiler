#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"

struct nodeType* newNode(int type) {
    struct nodeType *node = (struct nodeType*)malloc(sizeof(struct nodeType));
    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;
    node->child = NULL;
    node->lsibling = node;
    node->rsibling = node;

    return node;
}

void addChild(struct nodeType *node, struct nodeType *child) {
    child->parent = node;

    if(node->child == NULL) {
        node->child = child;
    }
    else {
        child->lsibling = node->child->lsibling;
        child->rsibling = node->child;
        node->child->lsibling->rsibling = child;
        node->child->lsibling = child;
    }
}

void deleteNode(struct nodeType *node) {
    if(node->string != NULL)
        free(node->string);
    free(node);
}

void printTree(struct nodeType *node, int ident) {
    static char blank[1024];
    for(int i=0; i<ident; i++)
        blank[i] = ' ';
    blank[ident] = 0;

    switch(node->nodeType) {
        case NODE_NUM:
            if(node->valueValid==VALUE_I_VALID) printf("%siNUM:%d\n", blank, node->iValue);
            else printf("%srNUM:%f\n", blank, node->rValue);
            break;
        case NODE_String:
            printf("%s%s\n", blank, node->string);
            break;
        case NODE_Char:
            printf("%s%s\n", blank, node->string);
            break;

        case NODE_ID://ID
            printf("%sID:%s\n", blank, node->string);
            break;
        case NODE_FUNCTION://function's id
            printf("%sfunction:%s\n", blank, node->string);
            break;
        case NODE_PROCEDURE://procedure's id
            printf("%sprocedure:%s\n", blank, node->string);
            break;         
        case NODE_SYM_REF:
            printf("%sSYM_REF %s\n", blank, node->string);
            break;    
        case NODE_OP:
            switch(node->op) {
                case OP_PLUS:
                    printf("%s+\n", blank);
                    break;
                case OP_MINUS:
                    printf("%s-\n", blank);
                    break;
                case OP_MUL:
                    printf("%s*\n", blank);
                    break;
                case OP_SLASH:
                    printf("%s/\n", blank);
                    break;
                case OP_GT:
                    printf("%s>\n", blank);
                    break;
                case OP_LT:
                    printf("%s<\n", blank);
                    break;
                case OP_EQUAL:
                    printf("%s=\n", blank);
                    break;
                case OP_GE:
                    printf("%s>=\n", blank);
                    break;
                case OP_LE:
                    printf("%s<=\n", blank);
                    break;
                case OP_notEQUAL:
                    printf("%s!=\n", blank);
                    break;
                case OP_NOT:
                    printf("%s!\n", blank);
                    break;    
            }
            ident++;
            break;          
        case NODE_prog:
            printf("%sPROGRAM\n", blank);
            ident++;
            break;
        case NODE_declarations:
            printf("%sDECL\n", blank);
            ident++;
            break;
        case NODE_TYPE_INT:
            printf("%sTYPE_INT\n", blank);
            break;
        case NODE_TYPE_REAL:
            printf("%sTYPE_REAL\n", blank);
            break;
        case NODE_TYPE_STRING:
            printf("%sTYPE_STRING\n", blank);
            break;
        case NODE_TYPE_CHAR:
            printf("%sTYPE_CHAR\n", blank);
            break;
        case NODE_TYPE_ARRAY:
            printf("%sTYPE_ARRAY\n", blank);
            break;          
        case NODE_ASSIGNMENT:
            printf("%sASSIGNMENT\n", blank);
            ident++;
            break;
        case NODE_subprogram_declarations:
            break;
        case NODE_subprogram_declaration:
            break;
        case NODE_subprogram_head:
            break;  
        case NODE_statement:
            break;
        case NODE_variable:
            break;
        case NODE_tail:
            break;
        case NODE_procedure_statement:
            break;  
        case NODE_expression:
            break;
        case NODE_factor:
            break;  
        case NODE_parameter_list:
            break;
        case NODE_identifier_list:
            //printf("NODE_identifier_list\n");
            break;   
        case NODE_END:
            break;    
        case NODE_arguments:
            break;     
        default:
            printf("default:%s%d\n", blank, node->nodeType);
            break;        
                            
    }

    struct nodeType *child = node->child;
    if(child != NULL) {
        do {
            printTree(child, ident);
            child = child->rsibling;
        } while(child != node->child);
    }
}

