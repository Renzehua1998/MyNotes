#
# @lc app=leetcode.cn id=222 lang=python3
#
# [222] 完全二叉树的节点个数
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        left = root.left
        right = root.right
        leftNum = 0
        rightNum = 0
        while left:
            left = left.left
            leftNum += 1
        while right:
            right = right.right
            rightNum += 1
        if leftNum == rightNum:
            return 2 ** (leftNum + 1) -1
        return self.countNodes(root.left) + self.countNodes(root.right) + 1
# @lc code=end

