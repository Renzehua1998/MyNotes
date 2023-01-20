#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        path = []
        def backtracking(candidates, need, startIndex):
            nonlocal res, path
            if need < 0: return
            if need == 0:
                res.append(path[:])
                return
            for i in range(startIndex, len(candidates)):
                if need - candidates[i] < 0: return  # 添加判断进行剪枝
                path.append(candidates[i])
                backtracking(candidates, need - candidates[i], i)
                path.pop()
        
        candidates.sort()  # 提前排序
        backtracking(candidates, target, 0)
        return res
# @lc code=end

