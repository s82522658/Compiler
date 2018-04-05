#include "symtab.h"
#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
TO-DO-LIST:
    v1. undeclared variables
    2. undeclared types
    v3. undeclared functions
    4. undeclared classes
    5. Arguments' types and numbers are wrong.
    6. type errors in arithmetic expressions
    7. redeclared variables
    8. redeclared types
    9. redeclared functions
    10. redeclared classes
    11. cycles in inheritance hierarchy
    12. cycles in structure containment
*/
// arguments in funtion?
// 2-d and 3-d array?

struct SymTable SymbolTable;
struct SymTable* ScopeStack[100];
int level=0;//a level counter
//int curlevel=0;


void OpenScope(){
    printf("A new scope is opened.\n");        
    printf("A new SymbolTable is created.\n");

    struct SymTable* newTable=calloc(1,sizeof(struct SymTable));
    newTable->status=1;//open scope
    level++;
    ScopeStack[level]=newTable;
    newTable->scope=level;
}
void CloseScope(){
    printf("A scope is closed.\n");        
    printf("A SymbolTable is deleted.\n");

    struct SymTable* temp=ScopeStack[level];
    //free(temp);
    temp->status=0;//close scope
    //level--;
}

struct SymTableEntry* findSymbol(char *s) {
    struct SymTable* temp;
    for(int j=level; j>=0; j--){//search from nearest openscope to farest openscope
        if(ScopeStack[j]->status == 1){//if it is a open scope
            temp=ScopeStack[j];
            for(int i=0; i<temp->size; i++) {
                if(strcmp(s, temp->entries[i].name) == 0) {
                    return &temp->entries[i];
                }
            }
        } 
    }
    return 0;
}

struct SymTableEntry* addVariable(struct SymTableEntry entry,int line_no) {
    struct SymTableEntry* temp=findSymbol(entry.name);   
    //printf("6\n");
    if(temp != 0 && entry.scope == temp->scope ) {
        printf("line:%d Error: duplicate declaration of variable %s\n",line_no,entry.name);
        //exit(0);
    }
    printf("Enter a Symbol %s,scope:%d,type:%d,dtype:%d \n",entry.name,entry.scope,entry.type,entry.dtype);
    struct SymTable* Table=ScopeStack[entry.scope];

    int index = Table->size;
    //int index = entry.scope;
    //printf("index %d\n",index );
    entry.Seq=Table->size;
    for(int i=0;i<20;i++) entry.funtail[i]='\0';
    Table->size++;
    Table->entries[index]=entry;
    return &Table->entries[index];
}

struct nodeType* nthChild(int n, struct nodeType *node) {
    if(node->child == NULL) return NULL;
    struct nodeType *child = node->child;
    //printf("1 type:%d\n",child->nodeType );
    for(int i=1; i<n; i++) {
        child = child->rsibling;
       // printf("%d type:%d\n",i+1,child->nodeType );
    }
    return child;
}

void semanticCheck(struct nodeType *node) {
    //printf("semanticCheck\n");
    printf("test:%d\n", node->nodeType);
    switch(node->nodeType) {
        case NODE_prog:{
            struct SymTableEntry entry;
            strcpy(entry.name,"writeln");
            entry.type=TypeNull;
            entry.dtype=Procedure;
            entry.scope=0;
            entry.Pptr=NULL;
            addVariable(entry,0);

            //goto NODE_declarations
            struct nodeType *child=nthChild(1,node);
            while(child->child != NULL){
                semanticCheck(child);
                child=nthChild(1,child);
            }

            child=nthChild(2,node);
            semanticCheck(child);
            child=nthChild(3,node);
            semanticCheck(child);
            return;
            //break;
        }
        //Variables and Array appear here
        case NODE_declarations: {
            /* We only implement integer and real type here,
               you should implement array type by yourself */
            
            struct SymTableEntry entry;
            entry.par_flag=0;
            entry.Arraydim=0;
            struct nodeType *typeNode = nthChild(3, node);
            //printf("2\n");
            if(typeNode == NULL) break;//There's no child!
           
            enum StdType valueType;
            enum dataType dtype=Variable;

            if(typeNode->nodeType == NODE_TYPE_INT){
                valueType = TypeInt;
            }
            else if(typeNode->nodeType == NODE_TYPE_REAL){
                valueType = TypeReal;
            }
            else if(typeNode->nodeType == NODE_TYPE_STRING){
                valueType = TypeString;
            }
            else if(typeNode->nodeType == NODE_TYPE_CHAR){
                valueType = TypeChar;
            }
            else{
                dtype=Array;
                do{
                    int Arrayinit;
                    int Arrayend;
                    struct nodeType *type;
                    type=nthChild(1, typeNode);//get init of array
                    Arrayinit=type->iValue;
                    type=nthChild(2, typeNode);//get end of array
                    Arrayend=type->iValue;
                    //int size=Arrayend-Arrayinit+1;

                    //entry.Arraysize[entry.Arraydim]=size;
                    entry.Arraydim++;
                    type = nthChild(3, typeNode);

                    if(type->nodeType == NODE_TYPE_INT){
                        //struct nodeType *temp=nthChild(1, typeNode);//get init value of array
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeInt;
                    }
                    else if(type->nodeType == NODE_TYPE_REAL){
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeReal;
                    }
                    else if(type->nodeType == NODE_TYPE_STRING){
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeString;
                    }
                    else if(type->nodeType == NODE_TYPE_CHAR){
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeChar;
                    }
                    else{
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeArray;
                        typeNode=type;
                    }
                }while(valueType == TypeArray);

            }
            struct nodeType *idList = nthChild(2, node);
            struct nodeType *idNode = idList->child;
            
            //May be a identifier list
            do {
                //entry.name=idNode->string;
                strcpy(entry.name,idNode->string);
                entry.dtype=dtype;
                entry.type=valueType;
                entry.scope=level;
                addVariable(entry,idNode->lineno);
                //printf("4\n");
                idNode = idNode->rsibling;
            } while(idNode != idList->child);

            return;
            //break;
        }
        //Function and Procedure appear here
        case NODE_subprogram_declaration:{
            OpenScope();
            curlevel++;
            break;
        }
        case NODE_subprogram_head:{
            //Looking for Function's return type
            struct nodeType *idNode = nthChild(1, node);
            enum StdType valueType;
            if(idNode->nodeType == NODE_FUNCTION){
                struct nodeType *typeNode = nthChild(3, node);
                if(typeNode->nodeType == NODE_TYPE_INT)
                    valueType = TypeInt;
                else if(typeNode->nodeType == NODE_TYPE_REAL)
                    valueType = TypeReal;
                else if(typeNode->nodeType == NODE_TYPE_STRING)
                    valueType = TypeString;
                else if(typeNode->nodeType == NODE_TYPE_CHAR)
                    valueType = TypeChar;
                else 
                    valueType = TypeArray;
            }
            else valueType= TypeNull;//Procedure has no return type

            //Function/Procedure entry
            struct SymTableEntry entry;
            entry.Pptr=NULL;
            entry.par_flag=0;
            //store arguments info into entry
            //NODE_parameter_list
            struct nodeType *argNode = nthChild(2, node);//get argument info
            int Par_set=0;
            if(argNode->nodeType == NODE_parameter_list){//Function/Procedure has arguments
                enum StdType valuetype;
                enum dataType dtype=Variable;
                int first=1;
                entry.Pptr=(struct Parameters*)calloc(1,sizeof(struct Parameters));
                struct Parameters* Curptr=entry.Pptr;
                do{
                    if(!first){
                        Curptr->next=(struct Parameters*)calloc(1,sizeof(struct Parameters));
                        Curptr=Curptr->next;
                    }
                    
                    //NODE_parameter_list->type
                    struct nodeType *typenode = nthChild(2, argNode);
                    if(typenode->nodeType == NODE_TYPE_INT){
                        valuetype = TypeInt;
                        
                    }
                    else if(typenode->nodeType == NODE_TYPE_REAL){
                        valuetype = TypeReal;
                        
                    }
                    else if(typenode->nodeType == NODE_TYPE_STRING){
                        valuetype = TypeString;
                       
                    }
                    else if(typenode->nodeType == NODE_TYPE_CHAR){
                        valuetype = TypeChar;
                    }
                    else{
                        printf("test:%d\n",typenode->nodeType );
                        Curptr->Aptr=(struct Arrayinfo*)calloc(1,sizeof(struct Arrayinfo));
                        Curptr->Aptr->Arraydim=0;
                        dtype=Array;
                        do{
                            int Arrayinit;
                            int Arrayend;
                            struct nodeType *type;
                            type=nthChild(1, typenode);//get init of array
                            Arrayinit=type->iValue;
                            type=nthChild(2, typenode);//get end of array
                            Arrayend=type->iValue;
                            
                            Curptr->Aptr->Arraydim++;
                            type = nthChild(3, typenode);

                            if(type->nodeType == NODE_TYPE_INT){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                
                                valuetype = TypeInt;
                            }
                            else if(type->nodeType == NODE_TYPE_REAL){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeReal;
                            }
                            else if(type->nodeType == NODE_TYPE_STRING){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeString;
                            }
                            else if(type->nodeType == NODE_TYPE_CHAR){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeChar;
                            }
                            else{
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeArray;
                                typenode=type;
                            }
                        }while(valuetype == TypeArray);
                    }      
                    //printf("dtype:%d vtype:%d \n",argNode->argdtype,argNode->argvtype );
                    //Get arguments
                    struct nodeType *idList = nthChild(1, argNode);
                    struct nodeType *idnode = idList->child;
                    struct SymTableEntry argument;
                    int count=0;
                    do {
                        count++;
                        strcpy(argument.name,idnode->string);
                        argument.dtype=dtype;
                        argument.type=valuetype;
                        argument.scope=level;
                        argument.par_flag=1;
                        addVariable(argument,idnode->lineno);
                        idnode = idnode->rsibling;
                    } while(idnode != idList->child);
                    //modify entry's parameters
                    Curptr->type=valuetype;
                    Curptr->dtype=dtype;
                    Curptr->Parnum=count;
                    //printf("abcderf\n");
                    first=0;
                    //goto next NODE_parameter_list
                    argNode=nthChild(3,argNode);
                    Par_set++;
                }while(argNode->nodeType == NODE_parameter_list);
                //free(Curptr);

            }
            entry.Par_set=Par_set;
            strcpy(entry.name,idNode->string);
            strcpy(ScopeStack[level]->name,idNode->string);//store funciont name in table
            entry.type=valueType;
            entry.scope=level;
            entry.dtype=Variable;
            if(idNode->nodeType == NODE_FUNCTION) {
                addVariable(entry,idNode->lineno);//used as variable in function
                entry.dtype=Function;
                //entry.scope=level-1;
                entry.scope=0;//surmise funcion is in global scope
                addVariable(entry,idNode->lineno);//used as function in outer scope
            }    
            else if(idNode->nodeType == NODE_PROCEDURE){
                //addVariable(entry,idNode->lineno);//used as variable in function
                entry.dtype=Procedure;
                //entry.scope=level-1;
                entry.scope=0;//surmise procedure is in global scope
                addVariable(entry,idNode->lineno);//used as function in outer scope
            }    
            return;
            //break;
        }
        case NODE_END:{
            //If now is not in "MainScope" then close scope.
            //if(level >= 1) CloseScope();
            if(curlevel != 0) CloseScope();
            curlevel--;
            return;
        }
        //ID or ID(....)
        case NODE_procedure_statement:{
            struct nodeType *idNode = nthChild(1, node);
            //semanticCheck(idNode);//check calling function's id
            //struct SymTableEntry* entry=idNode->entry;
            struct SymTableEntry* entry=findSymbol(idNode->string);
            
            struct nodeType *argNode = nthChild(2, node);
            if(!strcmp(idNode->string,"writeln")){
                semanticCheck(argNode);
                return;
            }
            struct Parameters* Curptr=entry->Pptr;

            if(entry->Pptr != NULL){//Function/Procedure has arguments
                if(argNode == NULL){
                    printf("line:%d Error:Function/Procedure:%s should have arguments!\n",idNode->lineno,idNode->string);
                    exit(0);
                }
                int count=Curptr->Parnum;
                while(argNode != NULL && argNode != node->child) {
                    //check whether argument exists
                    semanticCheck(argNode);
                    if(count == 0){
                        Curptr=Curptr->next;
                        if(Curptr == NULL){
                            printf("line:%d Error:Too many Arguments\n",idNode->lineno);
                            exit(0);
                        } 
                        count=Curptr->Parnum;
                    }
                    if(argNode->nodeType == NODE_ID){//ID
                        if(Curptr->type != argNode->valueType){
                            printf("line:%d Error:Wrong argument type1! yours:%d correct:%d\n",idNode->lineno,argNode->valueType,Curptr->type);
                            exit(0);
                        }
                    }
                    else{//expression
                        if(Curptr->type != argNode->valueType){
                            printf("line:%d Error:Wrong argument type2! yours:%d correct:%d\n",idNode->lineno,argNode->valueType,Curptr->type);
                            exit(0);
                        }
                    }

                    argNode=argNode->child;
                    count--;
                }   

            }
           
            return;
        }
        case NODE_parameter_list:{
            //printf("enter parameter list\n");
            /*
            struct SymTableEntry entry;
            entry.Arraydim=0;
            struct nodeType *typeNode = nthChild(2, node);

            if(typeNode == NULL) break;//There's no child!
           
            enum StdType valueType;
            enum dataType dtype=Variable;

            if(typeNode->nodeType == NODE_TYPE_INT) valueType = TypeInt;
            else if(typeNode->nodeType == NODE_TYPE_REAL) valueType = TypeReal;
            else if(typeNode->nodeType == NODE_TYPE_STRING) valueType = TypeString; 
            else if(typeNode->nodeType == NODE_TYPE_CHAR) valueType = TypeChar;
            else{
                dtype=Array;
                do{
                    struct nodeType *type;
                    type=nthChild(2, typeNode);//get size of array
                    int size=type->iValue;

                    entry.Arraysize[entry.Arraydim]=size;
                    entry.Arraydim++;
                    type = nthChild(3, typeNode);

                    if(type->nodeType == NODE_TYPE_INT){
                        valueType = TypeInt;
                    }
                    else if(type->nodeType == NODE_TYPE_REAL){
                        valueType = TypeReal;
                    }
                    else if(type->nodeType == NODE_TYPE_STRING){
                        valueType = TypeString;
                    }
                    else if(type->nodeType == NODE_TYPE_CHAR){
                        valueType = TypeChar;
                    }
                    else{
                        valueType = TypeArray;
                        typeNode=type;
                    }
                }while(valueType == TypeArray);

            }
            struct nodeType *idList = nthChild(1, node);
            struct nodeType *idNode = idList->child;
            
            //May be an identifier list
            node->argstart=ScopeStack[level]->size;
            node->argsize=0;
            node->arglevel=level;
            node->argdtype=dtype;
            node->argvtype=valueType;
            do {
                node->argsize++;
                strcpy(entry.name,idNode->string);
                entry.dtype=dtype;
                entry.type=valueType;
                entry.scope=level;
                addVariable(entry,idNode->lineno);
                idNode = idNode->rsibling;
            } while(idNode != idList->child);

            */
            break;
        }
        /* This case is simplified, actually you should check
           the symbol is a variable or a function with no parameter */       
       
        case NODE_ID: {//Identifier appear at right hand_side
            struct SymTableEntry *entry = findSymbol(node->string);
            if(entry == 0) {
                printf("line:%d Error: undeclared variable1 %s\n",node->lineno,node->string);
                exit(0);
            }
            
            if(!strcmp(entry->name,ScopeStack[entry->scope]->name)){
                for(int i=0;i<ScopeStack[0]->size;i++){
                    if(!strcmp(ScopeStack[0]->entries[i].name,entry->name)){
                        
                        node->dtype = ScopeStack[0]->entries[i].dtype;
                        node->valueType = ScopeStack[0]->entries[i].type;
                        entry=&ScopeStack[0]->entries[i];
                        //return;
                    }
                }
            }
            //Check whether arguments are right
            //if(entry->dtype == Procedure || entry->dtype == Function){
            if(entry->dtype == Function){
                //semanticCheck(node);//check calling function's id

                struct nodeType *argNode = nthChild(1, node);
                if(!strcmp(node->string,"writeln")){
                    semanticCheck(argNode);
                    return;
                }
                
                struct Parameters* Curptr=entry->Pptr;

                if(entry->Pptr != NULL){//Function/Procedure has arguments
                    if(argNode == NULL){
                        printf("line:%d Error:Function/Procedure:%s should have arguments!\n",node->lineno,node->string);
                        exit(0);
                    }
                    int count=Curptr->Parnum;
                    struct SymTableEntry* temp;
                    //while(argNode != NULL ) {
                    for(int i=0;i<entry->Par_set;i++){
                        //check whether argument exists
                        printf("lineno:%d count:%d name:%s\n",node->lineno,count,node->string );
                        semanticCheck(argNode);
                        if(count == 0){
                            Curptr=Curptr->next;
                            if(Curptr == NULL){
                                printf("line:%d Error:Too many Arguments\n",node->lineno);
                                exit(0);
                            } 
                            count=Curptr->Parnum;
                        }
                        if(argNode->nodeType == NODE_ID){//ID
                            if(Curptr->type != argNode->valueType){
                                printf("line:%d Error:Wrong argument type1! yours:%d correct:%d\n",node->lineno,argNode->valueType,Curptr->type);
                                exit(0);
                            }
                        }
                        else{//expression
                            if(Curptr->type != argNode->valueType){
                                printf("line:%d Error:Wrong argument type2! yours:%d correct:%d\n",node->lineno,argNode->valueType,Curptr->type);
                                exit(0);
                            }
                        }

                        argNode=argNode->child;
                        count--;
                    }   

                }
            }
            //Check whether Array index is out of bound
            if(entry->dtype == Array){
                //tail node
                struct nodeType *argNode = nthChild(1, node);
                struct nodeType *tailNode = nthChild(2, argNode);
                argNode= nthChild(1,argNode);
                int count=0;
                //while(argNode->nodeType != NODE_tail){
                while(tailNode != NULL){
                    semanticCheck(argNode);
                    if(count > entry->Arraydim-1){
                        printf("line:%d Error: Array dim out of bound\n",node->lineno);
                        exit(0);
                    }
                    if(argNode->nodeType == NODE_NUM){
                        //只能檢查有num的  expression 沒辦法
                        if(!(argNode->iValue <= entry->Arraysize[count] && argNode->iValue >= entry->Arrayinit[count])){
                            printf("line:%d Error: Array index out of bound\n",node->lineno);
                            exit(0);
                        }
                    }

                    argNode = nthChild(1, tailNode);
                    tailNode = nthChild(2,tailNode);
                    count++;
                }   
            }
            
            node->entry = entry;
            node->valueType = entry->type;
            node->dtype=entry->dtype;
            
            return;
        }    
        case NODE_SYM_REF: {//Identifier appear at left hand_side
            //printf("sym_ref\n");
            struct SymTableEntry *entry = findSymbol(node->string);
            if(entry == 0) {
                printf("line:%d Error: undeclared variable2 %s\n",node->lineno, node->string);
                exit(0);
            }
            //If SYM_REF is function or procedure , error
            if(entry->dtype == Procedure || entry->dtype == Function){
                printf("line:%d Error: SYM_REF is a function or procedure!\n",node->lineno);
                exit(0);
            }
            //Check whether Array index is out of bound
            //variable->SYM_REF tail
            if(entry->dtype == Array){
                //NODE_Tail->NODE_exp NODE_tail
                struct nodeType *argNode = nthChild(1, node);
                struct nodeType *tailNode = nthChild(2, argNode);
                //NODE_exp  
                argNode=nthChild(1,argNode);
                int count=0;
                //while(argNode->nodeType != NODE_tail){
                while(tailNode != NULL){
                    printf("enter type:%d\n",argNode->nodeType);
                    semanticCheck(argNode);
                    if(count > entry->Arraydim-1){
                        printf("count:%d\n",count );
                        printf("line:%d Error: Array(%s) dim out of bound\n",node->lineno,entry->name);
                        exit(0);
                    }
                    if(argNode->nodeType == NODE_NUM){
                        //只能檢查有num的  expression 沒辦法
                        if(!(argNode->iValue <= entry->Arraysize[count] && argNode->iValue >= entry->Arrayinit[count])){
                            printf("line:%d Error: Array index out of bound\n",node->lineno);
                            exit(0);
                        }
                    }
                    argNode = nthChild(1, tailNode);
                    tailNode= nthChild(2, tailNode);
                    count++;
                }   
            }
            /*
            if(entry->dtype == Array){
                int cnt=0;
                struct nodeType* temp=node;
                while(temp->child->nodeType == NODE_NUM){//array with num(not expression)
                    if(cnt >= entry->Arraydim){
                        printf("line:%d Error: Array dim out of bound\n",node->lineno);
                        exit(0);
                    }
                    if(!(temp->child->iValue < entry->Arraysize[cnt] && temp->child->iValue >= 0)){
                        printf("line:%d Error: Array index out of bound\n",node->lineno);
                        exit(0);
                    }
                    temp=temp->child;
                    cnt++;
                }
            }*/
            node->entry = entry;
            node->valueType = entry->type;
            node->dtype=entry->dtype;

            return;
        }

        case NODE_NUM: {
            if(node->valueValid == VALUE_I_VALID) node->valueType = TypeInt;     
            else node->valueType = TypeReal;   
            printf("num:%d\n",node->iValue );     
            return;
        }
        case NODE_String: {
            node->valueType = TypeString;        
            return;
        }
        case NODE_Char: {
            node->valueType = TypeChar;        
            return;
        }

        /* Only implemented binary op here, you should implement unary op */
        case NODE_OP:
        case NODE_ASSIGNMENT: {
            
            //printf("assignment\n");
            struct nodeType *child1 = nthChild(1, node);
            struct nodeType *child2 = nthChild(2, node);
            semanticCheck(child1);
            semanticCheck(child2);
            //printf("child1's type:%d child2's type:%d\n",child1->valueType,child2->valueType );
            //printf("child1's nodetype:%d child2's nodetype:%d\n",child1->nodeType,child2->nodeType );
            if(child2->dtype == Procedure){
                printf("line:%d Error: Procedure has no return type!\n",node->lineno);
                exit(0);
            }
            /* We only implement the checking for integer and real types
               you should implement the checking for array type by yourself */
            if(child1->valueType != child2->valueType) {
                if(node->nodeType == NODE_OP)
                    printf("line:%d Error: type mismatch for operator\n",node->lineno);
                else
                    printf("line:%d Error: type mismatch for assignment 1:%d 2:%d\n",node->lineno,child1->valueType,child2->valueType);
                printf("1:%s 2:%s type:%d\n",child1->string,child2->string,child2->nodeType );
                exit(0);
            }
            //check array here

            node->valueType = child1->valueType;
            //break;
            return;
        }
        default:{
            //printf("unknown node:%d\n",node->nodeType );
        }
    }

    /* Default action for other nodes not listed in the switch-case */
    struct nodeType *child = node->child;
    if(child != 0) {
        do {
            semanticCheck(child);
            child = child->rsibling;
        } while(child != node->child);
    }
}

