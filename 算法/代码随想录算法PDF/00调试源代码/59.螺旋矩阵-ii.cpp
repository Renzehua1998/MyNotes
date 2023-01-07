/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
#include <vector>
public:
    vector<vector<int>> generateMatrix(int n) {
        // 重设边界法，直到两个边界交错，停止迭代。边界都是闭区间
        vector<vector<int>> res(n, vector<int>(n, 0));  // 输出结果
        int up = 0, left = 0;
        int down = res.size() - 1;
        int right = res[0].size() - 1;
        int index = 1;
        while (true) {
            for (int i = left; i <= right; i++) res[up][i] = index++;
            if (++up > down) break;

            for (int i = up; i <= down; i++) res[i][right] = index++;
            if (--right < left) break;

            for (int i = right; i >= left; i--) res[down][i] = index++;
            if (--down < up) break;

            for (int i = down; i >= up; i--) res[i][left] = index++;
            if (++left > right) break;
        }
        return res;
    }
};
// @lc code=end

