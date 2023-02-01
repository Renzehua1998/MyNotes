#
# @lc app=leetcode.cn id=213 lang=python3
#
# [213] 打家劫舍 II
#

# @lc code=start
class Solution:
    def robRange(self, nums, start, end):
        if start == end: return nums[start]
        dp = [0] * len(nums)
        dp[start] = nums[start]
        dp[start + 1] = max(nums[start], nums[start + 1])
        for i in range(start + 2, end + 1):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        return dp[end]
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        res1 = self.robRange(nums, 0, len(nums) - 2)
        res2 = self.robRange(nums, 1, len(nums) - 1)
        return max(res1, res2)
# @lc code=end

