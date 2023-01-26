/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int step = 0;
        int curCover = 0;
        int nextCover = 0;
        for (int i = 0; i < nums.size() - 1; i++) {  // 遍历结尾很重要
            nextCover = max(nextCover, nums[i] + i);  // 更新当前最远距离
            if (i == curCover) {
                step++;
                curCover = nextCover;
            }
        }
        return step;
    }
};
// @lc code=end

