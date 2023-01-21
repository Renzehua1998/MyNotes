#
# @lc app=leetcode.cn id=90 lang=python3
#
# [90] 子集 II
#

# @lc code=start
class Solution:
    def __init__(self):
        self.res = []
        self.path = []
    def backtracking(self, nums, startIndex):
        self.res.append(self.path[:])
        for i in range(startIndex, len(nums)):
            if i > startIndex and nums[i] == nums[i - 1]:
                continue
            self.path.append(nums[i])
            self.backtracking(nums, i + 1)
            self.path.pop()
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.backtracking(nums, 0)
        return self.res
# @lc code=end

