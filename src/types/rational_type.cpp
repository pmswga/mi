#include "rational_type.h"

RationalType::RationalType(string var_name, double var_value)
    : VarType(var_name), var_value(var_value)
{

}

double RationalType::value()
{
    return this->var_value;
}

void RationalType::setValue(double var_value)
{
    this->var_value = var_value;
}
