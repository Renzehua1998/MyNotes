#
# @lc app=leetcode.cn id=617 lang=python3
#
# [617] 合并二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root1: return root2
        if not root2: return root1
        st = [root2, root1]
        while st:
            node1 = st.pop()
            node2 = st.pop()
            node1.val += node2.val

            if node1.left and node2.left:
                st.append(node2.left)
                st.append(node1.left)
            if node1.right and node2.right:
                st.append(node2.right)
                st.append(node1.right)
            
            if not node1.left and node2.left:
                node1.left = node2.left
            if not node1.right and node2.right:
                node1.right = node2.right
            
        return root1
# @lc code=end

