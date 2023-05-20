%{
#include "ast.h"
#include "grammar.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

extern "C" int yywrap() {return 1;}

char Char_Exchange(char ch){
	switch(ch){
	case 'a': return '\a';
	case 'b': return '\b';
	case 'f': return '\f';
	case 'n': return '\n';
	case 'r': return '\r';
	case 't': return '\t';
	case 'v': return '\v';
	case '\\': return '\\';
	case '\'': return '\'';
	case '\"': return '\"';
	default:
		if ('0' <= ch && ch <= '9')
			return (char)(ch - '0');
		else
			return ch;
	}
}
%}

%option never-interactive
%option outfile="lexical.cpp"

%%
","	 {return COMMA;}
"."	 {return DOT;}
"..." {return ELLIPSES;}
";"	 {return SEMICOLON;}
"{"	 {return LEFTBRACE;}
"}"	 {return RIGHTBRACE;}
"["	 {return LEFTBRACKET;}
"]"	 {return RIGHTBRACKET;}
"("	 {return LEFTPAREN;}
")"	 {return RIGHTPAREN;}
"<<" {return SHIFTL;}
">>" {return SHIFTR;}
"==" {return EQUAL;}
">"	 {return GREATER;}
"<"  {return LESSTHAN;}
">=" {return GORE;}
"<=" {return LORE;}
"!=" {return NOEQUAL;}
"!"	 {return NOT;}
"="	 {return ASSIGN;}
"&&" {return AND;}
"||" {return OR;}
"->" {return ARW;}
"+"	 {return ADD;}
"-"	 {return SUB;}
"*"	 {return MUL;}
"/"	 {return DIV;}
"%"	 {return MOD;}
"++" {return DOUBLEADD;}
"--" {return DOUBLESUB;}
"+=" {return ADDEQUAL;}
"-=" {return SUBEQUAL;}
"*=" {return MULEQUAL;}
"/=" {return DIVEQUAL;}
"%=" {return MODEQUAL;}
":"	 {return COLON;}
"struct" {return STRUCT;}
"ptr"	 {return PTR;}
"array"	 {return ARRAY;}
"if"     {return IF;}
"else"	 {return ELSE;}
"for"    {return FOR;}
"while"	 {return WHILE;}
"switch" {return SWITCH;}
"case"	 {return CASE;}
"default"	{return DEFAULT;}
"return"	{return RETURN;}
"true"		{return TRUE; }
"false"		{return FALSE; }
"break"		{return BREAK; }
"continue"	{return CONTINUE;}
"sizeof"	{return SIZEOF; }
"bool"		{return BOOL; }
"int"		{return INT; }
"long"		{return LONG; }
"char"		{return CHAR; }
"float"		{return FLOAT; }
"double"	{return DOUBLE; }
"void"		{return VOID; }
[ \t\n]		{ ; }
"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/" { ; }
"//".*	{ ; }
"\'"\\."\'"	{ yylval.char_Val = Char_Exchange(yytext[2]); return CHARACTER;}
"\'"[^\\']"\'"	{ yylval.char_Val = yytext[1]; return CHARACTER;}
"\'"			{ return SINGLEQUOTE; }
"\""			{ return DOUBLEQUOTE;}
"\""(\\.|[^"\\])*"\""									{
															yylval.str_Val = new std::string("");
															for (int i = 1; i <= yyleng-2; i++)
																if (yytext[i] == '\\'){
																	i++;
																	yylval.str_Val->push_back(Char_Exchange(yytext[i]));
																}else{
																	yylval.str_Val->push_back(yytext[i]);
																}
															return STRING;
														}
[a-zA-Z_][a-zA-Z0-9_]*	{ yylval.string_Val = new std::string(yytext, yyleng); return IDENTIFIER;} 
[0-9]+\.[0-9]+	{ double double_tmp; sscanf(yytext, "%lf", &double_tmp); yylval.double_Val = double_tmp; return REAL;}
[0-9]+			{ int int_tmp; sscanf(yytext, "%d", &int_tmp); yylval.int_Val = int_tmp; return INTEGER;}
%%