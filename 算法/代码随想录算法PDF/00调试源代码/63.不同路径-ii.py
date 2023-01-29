#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1: return 0
        dp = [0] * len(obstacleGrid[0])
        for i in range(len(obstacleGrid[0])):
            if obstacleGrid[0][i] == 0:
                dp[i] = 1
            else:
                break
        for i in range(1, len(obstacleGrid)):
            for j in range(len(obstacleGrid[0])):
                if obstacleGrid[i][j] == 1:
                    dp[j] = 0
                elif j != 0:
                    dp[j] = dp[j] + dp[j - 1]
        return dp[-1]
# @lc code=end

