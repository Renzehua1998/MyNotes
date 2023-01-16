#
# @lc app=leetcode.cn id=513 lang=python3
#
# [513] 找树左下角的值
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        que = collections.deque()
        que.append(root)
        res = 0
        while que:
            # lenq = len(que)
            for i in range(len(que)):
                node = que.popleft()
                if i == 0:
                    res = node.val
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
        return res
# @lc code=end

