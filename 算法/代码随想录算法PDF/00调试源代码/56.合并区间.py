#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#

# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        left = intervals[0][0]
        right = intervals[0][1]
        res = []
        for i in range(1, len(intervals)):
            if intervals[i][0] > right:
                res.append([left, right])
                left = intervals[i][0]
            right = max(right, intervals[i][1])
        res.append([left, right])
        return res
# @lc code=end

