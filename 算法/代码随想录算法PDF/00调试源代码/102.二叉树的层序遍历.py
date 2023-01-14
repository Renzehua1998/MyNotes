#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        def order(node, res, layer):
            if node == None:
                return
            if len(res) == layer:
                res.append([])
            res[layer].append(node.val)
            order(node.left, res, layer + 1)
            order(node.right, res, layer + 1)

        res = []
        layer = 0
        order(root, res, layer)
        return res
# @lc code=end

