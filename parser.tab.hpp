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

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_IDENTIFIER = 258,            /* T_IDENTIFIER  */
    T_NUMBER = 259,                /* T_NUMBER  */
    T_FLOAT_NUMBER = 260,          /* T_FLOAT_NUMBER  */
    T_STRING_LITERAL = 261,        /* T_STRING_LITERAL  */
    T_INT = 262,                   /* T_INT  */
    T_FLOAT = 263,                 /* T_FLOAT  */
    T_STRING = 264,                /* T_STRING  */
    T_BOOL = 265,                  /* T_BOOL  */
    T_PLUS = 266,                  /* T_PLUS  */
    T_MINUS = 267,                 /* T_MINUS  */
    T_TIMES = 268,                 /* T_TIMES  */
    T_DIVIDE = 269,                /* T_DIVIDE  */
    T_EQUALS = 270,                /* T_EQUALS  */
    T_LPAREN = 271,                /* T_LPAREN  */
    T_RPAREN = 272,                /* T_RPAREN  */
    T_LBRACE = 273,                /* T_LBRACE  */
    T_RBRACE = 274,                /* T_RBRACE  */
    T_SEMICOLON = 275,             /* T_SEMICOLON  */
    T_COMMA = 276,                 /* T_COMMA  */
    T_EQ = 277,                    /* T_EQ  */
    T_NEQ = 278,                   /* T_NEQ  */
    T_LT = 279,                    /* T_LT  */
    T_GT = 280,                    /* T_GT  */
    T_LE = 281,                    /* T_LE  */
    T_GE = 282,                    /* T_GE  */
    T_IF = 283,                    /* T_IF  */
    T_RETURN = 284,                /* T_RETURN  */
    T_EOF = 285,                   /* T_EOF  */
    T_UNKNOWN = 286                /* T_UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.ypp"

    int ival;
    float fval;
    char *sval;
    Node* node;
    Expression* expression;
    std::vector<std::pair<std::string, std::string>> *parameters;
    std::vector<std::unique_ptr<Node>> *statements;
    std::string *literal_value;
    std::string *identifier_name;

#line 107 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
