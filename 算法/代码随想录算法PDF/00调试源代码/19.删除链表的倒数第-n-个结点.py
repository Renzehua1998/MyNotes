#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第 N 个结点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummyHead = ListNode()
        dummyHead.next = head
        left, right = dummyHead, dummyHead
        while n:
            right = right.next
            n -= 1
        right = right.next # 右指针继续移动
        while right:
            right = right.next
            left = left.next
        left.next = left.next.next
        return dummyHead.next
# @lc code=end

