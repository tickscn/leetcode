/*
 * @lc app=leetcode.cn id=898 lang=cpp
 *
 * [898] 子数组按位或操作
 */

// @lc code=start
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A)
    {
        unordered_set<int> Set;
        vector<int> v;
        for (int i = 0; i < A.size(); ++i)
        {
            vector<int> vTmp;
            Set.insert(A[i]);
            int temp = A[i];
            vTmp.push_back(temp);
            for (int j = 0; j < v.size(); ++j)
            {
                int t = temp | v[j];
                if (t > temp)
                {
                    vTmp.push_back(t);
                }
                temp = t;
                Set.insert(temp);
            }
            v = std::move(vTmp);
        }
        return Set.size();
    }
};
// @lc code=end
