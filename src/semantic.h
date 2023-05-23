/**
 * Semantic Analysis
 * version 0.1
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ast.h"
// llvm
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Verifier.h>

#define FUNCTION 0
#define TYPE 1
#define VALUE 2
#define CONST 3

// 上下文环境，用于管理一组共享的编译器状态和资源
// 包括类型定义、常量、函数、全局变量等等
static llvm::LLVMContext context;
// 构建 LLVM IR 程序
static llvm::IRBuilder<> builder(context);
// 包含了一个程序的所有函数定义、全局变量以及其他相关信息
// 如添加函数、全局变量、指令等
// static llvm::Module *module;
class Generation {
public:
    llvm::Module *module;
    Generation() : module() {}
};

class Symbol {
private:
    int kind;
    llvm::Function *func_kind;
    llvm::Type *type_kind;
    llvm::Value *value_kind;
public:
    Symbol(llvm::Function* func) : func_kind(func), kind(FUNCTION) {}
    Symbol(llvm::Type* type) : type_kind(type), kind(TYPE) {}
    Symbol(llvm::Value* value, bool constant) : value_kind(value) {
        if(constant)
            kind = CONST;
        else
            kind = VALUE;
    }
    
    llvm::Function* getFunc() { return func_kind; }
    llvm::Type* getTy() { return type_kind; }
    llvm::Value* getValue(bool constant) { 
        if(constant && kind != CONST)
            return nullptr;
        return value_kind;
    }
};

typedef std::map<std::string, Symbol> SymbolTable;
std::vector<SymbolTable*> SymbolTables;


/** Semantic functions **/

// Deal with function
llvm::Function* GetCurrentFunction(void);
bool addFunc(std::string , llvm::Function* );
llvm::Function* findFunc(std::string func_name, int &result);

// Deal with type
llvm::Type* findType(std::string Name);
bool addType(std::string Name, llvm::Type* Type);

// Deal with variable
llvm::Value* findVar(std::string Name);
bool addVar(std::string Name, llvm::Value* Variable);
llvm::Value* findConst(std::string Name);

// Deal with structure
ast::StructTypeAST* FindStructType(llvm::StructType* Ty1);
bool AddStructType(llvm::StructType* Ty1, ast::StructTypeAST* Ty2);

// Deal with Symbol table
void pushSymbolTab();
void popSymbolTab();