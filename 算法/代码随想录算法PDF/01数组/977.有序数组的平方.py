#
# @lc app=leetcode.cn id=977 lang=python3
#
# [977] 有序数组的平方
#

# @lc code=start
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        i = 0
        n = len(nums)
        j, k = n - 1, n - 1
        result = [0] * n
        while i <= j:
            if nums[i] ** 2 < nums[j] ** 2:
                result[k] = nums[j] ** 2
                j -= 1
            else:
                result[k] = nums[i] ** 2
                i += 1
            k -= 1
        return result

# @lc code=end

