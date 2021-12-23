#include "type.h"

Type::Type(string var_name) : var_name(var_name)
{

}

string Type::getVarName()
{
    return this->var_name;
}

void Type::setVarName(string var_name)
{
    this->var_name = var_name;
}
