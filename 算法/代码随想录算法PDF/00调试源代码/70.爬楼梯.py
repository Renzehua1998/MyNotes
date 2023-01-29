#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2: return n
        dp = [1, 2]
        for _ in range(3, n + 1):
            sum = dp[0] + dp[1]
            dp[0] = dp[1]
            dp[1] = sum
        return dp[1]
# @lc code=end

