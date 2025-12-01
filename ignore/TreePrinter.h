#pragma once
#include <antlr4-runtime.h>
#include <iostream>
#include <string>

inline void printTree(antlr4::tree::ParseTree *node, const std::string &indent = "") {
    using namespace antlr4;
    if (!node) return;

    std::cout << indent << node->toString() << "\n";

    for (auto *child : node->children) {
        printTree(child, indent + "  ");
    }
}
