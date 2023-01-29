#
# @lc app=leetcode.cn id=746 lang=python3
#
# [746] 使用最小花费爬楼梯
#

# @lc code=start
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0, 0]
        for i in range(2, len(cost) + 1):
            dpi = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1])
            dp[0] = dp[1]
            dp[1] = dpi
        return dp[1]
# @lc code=end

