#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        def backtracking(nums, used):
            if len(nums) == len(path):
                res.append(path[:])
            for i in range(len(nums)):
                if used[i]:
                    continue
                used[i] = True
                path.append(nums[i])
                backtracking(nums, used)
                path.pop()
                used[i] = False
        
        used = [False] * len(nums)
        backtracking(nums, used)
        return res
# @lc code=end

