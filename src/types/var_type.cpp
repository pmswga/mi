#include "var_type.h"

VarType::VarType(string var_name) : var_name(var_name)
{

}

string VarType::name()
{
    return this->var_name;
}

void VarType::setVarName(string var_name)
{
    this->var_name = var_name;
}
