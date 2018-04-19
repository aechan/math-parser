// by Dmitry Soshnikov <dmitry.soshnikov@gmail.com>
// updated for C++11 by Alec Chan <me@alecchan.io>
// MIT Style License.
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <deque>
#include "token.h"
/**
 * Lexer class for simple math expressions.
 * Recognizes only integer numbers and symbols
 * (operators and grouping).
 */
class Lexer {

private:
    std::string m_source;
    int   m_sourceLength;
    int   m_cursor;
    char  m_currentChar;

    void  readNextChar();
    void  skipWhiteSpaces();
    Token readNumber();
    Token readSymbol();

public:
    Lexer(std::string source);

    bool isEOF();
    Token readNextToken();
    static std::deque<Token> tokenize(std::string);
};