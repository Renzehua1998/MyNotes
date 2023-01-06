#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slowIndex = 0
        for fastIndex in range(len(nums)):
            if (nums[fastIndex] != 0):
                nums[slowIndex] = nums[fastIndex]
                slowIndex += 1
        while slowIndex < len(nums):
            nums[slowIndex] = 0
            slowIndex += 1
# @lc code=end

