#ifndef RATIONAL_TYPE_H
#define RATIONAL_TYPE_H

#include "type.h"

class RationalType : public Type
{
    double value;

public:
    RationalType(string var_name, double value);

    void setValue(double value);

};


#endif // RATIONAL_TYPE_H
