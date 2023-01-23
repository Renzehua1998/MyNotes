#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N 皇后
#

# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        path = [['.'] * n for _ in range(n)]
        def backtracking(row):
            nonlocal n
            if row == n:
                line = []
                for tmp in path:
                    line.append(''.join(tmp))
                res.append(line)
                return
            for col in range(n):
                if isValid(row, col):
                    path[row][col] = 'Q'
                    backtracking(row + 1)
                    path[row][col] = '.'
        def isValid(row, col):
            nonlocal n
            for i in range(row):
                if path[i][col] == 'Q': return False
            i = row - 1
            j = col - 1
            while i >= 0 and j >= 0:
                if path[i][j] == 'Q': return False
                i -= 1
                j -= 1
            i = row - 1
            j = col + 1
            while i >= 0 and j < n:
                if path[i][j] == 'Q': return False
                i -= 1
                j += 1
            return True
        
        backtracking(0)
        return res
# @lc code=end

