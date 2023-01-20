#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        s = ""
        letterMap = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        def backtracking(index):
            nonlocal s
            if index == len(digits):
                res.append(s)
                return
            letters = letterMap[digits[index]]
            for letter in letters:
                s += letter
                backtracking(index + 1)
                s = s[:-1]
        
        if len(digits) == 0:
            return res
        backtracking(0)
        return res
# @lc code=end

