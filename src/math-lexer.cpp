#include "math-lexer.h"
#include "util.h"
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
string Lexer::readNextToken() {
    if (isdigit(m_currentChar))
        return readNumber();

    return readSymbol();
}

/**
 * Reds a number containing digits.
 */
string Lexer::readNumber() {
    string number;

    while (isdigit(m_currentChar)) {
        number += m_currentChar;
        readNextChar();
    }
    return number;
}

/**
 * Reads a symbol (operator or grouping).
 */
string Lexer::readSymbol() {
    // check for valid symbols
    string t(1, m_currentChar);
    if(util::is_operator(t)) {
        string symbol(1, m_currentChar);
        readNextChar();
        return symbol;
    }
    return "";
    
}

void Lexer::skipWhiteSpaces() {
    while (isspace(m_source[m_cursor]))
        m_cursor++;
}

/**
* Tokenizes a source expression, returns
* a vector with the tokens.
*/
std::vector<string> Lexer::tokenize(string source) {
    std::vector<string> tokens;
    Lexer lexer(source);
    do {
        string token = lexer.readNextToken();
        
        tokens.push_back(token);
    } while (!lexer.isEOF());
    return tokens;
}