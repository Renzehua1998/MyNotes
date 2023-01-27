/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;  // 至少需要一个
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {
                res++;
            } else {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end

