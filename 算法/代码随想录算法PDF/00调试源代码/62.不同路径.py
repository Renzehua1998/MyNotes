#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#

# @lc code=start
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        numerator = 1
        denominator = m - 1
        count = m - 1
        t = m + n - 2
        while count:
            numerator *= t
            t -= 1
            while denominator != 0 and numerator % denominator == 0:
                numerator /= denominator
                denominator -= 1
            count -= 1
        return int(numerator)
# @lc code=end

