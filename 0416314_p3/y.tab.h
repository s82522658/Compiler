/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     ELSE = 259,
     WHILE = 260,
     DO = 261,
     THEN = 262,
     IF = 263,
     OF = 264,
     FUNCTION = 265,
     PROCEDURE = 266,
     begin = 267,
     END = 268,
     ARRAY = 269,
     VAR = 270,
     NOT = 271,
     STRING = 272,
     ASSIGNMENT = 273,
     COLON = 274,
     COMMA = 275,
     INTEGER = 276,
     DOT = 277,
     DOTDOT = 278,
     EQUAL = 279,
     notEQUAL = 280,
     GE = 281,
     GT = 282,
     LBRAC = 283,
     LE = 284,
     LPAREN = 285,
     LT = 286,
     MINUS = 287,
     PLUS = 288,
     RBRAC = 289,
     REAL = 290,
     RPAREN = 291,
     SEMICOLON = 292,
     SLASH = 293,
     STAR = 294,
     CHAR = 295,
     NUM = 296,
     TOK_REL_OP = 297,
     String = 298,
     Char = 299,
     ID = 300
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ELSE 259
#define WHILE 260
#define DO 261
#define THEN 262
#define IF 263
#define OF 264
#define FUNCTION 265
#define PROCEDURE 266
#define begin 267
#define END 268
#define ARRAY 269
#define VAR 270
#define NOT 271
#define STRING 272
#define ASSIGNMENT 273
#define COLON 274
#define COMMA 275
#define INTEGER 276
#define DOT 277
#define DOTDOT 278
#define EQUAL 279
#define notEQUAL 280
#define GE 281
#define GT 282
#define LBRAC 283
#define LE 284
#define LPAREN 285
#define LT 286
#define MINUS 287
#define PLUS 288
#define RBRAC 289
#define REAL 290
#define RPAREN 291
#define SEMICOLON 292
#define SLASH 293
#define STAR 294
#define CHAR 295
#define NUM 296
#define TOK_REL_OP 297
#define String 298
#define Char 299
#define ID 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 30 "pascal.y"
{
    struct nodeType *node;
}
/* Line 1529 of yacc.c.  */
#line 143 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

