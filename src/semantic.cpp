#include "semantic.h"

/*******************************************************************/
/*********      Helper functions in semantic analysis      *********/
/*******************************************************************/

// 这几个函数我还正还写...

// Note that always add in the front symbol table. Any problem?
bool AddFunction(std::string funcName, llvm::Function* func) {
    if(SymbolTables.size() == 0)
        return false;
    
    auto bottom = *(SymbolTables.front());
    auto iter = bottom.find(funcName);
    if(iter != bottom.end()) {
        return false;
    }
    bottom[funcName] = Symbol(func);

    return true;
}


llvm::AllocaInst* CreateEntryBlockAlloca(llvm::Function* func, std::string varName, llvm::Type* varType) {
	llvm::IRBuilder<> TmpB(&func->getEntryBlock(), func->getEntryBlock().begin());
	return TmpB.CreateAlloca(varType, nullptr, varName);
}

/*******************************************************************/
/************      Semantic analysis in AST nodes      *************/
/*******************************************************************/

// 可以把原来ast.cpp中逻辑比较复杂的部分抽出来成函数写到这里，并在ast.h里面增加相关成员函数

void ast::FuncDeclAST::checkParams(std::vector<llvm::Type*> &paraTypes) {
    for(auto &parameter : *arg_list) {
        llvm::Type* _llvmType = parameter->para_type->getLlvmType();
        if(!_llvmType) {
            throw std::logic_error("Unknown type" + func_name);
            return ;
        }
        if(_llvmType->isVoidTy() && (*arg_list).size() != 1) {
            throw std::logic_error("Invalid void in function " + func_name);
            return ;
        }
        else if(_llvmType->isVoidTy())
            break;
        if(_llvmType->isArrayTy())
            _llvmType = _llvmType->getArrayElementType()->getPointerTo();
        
        paraTypes.push_back(_llvmType);
    }
}
