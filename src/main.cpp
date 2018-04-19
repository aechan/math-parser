#include "math-lexer.h"
#include "syard.h"
#include "token.h"
#include <deque>
#define NL std::endl

using namespace std;
void printTokens(std::deque<Token> tokens) {
    cout << "Tokens: [";
    unsigned int size = tokens.size();
    for (unsigned int k = 0; k < size; k++) {
        cout << '"' << tokens[k].str << '"';
        if (k < size - 1) cout << ", ";
    }
    cout << "]" << NL << NL;
}

void runRoutine(string expr) {
    cout << "Your infix expression tokenized:" << NL;
    deque<Token> infix = Lexer::tokenize(expr);
    printTokens(infix);
    cout << "Now we postfix it." << NL;
    printTokens(syard::postfix(infix));
}

void showExample() {
    string example = "15 * (3 + 17)";
    runRoutine(example);
}

int main()
{
    cout << "Math expression lexer." << NL << NL;
    showExample();
    cout << NL << "Now you try" << NL;
    cout << "Enter a simple math expression: ";
    string expr;
    cin >> expr;
    runRoutine(expr);

    return 0;
}