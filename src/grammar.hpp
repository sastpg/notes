/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_HPP_INCLUDED
# define YY_YY_GRAMMAR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "grammar.y"

	#include "ast.h" 
	#include <string>
	#include <iostream>
	#include <vector>

#line 56 "grammar.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    COMMA = 258,                   /* COMMA  */
    DOT = 259,                     /* DOT  */
    SEMICOLON = 260,               /* SEMICOLON  */
    ELLIPSES = 261,                /* ELLIPSES  */
    SINGLEQUOTE = 262,             /* SINGLEQUOTE  */
    DOUBLEQUOTE = 263,             /* DOUBLEQUOTE  */
    LEFTBRACE = 264,               /* LEFTBRACE  */
    RIGHTBRACE = 265,              /* RIGHTBRACE  */
    LEFTBRACKET = 266,             /* LEFTBRACKET  */
    RIGHTBRACKET = 267,            /* RIGHTBRACKET  */
    LEFTPAREN = 268,               /* LEFTPAREN  */
    RIGHTPAREN = 269,              /* RIGHTPAREN  */
    SHIFTL = 270,                  /* SHIFTL  */
    SHIFTR = 271,                  /* SHIFTR  */
    EQUAL = 272,                   /* EQUAL  */
    GREATER = 273,                 /* GREATER  */
    LESSTHAN = 274,                /* LESSTHAN  */
    GORE = 275,                    /* GORE  */
    LORE = 276,                    /* LORE  */
    NOEQUAL = 277,                 /* NOEQUAL  */
    NOT = 278,                     /* NOT  */
    ASSIGN = 279,                  /* ASSIGN  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    ARW = 282,                     /* ARW  */
    ADD = 283,                     /* ADD  */
    SUB = 284,                     /* SUB  */
    MUL = 285,                     /* MUL  */
    DIV = 286,                     /* DIV  */
    MOD = 287,                     /* MOD  */
    DOUBLEADD = 288,               /* DOUBLEADD  */
    DOUBLESUB = 289,               /* DOUBLESUB  */
    ADDEQUAL = 290,                /* ADDEQUAL  */
    SUBEQUAL = 291,                /* SUBEQUAL  */
    MULEQUAL = 292,                /* MULEQUAL  */
    DIVEQUAL = 293,                /* DIVEQUAL  */
    MODEQUAL = 294,                /* MODEQUAL  */
    COLON = 295,                   /* COLON  */
    STRUCT = 296,                  /* STRUCT  */
    PTR = 297,                     /* PTR  */
    ARRAY = 298,                   /* ARRAY  */
    IF = 299,                      /* IF  */
    ELSE = 300,                    /* ELSE  */
    FOR = 301,                     /* FOR  */
    WHILE = 302,                   /* WHILE  */
    SWITCH = 303,                  /* SWITCH  */
    CASE = 304,                    /* CASE  */
    DEFAULT = 305,                 /* DEFAULT  */
    RETURN = 306,                  /* RETURN  */
    TRUE = 307,                    /* TRUE  */
    FALSE = 308,                   /* FALSE  */
    BREAK = 309,                   /* BREAK  */
    CONTINUE = 310,                /* CONTINUE  */
    SIZEOF = 311,                  /* SIZEOF  */
    BOOL = 312,                    /* BOOL  */
    INT = 313,                     /* INT  */
    LONG = 314,                    /* LONG  */
    CHAR = 315,                    /* CHAR  */
    FLOAT = 316,                   /* FLOAT  */
    DOUBLE = 317,                  /* DOUBLE  */
    VOID = 318,                    /* VOID  */
    INTEGER = 319,                 /* INTEGER  */
    REAL = 320,                    /* REAL  */
    CHARACTER = 321,               /* CHARACTER  */
    IDENTIFIER = 322,              /* IDENTIFIER  */
    STRING = 323,                  /* STRING  */
    FUNC_CALL_ARG_LIST = 324       /* FUNC_CALL_ARG_LIST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "grammar.y"

   //��ͬ��������
    int int_Val;
    double double_Val;
    char char_Val;
	std::string *string_Val;
	std::string *str_Val;

    ast::ProgramAST *Program;

	/** Declarations **/
    ast::DeclAST *Decl;
    ast::DeclsAST *Decls; 

	/** Function declaration **/
    ast::FuncDeclAST *FuncDecl;
	ast::ArgAST *Arg;
    ast::ArgListAST *ArgList;
    ast::FuncBodyAST *FuncBody;

	/** Variable declaration **/
    ast::VarDeclAST *VarDecl;
	ast::VarInitAST *VarInit;
    ast::VarListAST *VarList;

	/** Type declaration **/
    ast::VarTypeAST *VarType;
    ast::BuiltInTypeAST* BuiltInType;
	ast::FieldDeclAST* FieldDecl;
    ast::FieldDeclsAST* FieldDecls;
	ast::MemListsAST* MemList;
	
	/** Statement **/
    ast::StmtAST *Statement;
	ast::StmtsAST *Statements;
    ast::IfStmtAST *IfStatement;
    ast::ForStmtAST *ForStatement;
    ast::WhileStmtAST *WhileStatement;
    ast::SwitchStmtAST *SwitchStatement;
	ast::CaseStmAST *CaseStatement;
    ast::CaseList *CaseList;
    ast::BreakStmtAST *BreakStatement;
	ast::ContinueStmtAST *ContinueStatement;
    ast::ReturnStmtAST *ReturnStatement;
    ast::BlockAST *Block;
	
	/** Expression **/
    ast::ExprAST *Expr;
	ast::ExprList* ExprList;
    ast::ConstantAST* Constant;

#line 194 "grammar.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAMMAR_HPP_INCLUDED  */
