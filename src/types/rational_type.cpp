#include "rational_type.h"

RationalType::RationalType(string var_name, double value) : Type(var_name), value(value)
{

}

void RationalType::setValue(double value)
{
    this->value = value;
}
