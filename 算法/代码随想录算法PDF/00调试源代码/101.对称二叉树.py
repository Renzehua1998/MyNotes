#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root: return True
        st = []
        st.append(root.left)
        st.append(root.right)
        while st:
            left = st.pop()
            right = st.pop()
            if not left and not right:
                continue
            if not left or not right or left.val != right.val:
                return False
            st.append(left.left)
            st.append(right.right)
            st.append(left.right)
            st.append(right.left)
        return True

# @lc code=end

