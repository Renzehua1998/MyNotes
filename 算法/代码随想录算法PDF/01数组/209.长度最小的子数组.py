#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i = 0
        sum = 0
        result = float("inf")
        for j in range(len(nums)):
            sum += nums[j]
            while sum >= target:
                result = min(result, j - i + 1)
                sum -= nums[i]
                i += 1
        return 0 if result == float("inf") else result

# @lc code=end

