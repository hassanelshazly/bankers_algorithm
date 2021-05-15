/**
 * 
 * Overloading of arithmetic operators for vectors and matrices
 * 
 */

#ifndef _HELPER_FUNCTIONS_
#define _HELPER_FUNCTIONS_

#include <vector>
#include <iostream>

using namespace std;

bool operator<=(const vector<int> &v1, const vector<int> &v2);

vector<vector<int>> operator-(const vector<vector<int>> &v1,
                              const vector<vector<int>> &v2);

vector<vector<int>> operator+(const vector<vector<int>> &v1,
                              const vector<vector<int>> &v2);

vector<int> operator-(const vector<int> &v1,
                      const vector<int> &v2);

vector<int> operator+(const vector<int> &v1,
                      const vector<int> &v2);

vector<int> &operator+=(vector<int> &v1,
                        const vector<int> &v2);

vector<int> &operator-=(vector<int> &v1,
                        const vector<int> &v2);

vector<int> &print_sequence(const vector<int> &seq, int req = -1);

#endif