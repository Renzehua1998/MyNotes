/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)  // 特殊情况
            return 0;
        vector<int> dp(obstacleGrid[0].size(), 0);
        for (int i = 0; i < dp.size() && obstacleGrid[0][i] != 1; i++) {
            dp[i] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < dp.size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j != 0) {  // 不处理第一个
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end

