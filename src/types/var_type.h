#ifndef VAR_TYPE_H
#define VAR_TYPE_H

#include <string>
using namespace std;

class VarType
{
    string var_name;

public:
    VarType(string var_name);

    string name();
    void setVarName(string var_name);
};


#endif // VAR_TYPE_H
