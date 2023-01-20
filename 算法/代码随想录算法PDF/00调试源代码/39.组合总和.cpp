/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int need, int startIndex) {
        if (need < 0) return ;
        if (need == 0) {
            res.push_back(path);
            return ;
        }
        // 添加判断进行剪枝
        for (int i = startIndex; i < candidates.size() && need - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, need - candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());  // 需要排序
        backtracking(candidates, target, 0);
        return res;
    }
};
// @lc code=end

