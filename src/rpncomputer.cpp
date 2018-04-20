#include "rpncomputer.h"
#include "token.h"
#include <deque>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int rpncomputer::evaluate(deque<Token> infix) {
    stack<Token> st;

    // for each token in the RPN expression
    for(auto token: infix) {
        // if the token is a number push it to top of stack
        if(token.type == Token::Type::Number) {
            st.push(token);
        // if the token is an operator
        } else if(token.type == Token::Type::Operator) {
            // get the top two values and pop them off the stack
            int a = st.top().value;
            st.pop();
            int b = st.top().value;
            st.pop();

            // stores the result of this operation
            int res;
            if(token.str == "^") {
                res = a^b;
            }
            else if (token.str == "*") {
                res = a * b;
            }
            else if (token.str == "/") {
                res = a / b;
            }
            else if (token.str == "+") {
                res = a + b;
            }
            else if (token.str == "-") {
                res = a - b;
            }
            // push the result back onto the stack
            st.push(Token(Token::Type::Number,res, to_string(res)));
        }

    }
    return st.top().value;
}