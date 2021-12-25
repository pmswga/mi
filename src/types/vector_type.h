#ifndef VECTOR_TYPE
#define VECTOR_TYPE

#include <vector>

#include "var_type.h"
using namespace std;

class VectorType : public VarType
{
    vector<double> var_data;

public:
    VectorType(string var_name, const vector<double> &var_data);

    vector<double>& data();
    void setData(const vector<double> &var_data);

};

#endif // VECTOR_TYPE
