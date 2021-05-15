#include <iostream>
#include <vector>
#include <algorithm>

#include "banker.h"

using namespace std;

int main()
{

    vector<vector<int>> alloc_m;
    vector<vector<int>> max_m;
    vector<int> avail_v;
    vector<int> request_v;
    vector<int> safe_sequence;

    // get the number of the processes and resources
    int n = 0, m = 0;
    do
    {
        cout << "Enter the number of the processes: ";
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!(cin))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input\n";
        }
    } while (n <= 0);

    do
    {
        cout << "Enter the number of the resources: ";
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!(cin))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input\n";
        }
    } while (m <= 0);

    // get the Allocation, Max and Available matrices
    need_matrix(alloc_m, max_m, avail_v, n, m);

    // // get the matrcies from the user
    // alloc_m = {
    //     {0, 0, 1, 2},
    //     {1, 0, 0, 0},
    //     {1, 3, 5, 4},
    //     {0, 6, 3, 2},
    //     {0, 0, 1, 4},
    // };

    // max_m = {
    //     {0, 0, 1, 2},
    //     {1, 7, 5, 0},
    //     {2, 3, 5, 6},
    //     {0, 6, 5, 2},
    //     {0, 6, 5, 6},
    // };

    // avail_v = {1, 5, 2, 0};
    // vector<int> request_v = {0, 4, 2, 0};

    while(true)
    {
        cout << "\n";
        cout << "For enquiry about the system state, enter: 1\n"
             << "For enquiry about immediate request, enter: 2\n"
             << "To exit, enter: 5\n"
             << "Your choice: ";
        int enq = 0;
        cin >> enq;
        cout << "\n";
        if (enq == 1)
        {
            if (is_safe(alloc_m, max_m, avail_v, safe_sequence))
            {
                cout << "Yes, Safe state ";
                print_sequence(safe_sequence);
            }
            else
            {
                cout << "No, It's not a safe state\n";
            }
        }
        else if (enq == 2)
        {
            request_v.resize(m);
            int req;
            cout << "Enter the requested index:\n";
            cin >> req;
            cout << "Enter the requested resources:\n";
            for (int i = 0; i < m; i++)
                cin >> request_v[i];

            int result = request(alloc_m, max_m, avail_v, request_v, safe_sequence, 1);
            if (result == 0)
            {
                cout << "Yes, request can be granted with safe state ";
                print_sequence(safe_sequence, 1);
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
        else if (enq == 5)
        {
            cout << "Bye, Bye\n";
            return 0;
        }
        else if (!(cin))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input\n";
        }
        else
        {
            cout << "invalid input\n";
        }
    };
}