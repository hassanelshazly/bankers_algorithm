#ifndef _BANKER_
#define _BANKER_

#include <vector>
#include <iostream>
#include <limits>

#include "helper_functions.h"

using namespace std;

/**
 * get the required matrices from the user
 * 
 * @param n num. of processes
 * @param m num. of resources 
 * 
 * @returns 1 in case of sucess
 * @returns 0 otherwise
 */
int get_matrices(vector<vector<int>> &alloc_m,
                vector<vector<int>> &max_m,
                vector<int> &avail_v,
                int n, int m);

/**
 * @param safe_sequence a possible safe sequence if the system in safe sate
 *                      ignored otherwise 
 * @returns true  if the system in a safe state
 * @returns false otherwise
 */
bool is_safe(const vector<vector<int>> &alloc_m,
             const vector<vector<int>> &max_m,
             const vector<int> &avail_v,
             vector<int> &safe_sequence);

/**
 * @param req -> index of the process
 * 
 * @returns 0 if the request can be granted safely
 * @returns 1 if the request can be granted with possibility of deadlock
 * 
 * @returns 2 if the request cannot be granted as the process will excees it's declared limits
 * @returns 3 if the request cannot be granted as there is no available resources
 */
int request(vector<vector<int>> &alloc_m,
            vector<vector<int>> &max_m,
            vector<int> &avail_v,
            vector<int> &request_v,
            vector<int> &safe_sequence,
            int req);

#endif