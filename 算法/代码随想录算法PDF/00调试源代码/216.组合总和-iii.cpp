/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    int globalN, globalK;
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int need, int startIndex) {
        if (need < 0) return ;
        if (path.size() == globalK) {
            if (need == 0) res.push_back(path);
            return ;
        }
        for (int i = startIndex; i <= 9 - (globalK - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(need - i, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        globalN = n;
        globalK = k;
        backtracking(n, 1);
        return res;
    }
};
// @lc code=end

