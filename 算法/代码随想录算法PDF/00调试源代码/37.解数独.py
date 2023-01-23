#
# @lc app=leetcode.cn id=37 lang=python3
#
# [37] 解数独
#

# @lc code=start
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def backtracking(board):
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if board[i][j] == '.':
                        for k in range(1, 10):
                            if isValid(i, j ,k, board):
                                board[i][j] = str(k)
                                if backtracking(board): return True
                                board[i][j] = '.'
                        return False
            return True
        def isValid(row, col, val, board):
            for i in range(len(board)):
                if board[i][col] == str(val): return False
                if board[row][i] == str(val): return False
            blocki = row // 3 * 3
            blockj = col // 3 * 3
            for i in range(blocki, blocki + 3):
                for j in range(blockj, blockj + 3):
                    if board[i][j] == str(val): return False
            return True
        backtracking(board)
# @lc code=end

