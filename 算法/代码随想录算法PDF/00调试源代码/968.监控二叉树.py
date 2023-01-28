#
# @lc app=leetcode.cn id=968 lang=python3
#
# [968] 监控二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, root):
        if not root: return 2
        left = self.traversal(root.left)
        right = self.traversal(root.right)
        if left == 2 and right == 2:
            return 0
        elif left == 0 or right == 0:
            self.res += 1
            return 1
        else:
            return 2
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        if self.traversal(root) == 0:
            self.res += 1
        return self.res
# @lc code=end

