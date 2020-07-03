/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组循环
 */

// @lc code=start
class Solution {
private:
    int size;

public:
    bool circularArrayLoop(vector<int>& nums)
    {
        size = nums.size();
        if (size < 2) return false;
        vector<int> visit(size, 0);
        int round = 0;
        bool flag;
        for (size_t i = 0; i != size; ++i)
        {
            if (visit[i] == 0)
            {
                ++round;
                visit[i] = round;
                int temp = i;
                flag     = nums[i] > 0;
                int next = (i + nums[i] % size + size) % size;
                while (visit[next] == 0 && next != temp && flag == nums[next] > 0)
                {
                    visit[next] = round;
                    temp        = next;
                    next        = (next + nums[next] % size + size) % size;
                }
                if (next != temp && visit[next] == round) return true;
            }
        }
        return false;
    }
};
// @lc code=end
