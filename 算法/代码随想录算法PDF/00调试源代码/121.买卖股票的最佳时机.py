#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [-prices[0], 0]
        for i in range(1, len(prices)):
            dp0, dp1 = dp[0], dp[1]
            dp[0] = max(dp0, -prices[i])
            dp[1] = max(dp1, dp0 + prices[i])
        return dp[1]
# @lc code=end

