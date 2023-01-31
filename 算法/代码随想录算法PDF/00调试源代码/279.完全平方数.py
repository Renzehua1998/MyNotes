#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        i = 1
        sqrNum = i * i
        while sqrNum <= n:
            for j in range(sqrNum, n + 1):
                dp[j] = min(dp[j - sqrNum] + 1, dp[j])
            i += 1
            sqrNum = i * i
        return int(dp[-1])
# @lc code=end

