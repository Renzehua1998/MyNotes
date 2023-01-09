#
# @lc app=leetcode.cn id=160 lang=python3
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        curA, curB = headA, headB
        while curA != curB:
            if curA:
                curA = curA.next
            else:
                curA = headB
            
            if curB:
                curB = curB.next
            else:
                curB = headA
        return curA
# @lc code=end

