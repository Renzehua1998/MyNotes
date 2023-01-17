#
# @lc app=leetcode.cn id=105 lang=python3
#
# [105] 从前序与中序遍历序列构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def subBuild(inorder, inBegin, inEnd, preorder, preBegin, preEnd):
            if preEnd == preBegin: return None
            root = TreeNode(preorder[preBegin])
            if preEnd - preBegin == 1: return root
            
            cutIndex = inBegin
            while cutIndex < inEnd:
                if inorder[cutIndex] == root.val: break
                cutIndex += 1
            
            root.left = subBuild(inorder, inBegin, cutIndex, preorder, preBegin + 1, preBegin + cutIndex - inBegin + 1)
            root.right = subBuild(inorder, cutIndex + 1, inEnd, preorder, preBegin + cutIndex - inBegin + 1, preEnd)
            return root

        if len(inorder) == 0 or len(preorder) == 0:
            return None
        return subBuild(inorder, 0, len(inorder), preorder, 0, len(preorder))
# @lc code=end

