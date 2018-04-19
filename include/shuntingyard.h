#pragma once
#include <queue>
#include <stack>
#include "token.h"

class shuntingyard {
private:
    std::queue<string> output_queue;
    std::stack<string> operator_stack;
public:
    std::string postfix(std::string infix);
};