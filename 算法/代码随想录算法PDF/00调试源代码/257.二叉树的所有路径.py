#
# @lc app=leetcode.cn id=257 lang=python3
#
# [257] 二叉树的所有路径
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res = []
        if not root: return res
        treeSt, pathSt = [root], [str(root.val)]
        while treeSt:
            node = treeSt.pop()
            path = pathSt.pop()
            if not node.left and not node.right:
                res.append(path)
            if node.right:
                treeSt.append(node.right)
                pathSt.append(path + "->" + str(node.right.val))
            if node.left:
                treeSt.append(node.left)
                pathSt.append(path + "->" + str(node.left.val))
        return res
# @lc code=end

