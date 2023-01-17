#
# @lc app=leetcode.cn id=106 lang=python3
#
# [106] 从中序与后序遍历序列构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        def subBuild(inorder, inBegin, inEnd, postorder, poBegin, poEnd):
            if poEnd == poBegin: return None
            root = TreeNode(postorder[poEnd - 1])
            if poEnd - poBegin == 1: return root
            
            cutIndex = inBegin
            while cutIndex < inEnd:
                if inorder[cutIndex] == root.val: break
                cutIndex += 1
            
            root.left = subBuild(inorder, inBegin, cutIndex, postorder, poBegin, poBegin + cutIndex - inBegin)
            root.right = subBuild(inorder, cutIndex + 1, inEnd, postorder, poBegin + cutIndex - inBegin, poEnd - 1)
            return root

        if len(inorder) == 0 or len(postorder) == 0:
            return None
        return subBuild(inorder, 0, len(inorder), postorder, 0, len(postorder))
# @lc code=end

