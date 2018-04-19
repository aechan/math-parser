#include <deque>
#include "token.h"

/**
 * Evaluates expressions given in RPN (reverse polish notation/postfix)
 **/
class rpncomputer {
public:
    static int evaluate(std::deque<Token> postfix);
};