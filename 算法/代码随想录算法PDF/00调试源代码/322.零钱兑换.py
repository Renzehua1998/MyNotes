#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(len(coins)):
            for j in range(coins[i], amount + 1):
                if dp[j - coins[i]] != float('inf'):
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1)
        if dp[-1] == float('inf'): return -1
        return int(dp[-1])
# @lc code=end

