#
# @lc app=leetcode.cn id=131 lang=python3
#
# [131] 分割回文串
#

# @lc code=start
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        path = []
        def isPalindrome(s, start, end):
            while start <= end:
                if s[start] != s[end]: return False
                start += 1
                end -= 1
            return True

        def backtracking(s, startIndex):
            nonlocal res, path
            if startIndex >= len(s):
                res.append(path[:])
                return
            for i in range(startIndex, len(s)):
                if isPalindrome(s, startIndex, i):
                    path.append(s[startIndex : i + 1])
                    backtracking(s, i + 1)
                    path.pop()
        
        backtracking(s, 0)
        return res
# @lc code=end

