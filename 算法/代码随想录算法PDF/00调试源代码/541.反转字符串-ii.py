#
# @lc app=leetcode.cn id=541 lang=python3
#
# [541] 反转字符串 II
#

# @lc code=start
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        i = 0
        while i < len(s):
            s = s[:i] + s[i:i+k][::-1] + s[i+k:]
            i += 2 * k
        return s
# @lc code=end

