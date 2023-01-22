#
# @lc app=leetcode.cn id=332 lang=python3
#
# [332] 重新安排行程
#

# @lc code=start
import collections
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        res = []
        targets = collections.defaultdict(list)
        for ticket in tickets:  # 填充映射
            targets[ticket[0]].append(ticket[1])
        for value in targets.values():  # 排序映射
            value.sort()
        res.append("JFK")

        def backtracking():
            if len(res) == len(tickets) + 1: return True
            for _ in targets[res[-1]]:
                tmp = targets[res[-1]].pop(0)
                res.append(tmp)
                if backtracking(): return True
                res.pop()
                targets[res[-1]].append(tmp)
            return False

        backtracking()
        return res
# @lc code=end

