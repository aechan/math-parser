#pragma once
#include <string>

class Token {
public:
    enum Type {
        Unknown = 0,
        Number,
        Operator,
        LeftParen,
        RightParen,
    };

    Token(Type t, const std::string& s, int prec = -1, bool ra = false)
        : type (t), str ( s ), precedence(prec), rightAssociative(ra)
    {};

    Type type;
    std::string str;
    int precedence;
    bool rightAssociative;
};