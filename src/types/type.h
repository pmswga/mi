#ifndef TYPE_H
#define TYPE_H

#include <string>
using namespace std;

class Type
{
    string var_name;

public:
    Type(string var_name);

    string getVarName();
    void setVarName(string var_name);
};


#endif // TYPE_H
