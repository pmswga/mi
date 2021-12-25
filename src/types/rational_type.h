#ifndef RATIONAL_TYPE_H
#define RATIONAL_TYPE_H

#include "var_type.h"

class RationalType : public VarType
{
    double var_value;

public:
    RationalType(string var_name, double var_value);

    double value();
    void setValue(double var_value);

};


#endif // RATIONAL_TYPE_H
