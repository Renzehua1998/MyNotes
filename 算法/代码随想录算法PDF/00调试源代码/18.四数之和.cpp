/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] >= 0) break; // 剪枝
            if (i > 0 && nums[i] == nums[i-1]) continue; // 去重
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] > target && nums[j] >= 0) break; // 剪枝
                if (j > i + 1 && nums[j] == nums[j-1]) continue; // 去重
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    if ((long) nums[i] + nums[j] + nums[right] + nums[left] > target) {
                        right--;
                    } else if ((long) nums[i] + nums[j] + nums[right] + nums[left] < target) {
                        left++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[right], nums[left]});
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

