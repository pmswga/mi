#include "parser.h"


Parser::Parser()
{
    st = new Node();
}

Parser::~Parser()
{

}

Node* Parser::parse(TokenList *tokens)
{
    if (tokens && !tokens->empty()) {
        this->tokens = tokens;

        parseVar();

        if (tokens->empty()) {
            st->op = "out";
            st->right = nullptr;
        } else {
            if (parseSetValue()) {
                st->op = "assignment";
            } else if (parseOp()) {
                st->op = "assignment";
            }
        }


        return st;
    }
}


bool Parser::parseVar()
{
    Token *t = tokens->back();

    if (t->type() != RATIONAL_VAR && t->type() != VECTOR_VAR) {
        return false;
    }

    st->left = t;

    tokens->pop_back();

    return true;
}

bool Parser::parseSetValue()
{
    Token *t = tokens->back();

    if (t->type() != EQUAL) {
        return false;
    }

    tokens->pop_back();

    t = tokens->back();

    if (t->type() != RATIONAL_VALUE && t->type() != VECTOR_VALUE) {
        return false;
    }

    st->right = t;

    tokens->pop_back();

    return true;
}

bool Parser::parseOp()
{
    Token *t = tokens->back();

//    if (t->type() != EQUAL) {
//        return false;
//    }
//
//    tokens->pop_back();
//
//    t = tokens->back();

    if (t->type() != VECTOR_VAR) {
        return false;
    }

    st->expr = new Node();
    st->expr->left = t;

    tokens->pop_back();

    t = tokens->back();

    if (t->type() != MUL) {
        return false;
    }

    st->expr->op = "multiplication";

    tokens->pop_back();

    t = tokens->back();

    if (t->type() != RATIONAL_VAR) {
        return false;
    }

    st->expr->right = t;

    tokens->pop_back();

    return true;
}
