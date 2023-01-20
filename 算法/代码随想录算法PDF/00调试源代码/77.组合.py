#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#

# @lc code=start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        path = []
        res = []
        def backtracking(startIndex):
            nonlocal n, k, path, res
            if len(path) == k:
                res.append(path[:])
                return
            for i in range(startIndex, n + 1):
                if i > n - (k - len(path)) + 1:  # 剪枝
                    break
                path.append(i)
                backtracking(i + 1)
                path.pop()
        
        backtracking(1)
        return res
# @lc code=end

