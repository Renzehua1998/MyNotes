#
# @lc app=leetcode.cn id=232 lang=python3
#
# [232] 用栈实现队列
#

# @lc code=start
class MyQueue:

    def __init__(self):
        self.stIn = []
        self.stOut = []

    def push(self, x: int) -> None:
        self.stIn.append(x)

    def pop(self) -> int:
        if self.stOut:
            return self.stOut.pop()
        else:
            for i in range(len(self.stIn)):
                self.stOut.append(self.stIn.pop())
            return self.stOut.pop()

    def peek(self) -> int:
        res = self.pop()
        self.stOut.append(res)
        return res

    def empty(self) -> bool:
        return not self.stIn and not self.stOut



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# @lc code=end

