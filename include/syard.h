#pragma once
#include <vector>
#include <string>
#include <deque>
#include "token.h"
class syard {
public:
    static std::deque<Token> postfix(std::deque<Token> infix);
};