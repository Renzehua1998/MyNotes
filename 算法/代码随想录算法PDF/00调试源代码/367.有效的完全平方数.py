#
# @lc app=leetcode.cn id=367 lang=python3
#
# [367] 有效的完全平方数
#

# @lc code=start
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 1: return True
        left = 1
        right = num // 2
        while left <= right:
            mid = left + (right - left) // 2
            if (mid ** 2 < num):
                left = mid + 1
            elif (mid ** 2 > num):
                right = mid - 1
            else:
                return True
        return False
# @lc code=end

