%{
#include "parser.tab.hpp"
#include <cstdlib>
#include <cstdio>
#include <string>

#define YYSTYPE_IS_DECLARED 1
YYSTYPE yylval;
%}

%%

[ \t\r\n]+            ;
"int"                 { return T_INT; }
"float"               { return T_FLOAT; }
"bool"                { return T_BOOL; }
"string"              { return T_STRING; }
"if"                  { return T_IF; }
"return"              { return T_RETURN; }
"=="                  { return T_EQ; }
"!="                  { return T_NEQ; }
"<="                  { return T_LE; }
">="                  { return T_GE; }
"<"                   { return T_LT; }
">"                   { return T_GT; }
"="                   { return T_EQUALS; }
"+"                   { return T_PLUS; }
"-"                   { return T_MINUS; }
"*"                   { return T_TIMES; }
"/"                   { return T_DIVIDE; }
"("                   { return T_LPAREN; }
")"                   { return T_RPAREN; }
"{"                   { return T_LBRACE; }
"}"                   { return T_RBRACE; }
";"                   { return T_SEMICOLON; }
","                   { return T_COMMA; }

[0-9]+                { yylval.literal_value = new std::string(yytext); return T_NUMBER; }
[0-9]+"."[0-9]+       { yylval.literal_value = new std::string(yytext); return T_FLOAT_NUMBER; }
\"(\\.|[^\"])*\"      { yylval.literal_value = new std::string(yytext + 1, yyleng - 2); return T_STRING_LITERAL; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.identifier_name = new std::string(yytext);
    return T_IDENTIFIER;
}

.                     { return T_UNKNOWN; }

%%

int yywrap() {
    return 1;
}

void yyerror(const char* s) {
    std::cerr << "Error: " << s << std::endl;
}
