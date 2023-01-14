#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] 二叉树的中序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        st = []
        if root:
            st.append(root)
        while st:
            node = st.pop()
            if node:
                if node.right:
                    st.append(node.right)
                st.append(node)
                st.append(None)
                if node.left:
                    st.append(node.left)
            else:
                node = st.pop()
                res.append(node.val)
        return res
# @lc code=end

