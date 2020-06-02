#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int start = 0, request = 0, sum = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            request += cost[i] - gas[i];
            if (request > 0)
            {
                start = i + 1;
                sum += request;
                request = 0;
            }
        }
        if (sum + request <= 0) return start;
        return -1;
    }
};
