%code requires {
	#include "ast.h" 
	#include <string>
	#include <iostream>
	#include <vector>
}

%{
#include "ast.h" 
#include <string>
#include <iostream>
#include <vector>

void yyerror(const char *s) {
    std::printf("Error: %s\n", s);
    std::exit(1); 
}

int yylex(void);

ast::ProgramAST *root;
%}

%output "grammar.cpp"

%union {
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
}

%token  COMMA DOT SEMICOLON ELLIPSES SINGLEQUOTE DOUBLEQUOTE
        LEFTBRACE RIGHTBRACE LEFTBRACKET RIGHTBRACKET LEFTPAREN RIGHTPAREN
		SHIFTL SHIFTR EQUAL GREATER LESSTHAN GORE LORE NOEQUAL
		NOT ASSIGN AND OR ARW
		ADD SUB MUL DIV MOD DOUBLEADD DOUBLESUB
		ADDEQUAL SUBEQUAL MULEQUAL DIVEQUAL MODEQUAL COLON
		STRUCT PTR ARRAY IF ELSE FOR WHILE SWITCH CASE DEFAULT
		RETURN TRUE FALSE BREAK CONTINUE SIZEOF
		BOOL INT LONG CHAR FLOAT DOUBLE VOID
		
%token<int_Val> INTEGER
%token<double_Val> REAL
%token<char_Val> CHARACTER
%token<string_Val> IDENTIFIER 
%token<str_Val> STRING

%type<Program>	ProgramAST

%type<Decl>		DeclAST	
%type<Decls>	DeclsAST	

%type<FuncDecl>	FuncDeclAST
%type<FuncBody>	FuncBodyAST	
%type<Arg>		ArgAST
%type<ArgList>	ArgListAST _ArgListAST

%type<VarDecl>	VarDeclAST
%type<VarInit>	VarInitAST	
%type<VarList>	VarListAST _VarListAST

%type<VarType>	    VarTypeAST _VarTypeAST
%type<BuiltInType>	BuiltInTypeAST
%type<FieldDecl>	FieldDeclAST
%type<FieldDecls>	FieldDeclsAST
%type<MemList>		MemListsAST _MemListsAST	

%type<Statement>		StmtAST
%type<Statements>		StmtsAST
%type<IfStatement>		IfStmtAST
%type<ForStatement>		ForStmtAST
%type<WhileStatement>	WhileStmtAST
%type<SwitchStatement>	SwitchStmtAST
%type<CaseStatement>		CaseStmAST
%type<CaseList>		CaseList
%type<BreakStatement>	BreakStmtAST
%type<ContinueStatement>	ContinueStmtAST
%type<ReturnStatement>	ReturnStmtAST
%type<Block>		BlockAST

%type<Expr>			ExprAST
%type<ExprList>		ExprList _ExprList
%type<Constant>		ConstantAST

%nonassoc IF
%nonassoc ELSE

%left	COMMA 
%left	FUNC_CALL_ARG_LIST
%right	ASSIGN ADDEQUAL SUBEQUAL MULEQUAL DIVEQUAL MODEQUAL
%right	COLON
%left	OR
%left	AND
%left	EQUAL NOEQUAL
%left	GORE GREATER LORE LESSTHAN
%left	SHIFTL SHIFTR
%left	ADD SUB
%left	MUL DIV MOD
%right	DOUBLEADD DOUBLESUB NOT SIZEOF
%left	DOT ARW

%start ProgramAST
%%
ProgramAST: DeclsAST         {  $$ = new ast::ProgramAST($1); 
                                root = $$; }
			;
			
DeclsAST:	DeclsAST DeclAST {  $$ = $1; 
                                $$->push_back($2); }
			|														
			                  {  $$ = new ast::DeclsAST(); }
			;

DeclAST:	FuncDeclAST	{  $$ = $1;   }
			| VarDeclAST{  $$ = $1;   }
			;

FuncDeclAST: VarTypeAST IDENTIFIER LEFTPAREN ArgListAST RIGHTPAREN SEMICOLON  {  $$ = new ast::FuncDeclAST($1, *$2, $4);   }
			| VarTypeAST IDENTIFIER LEFTPAREN ArgListAST RIGHTPAREN FuncBodyAST	{  $$ = new ast::FuncDeclAST($1, *$2, $4, $6);   }
			;

FuncBodyAST: LEFTBRACE StmtsAST RIGHTBRACE	{  $$ = new ast::FuncBodyAST($2);   }
			;

VarDeclAST:	VarTypeAST VarListAST SEMICOLON {  $$ = new ast::VarDeclAST($1,$2);   }
			;

VarListAST:	_VarListAST COMMA VarInitAST	{  $$ = $1; 
                                               $$ -> push_back($3);   }
			| VarInitAST				    {  $$ = new ast::VarListAST(); 
			                                   $$ -> push_back($1);   }											
			|						        {  $$ = new ast::VarListAST();   }
			;

_VarListAST: _VarListAST COMMA VarInitAST	{  $$ = $1; 
                                               $$->push_back($3);   }
			| VarInitAST				    {  $$ = new ast::VarListAST();
			                                   $$->push_back($1);   }	
			;

VarInitAST:	IDENTIFIER				   {  $$ = new ast::VarInitAST(*$1);   }
			| IDENTIFIER ASSIGN ExprAST{  $$ = new ast::VarInitAST(*$1, $3);   }
			;

VarTypeAST:	_VarTypeAST	{  $$ = $1; }
			;

_VarTypeAST: BuiltInTypeAST {  $$ = $1;   }
			| STRUCT LEFTBRACE FieldDeclsAST RIGHTBRACE	{  $$ = new ast::StructTypeAST($3);   }
			| _VarTypeAST PTR {  $$ = new ast::PointerTypeAST($1);   }
			| _VarTypeAST ARRAY LEFTPAREN INTEGER RIGHTPAREN {  $$ = new ast::ArrayTypeAST($1,$4);   }
			| _VarTypeAST ARRAY LEFTPAREN RIGHTPAREN {  $$ = new ast::ArrayTypeAST($1);   }
			| IDENTIFIER {  $$ = new ast::DefinedTypeAST(*$1);   }
			;
			
BuiltInTypeAST: BOOL	{  $$ = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_bool_);   }
			| INT		{  $$ = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_int_);   }
			| LONG		{  $$ = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_long_);   }
			| CHAR		{  $$ = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_char_);   }
			| FLOAT		{  $$ = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_float_);   }
			| DOUBLE	{  $$ = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_double_);   }
			| VOID		{  $$ = new ast::BuiltInTypeAST(ast::BuiltInTypeAST::BuiltinType::_void_);   }
			;

FieldDeclsAST: FieldDeclsAST FieldDeclAST {  $$ = $1; 
                                              if ($2 != NULL) 
									             $$->push_back($2);   }
			|					          {  $$ = new ast::FieldDeclsAST();   }
			;

FieldDeclAST: VarTypeAST MemListsAST SEMICOLON {  $$ = new ast::FieldDeclAST($1,$2);   }
			| SEMICOLON				           {  $$ = NULL;   }
			;

MemListsAST: _MemListsAST COMMA IDENTIFIER {  $$ = $1; 
                                              $$->push_back(*$3);   }
			| IDENTIFIER			       {  $$ = new ast::MemListsAST(); 
			                                  $$->push_back(*$1);   }	
			|						       {  $$ = new ast::MemListsAST();   }
			;

_MemListsAST: _MemListsAST COMMA IDENTIFIER {  $$ = $1; 
                                               $$->push_back(*$3);   }
			| IDENTIFIER			        {  $$ = new ast::MemListsAST(); 
			                                   $$->push_back(*$1);   }
			;

ArgListAST:	_ArgListAST COMMA ArgAST  {  $$ = $1; 
                                         $$->push_back($3);   }
			| ArgAST				  {  $$ = new ast::ArgListAST(); 
			                             $$->push_back($1);   }
			| _ArgListAST COMMA ELLIPSES { $$ = $1; $$->has_dot(); }
			| ELLIPSES				  { $$ = new ast::ArgListAST();
										$$->has_dot();            }
			|						  {  $$ = new ast::ArgListAST();   }
			;

_ArgListAST: _ArgListAST COMMA ArgAST {  $$ = $1; 
                                         $$->push_back($3);   }	 
			| ArgAST				  {  $$ = new ast::ArgListAST(); 
			                             $$->push_back($1);   }
			;

ArgAST:		VarTypeAST IDENTIFIER		  {  $$ = new ast::ArgAST($1, *$2);   }
			| VarTypeAST				  {  $$ = new ast::ArgAST($1);   }
			;

BlockAST:	LEFTBRACE StmtsAST RIGHTBRACE {  $$ = new ast::BlockAST($2);   }
			;

StmtsAST:	StmtsAST StmtAST      		  {  $$ = $1; 
                                             if ($2 != NULL) 
										       $$->push_back($2);   }	
			|						      {  $$ = new ast::StmtsAST();   }
			;

StmtAST:	ExprAST SEMICOLON		  {  $$ = $1;   }
			| IfStmtAST				  {  $$ = $1;   }
			| ForStmtAST			  {  $$ = $1;   }
			| WhileStmtAST			  {  $$ = $1;   }
			| SwitchStmtAST			  {  $$ = $1;   } 
			| BreakStmtAST			  {  $$ = $1;   }
			| ContinueStmtAST		  {  $$ = $1;   }
			| ReturnStmtAST			  {  $$ = $1;   }
			| BlockAST				  {  $$ = $1;   }
			| VarDeclAST			  {  $$ = $1;   }
			| SEMICOLON				  {  $$ = NULL;   }
			;

IfStmtAST:	IF LEFTPAREN ExprAST RIGHTPAREN StmtAST ELSE StmtAST	{  $$ = new ast::IfStmtAST($3, $5, $7);   }
			| IF LEFTPAREN ExprAST RIGHTPAREN StmtAST         	    {  $$ = new ast::IfStmtAST($3, $5);   }
			;

ForStmtAST:	FOR LEFTPAREN ExprAST SEMICOLON ExprAST SEMICOLON ExprAST RIGHTPAREN StmtAST	{  $$ = new ast::ForStmtAST($3, $5, $7, $9);   }
            | FOR LEFTPAREN VarDeclAST ExprAST SEMICOLON ExprAST RIGHTPAREN StmtAST {  $$ = new ast::ForStmtAST($3, $4, $6, $8);   }
			;

WhileStmtAST: WHILE LEFTPAREN ExprAST RIGHTPAREN StmtAST {  $$ = new ast::WhileStmtAST($3, $5);   }
			;

SwitchStmtAST: SWITCH LEFTPAREN ExprAST RIGHTPAREN LEFTBRACE CaseList RIGHTBRACE {  $$ = new ast::SwitchStmtAST($3, $6);   }
			;

CaseList:	CaseList CaseStmAST {  $$ = $1; 
                                   $$->push_back($2);   }	
			|				    {  $$ = new ast::CaseList();   }
			;

CaseStmAST:	CASE ExprAST COLON StmtsAST {  $$ = new ast::CaseStmAST($2, $4);   }
			| DEFAULT COLON StmtsAST    {  $$ = new ast::CaseStmAST(NULL, $3);   }
			;

ContinueStmtAST: CONTINUE SEMICOLON		{  $$ = new ast::ContinueStmtAST();   }
			;

BreakStmtAST:	BREAK SEMICOLON			{  $$ = new ast::BreakStmtAST();   }
			;

ReturnStmtAST: RETURN SEMICOLON 		{  $$ = new ast::ReturnStmtAST();   }
			| RETURN ExprAST SEMICOLON	{  $$ = new ast::ReturnStmtAST($2);   }
			;

ExprAST:	ExprAST LEFTBRACKET ExprAST RIGHTBRACKET %prec ARW	{  $$ = new ast::SubscriptAST($1, $3);   }
			| SIZEOF LEFTPAREN IDENTIFIER RIGHTPAREN		{  $$ = new ast::SizeOfAST(*$3);   }
			| SIZEOF LEFTPAREN ExprAST RIGHTPAREN			{  $$ = new ast::SizeOfAST($3);   }
			| SIZEOF LEFTPAREN VarTypeAST RIGHTPAREN		{  $$ = new ast::SizeOfAST($3);   }
			| IDENTIFIER LEFTPAREN ExprList RIGHTPAREN		{  $$ = new ast::FunctionCallAST(*$1, $3);   }
			| ExprAST DOT IDENTIFIER					    {  $$ = new ast::StructReferenceAST($1, *$3);   }
			| ExprAST ARW IDENTIFIER					    {  $$ = new ast::StructDereferenceAST($1, *$3);   }
			| ADD ExprAST %prec NOT					        {  $$ = new ast::UnaryPlusAST($2);   }
			| SUB ExprAST %prec NOT					        {  $$ = new ast::UnaryMinusAST($2);   }
			| LEFTPAREN VarTypeAST RIGHTPAREN ExprAST %prec NOT	{  $$ = new ast::TypeCastAST($2, $4);   }
			| DOUBLEADD ExprAST	%prec NOT					{  $$ = new ast::PrefixIncAST($2);   }
			| ExprAST DOUBLEADD %prec ARW					{  $$ = new ast::PostfixIncAST($1);   }
			| DOUBLESUB ExprAST %prec NOT					{  $$ = new ast::PrefixDecAST($2);   }
			| ExprAST DOUBLESUB	%prec ARW					{  $$ = new ast::PostfixDecAST($1);   }
			| MUL ExprAST %prec NOT					        {  $$ = new ast::IndirectionAST($2);   }
			| NOT ExprAST								    {  $$ = new ast::LogicNotAST($2);   }
			| ExprAST DIV ExprAST							{  $$ = new ast::DivAST($1, $3);   }
			| ExprAST MUL ExprAST							{  $$ = new ast::MulAST($1, $3);   } 
			| ExprAST MOD ExprAST 						    {  $$ = new ast::ModuloAST($1, $3);   }
			| ExprAST ADD ExprAST							{  $$ = new ast::AddAST($1, $3);   } 
			| ExprAST SUB ExprAST							{  $$ = new ast::SubAST($1, $3);   } 
			| ExprAST SHIFTL ExprAST						{  $$ = new ast::LeftShiftAST($1, $3);   } 
			| ExprAST SHIFTR ExprAST						{  $$ = new ast::RightShiftAST($1, $3);   } 
			| ExprAST GREATER ExprAST						{  $$ = new ast::LogicGTAST($1, $3);   } 
			| ExprAST GORE ExprAST							{  $$ = new ast::LogicGEAST($1, $3);   } 
			| ExprAST LESSTHAN ExprAST						{  $$ = new ast::LogicLTAST($1, $3);   } 
			| ExprAST LORE ExprAST							{  $$ = new ast::LogicLEAST($1, $3);   } 
			| ExprAST EQUAL ExprAST							{  $$ = new ast::LogicEQAST($1, $3);   } 
			| ExprAST NOEQUAL ExprAST						{  $$ = new ast::LogicNEQAST($1, $3);   } 
			| ExprAST AND ExprAST							{  $$ = new ast::LogicANDAST($1, $3);   } 
			| ExprAST OR ExprAST							{  $$ = new ast::LogicORAST($1, $3);   } 
			| ExprAST ASSIGN ExprAST 						{  $$ = new ast::DirectAssignAST($1, $3);   } 
			| ExprAST DIVEQUAL ExprAST 						{  $$ = new ast::DivAssignAST($1, $3);   } 
			| ExprAST MULEQUAL ExprAST						{  $$ = new ast::MulAssignAST($1, $3);   }  
			| ExprAST MODEQUAL ExprAST						{  $$ = new ast::ModAssignAST($1, $3);   } 
			| ExprAST ADDEQUAL ExprAST						{  $$ = new ast::AddAssignAST($1, $3);   } 
			| ExprAST SUBEQUAL ExprAST						{  $$ = new ast::SubAssignAST($1, $3);   } 
			| LEFTPAREN ExprAST RIGHTPAREN					{  $$ = $2;   }
			| IDENTIFIER							        {  $$ = new ast::VariableAST(*$1);   } 
			| ConstantAST								    {  $$ = $1;   }												
			| ExprAST COMMA ExprAST						    {  $$ = new ast::CommaExprAST($1, $3);   }
			;

ExprList:	_ExprList COMMA ExprAST					{  $$ = $1; 
                                                       $$->push_back($3);   }
			| ExprAST %prec FUNC_CALL_ARG_LIST		{  $$ = new ast::ExprList(); 
			                                           $$->push_back($1);   }
			|										{  $$ = new ast::ExprList();   }
			;

_ExprList:	_ExprList COMMA ExprAST 				{  $$ = $1; 
                                                       $$->push_back($3);   }
			| ExprAST %prec FUNC_CALL_ARG_LIST		{  $$ = new ast::ExprList(); 
			                                           $$->push_back($1);   }
			;

ConstantAST: TRUE			{  $$ =  new ast::ConstantAST(true);   }
			| FALSE			{  $$ =  new ast::ConstantAST(false);   }
			| CHARACTER		{  $$ =  new ast::ConstantAST($1);   }
			| INTEGER 		{  $$ =  new ast::ConstantAST($1);   }
			| REAL			{  $$ =  new ast::ConstantAST($1);   }
			| STRING		{  $$ =  new ast::GlobalStringAST(*$1);   }
			;
%%