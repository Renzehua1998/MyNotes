#
# @lc app=leetcode.cn id=654 lang=python3
#
# [654] 最大二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:

        def traversal(nums, begin, end):
            if begin >= end: return None
            maxNum = nums[begin]
            maxIndex = begin
            for i in range(begin, end):
                if nums[i] > maxNum:
                    maxNum = nums[i]
                    maxIndex = i
            root = TreeNode(maxNum)
            root.left = traversal(nums, begin, maxIndex)
            root.right = traversal(nums, maxIndex + 1, end)
            return root
        
        return traversal(nums, 0, len(nums))
# @lc code=end

