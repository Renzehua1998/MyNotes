#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        dummyHead.next = head
        cur = dummyHead
        while cur.next and cur.next.next:
            # 临时变量存放待交换节点指针
            temp1 = cur.next
            temp2 = cur.next.next.next
            # 更新顺序
            cur.next = cur.next.next
            cur.next.next = temp1
            temp1.next = temp2
            # 更新cur指针
            cur = cur.next.next
        return dummyHead.next
# @lc code=end

