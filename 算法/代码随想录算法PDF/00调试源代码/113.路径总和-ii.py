#
# @lc app=leetcode.cn id=113 lang=python3
#
# [113] 路径总和 II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import copy
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        path = []

        def dfs(root, targetSum):
            if not root: return
            path.append(root.val)
            if not root.left and not root.right and targetSum == root.val:
                res.append(path[:])
            if root.left:
                dfs(root.left, targetSum - root.val)
                path.pop()
            if root.right:
                dfs(root.right, targetSum - root.val)
                path.pop()
        
        dfs(root, targetSum)
        return res
# @lc code=end

