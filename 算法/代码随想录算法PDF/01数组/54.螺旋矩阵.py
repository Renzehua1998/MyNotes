#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#

# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        up, left = 0, 0
        down = len(matrix) - 1
        right = len(matrix[0]) - 1
        res = []
        while True:
            for i in range(left, right + 1):
                res.append(matrix[up][i])
            up += 1
            if up > down:
                break

            for i in range(up, down + 1):
                res.append(matrix[i][right])
            right -= 1
            if left > right:
                break

            for i in range(right, left - 1, -1):
                res.append(matrix[down][i])
            down -= 1
            if up > down:
                break

            for i in range(down, up - 1, -1):
                res.append(matrix[i][left])
            left += 1
            if left > right:
                break
        return res
# @lc code=end

