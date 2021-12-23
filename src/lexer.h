#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "types/rational_type.h"
#include <iostream>
#include <ctype.h>
using namespace std;

class Lexer
{

public:
    Lexer();

    void parseRationalVar(string input);

    string parseLexem(string input);

};

#endif // LEXER_H
