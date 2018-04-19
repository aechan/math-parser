#include "rpncomputer.h"
#include "token.h"
#include <deque>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int rpncomputer::evaluate(deque<Token> infix) {
    stack<Token> st;
    for(auto token: infix) {
        if(token.type == Token::Type::Number) {
            st.push(token);
        } else if(token.type == Token::Type::Operator) {
            int a = stoi(st.top().str);
            st.pop();
            int b = stoi(st.top().str);
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
            st.push(Token(Token::Type::Number, to_string(res)));
        }

    }
}