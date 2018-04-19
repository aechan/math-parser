#include "math-lexer.h"

using namespace std;
// ---------------------------------
// Lexer implementation.
// ---------------------------------


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
    string symbol;
    symbol[0] = m_currentChar;
    readNextChar();
    return symbol;
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
        tokens.push_back(lexer.readNextToken());
    } while (!lexer.isEOF());
    return tokens;
}