#
# @lc app=leetcode.cn id=718 lang=python3
#
# [718] 最长重复子数组
#

# @lc code=start
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [0] * (len(nums2) + 1)
        res = 0
        for i in range(1, len(nums1) + 1):
            for j in range(len(nums2), 0, -1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[j] = dp[j - 1] + 1
                else:
                    dp[j] = 0
                if res < dp[j]:
                    res = dp[j]
        return res
# @lc code=end

