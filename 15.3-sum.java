import java.util.ArrayList;
import java.util.Arrays;

/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.81%)
 * Likes:    5989
 * Dislikes: 730
 * Total Accepted:    822.9K
 * Total Submissions: 3.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    do {
                        j++;
                    } while (nums[j] == nums[j - 1] && j < nums.length - 1);
                    do {
                        k--;
                    } while (nums[k] == nums[k + 1] && k > 0);
                } else if (2 * nums[k] + nums[i] < 0)
                    break;
                else if (2 * nums[j] + nums[i] > 0)
                    break;
                else if (nums[j] + nums[k] + nums[i] < 0) {
                    do {
                        ++j;
                    } while (nums[j] == nums[j - 1] && j < nums.length - 1);
                } else {
                    do {
                        --k;
                    } while (nums[k] == nums[k + 1] && k > 0);
                }
            }
        }
        return res;
    }
}
// @lc code=end
