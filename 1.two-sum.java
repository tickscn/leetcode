import java.util.HashMap;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.55%)
 * Likes:    14159
 * Dislikes: 516
 * Total Accepted:    2.7M
 * Total Submissions: 6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hashtab = new HashMap<Integer, Integer>();
        hashtab.put(nums[0], 0);
        int[] ret = new int[2];
        for (int i = 1; i < nums.length; i++) {
            if (hashtab.containsKey(target - nums[i])) {
                ret[0] = hashtab.get(target - nums[i]);
                ret[1] = i;
                break;
            }
            hashtab.put(nums[i], i);
        }
        return ret;
    }
}
// @lc code=end
