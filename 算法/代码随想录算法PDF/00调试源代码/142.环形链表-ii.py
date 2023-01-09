#
# @lc app=leetcode.cn id=142 lang=python3
#
# [142] 环形链表 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = head, head
        if not fast:  # 为空的特殊情况
            return None
        if fast.next:  # 初始化
            slow = slow.next
            fast = fast.next.next
        else:
            return None
        while fast != slow:  # 判断是否有环
            if (not fast) or (not fast.next):  # 没环，返回None
                return None
            slow = slow.next
            fast = fast.next.next
        slow = head  # 有环，找如环点
        while fast != slow:  # 指针相遇，找到
            slow = slow.next
            fast = fast.next
        return fast
# @lc code=end

