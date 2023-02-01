#
# @lc app=leetcode.cn id=337 lang=python3
#
# [337] 打家劫舍 III
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def robTree(self, root: Optional[TreeNode]) -> list:
        if not root: return [0, 0]
        left = self.robTree(root.left)
        right = self.robTree(root.right)
        res1 = root.val + left[0] + right[0]
        res2 = max(left) + max(right)
        return [res2, res1]
    def rob(self, root: Optional[TreeNode]) -> int:
        res = self.robTree(root)
        return max(res)
# @lc code=end

