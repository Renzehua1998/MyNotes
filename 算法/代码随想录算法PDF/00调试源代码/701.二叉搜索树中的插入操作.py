#
# @lc app=leetcode.cn id=701 lang=python3
#
# [701] 二叉搜索树中的插入操作
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        cur, pre = root, root
        while cur:
            pre = cur
            if cur.val > val:
                cur = cur.left
            else:
                cur = cur.right
        node = TreeNode(val)
        if pre.val > val:
            pre.left = node
        else:
            pre.right = node
        return root
# @lc code=end

