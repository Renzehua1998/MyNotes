#
# @lc app=leetcode.cn id=151 lang=python3
#
# [151] 反转字符串中的单词
#

# @lc code=start
class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s)
        slow = 0
        i = 0
        while i < len(s):
            if s[i] != ' ':
                if slow != 0:
                    s[slow] = ' '
                    slow += 1
                while i < len(s) and s[i] != ' ':
                    s[slow] = s[i]
                    slow += 1
                    i += 1
            else:
                i += 1
        s = s[:slow]
        
        s = s[::-1]
        start = 0
        for i in range(len(s) + 1):
            if i == len(s) or s[i] == ' ':
                s = s[:start] + s[start:i][::-1] + s[i:]
                start = i + 1
        return ''.join(s)
# @lc code=end

