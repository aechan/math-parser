#include "math-lexer.h"
#include "syard.h"
#define NL std::endl

using namespace std;
void printTokens(std::vector<string> tokens) {
    cout << "Tokens: [";
    unsigned int size = tokens.size();
    for (unsigned int k = 0; k < size; k++) {
        cout << '"' << tokens[k] << '"';
        if (k < size - 1) cout << ", ";
    }
    cout << "]" << NL << NL;
}

void showExample() {
    string example = "15 * (3 + 17)";
    cout << "Math expression lexer." << NL << NL;
    cout << "Example: " << example << NL;
    vector<string> infix = Lexer::tokenize(example);
    printTokens(infix);
    cout << "Now we postfix it." << NL;
    printTokens(syard::postfix(infix));
}

int main()
{
    showExample();
    return 0;
}