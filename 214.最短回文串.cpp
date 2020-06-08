/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 *
 * https://leetcode-cn.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (31.53%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 27.8K
 * Testcase Example:  '"aacecaaa"'
 *
 * 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
 *
 * 示例 1:
 *
 * 输入: "aacecaaa"
 * 输出: "aaacecaaa"
 *
 *
 * 示例 2:
 *
 * 输入: "abcd"
 * 输出: "dcbabcd"
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        int size = s.length();
        if(size < 2) return s;
        bool flag = false;
        for(int i = size/2; i >= 0; --i)
        {
            int k = flag ? i + 1 : i + 2;
            bool fflag = false;
            for(int j = i; j >= 0; --j)
            {
                if(s[j] != s[k]){
                    fflag = true;
                    break;
                }
                ++k;
            }
            if(!fflag)
            {
                int pos = (i << 1) + static_cast<int>(!flag) + 1;
                string tmp=s.substr(pos + 1);
                return string(make_move_iterator(tmp.rbegin()), make_move_iterator(tmp.rend())) + s; 
            }
            if(!flag)
            {
                flag = true;
                ++i;
            }
            else flag = !flag;
        }
        string tmp = s.substr(1);
        return string(make_move_iterator(tmp.rbegin()), make_move_iterator(tmp.rend())) + s;
    }
};
// @lc code=end
