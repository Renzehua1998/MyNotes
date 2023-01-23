/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;  // 结果
    vector<string> path;  // 盘面排布
    int num;  // 盘面大小
    bool isValid(int row, int col) {
        for (int i = row - 1; i >= 0; i--) {
            if (path[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (path[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < num; i--, j++){
            if (path[i][j] == 'Q') return false;
        }
        return true;
    }
    void backtracking(int row) {
        if (row == num) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < num; i++) {
            if (isValid(row, i)) {  // 合法可以放
                path[row][i] = 'Q';
                backtracking(row + 1);  // 递归
                path[row][i] = '.';  // 回溯
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        num = n;
        path.assign(n, string(n, '.'));
        backtracking(0);
        return res;
    }
};
// @lc code=end

