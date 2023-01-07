#
# @lc app=leetcode.cn id=59 lang=python3
#
# [59] 螺旋矩阵 II
#

# @lc code=start
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [ [0] * n for _ in range(n)] # 返回二维数组
        loop = n // 2
        mid = n // 2
        startx, starty = 0, 0
        count = 1
        num = n - 1
        while loop:
            for i in range(starty, starty + num):
                res[startx][i] = count
                count += 1
            for i in range(startx, startx + num):
                res[i][starty + num] = count
                count += 1
            for i in range(starty + num, starty, -1):
                res[startx + num][i] = count
                count += 1
            for i in range(startx + num, startx, -1):
                res[i][starty] = count
                count += 1
            startx += 1
            starty += 1
            num -= 2
            loop -= 1
        if (n % 2):
            res[mid][mid] = count
        return res
# @lc code=end

