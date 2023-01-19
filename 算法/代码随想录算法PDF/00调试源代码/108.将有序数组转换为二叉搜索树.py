#
# @lc app=leetcode.cn id=108 lang=python3
#
# [108] 将有序数组转换为二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 0: return None
        root = TreeNode()
        nodeSt = [root]
        leftSt = [0]
        rightSt = [len(nums)]

        while nodeSt:
            node = nodeSt.pop()
            left = leftSt.pop()
            right = rightSt.pop()
            mid = left + (right - left) // 2
            node.val = nums[mid]

            if left < mid:
                node.left = TreeNode()
                nodeSt.append(node.left)
                leftSt.append(left)
                rightSt.append(mid)
            
            if right > mid + 1:
                node.right = TreeNode()
                nodeSt.append(node.right)
                leftSt.append(mid + 1)
                rightSt.append(right)
        
        return root
# @lc code=end

