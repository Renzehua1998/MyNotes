/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 左闭右开
        vector<vector<int>> res(n, vector<int>(n, 0));  // 输出结果
        int loop = n / 2; // 循环次数
        int mid = n / 2; // 中心标号（奇数填充）
        int count = 1; // 填充的数字，每次+1
        int startx = 0, starty = 0; // 循环的开头，每次+1
        int num = n - 1; // 循环时1/4圈填充数字的个数，每次-1
        int i, j; // 循环变量
        while (loop--) {
            // 上
            for (j = starty; j < starty + num; j++) {
                res[startx][j] = count++;
            }
            // 右
            for (i = startx; i < startx + num; i++) {
                res[i][j] = count++;
            }
            // 下
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 左
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            num -= 2; // 注意每次减2，因为往里少一圈，两边各减一
        }
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
// @lc code=end

