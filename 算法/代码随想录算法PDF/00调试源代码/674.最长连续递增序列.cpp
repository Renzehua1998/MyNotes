/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                count++;
            } else {
                count = 1;
            }
            if (count > res) res = count;
        }
        return res;
    }
};
// @lc code=end

