#ifndef ENV_H
#define ENV_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "types/rational_type.h"
#include "types/vector_type.h"

#include "parser.h"

using namespace std;

class Env
{
    map<string, RationalType*> r_vars;
    map<string, VectorType*> v_vars;


    bool isRationalVarExists(string var_name);
    bool isVectorVarExists(string var_name);

public:
    Env();

    void addVar(string var_name, RationalType* var_type);
    void addVar(string var_name, VectorType* var_type);

    RationalType* getRationalVar(string var_name);
    VectorType* getVectorVar(string var_name);

    void exec(Node *st);
};


#endif // ENV_H
