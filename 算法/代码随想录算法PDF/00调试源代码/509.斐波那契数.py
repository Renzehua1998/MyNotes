#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#

# @lc code=start
class Solution:
    def fib(self, n: int) -> int:
        if n <= 0: return n
        dp = [0, 1]
        for _ in range(2, n + 1):
            sum = dp[0] + dp[1]
            dp[0] = dp[1]
            dp[1] = sum
        return dp[1]
# @lc code=end


