#include "math-lexer.h"
#include "util.h"
#include "token.h"
#include <deque>

using namespace std;

Lexer::Lexer(string source) {
    m_source = source;
    m_sourceLength = source.size();
    m_cursor = 0;

    readNextChar();
}

bool Lexer::isEOF() {
    return m_cursor > m_sourceLength;
}

/**
 * Reads next char advancing cursor.
 */
void Lexer::readNextChar() {
    skipWhiteSpaces();

    if (isEOF()) {
        return;
    }

    m_currentChar = m_source[m_cursor++];
}

/**
 * Reads next token: a number or a symbol.
 */
Token Lexer::readNextToken() {
    if (isdigit(m_currentChar))
        return readNumber();

    return readSymbol();
}

/**
 * Reds a number containing digits.
 */
Token Lexer::readNumber() {
    string number;

    while (isdigit(m_currentChar)) {
        number += m_currentChar;
        readNextChar();
    }
    Token t(Token::Type::Number, number, -1, false);
    return t;
}

/**
 * Reads a symbol (operator or grouping).
 */
Token Lexer::readSymbol() {
    // check for valid symbols
    string t(1, m_currentChar);
    if(util::is_operator(t)) {
        string symbol(1, m_currentChar);
        readNextChar();
        return util::create_token(symbol);
    }
    return Token(Token::Type::Unknown, "");
    
}

void Lexer::skipWhiteSpaces() {
    while (isspace(m_source[m_cursor]))
        m_cursor++;
}

/**
* Tokenizes a source expression, returns
* a deque with the tokens.
*/
deque<Token> Lexer::tokenize(string source) {
    deque<Token> tokens;
    Lexer lexer(source);
    do {
        Token token = lexer.readNextToken();
        
        tokens.push_back(token);
    } while (!lexer.isEOF());
    return tokens;
}