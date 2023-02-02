#
# @lc app=leetcode.cn id=188 lang=python3
#
# [188] 买卖股票的最佳时机 IV
#

# @lc code=start
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if len(prices) == 0: return 0  # 特殊情况
        dp = [0] * (2 * k + 1)
        for i in range(1, 2 * k, 2):
            dp[i] = -prices[0]
        for i in range(1, len(prices)):
            for j in range(1, 2 * k + 1):
                if j % 2:
                    dp[j] = max(dp[j], dp[j - 1] - prices[i])
                else:
                    dp[j] = max(dp[j], dp[j - 1] + prices[i])
        return dp[-1]
# @lc code=end

