#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        def backtracking(nums, startIndex):
            res.append(path[:])
            if startIndex >= len(nums): return
            for i in range(startIndex, len(nums)):
                path.append(nums[i])
                backtracking(nums, i + 1)
                path.pop()

        backtracking(nums, 0)
        return res
# @lc code=end

