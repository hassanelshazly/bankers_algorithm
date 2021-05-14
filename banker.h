#ifndef _BANKER_
#define _BANKER_

#include <vector>
#include <iostream>

using namespace std;

int need_matrix(vector<vector<int>> &alloc_m,
                vector<vector<int>> &max_m,
                vector<int> &avail_v);

bool is_safe(const vector<vector<int>> &alloc_m,
             const vector<vector<int>> &max_m,
             const vector<int> &avail_v,
             vector<int> &safe_sequence);

int request(vector<vector<int>> &alloc_m,
            vector<vector<int>> &max_m,
            vector<int> &avail_v,
            vector<int> &request_v,
            vector<int> &safe_sequence,
            int i);

#endif