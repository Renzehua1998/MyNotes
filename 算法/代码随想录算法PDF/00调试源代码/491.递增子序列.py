#
# @lc app=leetcode.cn id=491 lang=python3
#
# [491] 递增子序列
#

# @lc code=start
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        def backtracking(nums, startIndex):
            if len(path) > 1:
                res.append(path[:])
            used = set()
            for i in range(startIndex, len(nums)):
                if (len(path) > 0 and nums[i] < path[-1]) or nums[i] in used:
                    continue
                used.add(nums[i])
                path.append(nums[i])
                backtracking(nums, i + 1)
                path.pop()
        
        backtracking(nums, 0)
        return res
# @lc code=end

