#
# @lc app=leetcode.cn id=404 lang=python3
#
# [404] 左叶子之和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        st = [root]
        res = 0
        while st:
            node = st.pop()
            if node.left and not node.left.left and not node.left.right:
                res += node.left.val
            if node.right:
                st.append(node.right)
            if node.left:
                st.append(node.left)
        return res
# @lc code=end

