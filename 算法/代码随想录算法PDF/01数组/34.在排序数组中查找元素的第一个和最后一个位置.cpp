/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int leftPos = -2; // 第一次找到的位置
        bool find = false; // 是否找到
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
                leftPos = mid - 1;
            }
            if (nums[mid] == target) find = true;
        }
        if (!find) {
            return {-1, -1};
        } else {
            int rightPos;
            for (rightPos = leftPos + 1; rightPos < nums.size() && nums[rightPos] == target; rightPos++) {}
            return {leftPos + 1, rightPos - 1};
        }

    }
};
// @lc code=end

