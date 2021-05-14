#include <iostream>
#include <vector>
#include <algorithm>

#include "helper_functions.h"

using namespace std;



int main()
{

    vector<vector<int>> alloc_m;
    vector<vector<int>> max_m;
    vector<int> avail_v;
    vector<int> safe_sequence;

    need_matrix(alloc_m, max_m, avail_v);

    // get the matrcies from the user
    alloc_m = {
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4},
    };

    max_m = {
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6},
    };

    avail_v = {1, 5, 2, 0};
    vector<int> request_v = {0, 4, 2, 0};

    if (is_safe(alloc_m, max_m, avail_v, safe_sequence))
    {
        cout << "Yes, Safe state ";
        print_sequence(safe_sequence);
    }
    else
    {
        cout << "No, It's not a safe state\n";
    }

    int result = request(alloc_m, max_m, avail_v, request_v, safe_sequence, 1);
    if (result == 0)
    {
        cout << "Yes, Safe state ";
        print_sequence(safe_sequence);
    }
    else if (result == 2)
    {
         cout << "The request cannot be granted it will lead to unsafe state\n";
    }
    else if (result == 2)
    {
        cout << "The request is more than it's declared max rescoures\n";
    }
    else if (result == 3)
    {
        cout << "there is not available resources, the process has to wait\n";

    }
    else
    {
        cout << "The request cannot be granted\n";
    }
}