#include<stdio.h>
#include<stdlib.h>
#include"symtab.h"
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
FILE* pfile;
char* pro_name;
int branch=0;
int levelcnt=0;
int curlevel=0;
void Codegen(struct nodeType *node,int scope);
//struct SymTable* ScopeStack[100];

void Codegenstart(struct nodeType *node,FILE* ptr){
	pfile=ptr;
	Codegen(node,0);
}

void Codegen(struct nodeType *node,int scope) {
    //printf("semanticCheck\n");
    printf("test:%d\n", node->nodeType);
    switch(node->nodeType) {
    	case NODE_prog:{
			pro_name=node->string;
			fprintf(pfile,".class public %s\n",node->string);
			fprintf(pfile,".super java/lang/Object\n");
			fprintf(pfile,"\n");
			struct SymTable* Table=ScopeStack[scope];
			//.field public static a I
			for(int i=0;i<Table->size;i++){
				if(Table->entries[i].dtype == Array || Table->entries[i].dtype == Variable){
					fprintf(pfile, ".field public static %s ",Table->entries[i].name );
	                for(int j=0;j<Table->entries[i].Arraydim;j++) fprintf(pfile, "[" );  
	            	if(Table->entries[i].type == TypeInt ) fprintf(pfile, "I" );
	            	else fprintf(pfile, "F" );
	            	fprintf(pfile, "\n");
				}
			}
			//goto NODE_declarations
			struct nodeType *child=nthChild(1,node);
			if(Table->size != 0){
				fprintf(pfile, ".method public static vinit()V\n");
				fprintf(pfile, "\t.limit locals 100\n");
				fprintf(pfile, "\t.limit stack 100\n");
				Codegen(child,0);
				fprintf(pfile, "\treturn\n");
	        	fprintf(pfile, ".end method\n");
			}
			//std initializer
			//fprintf(pfile, "; standard initializer\n");
			fprintf(pfile, ".method public <init>()V\n");
			fprintf(pfile, "\taload_0\n");
			fprintf(pfile, "\tinvokenonvirtual java/lang/Object/<init>()V\n");
			fprintf(pfile, "\treturn\n");
			fprintf(pfile, ".end method\n");
			//goto NODE_subprogram_declarations
			child=nthChild(2,node);
			Codegen(child,scope);
			//goto NODE_compound_statement
			fprintf(pfile, ".method public static main([Ljava/lang/String;)V\n");
			fprintf(pfile, "\t.limit locals 100\n");
			fprintf(pfile, "\t.limit stack 100\n");
			int flag=0;
			//if There is global variable
			if(Table->size != 0){
				for(int i=0;i<Table->size;i++){
					if(Table->entries[i].dtype == Variable || Table->entries[i].dtype == Array) {
						flag=1;
						break;
					}
				}
				//invokestatic foo/vinit()V
				if(flag) fprintf(pfile, "\tinvokestatic %s/vinit()V\n",pro_name);
			}
			child=nthChild(3,node);
			printf("type:%d\n",child->nodeType );
			Codegen(child,scope);

			//break;
			return;
		}	
        //Variables and Array appear here
        case NODE_declarations: {
        	struct SymTable* Table=ScopeStack[scope];
        	if(Table->size != 0){
        		for(int i=0;i<Table->size;i++){
        			if(!(Table->entries[i].dtype == Function || Table->entries[i].dtype == Procedure)&& !Table->entries[i].par_flag){
        				if(Table->entries[i].dtype != Array){
		        			if(Table->entries[i].type == TypeInt){
		        				
		        				fprintf(pfile, "\tldc 0\n");
		        				if(scope == 0) fprintf(pfile, "\tputstatic %s/%s I\n",pro_name,Table->entries[i].name );
		        				else fprintf(pfile, "\tistore %d\n",Table->entries[i].Seq);
		        			}
		        			else{
		        				
		        				fprintf(pfile, "\tldc 0.0\n");
		        				if(scope == 0) fprintf(pfile, "\tputstatic %s/%s F\n",pro_name,Table->entries[i].name );
		        				else fprintf(pfile, "\tfstore %d\n",Table->entries[i].Seq);
		        			}
		        		}
		        		else if (Table->entries[i].dtype == Array){
		        			char tail[20]={};
		        			for(int j=0;j<Table->entries[i].Arraydim;j++) fprintf(pfile,"\tbipush %d\n",Table->entries[i].Arraysize[j]-Table->entries[i].Arrayinit[j]+1);
		        			//multianewarray [I 1

		        			fprintf(pfile, "\tmultianewarray ");
		        			for(int j=0;j<Table->entries[i].Arraydim;j++){
		        				fprintf(pfile, "[");
		        				strcat(tail,"[");
		        			}
		        			if(Table->entries[i].type == TypeInt) {
		        				fprintf(pfile, "I ");
		        				strcat(tail, "I");
		        			}
		        			else {
		        				fprintf(pfile, "F ");
		        				strcat(tail, "F");
		        			}
		        			fprintf(pfile, "%d\n",Table->entries[i].Arraydim);
		        			//putstatic foo/d [I
		        			if(scope == 0 ){
		        				fprintf(pfile, "\tputstatic %s/%s %s\n",pro_name,Table->entries[i].name,tail );
			        			/*for(int j=0;j<Table->entries[i].Arraydim;j++) {
			        				fprintf(pfile, "[");
			        				strcat(tail,"[");
			        			}
			        			if(Table->entries[i].type == TypeInt) {
			        				fprintf(pfile, "I\n");
			        				strcat(tail,"I");
			        			}
			        			else {
			        				fprintf(pfile, "F\n");
			        				strcat(tail,"F");
			        			}*/
			        			
		        			}
		        			else fprintf(pfile, "\tastore %d\n",Table->entries[i].Seq);
							strcpy(Table->entries[i].funtail,tail);
		        		}
        			}	
	        	}
	        	
        	}
        	return;
            //break;
        }
        //Function and Procedure appear here
        case NODE_subprogram_declaration:{
            //OpenScope();

            levelcnt++;
            curlevel++;
            scope = levelcnt;
            ScopeStack[scope]->status=1;
            printf("levlecnt:%d\n",levelcnt );
            break;
        }
        case NODE_subprogram_head:{
        	//level++;//enter a new scope
        	//assume funtions/procedures can only be declared in global scope
            struct SymTable* Table=ScopeStack[0];
            //get funtcion name
            struct nodeType *idNode = nthChild(1, node);
            for(int i=0;i<Table->size;i++){
            	//if((Table->entries[i].dtype==Function || Table->entries[i].dtype==Procedure)&&(strcmp(Table->entries[i].name,"writeln")) ){
            		if(!strcmp(idNode->string,Table->entries[i].name)){
            		//.method public static ggyy(FF)F
					char tail[20]={};
            		fprintf(pfile, ".method public static %s(",Table->entries[i].name);
            		struct Parameters* Pptr=Table->entries[i].Pptr;
            		while(Pptr != NULL){
            			//fprintf(pfile,"loop1\n");
            			for(int j=0;j<Pptr->Parnum;j++){
            				//fprintf(pfile, "parnum:%d\n",Pptr->Parnum);
            				if(Pptr->Aptr != NULL) {
            					for(int j=0;j<Pptr->Aptr->Arraydim;j++) {
            						fprintf(pfile,"[");
            						strcat(tail,"[");
            					}
            				}
            				if(Pptr->type == TypeInt ){
            					fprintf(pfile,"I");
            					strcat(tail,"I");
            				}
            				else {
            					fprintf(pfile,"F");
            					strcat(tail,"F");
            				}
            				printf("end\n");
            			}
            			Pptr=Pptr->next;
            		}
            		fprintf(pfile, ")");
            		strcat(tail,")");
            		if(Table->entries[i].type == TypeInt) {
            			fprintf(pfile, "I\n");
            			strcat(tail,"I");
            		}
            		else if(Table->entries[i].type == TypeNull) {
            			fprintf(pfile, "V\n");
            			strcat(tail,"V");
            		}
            		else {
            			fprintf(pfile, "F\n");
            			strcat(tail,"F");
            		}
            		strcpy(Table->entries[i].funtail,tail);
            		//Table->entries[i].funtail=tail;
            		//fprintf(pfile, "funtail:%s\n",tail );
					fprintf(pfile, ".limit locals 100\n");
					fprintf(pfile, ".limit stack 100\n");
            	}	
            }
            //scope = level;
            //break;
            return;
        }
        case NODE_END:{
        	//fprintf(pfile, "END here\n");
            //Do things only for Procedure/Function
            //fload 2
			//freturn
			//.end method
			struct SymTable* Table=ScopeStack[scope];
			for(int i=0;i<ScopeStack[0]->size;i++){
				if(!strcmp(Table->name,ScopeStack[0]->entries[i].name)){
					if(!(ScopeStack[0]->entries[i].dtype == Function || ScopeStack[0]->entries[i].dtype == Procedure)) return;
					if(ScopeStack[0]->entries[i].type != TypeNull){//Procedure has no return type
						char head;
						for(int j=0;j<Table->size;j++){
							if(!strcmp(Table->name,Table->entries[j].name)){
								if(Table->entries[j].type == TypeInt) head='i';
								else head='f';
								fprintf(pfile, "\t%cload %d\n",head,Table->entries[j].Seq );
								break;
							}
						}
						fprintf(pfile, "\t%creturn\n",head);
					}
					else fprintf(pfile, "\treturn\n");
					fprintf(pfile, ".end method\n");
				}
				
			}
			if(scope != 0) ScopeStack[scope]->status=0;
			curlevel--;
            return;
        }
        //lots of statements
        case NODE_compound_statement:{
        	
        	//return;
        	break;
        }
        //Nullstmt
        case NODE_statement:{
        	
        	//return;
        	break;
        }
        //If...else... 
        case NODE_if:{
        	//NODE_expression
        	struct nodeType *expNode = nthChild(1, node);
        	Codegen(expNode,scope);
        	//ELSEstmt
        	struct nodeType *stmtNode = nthChild(2, node);
        	Codegen(stmtNode,scope);
        	fprintf(pfile, "\tgoto L%d\n",expNode->branch+1);
        	//IFstmt
        	fprintf(pfile, "L%d:\n",expNode->branch );
        	stmtNode = nthChild(3, node);
        	Codegen(stmtNode,scope);
        	fprintf(pfile, "L%d:\n",branch);
        	branch++;

        	return;
        }
        //whild..do.
        case NODE_while:{
        	int mybranch=branch;
        	fprintf(pfile, "L%d:\n",branch );
        	branch++;
        	//NODE_expression
        	struct nodeType *expNode = nthChild(1, node);
        	Codegen(expNode,scope);
        	//Dostmt
        	struct nodeType *stmtNode = nthChild(2, node);
        	Codegen(stmtNode,scope);
        	fprintf(pfile, "\tgoto L%d\n",mybranch);
        	//Notdostmt
        	fprintf(pfile, "L%d:\n",expNode->branch );

        	return;
        }
        //ID or ID(....)
        case NODE_procedure_statement:{
        	struct nodeType *idNode = nthChild(1, node);
			struct nodeType *argNode = nthChild(2, node);
        	//For writeln
        	if(!strcmp(idNode->string,"writeln")){
        		//invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
        		//getstatic foo/a I
        		fprintf(pfile, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        		if(argNode->valueType == TypeChar ||argNode->valueType == TypeString){
        			fprintf(pfile, "\tldc %s\n",argNode->string );
        		}
        		else{
        			if(argNode->valueType == TypeInt){
        				fprintf(pfile,"\tgetstatic %s/%s I\n",pro_name,argNode->string);
        				fprintf(pfile,"\tinvokestatic java/lang/String/valueOf(I)Ljava/lang/String;\n");
        			}
        			else {
        				fprintf(pfile,"\tgetstatic %s/%s F\n",pro_name,argNode->string);
        				fprintf(pfile,"\tinvokestatic java/lang/String/valueOf(F)Ljava/lang/String;\n");
        			}
        			
        		}
        		fprintf(pfile,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        		return;
        	}
        	//for normal function 
			//recursive search for arguments
			while(argNode != NULL  && argNode != node->child) {
				Codegen(argNode,scope);
			 	argNode=argNode->child;
			}
			char tail[20]={};
			for(int i=0;i<ScopeStack[0]->size;i++){
			 	if(!strcmp(idNode->string,ScopeStack[0]->entries[i].name)){
			 		//tail=ScopeStack[0]->entries[i].funtail;
			 		strcpy(tail,ScopeStack[0]->entries[i].funtail);
			 	}
			}
			//fprintf(pfile, "IN procedures\n" );
            fprintf(pfile, "\tinvokestatic %s/%s(%s\n",pro_name,idNode->string,tail);
            return;
        }

        case NODE_parameter_list:{
            
            break;
        }
        case NODE_ID: {//Identifier appear at right hand_side        	
            struct SymTableEntry *entry = findSymbol(node->string);
            //haven't consider array
            
            //If ID is a Function
            if(entry->dtype == Function || entry->dtype == Procedure ){
            	//invokestatic foo/addition(II)I
				struct nodeType *argNode = nthChild(1, node);
            	//while(argNode != NULL) {
            	for(int i=0;i<entry->Par_set;i++){
            		if(argNode->dtype == Function){
            			//printf("loop1\n");
            			int set;
            			for(int j=0;j<ScopeStack[0]->size;i++){
            				if(!strcmp(argNode->string,ScopeStack[0]->entries[j].name)){
            					set=ScopeStack[0]->entries[j].Par_set;
            				}
            			}
            			//not finished
            			Codegen(argNode,scope);
            			i+=set;
            			for(int j=set;j>=0;j--) {
            				argNode=argNode->child;
            				//printf("loop2\n");
            			}
            		}
	            	
					Codegen(argNode,scope);
				 	argNode=argNode->child;
				}
				char tail[20]={};
				strcpy(tail,entry->funtail);

				/*for(int i=0;i<ScopeStack[0]->size;i++){
				 	if(!strcmp(idNode->string,ScopeStack[0]->entries[i].name)){
				 		tail=ScopeStack[0]->entries[i].funtail;
				 	}
				}*/
				//fprintf(pfile, "IN iD\n" );
	            fprintf(pfile, "\tinvokestatic %s/%s(%s\n",pro_name,entry->name,tail);
	            return;
            }
            if(entry->dtype != Array){
            	if(entry->scope !=0){
            		//If it is a recursive function
            		if(!strcmp(entry->name,ScopeStack[entry->scope]->name)){
            			char tail[20]={};
            			for(int i=0;i<ScopeStack[0]->size;i++){
            				if(!strcmp(ScopeStack[0]->entries[i].name,entry->name)){
            					entry = &ScopeStack[0]->entries[i];
            					//entry->type = ScopeStack[0]->entries[i].type;
		                        //entry->dtype = ScopeStack[0]->entries[i].dtype;
		                        //entry->Pptr = ScopeStack[0]->entries[i].Pptr;
		                        node->dtype = ScopeStack[0]->entries[i].dtype;
		                        node->valueType = ScopeStack[0]->entries[i].type;
		                        //fprintf(pfile, "Valuetype:%d\n",node->valueType );
		                        strcpy(tail,ScopeStack[0]->entries[i].funtail);
            				}
            			}
            			struct nodeType *argNode = nthChild(1, node);
		            	//while(argNode != NULL) {
		            	for(int i=0;i<entry->Par_set;i++){
		            		if(argNode->dtype == Function){
		            			//fprintf(pfile, "is Function\n");
		            			int set;
		            			for(int j=0;j<ScopeStack[0]->size;i++){
		            				if(!strcmp(argNode->string,ScopeStack[0]->entries[j].name)){
		            					set=ScopeStack[0]->entries[j].Par_set;
		            				}
		            			}
		            			//not finished
		            			Codegen(argNode,scope);
		            			i+=set;
		            			for(int j=set;j>=0;j--) argNode=argNode->child;
		            		}
							Codegen(argNode,scope);
						 	argNode=argNode->child;
						}
						
						//strcpy(tail,entry->funtail);

			            fprintf(pfile, "\tinvokestatic %s/%s(%s\n",pro_name,entry->name,tail);
			            return;
            		}
					if(entry->type == TypeInt) fprintf(pfile, "\tiload %d\n",entry->Seq);
					else fprintf(pfile, "\tfload %d\n",entry->Seq);
				}
				else{
					if(entry->type == TypeInt) fprintf(pfile, "\tgetstatic %s/%s I\n",pro_name,entry->name );
					else fprintf(pfile, "\tgetstatic %s/%s F\n",pro_name,entry->name );
				}
            }
            //else if ID is an Array
           	if(entry->dtype == Array){
            	if(entry->scope !=0){
					//if(entry->type == TypeInt) fprintf(pfile, "\tiload %d\n",entry->Seq);
					//else fprintf(pfile, "\tfload %d\n",entry->Seq);
					fprintf(pfile, "\taload %d\n",entry->Seq);
				}
				else fprintf(pfile, "\tgetstatic %s/%s %s\n",pro_name,entry->name,entry->funtail );
           		struct nodeType *argNode = nthChild(1, node);
           		
           		struct nodeType *tailNode = nthChild(2, argNode);
           		argNode = nthChild(1,argNode);
            	int count=0;
				//while(argNode->nodeType != NODE_tail){
				while(tailNode != NULL){
					//for(int i=0;i<entry->Arraydim;i++){
					Codegen(argNode,scope);
					fprintf(pfile,"\tldc %d\n",entry->Arrayinit[count]);
					fprintf(pfile, "\tisub\n");
					if(count != entry->Arraydim-1) fprintf(pfile, "\taaload\n");
					//}
					argNode = nthChild(1, tailNode);
					tailNode = nthChild(2,tailNode);
					count++;
				}	
           		if(entry->type == TypeInt) fprintf(pfile, "\tiaload\n");
           		else fprintf(pfile, "\tfaload\n");
            }   
                 
            		
            return;
        }    
        case NODE_SYM_REF:{
			//haven't consider array
			struct SymTableEntry *entry = findSymbol(node->string);

			if(entry->dtype == Array){
				if(entry->type == TypeInt) fprintf(pfile, "\tiastore\n");
				else fprintf(pfile, "\tfastore\n");
				return;
			}
			if(entry->scope !=0){
				if(entry->type == TypeInt) fprintf(pfile, "\tistore %d\n",entry->Seq);
				else fprintf(pfile, "\tfstore %d\n",entry->Seq);
			}
			else{
				fprintf(pfile, "\tputstatic %s/%s ",pro_name,entry->name );
				if(entry->dtype == Array){
					fprintf(pfile, "%s\n",entry->funtail );
				}
				else{
					if(entry->type == TypeInt) fprintf(pfile, "I\n");
					else fprintf(pfile, "F\n");
				}	
			}
				
			return;
		}
        case NODE_NUM: {
            if(node->valueValid == VALUE_I_VALID) fprintf(pfile, "\tldc %d\n",node->iValue );      
            else fprintf(pfile, "\tldc %f\n",node->rValue ); 

            return;
        }
        case NODE_String: {
            fprintf(pfile, "\tldc %s\n",node->string );         
            return;
        }
        case NODE_Char: {
            fprintf(pfile, "\tldc %s\n",node->string );        
            return;
        }
        case NODE_OP:{
			char head;
			//goto OP1
			struct nodeType* child=nthChild(1,node);
			Codegen(child, scope);
			//goto OP2
			child=nthChild(2,node);
			Codegen(child, scope);

			if(node->valueType == TypeInt) head = 'i';
			else head = 'f';
				
			switch(node->op){
				case OP_PLUS:
					fprintf(pfile, "\t%cadd\n",head);
				break;
				case OP_MINUS:
					fprintf(pfile, "\t%csub\n",head);
				break;
				case OP_MUL:
					fprintf(pfile, "\t%cmul\n",head);
				break;
				case OP_SLASH:
					fprintf(pfile, "\t%cdiv\n",head);
				break;
				case OP_LT://<
					if(child->valueType == TypeInt) {
						fprintf(pfile, "\tif_icmpge L%d\n",branch );
					}
					else {
						fprintf(pfile, "\tfcmpl\n");
						fprintf(pfile, "\tifge L%d\n",branch);
					}
					node->branch=branch;
					branch++;
				break;
				case OP_GT://>
					if(child->valueType == TypeInt) {
						fprintf(pfile, "\tif_icmple L%d\n",branch);
					}
					else {
						fprintf(pfile, "\tfcmpl\n");
						fprintf(pfile, "\tifle L%d\n",branch);
					}
					node->branch=branch;
					branch++;
				break;
				case OP_LE://<=
					if(child->valueType == TypeInt) {
						fprintf(pfile, "\tif_icmpgt L%d\n",branch );
					}
					else {
						fprintf(pfile, "\tfcmpl\n");
						fprintf(pfile, "\tifgt L%d\n",branch);
					}
					node->branch=branch;
					branch++;
				break;
				case OP_GE://>=
					if(child->valueType == TypeInt) {
						fprintf(pfile, "\tif_icmplt L%d\n",branch);
					}
					else {
						fprintf(pfile, "\tfcmpl\n");
						fprintf(pfile, "\tiflt L%d\n",branch);
					}
					node->branch=branch;
					branch++;
				break;
				case OP_EQUAL://=
					if(child->valueType == TypeInt) {
						fprintf(pfile, "\tif_icmpne L%d\n",branch);
					}
					else {
						fprintf(pfile, "\tfcmpl\n");
						fprintf(pfile, "\tifne L%d\n",branch);
					}
					node->branch=branch;
					branch++;
				break;
				case OP_notEQUAL://!=
					if(child->valueType == TypeInt) {
						fprintf(pfile, "\tif_icmpeq L%d\n",branch);
					}
					else {
						fprintf(pfile, "\tfcmpl\n");
						fprintf(pfile, "\tifeq L%d\n",branch);
					}
					node->branch=branch;
					branch++;
				break;

			}
			//break;
			return;
		}

        /* You should check the LHS of assign stmt is assignable
           You should also report error if LHS is a function with no parameter 
           (function is not implemented in this sample, you should implement it) */ 
        case NODE_ASSIGNMENT: {
        	
			struct nodeType *child2 = nthChild(2, node);
            struct nodeType *child1 = nthChild(1, node);
            if(child1->dtype == Array){
            	struct SymTableEntry *entry = findSymbol(child1->string);
            	struct nodeType *argNode = nthChild(1, child1);
            	
            	struct nodeType *tailNode = nthChild(2, argNode);
            	argNode= nthChild(1,argNode);
            	//getstatic foo/d [I
            	//fprintf(pfile, "entry:%s funtail:%s\n",entry->name,entry->funtail );
            	if(entry->scope == 0) fprintf(pfile,"\tgetstatic %s/%s %s\n",pro_name,child1->string,entry->funtail );
            	else {
            		if(entry->dtype == Array) fprintf(pfile, "\taload %d\n",entry->Seq);
					else{
						if(entry->type == TypeInt) fprintf(pfile, "\tiload %d\n",entry->Seq);
						else fprintf(pfile, "\tfload %d\n",entry->Seq);	
					}
					
            	}
            	//Array
				int count=0;
				//while(argNode->nodeType != NODE_tail){
				while(tailNode != NULL){
					//for(int i=0;i<entry->Arraydim;i++){
					Codegen(argNode,scope);
					fprintf(pfile,"\tldc %d\n",entry->Arrayinit[count]);
					fprintf(pfile, "\tisub\n");
					if(count != entry->Arraydim-1) fprintf(pfile, "\taaload\n");
					//}

					argNode = nthChild(1, tailNode);
					tailNode= nthChild(2,tailNode);
					count++;
				}	
            }
            //goto NODE_expression
            Codegen(child2,scope);
            //goto NODE_SYM_REF   
            Codegen(child1,scope);
            
            
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
        	//fprintf(pfile,"now:%d\n",child->nodeType );
            Codegen(child,scope);
            child = child->rsibling;
            //fprintf(pfile,"right sibling:%d\n",child->nodeType);
        } while(child != node->child);
    }
}

