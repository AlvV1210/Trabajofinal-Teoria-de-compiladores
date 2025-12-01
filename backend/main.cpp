#include <iostream>
#include <fstream>
#include <string>

#include "antlr4-runtime.h"
#include "../frontend/generated/RecipeLangLexer.h"
#include "../frontend/generated/RecipeLangParser.h"
#include "./RecipeCodegenVisitor.h"

using namespace antlr4;
using namespace std;

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        cerr << "Uso: ./recipec archivo.recipe\n";
        return 1;
    }

    string filename = argv[1];
    ifstream stream(filename);

    if (!stream.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << "\n";
        return 1;
    }

    ANTLRInputStream input(stream);
    RecipeLangLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    RecipeLangParser parser(&tokens);
    tree::ParseTree *tree = parser.program();

    RecipeCodegenVisitor visitor;
    visitor.visit(tree);
    visitor.printIR();

    return 0;
}
