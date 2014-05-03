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
     TIDENT = 258,
     TPRIME = 259,
     TNUM = 260,
     TPLUS = 261,
     TMINUS = 262,
     TMULT = 263,
     TTT = 264,
     TFF = 265,
     TLT = 266,
     TLE = 267,
     TGT = 268,
     TGE = 269,
     TEQ = 270,
     TNEQ = 271,
     TNOT = 272,
     TOR = 273,
     TAND = 274,
     TLPAR = 275,
     TRPAR = 276,
     TPOW = 277,
     TLBRA = 278,
     TRBRA = 279,
     TCOMMA = 280,
     TQMARK = 281,
     TTIL = 282,
     TNL = 283,
     TVAR = 284,
     TDEF = 285,
     TEQN = 286,
     TINIT = 287,
     TTRANS = 288,
     TSEMI = 289,
     TARROW = 290,
     TAX = 291,
     TAG = 292,
     TAF = 293,
     TA = 294,
     TEX = 295,
     TEG = 296,
     TEF = 297,
     TE = 298,
     TX = 299,
     TF = 300,
     TG = 301,
     TU = 302,
     TR = 303,
     TPROP = 304,
     TMOD = 305,
     TDIV = 306,
     TNEG = 307
   };
#endif
/* Tokens.  */
#define TIDENT 258
#define TPRIME 259
#define TNUM 260
#define TPLUS 261
#define TMINUS 262
#define TMULT 263
#define TTT 264
#define TFF 265
#define TLT 266
#define TLE 267
#define TGT 268
#define TGE 269
#define TEQ 270
#define TNEQ 271
#define TNOT 272
#define TOR 273
#define TAND 274
#define TLPAR 275
#define TRPAR 276
#define TPOW 277
#define TLBRA 278
#define TRBRA 279
#define TCOMMA 280
#define TQMARK 281
#define TTIL 282
#define TNL 283
#define TVAR 284
#define TDEF 285
#define TEQN 286
#define TINIT 287
#define TTRANS 288
#define TSEMI 289
#define TARROW 290
#define TAX 291
#define TAG 292
#define TAF 293
#define TA 294
#define TEX 295
#define TEG 296
#define TEF 297
#define TE 298
#define TX 299
#define TF 300
#define TG 301
#define TU 302
#define TR 303
#define TPROP 304
#define TMOD 305
#define TDIV 306
#define TNEG 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "parser.y"
{
  int value;
  char *name;
  struct ast *ast;
}
/* Line 1529 of yacc.c.  */
#line 159 "parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

