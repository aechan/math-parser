#include "util.h"
#include "token.h"
#include <string>
using namespace std;
bool util::is_operator(string token) {
    return (token == "*" ||
        token == "/" ||
        token == "+" ||
        token == "-" ||
        token == "^" ||
        token == "(" ||
        token == ")"
        );
}



bool util::is_number(const string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int util::rank_operator(string op) {
    if(op == "^") return 4;
    if(op == "*") return 3;
    if(op == "/") return 3;
    if(op == "+") return 2;
    if(op == "-") return 2;
    return 0;
}

int util::rank_operator(Token tok) {
    return util::rank_operator(tok.str);
}

Token util::create_token(string token) {
    if(util::is_number(token)) {
        Token t(Token::Type::Number, token);
        return t;
    }
    if(util::is_operator(token)) {
        if(token == "(") {
            Token t(Token::Type::LeftParen, token);
            return t;
        }
        if(token == ")") {
            Token t(Token::Type::RightParen, token);
            return t;
        }
        if(token == "^") {
            Token t(Token::Type::Operator, token, 4, true);
            return t;
        }
        if(token == "*" || token == "/") {
            Token t(Token::Type::Operator, token, 3);
            return t;
        }
        else {
            Token t(Token::Type::Operator, token, 2);
            return t;
        }
    }
}