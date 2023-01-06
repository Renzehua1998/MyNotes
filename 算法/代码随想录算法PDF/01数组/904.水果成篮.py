#
# @lc app=leetcode.cn id=904 lang=python3
#
# [904] 水果成篮
#

# @lc code=start
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        head, next = 0, 0
        basket1 = fruits[0]
        basket2 = -1
        num = 0
        for i in range(len(fruits)):
            if fruits[i] == basket1: continue
            if fruits[i] != basket2 and basket2 != -1:
                num = max(i - head, num)
                head = next
            basket2 = basket1
            basket1 = fruits[i]
            next = i
        num = max(len(fruits) - head, num)
        return num
# @lc code=end

