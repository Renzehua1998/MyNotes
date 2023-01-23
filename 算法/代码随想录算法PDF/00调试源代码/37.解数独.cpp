/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {  // 遍历行
            for (int j = 0; j < board[0].size(); j++) {  // 遍历列
                if (board[i][j] == '.') {  // 遇到未填充的位置
                    for (char k = '1'; k <= '9'; k++) {  // 遍历0-9
                        if (isValid(i, j, k, board)) {  // 这个地方可以填
                            board[i][j] = k;  // 填
                            if (backtracking(board)) return true;  // 递归，找到直接返回
                            board[i][j] = '.';  // 回溯
                        }
                    }
                    return false;  // 试数字没找到，避免死循环，返回回溯位置告诉上层
                }
            }
        }
        return true;  // 都遍历完没有空，说明全填充了且符合条件，返回true
    }
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == val) return false;
            if (board[row][i] == val) return false;
        }
        int blocki = row / 3 * 3;
        int blockj = col / 3 * 3;
        for (int i = blocki; i < blocki + 3; i++) {
            for (int j = blockj; j < blockj + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

