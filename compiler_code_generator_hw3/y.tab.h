/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    NEWLINE = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LEQ = 267,
    EQL = 268,
    NEQ = 269,
    GTR = 270,
    LSS = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    QUO_ASSIGN = 275,
    REM_ASSIGN = 276,
    LAND = 277,
    LOR = 278,
    PRINT = 279,
    PRINTLN = 280,
    IF = 281,
    ELSE = 282,
    FOR = 283,
    TRUE = 284,
    FALSE = 285,
    INT_LIT = 286,
    FLOAT_LIT = 287,
    STRING_LIT = 288,
    BOOL_LIT = 289,
    IDENT = 290
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define NEWLINE 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LEQ 267
#define EQL 268
#define NEQ 269
#define GTR 270
#define LSS 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define QUO_ASSIGN 275
#define REM_ASSIGN 276
#define LAND 277
#define LOR 278
#define PRINT 279
#define PRINTLN 280
#define IF 281
#define ELSE 282
#define FOR 283
#define TRUE 284
#define FALSE 285
#define INT_LIT 286
#define FLOAT_LIT 287
#define STRING_LIT 288
#define BOOL_LIT 289
#define IDENT 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;

#line 130 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
