#include "math-lexer.h"

void printTokens(std::vector<string> tokens) {
    std::cout << "Tokens: [";
    unsigned int size = tokens.size();
    for (unsigned int k = 0; k < size; k++) {
        std::cout << '"' << tokens[k] << '"';
        if (k < size - 1) std::cout << ", ";
    }
    std::cout << "]" << NL << NL;
}

int main()
{
    
    return 0;
}