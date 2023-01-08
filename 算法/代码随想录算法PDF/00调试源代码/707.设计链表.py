#
# @lc app=leetcode.cn id=707 lang=python3
#
# [707] 设计链表
#

# @lc code=start
class ListNode:
    def __init__(self, val = 0) -> None:
        self.val = val
        self.next = None
class MyLinkedList:

    def __init__(self):
        self.dummyHead = ListNode()
        self.size = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        cur = self.dummyHead.next
        while index:
            cur = cur.next
            index -= 1
        return cur.val

    def addAtHead(self, val: int) -> None:
        node = ListNode(val)
        node.next = self.dummyHead.next
        self.dummyHead.next = node
        self.size += 1

    def addAtTail(self, val: int) -> None:
        node = ListNode(val)
        cur = self.dummyHead
        while cur.next:
            cur = cur.next
        cur.next = node
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.size:
            return
        if index < 0:
            index = 0
        node = ListNode(val)
        cur = self.dummyHead
        while index:
            cur = cur.next
            index -= 1
        node.next = cur.next
        cur.next = node
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        cur = self.dummyHead
        while index:
            cur = cur.next
            index -= 1
        cur.next = cur.next.next
        self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
# @lc code=end

