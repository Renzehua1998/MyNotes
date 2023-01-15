#
# @lc app=leetcode.cn id=572 lang=python3
#
# [572] 另一棵树的子树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        import sys

        def dfsOrder(root, order):
            if not root: return
            order.append(root.val)
            if root.left:
                dfsOrder(root.left, order)
            else:
                order.append(sys.maxsize)
            if root.right:
                dfsOrder(root.right, order)
            else:
                order.append(sys.maxsize)

        def kmp(s, t):
            lens = len(s)
            lent = len(t)
            next = [-1] * len(t)
            j = -1
            for i in range(1, lent):
                while j != -1 and t[i] != t[j + 1]:
                    j = next[j]
                if t[i] == t[j + 1]:
                    j += 1
                next[i] = j
            j = -1
            for i in range(lens):
                while j != -1 and s[i] != t[j + 1]:
                    j = next[j]
                if s[i] == t[j + 1]:
                    j += 1
                if j == lent - 1:
                    return True
            return False

        rootOrd = []
        subOrd = []
        dfsOrder(root, rootOrd)
        dfsOrder(subRoot, subOrd)
        return kmp(rootOrd, subOrd)
# @lc code=end

