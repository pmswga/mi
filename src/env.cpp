#include "env.h"

Env::Env()
{


}

bool Env::isRationalVarExists(string var_name)
{
    r_vars.find(var_name) != r_vars.end();
}

bool Env::isVectorVarExists(string var_name)
{
    v_vars.find(var_name) != v_vars.end();
}


void Env::addVar(string var_name, RationalType* var_type)
{
    auto v = r_vars.find(var_name);

    if (v == r_vars.end()) {
        r_vars.insert(std::pair<string, RationalType*>(var_name, var_type));
    }
}


void Env::addVar(string var_name, VectorType* var_type)
{
    auto v = v_vars.find(var_name);

    if (v == v_vars.end()) {
        v_vars.insert(std::pair<string, VectorType*>(var_name, var_type));
    }
}

RationalType* Env::getRationalVar(string var_name)
{
    if (!var_name.empty()) {
        if (isRationalVarExists(var_name)) {
            return r_vars.at(var_name);
        }
    }

    return nullptr;
}

VectorType* Env::getVectorVar(string var_name)
{
    if (!var_name.empty()) {
        if (isVectorVarExists(var_name)) {
            return v_vars.at(var_name);
        }
    }

    return nullptr;
}

void Env::exec(Node *st)
{
    if (st) {
        if (st->op == "out") {
            if (st->left->type() == RATIONAL_VAR) {
                RationalType *rt = getRationalVar(st->left->value());

                if (rt) {
                    cout << rt->name() << " = " << rt->value() << endl;
                } else {
                    cerr << "Variable '" << st->left->value() << "' doesn't exist" << endl;
                }
            }

            if (st->left->type() == VECTOR_VAR) {
                VectorType *vt = getVectorVar(st->left->value());

                if (vt) {
                    cout << vt->name() << " = " << "[";

                    int i = 0;
                    for (auto v : vt->data()) {
                        cout << v;

                        if (i+1 < vt->data().size()) {
                            cout << " ";
                        }

                        i++;
                    }

                    cout << "]" << endl;
                } else {
                    cerr << "Variable '" << st->left->value() << "' doesn't exist" << endl;
                }
            }
        }

        if (st->op == "assignment") {

            if (st->left->type() == RATIONAL_VAR && !st->expr) {
                double value = 0., a = 0., b = 0.;
                string r_value = st->right->value();
                int n = r_value.find("/");

                a = atof(r_value.substr(0, n).c_str());
                b = atof(r_value.substr(n+1, r_value.size()-1).c_str());

                value = a / b;

                if (!isRationalVarExists(st->left->value())) {
                    RationalType *rt = new RationalType(st->left->value(), value);
                    addVar(st->left->value(), rt);
                } else {
                    getRationalVar(st->left->value())->setValue(value);
                }
            } else if (st->left->type() == VECTOR_VAR && !st->expr) {
                vector<double> data;
                string value;
                string del = " ";
                string r_value = st->right->value();
                int n = 0;

                r_value.erase(r_value.begin());
                r_value.pop_back();

                while ((n = r_value.find(del)) != std::string::npos) {
                    value = r_value.substr(0, n);
                    data.push_back(atof(value.c_str()));
                    r_value.erase(0, n + del.length());
                }

                if (!r_value.empty()) {
                    data.push_back(atoi(r_value.c_str()));
                }

                if (!isVectorVarExists(st->left->value())) {
                    VectorType *vt = new VectorType(st->left->value(), data);
                    addVar(st->left->value(), vt);
                } else {
                    getVectorVar(st->left->value())->setData(data);
                }
            } else if (st->expr) {
                if (st->left->type() == VECTOR_VAR) {
                    if (st->expr->left->type() == VECTOR_VAR &&
                        st->expr->op == "multiplication" &&
                        st->expr->right->type() == RATIONAL_VAR) {

                        VectorType *vt = getVectorVar(st->expr->left->value());
                        RationalType *rt = getRationalVar(st->expr->right->value());

                        if (vt != nullptr && rt != nullptr) {
                            for (int i = 0; i < vt->data().size(); i++) {
                                vt->data()[i] *= rt->value();
                            }
                        }

                    }
                }
            }
        }

    }
}
