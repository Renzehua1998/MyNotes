#
# @lc app=leetcode.cn id=350 lang=python3
#
# [350] 两个数组的交集 II
#

# @lc code=start
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        nums1.sort()
        nums2.sort()
        point1, point2 = 0, 0
        while point1 < len(nums1) and point2 < len(nums2):
            if nums1[point1] < nums2[point2]:
                point1 += 1
            elif nums1[point1] > nums2[point2]:
                point2 += 1
            else:
                res.append(nums1[point1])
                point1 += 1
                point2 += 1
        return res
# @lc code=end

