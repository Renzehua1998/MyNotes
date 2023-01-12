#
# @lc app=leetcode.cn id=1047 lang=python3
#
# [1047] 删除字符串中的所有相邻重复项
#

# @lc code=start
class Solution:
    def removeDuplicates(self, s: str) -> str:
        s = list(s)
        slow, fast = 0, 0
        while fast < len(s):
            s[slow] = s[fast]
            if slow > 0 and s[slow] == s[slow - 1]:
                slow -= 1
            else:
                slow += 1
            fast += 1
        return ''.join(s[:slow])
# @lc code=end

