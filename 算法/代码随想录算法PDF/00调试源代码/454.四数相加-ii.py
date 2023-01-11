#
# @lc app=leetcode.cn id=454 lang=python3
#
# [454] 四数相加 II
#

# @lc code=start
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        umap = collections.defaultdict(int)
        for a in nums1:
            for b in nums2:
                umap[a + b] += 1
        count = 0
        for c in nums3:
            for d in nums4:
                if (0 - c - d) in umap:
                    count += umap[0 - c - d]
        return count
# @lc code=end

