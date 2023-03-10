/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
#include <vector>
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 重设边界法，直到两个边界交错，停止迭代。边界都是闭区间
        vector<int> res;
        if (matrix.empty()) return {};
        int up = 0, left = 0;
        int down = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        while (true) {
            for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            if (++up > down) break;

            for (int i = up; i <= down; i++) res.push_back(matrix[i][right]);
            if (--right < left) break;

            for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
            if (--down < up) break;

            for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};
// @lc code=end

