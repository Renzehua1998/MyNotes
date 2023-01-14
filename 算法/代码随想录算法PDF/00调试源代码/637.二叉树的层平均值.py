#
# @lc app=leetcode.cn id=637 lang=python3
#
# [637] 二叉树的层平均值
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        from collections import deque
        que = deque([])
        res = []
        if root:
            que.append(root)
        while que:
            sum = 0
            size = len(que)
            for i in range(size):
                node = que.popleft()
                sum += node.val
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
            res.append(sum / size)
        return res
# @lc code=end

