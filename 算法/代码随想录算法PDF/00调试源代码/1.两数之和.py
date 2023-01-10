#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        option = {}
        for i in range(len(nums)):
            need = target - nums[i]
            if need in option:
                return [option[need], i]
            else:
                option[nums[i]] = i
        return []
# @lc code=end

