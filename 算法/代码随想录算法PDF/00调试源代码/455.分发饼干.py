#
# @lc app=leetcode.cn id=455 lang=python3
#
# [455] 分发饼干
#

# @lc code=start
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        index = len(s) - 1
        res = 0
        for i in range(len(g) - 1, -1, -1):
            if index >= 0 and s[index] >= g[i]:
                index -= 1
                res += 1
        return res
# @lc code=end

