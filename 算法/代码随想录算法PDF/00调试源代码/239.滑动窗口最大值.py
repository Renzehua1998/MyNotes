#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
from collections import *
class MyQueue:
    # 初始化
    def __init__(self) -> None:
        self.que = deque()

    # push新元素，把小于它的全清除
    def push(self, x) -> None:
        while self.que and self.que[-1] < x:
            self.que.pop()
        self.que.append(x)
    
    # pop头部元素，只在相等时pop
    def pop(self, x) -> None:
        if self.que and self.que[0] == x:
            self.que.popleft()
    
    # 获取最大元素
    def maxVal(self) -> int:
        return self.que[0]

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        que = MyQueue()
        res = []
        for i in range(k):
            que.push(nums[i])
        res.append(que.maxVal())
        for i in range(k, len(nums)):
            que.pop(nums[i - k])
            que.push(nums[i])
            res.append(que.maxVal())
        return res
# @lc code=end

