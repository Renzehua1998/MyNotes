/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int globalN, globalK;
    void backtracking(int startIndex) {
        if (path.size() == globalK) {
            res.push_back(path);
            return ;
        }
        for (int i = startIndex; i <= globalN - (globalK - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        globalN = n;
        globalK = k;
        backtracking(1);
        return res;
    }
};
// @lc code=end

