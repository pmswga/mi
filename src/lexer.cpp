#include "lexer.h"

Lexer::Lexer()
{


}

bool Lexer::parseEqual(string input)
{
    return input == "=";
}


bool Lexer::parseMul(string input)
{
    return input == "*";
}

bool Lexer::parseDivSlash(string input)
{
    return input == "/";
}


bool Lexer::parseRationalVar(string input)
{
    std::regex _regex("R[0-9]+",
                          std::regex_constants::ECMAScript);

    return std::regex_search(input, _regex);
}

bool Lexer::parseRationalValue(string input)
{
    std::regex _regex("[0-9]+/[0-9]+",
                          std::regex_constants::ECMAScript);

    return std::regex_search(input, _regex);
}

bool Lexer::parseVectorVar(string input)
{
    std::regex _regex("V[0-9]+",
                          std::regex_constants::ECMAScript);

    return std::regex_search(input, _regex);
}

bool Lexer::parseVectorValue(string input)
{
    std::regex _regex("[ [0-9]+]",
                          std::regex_constants::ECMAScript);

    return std::regex_search(input, _regex);
}


bool Lexer::parseMatrixVar(string input)
{
    std::regex _regex("M[0-9]+",
                          std::regex_constants::ECMAScript);

    return std::regex_search(input, _regex);
}

TokenList* Lexer::parse(string input)
{
    if (!input.empty()) {
        string token = "";

        for (auto c : input) {
            token += c;

            token = std::regex_replace(token, std::regex( "^\\s+" ), "");

            if (parseRationalVar(token)) {
                tokens.push_back(new Token(TokenType::RATIONAL_VAR, token));
                token.clear();
            }

            if (parseVectorVar(token)) {
                tokens.push_back(new Token(TokenType::VECTOR_VAR, token));
                token.clear();
            }

            if (parseMatrixVar(token)) {
                tokens.push_back(new Token(TokenType::MATRIX_VAR, token));
                token.clear();
            }


            if (parseEqual(token)) {
                tokens.push_back(new Token(TokenType::EQUAL, token));
                token.clear();
            }

            if (parseRationalValue(token)) {
                tokens.push_back(new Token(TokenType::RATIONAL_VALUE, token));
                token.clear();
            }

            if (parseVectorValue(token)) {
                tokens.push_back(new Token(TokenType::VECTOR_VALUE, token));
                token.clear();
            }

            if (parseMul(token)) {
                tokens.push_back(new Token(TokenType::MUL, token));
                token.clear();
            }

        }

        return &tokens;
    }

    return nullptr;
}

