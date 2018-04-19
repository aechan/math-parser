#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <deque>
#include "token.h"

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