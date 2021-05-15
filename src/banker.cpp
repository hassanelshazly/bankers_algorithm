#include "banker.h"

int need_matrix(vector<vector<int>> &alloc_m,
                vector<vector<int>> &max_m,
                vector<int> &avail_v,
                int n, int m)
{
    try
    {
        alloc_m.resize(n);
        max_m.resize(n);
        avail_v.resize(m);
        for (int i = 0; i < n; i++)
        {
            alloc_m[i].resize(m);
            max_m[i].resize(m);
        }

        cout << "Enter the allocated matrix\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> alloc_m[i][j];

        cout << "Enter the max matrix\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> max_m[i][j];

        cout << "Enter the available vector\n";
        for (int j = 0; j < m; j++)
            cin >> avail_v[j];

        return 1;
    }
    catch (...)
    {
        return 0;
    }
}

bool is_safe(const vector<vector<int>> &alloc_m,
             const vector<vector<int>> &max_m,
             const vector<int> &avail_v,
             vector<int> &safe_sequence)
{
    // init the sequence, work, finished vectors and need matrix
    safe_sequence.clear();
    vector<int> work_v = avail_v;
    vector<int> finish_v(alloc_m.size(), false);

    vector<vector<int>> need_m = max_m - alloc_m;

    // search for not finished proceess with available resources
    // finish it, release it's allocated resources
    // do that until there is no resources left
    bool done = false;
    while (!done)
    {
        done = true;

        for (int i = 0; i < finish_v.size(); i++)
        {
            if (!finish_v[i] && need_m[i] <= work_v)
            {
                safe_sequence.push_back(i);
                work_v += alloc_m[i];
                finish_v[i] = true;
                done = false;
                break;
            }
        }
    }

    // if all the processes have been finished return true
    // else return false
    for (const bool &item : finish_v)
        if (!item)
            return false;
    return true;
}

int request(vector<vector<int>> &alloc_m,
            vector<vector<int>> &max_m,
            vector<int> &avail_v,
            vector<int> &request_v,
            vector<int> &safe_sequence,
            int req)
{
    // save the system state
    vector<int> alloc_saved = alloc_m[req];
    vector<int> avail_saved = avail_v;

    // check for limits
    if (!(alloc_m[req] + request_v <= max_m[req]))
        return 2;

    if (!(request_v <= avail_v))
        return 3;

    // pretend a new state, check if the new state is safe
    // roll back if it's not
    alloc_m[req] += request_v;
    avail_v -= request_v;

    if (is_safe(alloc_m, max_m, avail_v, safe_sequence))
    {
        // the request has been granted
        return 0;
    }
    else
    {
        // roll back
        alloc_m[req] -= request_v;
        avail_v += request_v;
        return 1;
    }

    // error has occured shouldn't got here
    return 4;
}