/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> option;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];  // 要找的值
            if (option.count(need)) {
                return {option[need], i};
            } else {
                option[nums[i]] = i;
            }
        }
        return {};
    }
};
// @lc code=end

