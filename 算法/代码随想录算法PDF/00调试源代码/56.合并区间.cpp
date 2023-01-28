/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0];
        int right = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > right) {  // 不在重叠区间
                res.push_back({left, right});
                left = intervals[i][0];
            }
            right = max(right, intervals[i][1]);
        }
        res.push_back({left, right});
        return res;
    }
};
// @lc code=end

