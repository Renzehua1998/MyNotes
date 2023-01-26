#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#

# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        cover = 0
        i = 0
        while i <= cover:
            cover = max(nums[i] + i, cover)
            i += 1
            if cover >= len(nums) - 1:
                return True
        return False
# @lc code=end

