#ifndef NODE_H
#define NODE_H

#include <string>

#include "token.h"

using namespace std;

class Node
{

public:

    string op;
    Token *left;
    Token *right;
    Node *expr;

    Node();

    ~Node();
};



#endif // NODE_H
