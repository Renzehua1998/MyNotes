#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根 
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return x
        C, x0, x1 = x, x, x
        while True:
            x1 = 0.5 * (x0 + C / x0)
            if abs(x0 - x1) < 1e-7:
                break
            x0 = x1
        return int(x0)
# @lc code=end

