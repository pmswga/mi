#include "vector_type.h"

VectorType::VectorType(string var_name, const vector<double> &var_data)
    : VarType(var_name), var_data(var_data)
{

}

vector<double>& VectorType::data()
{
    return this->var_data;
}


void VectorType::setData(const vector<double> &var_data)
{
    this->var_data = var_data;
}
