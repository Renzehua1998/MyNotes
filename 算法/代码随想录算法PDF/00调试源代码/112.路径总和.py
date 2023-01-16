#
# @lc app=leetcode.cn id=112 lang=python3
#
# [112] 路径总和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root: return False
        st = [(root, root.val)]
        while st:
            node, sumP = st.pop()
            if not node.left and not node.right and sumP == targetSum:
                return True
            if node.left:
                st.append((node.left, sumP + node.left.val))
            if node.right:
                st.append((node.right, sumP + node.right.val))
        return False
# @lc code=end

