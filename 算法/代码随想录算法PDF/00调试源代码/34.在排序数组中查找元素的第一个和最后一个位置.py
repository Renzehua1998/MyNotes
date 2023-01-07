#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums) - 1
        leftPos = -2
        while left <= right:
            mid = (left + right) // 2
            if (nums[mid] < target):
                left = mid + 1
            else:
                right = mid - 1
                leftPos = right
        left = 0
        right = len(nums) - 1
        rightPos = -2
        while left <= right:
            mid = (left + right) // 2
            if (nums[mid] <= target):
                left = mid + 1
                rightPos = left
            else:
                right = mid - 1
        if rightPos - leftPos > 1 and rightPos != -2 and leftPos != -2:
            return [leftPos + 1, rightPos - 1]
        return [-1, -1]
# @lc code=end

