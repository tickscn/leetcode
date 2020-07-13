/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        priority_queue<long, vector<long>, greater<long>> pq;
        long res = 1;
        while (--n)
        {
            for (int prime : primes)
            {
                pq.push(prime * res);
            }
            res = pq.top();
            pq.pop();
            while (!pq.empty() && res == pq.top()) pq.pop();
        }
        return res;
    }
};
// @lc code=end
