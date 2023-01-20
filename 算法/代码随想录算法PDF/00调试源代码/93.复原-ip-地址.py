#
# @lc app=leetcode.cn id=93 lang=python3
#
# [93] 复原 IP 地址
#

# @lc code=start
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        path = []

        def isIPNum(s, left, right):
            if left > right: return False
            if s[left] == '0' and left < right: return False
            if not 0 <= int(s[left:right + 1]) <= 255: return False
            return True
        
        def backtracking(s, startIndex):
            if len(path) == 4 and startIndex >= len(s):
                res.append('.'.join(path))
            for i in range(startIndex, len(s)):
                if isIPNum(s, startIndex, i):
                    path.append(s[startIndex : i + 1])
                    backtracking(s, i + 1)
                    path.pop()
        
        backtracking(s, 0)
        return res
# @lc code=end

