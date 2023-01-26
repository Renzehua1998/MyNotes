#
# @lc app=leetcode.cn id=45 lang=python3
#
# [45] 跳跃游戏 II
#

# @lc code=start
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        curCover = 0
        nextCover = 0
        step = 0
        for i in range(len(nums) - 1):
            nextCover = max(nextCover, nums[i] + i)
            if i == curCover:
                step += 1
                curCover = nextCover
        return step
# @lc code=end

