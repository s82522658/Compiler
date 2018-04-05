#ifndef __SYMTAB_H___
#define __SYMTAB_H___

enum StdType { TypeReal, TypeInt, TypeString, TypeChar, TypeArray, TypeNull};
enum dataType { Variable, Function, Procedure, Array};

struct SymTableEntry {
    char name[100];//ID
    enum StdType type;//int,float,string,char...
    enum dataType dtype;//var,function,procedure,array...
    int scope;
    //sequence in local area
    int Seq;
    //for Arrayinfo
   	int Arraysize[10];
    int Arrayinit[10];
   	int Arraydim;
    //for function's argument
    struct Parameters* Pptr;
    //Num of sets of parameters
    int Par_set;
    //for function's tail
    char funtail[20];//I or F or [[I ...
    //is/isn't a parameter?
    int par_flag;
    //...........
   	int argnum;
};
struct Arrayinfo{
    int Arraysize[10];
    int Arrayinit[10];
    int Arraydim;
};
struct Parameters{
    enum StdType type;//int,float,string,char...
    enum dataType dtype;//var,function,procedure,array...
    int Parnum;
    struct Arrayinfo* Aptr;
    struct Parameters* next;
};

struct SymTable {
    int scope;
    int size;//Num of entries
    int status;//Open or Close scope
    char name[100];//Funcion/Procedure name
    struct SymTableEntry entries[100];
};
union Array {
    int* intArray;
    float* realArray;
    char* stringArray;
};

extern struct SymTable SymbolTable;
extern struct SymTable* ScopeStack[100];
extern void CloseScope();
extern struct SymTableEntry* findSymbol(char *s);
extern struct nodeType* nthChild(int n, struct nodeType *node);

#include "node.h"
void semanticCheck(struct nodeType* node);
void OpenScope();
void CloseScope();

#endif

