lex mini-pascal-with-yacc.l \
&& yacc -d pascal.y \
&& gcc -c -o lex.yy.o lex.yy.c \
&& gcc -c -o y.tab.o y.tab.c \
&& gcc -c -o node.o node.c -std=gnu99 \
&& gcc -c -o symtab.o symtab.c -std=gnu99 \
&& gcc -o parse lex.yy.o y.tab.o node.o symtab.o -ll 

