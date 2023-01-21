#
# @lc app=leetcode.cn id=47 lang=python3
#
# [47] 全排列 II
#

# @lc code=start
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        def backtracking(nums, used):
            if len(nums) == len(path):
                res.append(path[:])
            for i in range(len(nums)):
                if used[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and used[i - 1] == False:
                    continue
                used[i] = True
                path.append(nums[i])
                backtracking(nums, used)
                path.pop()
                used[i] = False
        
        used = [False] * len(nums)
        nums.sort()
        backtracking(nums, used)
        return res
# @lc code=end

