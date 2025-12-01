#include <iostream>
#include <fstream>

#include <antlr4-runtime.h>
#include "../frontend/generated/RecipeLangLexer.h"
#include "../frontend/generated/RecipeLangParser.h"
#include "./TreePrinter.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>

#include "CodegenVisitor.h"

using namespace antlr4;

int main(int argc, const char **argv) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo.recipe>\n";
        return 1;
    }

    std::ifstream stream(argv[1]);
    if (!stream) {
        std::cerr << "No se pudo abrir el archivo: " << argv[1] << "\n";
        return 1;
    }

    ANTLRInputStream input(stream);
    RecipeLangLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    RecipeLangParser parser(&tokens);

    // Regla raíz de tu gramática:
    // program : recipeStmt statement* EOF ;
    auto *tree = parser.program();

    llvm::LLVMContext context;
    auto module = std::make_unique<llvm::Module>("recipe_module", context);
    llvm::IRBuilder<> builder(context);

    CodegenVisitor visitor(context, module.get(), builder);
    visitor.visit(tree);
    visitor.generateIR();

    // Imprimir IR a stdout
    llvm::outs() << "=== LLVM IR generado ===\n";
    module->print(llvm::outs(), nullptr);

    printTree(tree);

    return 0;
}
