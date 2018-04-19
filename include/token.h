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
    Token(Type t, int value, const std::string& s, int prec = -1, bool ra = false)
        : type (t), str ( s ), precedence(prec), rightAssociative(ra), value(value)
    {};

    Type type;
    int value;
    std::string str;
    int precedence;
    bool rightAssociative;
};