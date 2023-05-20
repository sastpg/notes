#include "ast.h"
#include <iostream>
#include <string>
#include <vector>

// Remove escape characters, but it's imcomplete
std::string strip(std::string input) {
    std::string result;
    bool escapeFlag = false;

    for (char c : input) {
        if (escapeFlag) {
            switch (c) {
                case 'n':
                    result.push_back('\n');
                    break;
                case 't':
                    result.push_back('\t');
                    break;
                case 'r':
                    result.push_back('\r');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case '\"':
                    result.push_back('\"');
                    break;
                default:
                    result.push_back('\\');
                    result.push_back(c);
                    break;
            }
            escapeFlag = false;
        } else if (c == '\\') {
            escapeFlag = true;
        } else {
            result.push_back(c);
        }
    }

    return result;
}

// Dump to json format
/**
 * @param: node_name 节点名称, decendant 该节点后代
 * @return: json format std::string
*/
std::string DumpJson(std::string node_name, std::vector<std::string> descendant = {}) {
    std::string parent = "{ \"name\" : \"" + node_name + "\"";
    std::string children = "";
    int i = 0;
    for(auto &child : descendant) {
        if(i != descendant.size() - 1)
            children += child + ", ";
        else
            children += child + " ";
        i++;
    }
    if(children != "")
        children = ", \"children\" : [ " + children + " ]";
    std::string json = parent + children + " }";
    return json;
}

// ProgramAST
std::string ast::ProgramAST::to_json() const {
    std::vector<std::string> program;
    for(auto &x : *decls)
        program.push_back(x->to_json());
    return DumpJson("Program", program);
}

// FuncDeclAST
std::string ast::FuncDeclAST::to_json() const {
    std::vector<std::string> funcDecl;
    // Return type
    funcDecl.push_back(DumpJson("Return Type", {return_type->to_json()}));
    // Function name
    funcDecl.push_back(DumpJson("Function Name", {DumpJson(func_name)}));
    // Args
    std::vector<std::string> argList;
    for(auto &x : *arg_list)
        argList.push_back(x->to_json());
    if(arg_list->with_dot)
        argList.push_back(DumpJson("Dot", {"..."}));
    funcDecl.push_back(DumpJson("Parameters", argList));
    // Body
    if(fun_body)
        funcDecl.push_back(fun_body->to_json());
    
    return DumpJson("Function Declaration", funcDecl);
}

// ArgAST
std::string ast::ArgAST::to_json() const {
    std::vector<std::string> arg;
    arg.push_back(para_type->to_json());
    if(var_name != "")
        arg.push_back(DumpJson(var_name));
    return DumpJson("Parameter", arg);
}

// ArgListAST
std::string ast::ArgListAST::to_json() const {
    // 先暂时不写，有点疑惑
    return "";
}

// FuncBodyAST
std::string ast::FuncBodyAST::to_json() const {
    std::vector<std::string> funcBody;
    for(auto &x : *stmts)
        funcBody.push_back(x->to_json());
    
    return DumpJson("Function Body", funcBody);
}

// VarDeclAST
std::string ast::VarDeclAST::to_json() const {
    std::vector<std::string> varDecl;
    // VarType
    varDecl.push_back(var_type->to_json());
	// VarList
	std::vector<std::string> varList;
	for(auto &x : *var_list)
		varList.push_back(x->to_json());

	varDecl.push_back(DumpJson("Var Lists", varList));
	return DumpJson("Var Declaration", varDecl);
}

// VarInitAST
std::string ast::VarInitAST::to_json() const {
	std::vector<std::string> varInit;
	varInit.push_back(DumpJson(var_name));
	if(expr)
		varInit.push_back(expr->to_json());

	return DumpJson("Var Init", varInit);
}

// BuiltInTypeAST
std::string ast::BuiltInTypeAST::to_json() const {
	switch (builtin_type)
	{
        case _bool_:
            return DumpJson("BuiltInType", {DumpJson("bool")});
            break;
        case _int_:
            return DumpJson("BuiltInType", {DumpJson("int")});
            break;
        case _long_:
            return DumpJson("BuiltInType", {DumpJson("long")});
            break;
        case _char_:
            return DumpJson("BuiltInType", {DumpJson("char")});
            break;
        case _float_:
            return DumpJson("BuiltInType", {DumpJson("float")});
            break;
        case _double_:
            return DumpJson("BuiltInType", {DumpJson("double")});
            break;
        case _void_:
            return DumpJson("BuiltInType", {DumpJson("void")});
            break;
        default:
            break;
	}
	return DumpJson("UnknownType", {DumpJson("error")});
}

// DefinedTypeAST
std::string ast::DefinedTypeAST::to_json() const {
	std::vector<std::string> definedType;
	definedType.push_back(DumpJson(id));
	return DumpJson("DefinedType", definedType);
}

// ArrayTypeAST
std::string ast::ArrayTypeAST::to_json() const {
	std::vector<std::string> arrayType;
	arrayType.push_back(var_type->to_json());
	arrayType.push_back(DumpJson(std::to_string(ele_num)));
	return DumpJson("ArrayType", arrayType);
}

// PointerTypeAST
std::string ast::PointerTypeAST::to_json() const {
	std::vector<std::string> pointType;
	pointType.push_back(ptr_type->to_json());
	return DumpJson("PointerType", pointType);
}

// StructTypeAST
std::string ast::StructTypeAST::to_json() const {
	std::vector<std::string> structType;
	for(auto &x : *struct_body)
		structType.push_back(x->to_json());
	
	return DumpJson("StructType", structType);
}

// FieldDeclAST
std::string ast::FieldDeclAST::to_json() const {
	std::vector<std::string> fieldDecl;
	fieldDecl.push_back(var_type->to_json());
	// varlist
	std::vector<std::string> varList;
	for(auto &x : *var_list)
		varList.push_back(DumpJson(x));
	fieldDecl.push_back(DumpJson("Var List", varList));

	return DumpJson("Field Declaration", fieldDecl);
}

// IfStmtAST
std::string ast::IfStmtAST::to_json() const {
	std::vector<std::string> ifStmt;
	ifStmt.push_back(conditions->to_json());
	ifStmt.push_back(branch1->to_json());
	if(branch2)
		ifStmt.push_back(branch2->to_json());
	
	return DumpJson("If Statement", ifStmt);
}

// ForStmtAST
std::string ast::ForStmtAST::to_json() const {
	std::vector<std::string> forStmt;
	if(init)
		forStmt.push_back(init->to_json());
	if(condition)
		forStmt.push_back(condition->to_json());
	if(operation)
		forStmt.push_back(operation->to_json());
	if(body)
		forStmt.push_back(body->to_json());

	return DumpJson("For Statement", forStmt);
}

// WhileStmtAST
std::string ast::WhileStmtAST::to_json() const {
	std::vector<std::string> whileStmt;
	whileStmt.push_back(condition->to_json());
	if(body)
		whileStmt.push_back(body->to_json());

	return DumpJson("While Statement", whileStmt);
}

// SwitchStmtAST
std::string ast::SwitchStmtAST::to_json() const {
	std::vector<std::string> switchStmt;
	switchStmt.push_back(identifier->to_json());
	// Case
	std::vector<std::string> caseList;
	for(auto &x : *case_list)
		caseList.push_back(x->to_json());
	switchStmt.push_back(DumpJson("Case List", caseList));

	return DumpJson("Switch Statement", switchStmt);
}

// CaseStmAST
std::string ast::CaseStmAST::to_json() const {
	std::vector<std::string> caseStmt;
	if(expr)
		caseStmt.push_back(expr->to_json());
	else
		caseStmt.push_back(DumpJson("Default"));

	std::vector<std::string> stmtList;
	for(auto &x : *stmt)
		stmtList.push_back(x->to_json());
	caseStmt.push_back(DumpJson("Statements", stmtList));

	return DumpJson("Case Statement", caseStmt);
}

// BreakStmtAST
std::string ast::BreakStmtAST::to_json() const {
	return DumpJson("Break");
}

// ContinueStmtAST
std::string ast::ContinueStmtAST::to_json() const {
	return DumpJson("Continue");
}

// ReturnStmtAST
std::string ast::ReturnStmtAST::to_json() const {
	std::vector<std::string> returnStmt;
	if(ret_val)
		returnStmt.push_back(ret_val->to_json());
	return DumpJson("Return", returnStmt);
}

// BlockAST
std::string ast::BlockAST::to_json() const {
	std::vector<std::string> block;
	// std::vector<std::string> stmtList;
	for(auto &x : *stmts)
		block.push_back(x->to_json());
	
	// block.push_back(DumpJson("Statements", stmtList));
	return DumpJson("Block", block);
}


std::string ast::SubscriptAST::to_json() const {
	std::vector<std::string> subscript;
	subscript.push_back(_Ary->to_json());
	subscript.push_back(_Idx->to_json());
	return DumpJson("Subscript", subscript);
}

std::string ast::SizeOfAST::to_json() const {
	std::vector<std::string> sizeOF;	
	if (_Arg1 != NULL)
		sizeOF.push_back(_Arg1->to_json());
	if (_Arg2 != NULL)
		sizeOF.push_back(_Arg2->to_json());
	return DumpJson("Sizeof", sizeOF);
}

std::string ast::FunctionCallAST::to_json() const {
	std::vector<std::string> funcall;	
	funcall.push_back(DumpJson("Function Name", {DumpJson(_Func)}));
	std::vector<std::string> argLJson;
	for (auto x : *_ArgL)
		argLJson.push_back(x->to_json());
	funcall.push_back(DumpJson("ArgList", argLJson));
	return DumpJson("FunctionCall", funcall);
}

std::string ast::StructReferenceAST::to_json() const {
	std::vector<std::string> StructRef;	//children node json
	StructRef.push_back(_Struct->to_json());
	StructRef.push_back(DumpJson("Memory", {_Mem}));
	return DumpJson("StructReference", StructRef);
}

std::string ast::StructDereferenceAST::to_json() const{
	std::vector<std::string> StructDeref;	//children node json
	StructDeref.push_back(_StructPtr->to_json());
	StructDeref.push_back(DumpJson("Memory", {_Mem}));
	return DumpJson("StructDereference", StructDeref);
}

std::string ast::UnaryPlusAST::to_json() const{
	std::vector<std::string> Plus;	//children node json
	Plus.push_back(_Op->to_json());
	return DumpJson("UnaryPlus", Plus);
}

std::string ast::UnaryMinusAST::to_json() const{
	std::vector<std::string> Minus;	//children node json
	Minus.push_back(_Op->to_json());
	return DumpJson("UnaryMinus", Minus);
}

std::string ast::TypeCastAST::to_json() const{
	std::vector<std::string> Typecast;	//children node json
	Typecast.push_back(_VarType->to_json());
	Typecast.push_back(_Op->to_json());
	return DumpJson("TypeCast", Typecast);
}

std::string ast::PrefixIncAST::to_json() const{
	std::vector<std::string> PreInc;	//children node json
	PreInc.push_back(_Op->to_json());
	return DumpJson("PrefixInc", PreInc);
}

std::string ast::PostfixIncAST::to_json() const{
	std::vector<std::string> PostInc;	//children node json
	PostInc.push_back(_Op->to_json());
	return DumpJson("PostfixInc", PostInc);
}

std::string ast::PrefixDecAST::to_json() const{
	std::vector<std::string> PreDec;	//children node json
	PreDec.push_back(_Op->to_json());
	return DumpJson("PrefixDec", PreDec);
}

std::string ast::PostfixDecAST::to_json() const{
	std::vector<std::string> PostDec;	//children node json
	PostDec.push_back(_Op->to_json());
	return DumpJson("PostfixDec", PostDec);
}

std::string ast::IndirectionAST::to_json() const{
	std::vector<std::string> Indirection;	//children node json
	Indirection.push_back(_Op->to_json());
	return DumpJson("Indirection", Indirection);
}

std::string ast::AddressOfAST::to_json() const{
	std::vector<std::string> AddrOf;	//children node json
	AddrOf.push_back(_Op->to_json());
	return DumpJson("Addressof", AddrOf);
}

std::string ast::LogicNotAST::to_json() const{
	std::vector<std::string> Logicnot;	//children node json
	Logicnot.push_back(_Op->to_json());
	return DumpJson("LogicNot", Logicnot);
}

std::string ast::DivAST::to_json() const{
	std::vector<std::string> Div;	//children node json
	Div.push_back(_LHS->to_json());
	Div.push_back(_RHS->to_json());
	return DumpJson("Division", Div);
}

std::string ast::MulAST::to_json() const{
	std::vector<std::string> Mul;	//children node json
	Mul.push_back(_LHS->to_json());
	Mul.push_back(_RHS->to_json());
	return DumpJson("Multiplication", Mul);
}

std::string ast::ModuloAST::to_json() const{
	std::vector<std::string> Mod;	//children node json
	Mod.push_back(_LHS->to_json());
	Mod.push_back(_RHS->to_json());
	return DumpJson("Modulo", Mod);
}

std::string ast::AddAST::to_json() const{
	std::vector<std::string> Add;	//children node json
	Add.push_back(_LHS->to_json());
	Add.push_back(_RHS->to_json());
	return DumpJson("Addition", Add);
}

std::string ast::SubAST::to_json() const{
	std::vector<std::string> Sub;	//children node json
	Sub.push_back(_LHS->to_json());
	Sub.push_back(_RHS->to_json());
	return DumpJson("Subtraction", Sub);
}

std::string ast::LeftShiftAST::to_json() const{
	std::vector<std::string> LeftShift;	//children node json
	LeftShift.push_back(_LHS->to_json());
	LeftShift.push_back(_RHS->to_json());
	return DumpJson("LeftShift", LeftShift);
}

std::string ast::RightShiftAST::to_json() const{
	std::vector<std::string> RightShift;	//children node json
	RightShift.push_back(_LHS->to_json());
	RightShift.push_back(_RHS->to_json());
	return DumpJson("RightShift", RightShift);
}

std::string ast::LogicGTAST::to_json() const{
	std::vector<std::string> LogicGT;	//children node json
	LogicGT.push_back(_LHS->to_json());
	LogicGT.push_back(_RHS->to_json());
	return DumpJson("LogicGT", LogicGT);
}

std::string ast::LogicGEAST::to_json() const{
	std::vector<std::string> LogicGE;	//children node json
	LogicGE.push_back(_LHS->to_json());
	LogicGE.push_back(_RHS->to_json());
	return DumpJson("LogicGE", LogicGE);
}

std::string ast::LogicLTAST::to_json() const{
	std::vector<std::string> LogicLT;	//children node json
	LogicLT.push_back(_LHS->to_json());
	LogicLT.push_back(_RHS->to_json());
	return DumpJson("LogicLT", LogicLT);
}

std::string ast::LogicLEAST::to_json() const{
	std::vector<std::string> LogicLE;	//children node json
	LogicLE.push_back(_LHS->to_json());
	LogicLE.push_back(_RHS->to_json());
	return DumpJson("LogicLE", LogicLE);
}

std::string ast::LogicEQAST::to_json() const{
	std::vector<std::string> LogicEQ;	//children node json
	LogicEQ.push_back(_LHS->to_json());
	LogicEQ.push_back(_RHS->to_json());
	return DumpJson("LogicEQ", LogicEQ);
}

std::string ast::LogicNEQAST::to_json() const{
	std::vector<std::string> LogicNEQ;	//children node json
	LogicNEQ.push_back(_LHS->to_json());
	LogicNEQ.push_back(_RHS->to_json());
	return DumpJson("LogicNEQ", LogicNEQ);
}

std::string ast::LogicANDAST::to_json() const{
	std::vector<std::string> LogicAND;	//children node json
	LogicAND.push_back(_LHS->to_json());
	LogicAND.push_back(_RHS->to_json());
	return DumpJson("LogicAND", LogicAND);
}

std::string ast::LogicORAST::to_json() const{
	std::vector<std::string> LogicOR;	//children node json
	LogicOR.push_back(_LHS->to_json());
	LogicOR.push_back(_RHS->to_json());
	return DumpJson("LogicOR", LogicOR);
}

std::string ast::DirectAssignAST::to_json() const{
	std::vector<std::string> DirectAssign;	//children node json
	DirectAssign.push_back(_LHS->to_json());
	DirectAssign.push_back(_RHS->to_json());
	return DumpJson("DirectAssign", DirectAssign);
}

std::string ast::DivAssignAST::to_json() const{
	std::vector<std::string> DivAssign;	//children node json
	DivAssign.push_back(_LHS->to_json());
	DivAssign.push_back(_RHS->to_json());
	return DumpJson("DivAssign", DivAssign);
}

std::string ast::MulAssignAST::to_json() const{
	std::vector<std::string> MulAssign;	//children node json
	MulAssign.push_back(_LHS->to_json());
	MulAssign.push_back(_RHS->to_json());
	return DumpJson("MulAssign", MulAssign);
}

std::string ast::ModAssignAST::to_json() const{
	std::vector<std::string> ModAssign;	//children node json
	ModAssign.push_back(_LHS->to_json());
	ModAssign.push_back(_RHS->to_json());
	return DumpJson("ModAssign", ModAssign);
}

std::string ast::AddAssignAST::to_json() const{
	std::vector<std::string> AddAssign;	//children node json
	AddAssign.push_back(_LHS->to_json());
	AddAssign.push_back(_RHS->to_json());
	return DumpJson("AddAssign", AddAssign);
}

std::string ast::SubAssignAST::to_json() const{
	std::vector<std::string> SubAssign;	//children node json
	SubAssign.push_back(_LHS->to_json());
	SubAssign.push_back(_RHS->to_json());
	return DumpJson("SubAssign", SubAssign);
}

std::string ast::CommaExprAST::to_json() const{
	std::vector<std::string> CommaExpr;	//children node json
	CommaExpr.push_back(_LHS->to_json());
	CommaExpr.push_back(_RHS->to_json());
	return DumpJson("CommaExpr", CommaExpr);
}

std::string ast::VariableAST::to_json() const{
	std::vector<std::string> Variable;	//children node json
	Variable.push_back(DumpJson(_Name));
	return DumpJson("Variable", Variable);
}

std::string ast::GlobalStringAST::to_json() const{
	std::vector<std::string> GlobolSTR;	//children node json
	GlobolSTR.push_back(DumpJson("", {"\"" + strip(_Content) + "\""}));
	return DumpJson("Global String", GlobolSTR);
}

std::string ast::ConstantAST::to_json() const{
	std::vector<std::string> Const;	//children node json
	switch (_Type)
	{
	case BuiltInTypeAST::BuiltinType::_bool_:
		if(_Bool) return DumpJson("Constant", {DumpJson("True")});
		else return DumpJson("Constant", {DumpJson("False")});
		break;
	case BuiltInTypeAST::BuiltinType::_int_:
	case BuiltInTypeAST::BuiltinType::_long_:
		return DumpJson("Constant", {DumpJson(std::to_string(_Integer))});
		break;
	case BuiltInTypeAST::BuiltinType::_char_:
		return DumpJson("Constant",  {DumpJson("\'" + strip(std::string(1, _Character)) + "\'")});
		break;
	case BuiltInTypeAST::BuiltinType::_float_:
	case BuiltInTypeAST::BuiltinType::_double_:
		return DumpJson("Constant", {DumpJson(std::to_string(_Real))});
		break; 
	default:
		break;
	}
	return DumpJson("UnknownType", {DumpJson("error")});
}
