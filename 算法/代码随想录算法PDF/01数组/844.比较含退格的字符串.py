#
# @lc app=leetcode.cn id=844 lang=python3
#
# [844] 比较含退格的字符串
#

# @lc code=start
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i, j = len(s)- 1, len(t) - 1  # 下标指针
        backS, backT = 0, 0  # 退格变量
        while i >= 0 or j >= 0:
            while i >= 0:
                if s[i] == "#":
                    backS += 1
                    i -= 1
                elif backS > 0:
                    backS -= 1
                    i -= 1
                else:
                    break
            while j >= 0:
                if t[j] == "#":
                    backT += 1
                    j -= 1
                elif backT > 0:
                    backT -= 1
                    j -= 1
                else:
                    break
            if i >= 0 and j >= 0:
                if s[i] != t[j]:
                    return False
            elif i >= 0 or j >= 0:
                return False
            i -= 1
            j -= 1
        return True
# @lc code=end

