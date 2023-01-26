#
# @lc app=leetcode.cn id=134 lang=python3
#
# [134] 加油站
#

# @lc code=start
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        curSum = 0
        totSum = 0
        start = 0
        for i in range(len(gas)):
            curSum += gas[i] - cost[i]
            totSum += gas[i] - cost[i]
            if curSum < 0:
                start = i + 1
                curSum = 0
        if totSum < 0:
            return -1
        return start
# @lc code=end

