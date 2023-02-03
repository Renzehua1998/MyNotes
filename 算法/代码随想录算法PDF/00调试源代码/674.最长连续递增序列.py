#
# @lc app=leetcode.cn id=674 lang=python3
#
# [674] 最长连续递增序列
#

# @lc code=start
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        res = 1
        count = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                count += 1
            else:
                count = 1
            if res < count:
                res = count
        return res
# @lc code=end

