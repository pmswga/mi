#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>
#include <ctype.h>
#include <vector>
#include <regex>

#include "types/rational_type.h"
#include "token.h"


using namespace std;

class Lexer
{
    TokenList tokens;

public:
    Lexer();

    bool parseEqual(string input);
    bool parseMul(string input);
    bool parseDivSlash(string input);

    bool parseRationalVar(string input);
    bool parseRationalValue(string input);

    bool parseVectorVar(string input);
    bool parseVectorValue(string input);

    bool parseMatrixVar(string input);

    TokenList* parse(string input);
};

#endif // LEXER_H
