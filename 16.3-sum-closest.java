import java.util.Arrays;

/*
 * @lc app=leetcode id=16 lang=java
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    1758
 * Dislikes: 124
 * Total Accepted:    439.1K
 * Total Submissions: 959.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int diff, res;
        Arrays.sort(nums);
        res = nums[0] + nums[1] + nums[2];
        diff = Math.abs(res - target);
        for (int i = 0; i < nums.length - 2; i++) {
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == target)
                    return tmp;
                if (Math.abs(tmp - target) < diff) {
                    diff = Math.abs(tmp - target);
                    res = tmp;
                }
                if (tmp < target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
}
// @lc code=end
