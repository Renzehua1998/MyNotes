/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX; // 代表无穷大
        int i = 0; // 窗口头指针
        int sum = 0; // 和
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                int len = j - i + 1;
                result = result < len ? result : len;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

