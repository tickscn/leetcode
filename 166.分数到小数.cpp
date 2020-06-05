/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (26.39%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 44.4K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 *
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 *
 * 示例 1:
 *
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 *
 *
 * 示例 2:
 *
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 *
 * 示例 3:
 *
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 *
 *
 */

// @lc code=start
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        unordered_map<unsigned long long, int> hashtable;
        string integerPart;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) integerPart = "-";
        unsigned long long n;
        unsigned d;
        n = numerator < 0 ? (unsigned)~numerator + 1 : numerator;
        d = denominator < 0 ? (unsigned)~denominator + 1 : denominator;
        integerPart += to_string(n / d);
        n = n % d * 10;
        if (n == 0) return integerPart;
        integerPart += ".";
        string decimalPart;
        int i = 0;
        do
        {
            if (hashtable.count(n) == 0)
            {
                hashtable[n] = i;
                decimalPart += to_string(n / d);
                n = n % d * 10;
                i = decimalPart.length();
            }
            else
            {
                decimalPart.insert(decimalPart.begin() + hashtable[n], '(');
                decimalPart += ")";
                return integerPart + decimalPart;
            }
        } while (n != 0);
        return integerPart + decimalPart;
    }
};
// @lc code=end
