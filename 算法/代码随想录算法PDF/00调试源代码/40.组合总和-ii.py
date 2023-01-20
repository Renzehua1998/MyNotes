#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#

# @lc code=start
class Solution:
    def __init__(self):
        self.res = []
        self.path = []
    def backtracking(self, candidates: List[int], need: int, startIndex: int) -> None:
        if need == 0:
            self.res.append(self.path[:])
            return
        for i in range(startIndex, len(candidates)):
            if need - candidates[i] < 0:  # 剪枝
                break
            if i > startIndex and candidates[i] == candidates[i - 1]:  # 去重
                continue
            self.path.append(candidates[i])
            self.backtracking(candidates, need - candidates[i], i + 1)
            self.path.pop()
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.backtracking(candidates, target, 0)
        return self.res

# @lc code=end

