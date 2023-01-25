#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = -float('inf')
        count = 0
        for num in nums:
            count += num
            if count > res:
                res = count
            if count < 0:
                count = 0
        return res
# @lc code=end

