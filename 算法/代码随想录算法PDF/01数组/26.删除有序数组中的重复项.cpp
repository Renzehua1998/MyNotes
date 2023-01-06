/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;  // 慢指针指示插入单一数值位置
        int nowNum = nums[0];
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {  // 快指针指示遍历末尾
            if (nums[fastIndex] != nowNum) {
                nums[slowIndex++] = nowNum;
                nowNum = nums[fastIndex];
            }
        }
        nums[slowIndex++] = nowNum;  // 最后一个存入
        return slowIndex;
    }
};
// @lc code=end

