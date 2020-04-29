import java.util.*;

/*
 * @lc app=leetcode.cn id=18 lang=java
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (37.50%)
 * Likes:    439
 * Dislikes: 0
 * Total Accepted:    73.7K
 * Total Submissions: 196.6K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length < 4)
            return res;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < nums.length - 2; j++) {
                if (j != i + 1 && nums[j - 1] == nums[j])
                    continue;
                int m = j + 1;
                int n = nums.length - 1;
                while (m < n) {
                    if (nums[i] + nums[j] + nums[m] + nums[n] == target) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[m], nums[n]));
                        m++;
                        n--;
                        while (m < n && nums[m] == nums[m - 1])
                            m++;
                        while (m < n && nums[n] == nums[n + 1])
                            n--;
                    } else if (nums[i] + nums[j] + nums[m] + nums[n] < target)
                        m++;
                    else
                        n--;
                }
            }
        }
        return res;
    }
}
// @lc code=end
