/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int need, int startIndex) {
        if (need == 0) {
            res.push_back(path);
            return ;
        }
        for (int i = startIndex; i < candidates.size() && need - candidates[i] >= 0; i++) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;  // 同层去重
            path.push_back(candidates[i]);
            backtracking(candidates, need - candidates[i], i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 排序很重要！
        backtracking(candidates, target, 0);
        return res;
    }
};
// @lc code=end

