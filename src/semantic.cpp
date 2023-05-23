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

/*******************************************************************/
/************      Semantic analysis in AST nodes      *************/
/*******************************************************************/

// 可以把原来ast.cpp中逻辑比较复杂的部分抽出来成函数写到这里，并在ast.h里面增加相关成员函数

