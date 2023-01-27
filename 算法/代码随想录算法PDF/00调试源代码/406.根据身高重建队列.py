#
# @lc app=leetcode.cn id=406 lang=python3
#
# [406] 根据身高重建队列
#

# @lc code=start
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # lambda返回的是一个元组：先按x[0]从高到低排序
        # 当-x[0](维度h）相同时，再根据x[1]（维度k）从小到大排序
        people.sort(key = lambda x : [-x[0], x[1]])
        que = []
        for p in people:
            que.insert(p[1], p)
        return que
# @lc code=end

