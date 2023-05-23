#include "semantic.h"
#include "ast.h"

// 参考的那份Module改为module,用的时候使用 gen.module
// IRBuilder改为builder, Context改成context

extern Generation gen;

llvm::Value* ast::ProgramAST::codegen() {
    for(auto &x : *decls)
        x->codegen();
    return nullptr;
}

llvm::Value* ast::FuncDeclAST::codegen() {
    // Check parameters types
    std::vector<llvm::Type*> paraTypes;
    for(auto &parameter : *arg_list) {
        llvm::Type* _llvmType = parameter->para_type->getLlvmType();
        if(!_llvmType) {
            throw std::logic_error("Unknown type" + func_name);
            return nullptr;
        }
        if(_llvmType->isVoidTy() && (*arg_list).size() != 1) {
            throw std::logic_error("Invalid void in function " + func_name);
            return nullptr;
        }
        else if(_llvmType->isVoidTy())
            break;
        if(_llvmType->isArrayTy())
            _llvmType = _llvmType->getArrayElementType()->getPointerTo();
        
        paraTypes.push_back(_llvmType);
    }

    // Check return type
    llvm::Type* returnType = return_type->getLlvmType();
    if(returnType->isArrayTy()) {
        throw std::logic_error("Return type in function " + func_name + " is array.");
        return nullptr;
    }
    
    // 创建 LLVM IR 中的函数类型
    llvm::FunctionType* funcType = llvm::FunctionType::get(returnType, paraTypes, arg_list->with_dot);
    llvm::Function* func = llvm::Function::Create(funcType, llvm::GlobalValue::ExternalLinkage, func_name, gen.module);


    if(func->getName() != func_name) {
        func->eraseFromParent();
        func = gen.module->getFunction(func_name);
        if(!func->empty() || !fun_body) {
            throw std::logic_error("Referring function " + func_name);
            return nullptr;
        }
        if(func->getFunctionType() != funcType) {
            throw std::logic_error("Confilict type" + func_name);
            return nullptr;
        }
    }

    if(fun_body) {
        llvm::BasicBlock* newBlock = llvm::BasicBlock::Create(context, "entry", func);
        builder.SetInsertPoint(newBlock);
        pushSymbolTab();

        fun_body->codegen();

        popSymbolTab();
    }
}


//BuiltInTypeAST
llvm::Type* ast::BuiltInTypeAST::getLlvmType() {
    if(!llvmType)
    {
        switch (builtin_type)
        {
        case _bool_:
            llvmType = builder.getInt1Ty();
            break;
        case _int_:
            llvmType = builder.getInt32Ty();
            break;
        case _long_:
            llvmType = builder.getInt64Ty();
            break;
        case _char_:
            llvmType = builder.getInt8Ty();
            break;
        case _float_:
            llvmType = builder.getFloatTy();
            break;
        case _double_:
            llvmType = builder.getDoubleTy();
            break;
        case _void_:
            llvmType = builder.getVoidTy();
            break;
        default:
            break;
        }
    }
    return llvmType;
}


// 上面是我的部分
// 参考的那份Module改为module,用的时候使用 gen.module
// IRBuilder改为builder, Context改成context
