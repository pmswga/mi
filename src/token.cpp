#include "token.h"

Token::Token(TokenType token_type, string token_value)
    : token_type(token_type), token_value(token_value)
{

}

TokenType Token::type()
{
    return this->token_type;
}

string Token::value()
{
    return this->token_value;
}
