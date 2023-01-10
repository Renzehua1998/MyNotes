#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#

# @lc code=start
class Solution:
    def getHappy(self, n: int) -> int:
        res = 0
        while n:
            res += (n % 10) * (n % 10)
            n //= 10
        return res
    def isHappy(self, n: int) -> bool:
        Cycle = {4, 16, 37, 58, 89, 145, 42, 20}
        while n != 1 and n not in Cycle:
            n = self.getHappy(n)
        return n == 1
# @lc code=end

