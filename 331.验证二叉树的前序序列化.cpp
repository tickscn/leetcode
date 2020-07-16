/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        int count = 0;
        int i;
        for (i = 0; i < preorder.length(); ++i)
        {
            if (preorder[i] == ',')
                continue;
            else if (preorder[i] == '#')
            {
                if (count)
                    --count;
                else
                    break;
            }
            else
            {
                while (i < preorder.length() && isdigit(preorder[i])) ++i;
                ++count;
            }
        }
        return i == preorder.length() - 1;
    }
};
// @lc code=end
