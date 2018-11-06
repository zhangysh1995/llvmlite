//
// Created by zhangysh1995 on 11/5/18.
//


#include <string>
#include <llvm/IR/Module.h>
#include "llvm-c/Core.h"
#include "core.h"

// the following is needed for WriteGraph()
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Support/GraphWriter.h"

extern "C" {

void LLVMPY_WriteCallGraph(LLVMModuleRef Fval, const char **OutStr) {
    using namespace llvm;

    Module *m = unwrap(Fval);
    CallGraph cg = CallGraph(*m);
    std::string buffer;
    raw_string_ostream stream(buffer);

    cg.print(stream);
    *OutStr = LLVMPY_CreateString(stream.str().c_str());
}

}