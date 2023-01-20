#
# @lc app=leetcode.cn id=216 lang=python3
#
# [216] 组合总和 III
#

# @lc code=start
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        path = []
        def backtracking(need, startIndex):
            nonlocal path, res, n, k
            if need < 0: return  # 剪枝
            if len(path) == k:
                if need == 0:
                    res.append(path[:])
                return
            for i in range(startIndex, 10 - (k - len(path)) + 1):
                path.append(i)
                backtracking(need - i, i + 1)
                path.pop()
        
        backtracking(n, 1)
        return res
# @lc code=end

