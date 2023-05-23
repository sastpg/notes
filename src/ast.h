/**
 * Class definition of all AST nodes
 * version 0.1
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
// llvm
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Verifier.h>

namespace ast {
    /*************************************************************/
    /*********      Class declarations of AST nodes      *********/
    /*************************************************************/

    /** 什么时候用 vector: 1. 包含自己到自己的左递归 
        2. 最终推导出来的产生式有唯一的terminal和唯一的的non-terminal **/
    /** 如果有多个terminal或non-terminal，那么用一个 class 表示 **/

	#pragma region ClassDecl
    /** Base **/
    class BaseAST;
    class ProgramAST;
    class StmtAST;
    class ExprAST;
    class DeclAST;
    class VarTypeAST;
    /** Declarations **/
    typedef std::vector<DeclAST*> DeclsAST;
    /** Function declaration **/
    class FuncDeclAST;
    class ArgAST;
    typedef std::vector<ArgAST*> ArgsAST;  // without arg '...'
    class ArgListAST;  // contain '...'
    class FuncBodyAST;
    /** Variable declaration **/
    class VarDeclAST;
    class VarInitAST;
    typedef std::vector<VarInitAST*> VarListAST;
    /** Type declaration **/
    class BuiltInTypeAST;
    class DefinedTypeAST;
    class ArrayTypeAST;
    class PointerTypeAST;
    class StructTypeAST;
    class FieldDeclAST;
    typedef std::vector<FieldDeclAST*> FieldDeclsAST;
    typedef std::vector<std::string> MemListsAST;
    /** Statement **/
    typedef std::vector<StmtAST*> StmtsAST;
    class IfStmtAST;
    class ForStmtAST;
    class WhileStmtAST;
    class SwitchStmtAST;
    class CaseStmAST;
    typedef std::vector<CaseStmAST*> CaseList;
    class BreakStmtAST;
    class ContinueStmtAST;
    class ReturnStmtAST;
    class BlockAST;
    /** Expression **/
    typedef std::vector<ExprAST*> ExprList;
    class SubscriptAST;
    class SizeOfAST;
    class FunctionCallAST;
	class StructReferenceAST;
    class StructDereferenceAST;
    class UnaryPlusAST;
    class UnaryMinusAST;
    class TypeCastAST;
    class PrefixIncAST;
    class PostfixIncAST;
    class PrefixDecAST;
    class PostfixDecAST;
    class IndirectionAST;
    class AddressOfAST;
    class LogicNotAST;
    class BitwiseNotAST;
    class DivAST;
    class MulAST;
    class ModuloAST;
    class AddAST;
    class SubAST;
    class LeftShiftAST;
    class RightShiftAST;
    class LogicGTAST;
    class LogicGEAST;
    class LogicLTAST;
    class LogicLEAST;
    class LogicEQAST;
    class LogicNEQAST;
    class LogicANDAST;
    class LogicORAST;
    class DirectAssignAST;
    class DivAssignAST;
    class MulAssignAST;
    class ModAssignAST;
    class AddAssignAST;
    class SubAssignAST;
    class CommaExprAST;
    class VariableAST;
    class ConstantAST;
    class GlobalStringAST;
	#pragma endregion ClassDecl

    /*************************************************************/
    /**********      Class definitions of AST nodes      *********/
    /*************************************************************/

    // Base class for all AST 
    class BaseAST {
    public:
        BaseAST() {}
        virtual ~BaseAST() = default;
        /** Convert node expression to json for visualization **/
        virtual std::string to_json() const = 0;
		/** Generate IR Code **/
		virtual llvm::Value* codegen() = 0;
    };
    
    // ProgramAST
    class ProgramAST : public BaseAST {
    public:
        DeclsAST* decls;
        ProgramAST(DeclsAST* decls) : decls(decls) {}
        std::string to_json() const;
		llvm::Value* codegen();
        ~ProgramAST() {}
    };

    // StmtAST
    class StmtAST : public BaseAST {
    public:
        StmtAST() {}
        virtual std::string to_json() const = 0;
		virtual llvm::Value* codegen() = 0;
        ~StmtAST() {}
    };

    // ExprAST
    class ExprAST : public StmtAST {
	public:
		ExprAST() {}
		// virtual llvm::Value* CodeGenPtr(CodeGenerator& __Generator) = 0;
		virtual std::string to_json() const = 0;
		virtual llvm::Value* codegen() = 0;
        ~ExprAST() {}
	};

    // DeclAST
    class DeclAST : public StmtAST {
    public:
        DeclAST() {}
        virtual std::string to_json() const = 0;
		virtual llvm::Value* codegen() = 0;
        ~DeclAST() {}
    };

    // VarTypeAST
    class VarTypeAST : public BaseAST {
    public:
        bool is_const;
		llvm::Type *llvmType;

        VarTypeAST() : is_const(false) {}
        VarTypeAST(bool is_const) : is_const(is_const), llvmType(nullptr) {}
        virtual std::string to_json() const = 0;
        void set_const();
        /**
         * 1: Built in type
         * 2: Defined type
         * 3. Array type
         * 4. Pointer type
         * 5. Struct type
        */
        virtual int get_type() const = 0;
		virtual llvm::Type* getLlvmType() = 0;
		llvm::Value* codegen() { return nullptr; }
        ~VarTypeAST() {}
    };

    // FuncDeclAST <-- DeclsAST
    class FuncDeclAST : public DeclAST {
    public:
        VarTypeAST *return_type;
        std::string func_name;
        ArgListAST *arg_list;
        FuncBodyAST *fun_body;

        FuncDeclAST(VarTypeAST *return_type, std::string& func_name, ArgListAST *arg_list, FuncBodyAST *fun_body = nullptr) :
            return_type(return_type), func_name(func_name), arg_list(arg_list), fun_body(fun_body){}
        std::string to_json() const;
		/** Semantic functions **/
		void checkParams(std::vector<llvm::Type*> &paraTypes);
		bool checkDuplicate(llvm::Function* func);
		llvm::Value* codegen();
        ~FuncDeclAST() {}
    };

    // ArgAST
    class ArgAST : public BaseAST {
    public:
        VarTypeAST *para_type;
        std::string var_name;

        ArgAST(VarTypeAST *para_type, std::string var_name = "") :
        para_type(para_type), var_name(var_name) {}
        std::string to_json() const;
        ~ArgAST() {}
    };

    // ArgListAST
    class ArgListAST: public ArgsAST, public BaseAST {
    public:
		bool with_dot;

        ArgListAST() {}
		void has_dot() { with_dot = true; }
        std::string to_json() const;
        ~ArgListAST() {}
    };

    // FuncBodyAST
    class FuncBodyAST : public BaseAST {
    public:
        StmtsAST *stmts;

        FuncBodyAST(StmtsAST *stmts) : stmts(stmts) {}
        std::string to_json() const;
        ~FuncBodyAST() {}
    };

    // VarDeclAST
    class VarDeclAST : public DeclAST {
    public:
        VarTypeAST *var_type;
        VarListAST *var_list;

        VarDeclAST(VarTypeAST *var_type, VarListAST *var_list) :
        var_type(var_type), var_list(var_list) {}
        std::string to_json() const;
        ~VarDeclAST() {}
    };

    // VarInitAST
    class VarInitAST : public BaseAST {
    public:
        std::string var_name;
        ExprAST *expr;

        VarInitAST(std::string var_name, ExprAST *expr = nullptr) :
        var_name(var_name), expr(expr) {}
        std::string to_json() const;
        ~VarInitAST() {}
    };

    // BuiltInTypeAST
    class BuiltInTypeAST : public VarTypeAST {
    public:
        enum BuiltinType {
            _bool_, _int_, _long_, _char_, _float_, _double_, _void_
        };
        BuiltinType builtin_type;
        BuiltInTypeAST(BuiltinType builtin_type) : builtin_type(builtin_type) {}
        std::string to_json() const;
        int get_type() const { return 1; }
		llvm::Type* getLlvmTy();
        ~BuiltInTypeAST() {}
    };

    // DefinedTypeAST
    class DefinedTypeAST : public VarTypeAST {
    public:
        std::string id;

        DefinedTypeAST(std::string id) : id(id) {}
        std::string to_json() const;
        int get_type() const { return 2; }
        ~DefinedTypeAST() {}
    };

    // ArrayTypeAST
    class ArrayTypeAST : public VarTypeAST {
    public:
        VarTypeAST *var_type;
        size_t ele_num;

        ArrayTypeAST(VarTypeAST *var_type, size_t ele_num = 0) :
        var_type(var_type), ele_num(ele_num) {}
        std::string to_json() const;
        int get_type() const { return 3; }
        ~ArrayTypeAST() {}
    };

    // PointerTypeAST
    class PointerTypeAST : public VarTypeAST {
    public:
        VarTypeAST *ptr_type;

        PointerTypeAST(VarTypeAST *ptr_type) : ptr_type(ptr_type) {}
        std::string to_json() const;
        int get_type() const { return 4; }
        ~PointerTypeAST() {}
    };

    // StructTypeAST
    class StructTypeAST : public VarTypeAST {
    public:
        FieldDeclsAST *struct_body;

        StructTypeAST(FieldDeclsAST *struct_body) : struct_body(struct_body) {}
        std::string to_json() const;
        int get_type() const { return 5; }
        ~StructTypeAST() {}
    };

    // FieldDeclAST
    class FieldDeclAST : public DeclAST {
    public:
        VarTypeAST *var_type;
        MemListsAST *var_list;

        FieldDeclAST(VarTypeAST *var_type, MemListsAST *var_list) :
        var_type(var_type), var_list(var_list) {}
        std::string to_json() const;
        ~FieldDeclAST() {}
    };

    // IfStmtAST
    class IfStmtAST : public StmtAST {
    public:
        ExprAST *conditions;
        StmtAST *branch1;
        StmtAST *branch2;

        IfStmtAST(ExprAST *conditions, StmtAST *branch1, StmtAST *branch2 = nullptr) :
        conditions(conditions), branch1(branch1), branch2(branch2) {}
        std::string to_json() const;
        ~IfStmtAST() {}
    };

    // ForStmtAST
    class ForStmtAST : public StmtAST {
    public:
        StmtAST *init;
        ExprAST *condition;
        ExprAST *operation;
        StmtAST *body;

        ForStmtAST(StmtAST *init, ExprAST *condition, ExprAST *operation, StmtAST *body) :
        init(init), condition(condition), operation(operation), body(body) {}
        std::string to_json() const;
        ~ForStmtAST() {}
    };

    // WhileStmtAST
    class WhileStmtAST : public StmtAST {
    public:
        ExprAST *condition;
        StmtAST *body;

        WhileStmtAST(ExprAST *condition, StmtAST *body) :
        condition(condition), body(body) {}
        std::string to_json() const;
        ~WhileStmtAST() {}
    };

    // SwitchStmtAST
    class SwitchStmtAST : public StmtAST {
    public:
        ExprAST *identifier;
        CaseList *case_list;

        SwitchStmtAST(ExprAST *identifier, CaseList *case_list) :
        identifier(identifier), case_list(case_list) {}
        std::string to_json() const;
        ~SwitchStmtAST() {}
    };

    // CaseStmAST
    class CaseStmAST : public StmtAST {
    public:
        ExprAST *expr;
        StmtsAST *stmt;

        CaseStmAST(ExprAST *expr, StmtsAST *stmt) : expr(expr), stmt(stmt) {}
        std::string to_json() const;
        ~CaseStmAST() {}
    };

    // BreakStmtAST
    class BreakStmtAST : public StmtAST {
    public:
        BreakStmtAST() {}
        std::string to_json() const;
        ~BreakStmtAST() {}
    };
    
    // ContinueStmtAST
    class ContinueStmtAST : public StmtAST {
    public:
        ContinueStmtAST() {}
        std::string to_json() const;
        ~ContinueStmtAST() {}
    };

    // ReturnStmtAST
    class ReturnStmtAST : public StmtAST {
    public:
        ExprAST *ret_val;

        ReturnStmtAST(ExprAST *ret_val = nullptr) : ret_val(ret_val) {}
        std::string to_json() const;
        ~ReturnStmtAST() {}
    };

    // BlockAST
    class BlockAST : public StmtAST {
    public:
        StmtsAST *stmts;

        BlockAST(StmtsAST *stmts) : stmts(stmts) {}
        std::string to_json() const;
        ~BlockAST() {}
    };

    // SubscriptAST
	class SubscriptAST : public ExprAST {
	public:
		ExprAST* _Ary;
        ExprAST* _Idx;
		SubscriptAST(ExprAST* __Ary, ExprAST* __Idx) : _Ary(__Ary), _Idx(__Idx) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
        ~SubscriptAST(void) {}
	};
	
	// SizeOfAST
	class SizeOfAST : public ExprAST {
	public:
		ExprAST* _Arg1;
		VarTypeAST* _Arg2;
		std::string _Arg3;
		SizeOfAST(ExprAST* __Arg1) {
			_Arg1 = __Arg1;
		}
		SizeOfAST(VarTypeAST* __Arg2) {
			_Arg2 = __Arg2;
		}
		SizeOfAST(const std::string& __Arg3) {
			_Arg3 = __Arg3;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
        ~SizeOfAST(void) {}
	};

	// FunctionCallAST
	class FunctionCallAST : public ExprAST {
	public:
		std::string _Func;
		ExprList* _ArgL;
		FunctionCallAST(const std::string& __Func, ExprList* __ArgL) {
			_Func = __Func;
			_ArgL = __ArgL;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~FunctionCallAST(void) {}
		std::string to_json() const;
	};

	class StructReferenceAST : public ExprAST {
	public:
		ExprAST* _Struct;
		std::string _Mem;
		StructReferenceAST(ExprAST* __Struct, const std::string& __Mem) {
			_Struct = __Struct;
			_Mem = __Mem;
		}	
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~StructReferenceAST(void) {}
		std::string to_json() const;
	};

	class StructDereferenceAST : public ExprAST {
	public:
		ExprAST* _StructPtr;
		std::string _Mem;
		StructDereferenceAST(ExprAST* __StructPtr, const std::string& __Mem) {
			_StructPtr = __StructPtr;
			_Mem = __Mem;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~StructDereferenceAST(void) {}
		std::string to_json() const;
	};

	class UnaryPlusAST : public ExprAST {
	public:
		ExprAST* _Op;
		UnaryPlusAST(ExprAST* __Op) {
			_Op = __Op;
		}
		~UnaryPlusAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class UnaryMinusAST : public ExprAST {
	public:
		ExprAST* _Op;
		UnaryMinusAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
		~UnaryMinusAST(void) {}
	};

	class TypeCastAST : public ExprAST {
	public:
		VarTypeAST* _VarType;
		ExprAST* _Op;
		TypeCastAST(VarTypeAST* __VarType, ExprAST* __Op) {
			_VarType = __VarType;
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
		~TypeCastAST(void) {}
	};

	class PrefixIncAST : public ExprAST {
	public:
		ExprAST* _Op;
		PrefixIncAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~PrefixIncAST(void) {}
		std::string to_json() const;
	};

	class PostfixIncAST : public ExprAST {
	public:
		ExprAST* _Op;
		PostfixIncAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~PostfixIncAST(void) {}
		std::string to_json() const;
	};

	class PrefixDecAST : public ExprAST {
	public:
		ExprAST* _Op;
		PrefixDecAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~PrefixDecAST(void) {}
		std::string to_json() const;
	};

	class PostfixDecAST : public ExprAST {
	public:
		ExprAST* _Op;
		PostfixDecAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~PostfixDecAST(void) {}
		std::string to_json() const;
	};

	class IndirectionAST : public ExprAST {
	public:
		ExprAST* _Op;
		IndirectionAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~IndirectionAST(void) {}
		std::string to_json() const;
	};

	class AddressOfAST : public ExprAST {
	public:
		ExprAST* _Op;
		AddressOfAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~AddressOfAST(void) {}
		std::string to_json() const;
	};

	class LogicNotAST : public ExprAST {
	public:
		ExprAST* _Op;
		LogicNotAST(ExprAST* __Op) {
			_Op = __Op;
		}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicNotAST(void) {}
		std::string to_json() const;
	};

	class DivAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		DivAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~DivAST(void) {}
		std::string to_json() const;
	};

	class MulAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		MulAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~MulAST(void) {}
		std::string to_json() const;
	};

	class ModuloAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		ModuloAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~ModuloAST(void) {}
		std::string to_json() const;
	};

	class AddAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		AddAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~AddAST(void) {}
		std::string to_json() const;
	};

	class SubAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		SubAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~SubAST(void) {}
		std::string to_json() const;
	};

	class LeftShiftAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LeftShiftAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LeftShiftAST(void) {}
		std::string to_json() const;
	};

	class RightShiftAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		RightShiftAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~RightShiftAST(void) {}
		std::string to_json() const;
	};

	class LogicGTAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicGTAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicGTAST(void) {}
		std::string to_json() const;
	};

	class LogicGEAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicGEAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicGEAST(void) {}
		std::string to_json() const;
	};

	class LogicLTAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicLTAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicLTAST(void) {}
		std::string to_json() const;
	};

	class LogicLEAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicLEAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicLEAST(void) {}
		std::string to_json() const;
	};

	class LogicEQAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicEQAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicEQAST(void) {}
		std::string to_json() const;
	};

	class LogicNEQAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicNEQAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicNEQAST(void) {}
		std::string to_json() const;
	};

	class LogicANDAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicANDAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~LogicANDAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class LogicORAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		LogicORAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		~LogicORAST(void) {}
		std::string to_json() const;
	};

	class DirectAssignAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		DirectAssignAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~DirectAssignAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class DivAssignAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		DivAssignAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~DivAssignAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class MulAssignAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		MulAssignAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~MulAssignAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class ModAssignAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		ModAssignAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~ModAssignAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class AddAssignAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		AddAssignAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~AddAssignAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class SubAssignAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		SubAssignAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~SubAssignAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class CommaExprAST : public ExprAST {
	public:
		ExprAST* _LHS;
		ExprAST* _RHS;
		CommaExprAST(ExprAST* __LHS, ExprAST* __RHS) : _LHS(__LHS), _RHS(__RHS) {}
		~CommaExprAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class VariableAST : public ExprAST {
	public:
		std::string _Name;
		VariableAST(const std::string& __Name) {
			_Name = __Name;
		}
		~VariableAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class ConstantAST : public ExprAST {
	public:
		BuiltInTypeAST::BuiltinType _Type;
		bool _Bool;
		char _Character;
		int _Integer;
		double _Real;
		ConstantAST(bool __Bool) {
			_Type = BuiltInTypeAST::BuiltinType::_bool_;
			_Bool = __Bool;
		}
		ConstantAST(char __Character) {
			_Type = BuiltInTypeAST::BuiltinType::_char_;
			_Character = __Character;
		}
		ConstantAST(int __Integer) {
			_Type = BuiltInTypeAST::BuiltinType::_int_;
			_Integer = __Integer;
		}
		ConstantAST(double __Real) {
			_Type = BuiltInTypeAST::BuiltinType::_double_;
			_Real = __Real;
		}
		~ConstantAST() {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};

	class GlobalStringAST : public ConstantAST {
	public:
		std::string _Content;
		GlobalStringAST(const std::string& __Content) : ConstantAST(0) {
			_Content = __Content;
		}
		~GlobalStringAST(void) {}
		// llvm::Value* codegen(CodeGenerator& __Generator);
		// llvm::Value* CodeGenPtr(CodeGenerator& __Generator);
		std::string to_json() const;
	};
    
}
