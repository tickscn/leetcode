/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num)
    {
        if (num.length() < 3) return false;
        vector<unsigned long> temp;
        return healper(temp, num);
    }
    bool healper(vector<unsigned long>& temp, string num)
    {
        size_t size = temp.size();
        if (size > 2 && temp[size - 2] + temp[size - 3] != temp[size - 1]) return false;
        if (size > 2 && num.empty()) return true;
        for (size_t i = 0; i < num.length(); ++i)
        {
            if (num[0] == '0' && i != 0) continue;
            temp.push_back(strtoul(num.substr(0, i + 1).c_str(), 0, 10));
            if (healper(temp, num.substr(i + 1))) return true;
            temp.pop_back();
        }
        return false;
    }
};
// @lc code=end
