#
# @lc app=leetcode.cn id=435 lang=python3
#
# [435] 无重叠区间
#

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0: return 0
        intervals.sort(key = lambda x: x[1])
        end = intervals[0][1]
        count = 1
        for item in intervals:
            if item[0] >= end:
                count += 1
                end = item[1]
        return len(intervals) - count
# @lc code=end

