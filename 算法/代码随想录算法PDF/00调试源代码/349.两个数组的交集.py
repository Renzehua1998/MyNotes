#
# @lc app=leetcode.cn id=349 lang=python3
#
# [349] 两个数组的交集
#

# @lc code=start
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        resSet = set()
        numSet = set()
        for num in nums1:
            numSet.add(num)
        for num in nums2:
            if num in numSet:
                resSet.add(num)
        return list(resSet)
# @lc code=end

