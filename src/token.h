#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>
using namespace std;

enum TokenType {
    RATIONAL_VAR,
    RATIONAL_VALUE,
    VECTOR_VAR,
    VECTOR_VALUE,
    MATRIX_VAR,
    MATRIX_VALUE,
    EQUAL,
    MUL,
    DIV_SLASH
};



class Token
{
    TokenType token_type;
    string token_value;

public:
    Token(TokenType token_type, string token_value);

    TokenType type();
    string value();
};


using TokenList = vector<Token*>;

#endif // TOKEN_H
