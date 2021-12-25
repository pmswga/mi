#include "node.h"

Node::Node() : left(nullptr), right(nullptr), expr(nullptr)
{

}

Node::~Node()
{
    delete expr;
}
