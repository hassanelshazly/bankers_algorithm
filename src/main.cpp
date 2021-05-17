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
        if (!cin)
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
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input\n";
        }
    } while (m <= 0);

    // get the Allocation, Max and Available matrices
    get_matrices(alloc_m, max_m, avail_v, n, m);

    // output need matrix
    vector<vector<int>> need_m = max_m - alloc_m;
    cout << "\n\t\tNeed Matrix\n\t";
    for (int i = 0; i < m; i++)
        cout << "R" << i << "\t";
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "\t";
        for (int j = 0; j < m; j++)
        {
            cout << need_m[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << flush;

    bool success = true;
    while (true)
    {
        if (success)
        {
            cout << "\n";
            cout << "For enquiry about the system state, enter: 1\n"
                 << "For enquiry about immediate request, enter: 2\n"
                 << "To exit, enter: 5\n";
        }
        cout << "Your choice: ";
        int enq = 0;
        cin >> enq;
        if (enq == 1)
        {
            if (is_safe(alloc_m, max_m, avail_v, safe_sequence))
            {
                cout << "\nYes, Safe state ";
                print_sequence(safe_sequence);
            }
            else
            {
                cout << "\nNo, It's not a safe state\n";
            }
            success = true;
        }
        else if (enq == 2)
        {
            request_v.resize(m);
            int req;
            cout << "\nEnter the requested index: ";
            cin >> req;

            if (req >= n)
            {
                cout << "\nThere is no such process, plz try again\n";
                success = true;
                continue;
            }

            cout << "Enter the requested resources:\n";
            for (int i = 0; i < m; i++)
                cin >> request_v[i];

            int result = request(alloc_m, max_m, avail_v, request_v, safe_sequence, req);
            if (result == 0)
            {
                cout << "\nYes, request can be granted with safe state ";
                print_sequence(safe_sequence, req);
            }
            else if (result == 1)
            {
                cout << "\nThe request cannot be granted it will lead to unsafe state\n";
            }
            else if (result == 2)
            {
                cout << "\nThe request is more than it's declared max rescoures\n";
            }
            else if (result == 3)
            {
                cout << "\nthere is not available resources, the process has to wait\n";
            }
            else
            {
                cout << "\nThe request cannot be granted\n";
            }
            success = true;
        }
        else if (enq == 5)
        {
            cout << "\nBye, Bye\n";
            return 0;
        }
        else if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input\n";
            success = false;
        }
        else
        {
            cout << "invalid input\n";
            success = false;
        }
    };
}