#
# @lc app=leetcode.cn id=377 lang=python3
#
# [377] 组合总和 Ⅳ
#

# @lc code=start
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for j in range(target + 1):
            for i in range(len(nums)):
                if j >= nums[i]:
                    dp[j] += dp[j - nums[i]]
        return dp[target]
# @lc code=end

