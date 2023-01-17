#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        pre = None
        st = []
        while root or st:
            if root:
                st.append(root)
                root = root.left
            else:
                root = st.pop()
                if pre and pre.val >= root.val:
                    return False
                pre = root
                root = root.right
        return True
# @lc code=end

