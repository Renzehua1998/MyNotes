#
# @lc app=leetcode.cn id=530 lang=python3
#
# [530] 二叉搜索树的最小绝对差
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        minDiff = float('inf')
        pre = None
        st = []
        while root or st:
            if root:
                st.append(root)
                root = root.left
            else:
                root = st.pop()
                if pre:
                    minDiff = min(minDiff, root.val - pre.val)
                pre = root
                root = root.right
        return minDiff
# @lc code=end

