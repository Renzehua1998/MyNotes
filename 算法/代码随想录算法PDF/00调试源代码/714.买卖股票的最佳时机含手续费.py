#
# @lc app=leetcode.cn id=714 lang=python3
#
# [714] 买卖股票的最佳时机含手续费
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        res = 0
        minPrice = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
            if prices[i] > minPrice + fee:
                res += prices[i] - minPrice - fee
                minPrice = prices[i] - fee  # 重要！
        return res
# @lc code=end

