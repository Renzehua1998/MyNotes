/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int x, int y) {
        return abs(x) > abs(y);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;
        int res = 0;
        for (int num : nums) res += num;
        return res;
    }
};
// @lc code=end

