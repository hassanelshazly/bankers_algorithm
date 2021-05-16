#include "helper_functions.h"

bool operator<=(const vector<int> &v1, const vector<int> &v2)
{
    for (int i = 0; i < v1.size(); i++)
        if (v1[i] > v2[i])
            return false;
    return true;
}

vector<vector<int>> operator-(const vector<vector<int>> &v1,
                              const vector<vector<int>> &v2)
{
    vector<vector<int>> result = v1;
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[i].size(); j++)
            result[i][j] -= v2[i][j];

    return result;
}

vector<vector<int>> operator+(const vector<vector<int>> &v1,
                              const vector<vector<int>> &v2)
{
    vector<vector<int>> result = v1;
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[i].size(); j++)
            result[i][j] += v2[i][j];

    return result;
}

vector<int> operator-(const vector<int> &v1,
                      const vector<int> &v2)
{
    vector<int> result = v1;
    for (int i = 0; i < result.size(); i++)
        result[i] -= v2[i];

    return result;
}

vector<int> operator+(const vector<int> &v1,
                      const vector<int> &v2)
{
    vector<int> result = v1;
    for (int i = 0; i < result.size(); i++)
        result[i] += v2[i];

    return result;
}

vector<int> &operator+=(vector<int> &v1,
                        const vector<int> &v2)
{
    for (int i = 0; i < v1.size(); i++)
        v1[i] += v2[i];

    return v1;
}

vector<int> &operator-=(vector<int> &v1,
                        const vector<int> &v2)
{
    for (int i = 0; i < v1.size(); i++)
        v1[i] -= v2[i];

    return v1;
}

void print_sequence(const vector<int> &seq, int req)
{
    cout << "<";
    if(req >= 0)
        cout << "P" << req << "req, ";
    for (int i = 0; i < seq.size() - 1; i++)
        cout << "P" << seq[i] << ", ";
    cout << "P" << seq.back() << ">\n";
}