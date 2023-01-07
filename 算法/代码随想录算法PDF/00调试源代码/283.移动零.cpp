/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0; // 慢指针
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex++] = nums[fastIndex];  // 替换非0元素
            }
        }
        for (;slowIndex < nums.size(); slowIndex++) {
            nums[slowIndex] = 0; // 末尾补0
        }
    }
};
// @lc code=end

