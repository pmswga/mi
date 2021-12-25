#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "node.h"

using namespace std;


class Parser
{
    TokenList *tokens;
    Node *st;

public:
    Parser();
    ~Parser();

    Node* parse(TokenList *tokens);

    bool parseVar();
    bool parseSetValue();
    bool parseOp();

};


#endif // PARSER_H
